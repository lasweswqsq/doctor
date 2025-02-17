import numpy as np
import pymysql
import pprint as pp
from plotly.graph_objs import Bar, Layout
from plotly import offline

conn = pymysql.connect(
    host='DTY-AI-PC',  # 主机名
    port=3306,         # 端口号，MySQL默认为3306
    user='heima',       # 用户名
    password='1234', # 密码
    database='book_manager',   # 数据库名称
)

cursor = conn.cursor()

cursor.execute("SELECT book_id FROM borrow_record")

result = cursor.fetchall()
dic={}
for row in result:
    book_id = row[0]
    if book_id in dic:
        dic[book_id] += 1
    else:
        dic[book_id] = 1

x = sorted(dic.items(), key=lambda x: x[1], reverse=True)
categories = [i[0] for i in x]
z = [i[1] for i in x]

import matplotlib.pyplot as plt

bar_width = 0.35
index = np.arange(len(categories))
plt.bar(index, z, bar_width, alpha=0.8, color='orange')
plt.xlabel('Book ID')
plt.ylabel('Number of Borrowing')
plt.title('Number of Borrowing of Each Book')
plt.xticks(index + bar_width / 2 - 0.15, categories)

#plt.show()
plt.savefig('bar_chart.png')
#pp.pprint(dic)

cursor.close()
conn.close()


