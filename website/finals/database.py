import pymysql
import pprint as pp

conn = pymysql.connect(
    host='DTY-AI-PC',  # 主机名
    port=3306,         # 端口号，MySQL默认为3306
    user='heima',       # 用户名
    password='1234', # 密码
    database='book_manager',   # 数据库名称
)

print(conn)

#游标实际上是一种能从包括多条数据记录的结果集中每次提取一条记录的机制
#尽管游标能遍历结果中的所有行，但他一次只指向一行。
#游标的一个常见用途就是保存查询结果，以便以后使用。 游标的结果集是由SELECT语句产生，如果处理过程需要重复使用一个记录集，那么创建一次游标而重复使用若干次，比重复查询数据库要快的多。

#创建游标
cursor = conn.cursor()
# 执行 SQL 查询语句
cursor.execute("SELECT * FROM book WHERE author = '12wehd723b'")

#cursor.execute("SELECT * FROM book WHERE author = '2'")
#cursor.execute("UPDATE book set author='12wehd723b' where title='123124';")
#update,insert could not be run



#execute 会产生覆盖效果，不会报错
# 获取查询结果
result = cursor.fetchall()

#this is useful
pp.pprint(result)

import pandas as pd
# 将查询结果转化为 Pandas dataframe 对象
df = pd.DataFrame(result, columns=[i[0] for i in cursor.description])

print(df)
#this is useless
pp.pprint(df)

# 关闭游标和数据库连接
cursor.close()
conn.close()