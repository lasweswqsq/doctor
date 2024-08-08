from multiprocessing.resource_tracker import getfd
import pymysql
import pprint as pp
from fastapi.middleware.cors import CORSMiddleware



conn = pymysql.connect(
    host='DTY-AI-PC',  # 主机名
    port=3306,         # 端口号，MySQL默认为3306
    user='heima',       # 用户名
    password='1234', # 密码
    database='book_manager',   # 数据库名称
)


from fastapi import FastAPI

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
#uvicorn database:app --reload