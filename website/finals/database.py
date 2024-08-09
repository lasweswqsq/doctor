
import pymysql
import datetime
from fastapi.middleware.cors import CORSMiddleware



conn = pymysql.connect(
    host='DTY-AI-PC',  # 主机名
    port=3306,         # 端口号，MySQL默认为3306
    user='heima',       # 用户名
    password='1234', # 密码
    database='book_manager',   # 数据库名称
)


from fastapi import FastAPI, Form

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
async def get_book_info(title:str):
    #创建游标
    cursor = conn.cursor()
    # 执行 SQL 查询语句
    cursor.execute("SELECT * FROM book WHERE title like %s", ("%"+title+"%"))

    result = cursor.fetchall()
    return result


@app.post("/items/borrow/{id}")
async def patch_book_info(id:int):
    cursor = conn.cursor()
    # 执行 SQL 查询语句
    cursor.execute("UPDATE book set status=1 where id=%s", id)
    return 0

@app.post("/items/return/{id}")
async def fridge_book_info(id:int):
    cursor = conn.cursor()
    # 执行 SQL 查询语句
    cursor.execute("UPDATE book set status=0 where id=%s", id)
    return 0


@app.post("/users/{user}/{password}")
async def ps_book_info(user:str,password:str):
    cursor = conn.cursor()
    # 执行 SQL 查询语句
    cursor.execute("SELECT * FROM user WHERE name=%s AND password=%s", (user, password))
    result = cursor.fetchall()
    if result:
        return 1
    else:
        return 0
    

@app.post("/items/add/{title}/{author}/{time}/{creator}")
async def ps_book_info(title:str,author:str,time:str,creator:str):
    cursor = conn.cursor()
    create_time = datetime.datetime.now()
    # 执行 SQL 查询语句
    cursor.execute("INSERT INTO book (title,author,time,create_time,creator,status) VALUES (%s,%s,%s,%s,%s,0)", (title,author,time,create_time,creator))
    conn.commit()
    return 0



#uvicorn database:app --reload

#@app.post("/users/{user}/{password}")
#async def ps_book_info(user:str,password:str):


