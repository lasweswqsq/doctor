import pandas as pd
import pymysql
from sqlalchemy import create_engine
def query_mysql(sql_query, host=None, port=None, user=None, password=None, database=None, engine=None):
    """
    连接 MySQL 数据库，执行查询，并将查询结果转化为 Pandas DataFrame 对象。
    :param sql_query: SQL 查询语句 this is what you want
    :param host: 主机名，默认为 None
    :param port: 端口号，默认为 None
    :param user: 用户名，默认为 None
    :param password: 密码，默认为 None
    :param database: 数据库名称，默认为 None
    :param engine: SQLAlchemy 的数据库引擎对象，默认为 None
    :return: Pandas DataFrame 对象
    """
    # 如果未提供数据库连接引擎，则使用 pymysql 库连接 MySQL 数据库
    if engine is None:
        # 连接 MySQL 数据库
        conn = pymysql.connect(
            host=host,
            port=port,
            user=user,
            password=password,
            database=database,
        )
        # 创建游标对象
        cursor = conn.cursor()
        # 执行 SQL 查询语句
        cursor.execute(sql_query)
        # 获取查询结果
        result = cursor.fetchall()
        # 将查询结果转化为 Pandas DataFrame 对象
        df = pd.DataFrame(result, columns=[i[0] for i in cursor.description])
        # 关闭游标和数据库连接
        cursor.close()
        conn.close()
    # 如果已提供数据库连接引擎，则使用 SQLAlchemy 库连接 MySQL 数据库
    else:
        # 执行 SQL 查询语句，并将结果转化为 Pandas DataFrame 对象
        df = pd.read_sql(sql_query, con=engine)
    return df

'''
    host='DTY-AI-PC',  # 主机名
    port=3306,         # 端口号，MySQL默认为3306
    user='heima',       # 用户名
    password='1234', # 密码
    database='book_manager',   # 数据库名称
'''
c=query_mysql("select COUNT(*) from book;", host='DTY-AI-PC', port=3306, user='heima', password='1234', database='book_manager', engine=None)
d=query_mysql("select distinct title from book;", host='DTY-AI-PC', port=3306, user='heima', password='1234', database='book_manager', engine=None)
er=query_mysql("select creator from book where author like '_';", host='DTY-AI-PC', port=3306, user='heima', password='1234', database='book_manager', engine=None)


print(c,d,er)