
import random
from fastapi.responses import FileResponse
import pymysql
import datetime
from fastapi.middleware.cors import CORSMiddleware

from fastapi import FastAPI, Header

import os


conn = pymysql.connect(
    host='DTY-AI-PC',  # 主机名
    port=3306,         # 端口号，MySQL默认为3306
    user='heima',       # 用户名
    password='1234', # 密码
    database='book_manager',   # 数据库名称
)




app = FastAPI()

# 配置允许的源列表 
origins = ["*" ] 
# 添加 CORS 中间件 
app.add_middleware(CORSMiddleware, 
                   allow_origins=origins, 
                   allow_credentials=True, # 允许携带认证信息 
                   allow_methods=["*"], # 允许所有方法（GET, POST, PUT, DELETE 等） 
                   allow_headers=["*"], # 允许所有头信息 
                   )

#same website name only counts the first
@app.get("/items/{title}")
async def get_book_info(title:str, token: str = Header(None)):
    #print(token)
    
    #创建游标
    cursor = conn.cursor()
    time = datetime.datetime.now()
    cursor.execute("SELECT * FROM token WHERE token=%s and expire_time>%s", (token,time))
    resul = cursor.fetchone()
    if resul:  
        cursor.execute("SELECT * FROM book WHERE title like %s", ("%"+title+"%"))
        result = cursor.fetchall()
        return {
            "status": 1,
            "data": result
        }
    else:
        return {
            "status": -2,
            "message": "token expired"
        }


@app.post("/items/borrow/{id}")
async def patch_book_info(id:int):
    cursor = conn.cursor()
    # 执行 SQL 查询语句
    print(id)
    cursor.execute("UPDATE book set status=1 where id=%s", id)
    conn.commit()
    return 0

@app.post("/items/return/{id}")
async def fridge_book_info(id:int):
    cursor = conn.cursor()
    # 执行 SQL 查询语句
    cursor.execute("UPDATE book set status=0 where id=%s", id)
    conn.commit()
    return 0


@app.post("/users/{user}/{password}")
async def ps_book_info(user:str,password:str):
    cursor = conn.cursor()
    # 执行 SQL 查询语句
    cursor.execute("SELECT * FROM user WHERE name=%s AND password=%s", (user, password))
    result = cursor.fetchall()
    time = datetime.datetime.now()
    time = time + datetime.timedelta(hours=2)
    if result:
        key=random.randint(1,10000000)
        cursor.execute("INSERT INTO token (token,user,expire_time) VALUES (%s,%s,%s)", (key,user,time))
        conn.commit()
        return {
            "status": 1,
            "token": key,
            "expire_time": time
        }
    else:
        return {
            "status": 0
        }
    

@app.post("/items/add/{title}/{author}/{time}/{creator}")
async def ps_book_info(title:str,author:str,time:str,creator:str):
    cursor = conn.cursor()
    create_time = datetime.datetime.now()
    # 执行 SQL 查询语句
    cursor.execute("INSERT INTO book (title,author,time,create_time,creator,status) VALUES (%s,%s,%s,%s,%s,0)", (title,author,time,create_time,creator))
    conn.commit()
    return 0

@app.post("/items/update/{id}/{title}/{author}/{time}")
async def ps2_book_info(id:int,title:str,author:str,time:str):
    cursor = conn.cursor()
    create_time = datetime.datetime.now()
    # 执行 SQL 查询语句
    cursor.execute("UPDATE book SET title=%s,author=%s,time=%s,create_time=%s WHERE id=%s", (title,author,time,create_time,id))
    conn.commit()
    return 0

@app.get("/item/{id}")
async def ps21_book_info(id:int):
    print(id)
    cursor = conn.cursor()
    cursor.execute("select * from book where id=%s", id)
    result = cursor.fetchone()
    print(result)
    return result

@app.post("/items/delete/{id}")
async def ps21_book_info(id:int):
    print(id)
    cursor = conn.cursor()
    cursor.execute("delete from book where id=%s", id)
    conn.commit()

@app.get("/items/export/{title}")
async def get_book_info(title:str):
    #创建游标
    cursor = conn.cursor()
    # 执行 SQL 查询语句
    cursor.execute("SELECT * FROM book WHERE title like %s", ("%"+title+"%"))
    result = cursor.fetchall()
    result=str(result)
    with open("book.txt","w",encoding="utf-8") as f:
        f.write(result)
    # image_data = open("book.txt","rb").read()
    headers = {'Content-Disposition': 'attachment; filename="example.txt"'}
    return FileResponse(path="book.txt", media_type="text/plain", headers=headers)




#uvicorn database:app --reload

#@app.post("/users/{user}/{password}")
#async def ps_book_info(user:str,password:str):

'''
    # 获取文件的绝对路径
    file_path = os.path.abspath("d://temp//book.txt")
    # 转换为URL
    file_url = 'file://' + file_path
'''