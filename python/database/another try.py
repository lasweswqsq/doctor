# 步骤 1：创建 MySQL 数据库连接引擎
import pprint as pp

from sqlalchemy import create_engine

# 创建 MySQL 数据库连接引擎
engine = create_engine('mysql+pymysql://heima:1234@DTY-AI-PC:3306/book_manager')

#步骤 2：执行 SQL 查询语句并将结果转化为 Pandas dataframe 对象
import pandas as pd

# 执行 SQL 查询语句，并将结果转化为 Pandas dataframe 对象
df = pd.read_sql("select COUNT(*) from book;", con=engine)
dc=pd.read_sql("select time from book where author='2'", con=engine)
#dp=pd.read_sql("INSERT INTO book(title,author,time,create_time,creator) values('123124','234yt2gs87dgh3si','1994-12-22 10:31:48','1994-12-22 10:31:48','nscjoxe8g09psk');", con=engine)
print(df,'\n',dc)

# 关闭数据库连接
engine.dispose()








