from fastapi import FastAPI

app=FastAPI()

'''
当视图函数声明不属于 URL 路径参数的其他参数时，FastAPI 将自动解析为 Query 查询参数。



✍ 查询参数即 URL 地址中 ? 之后的一系列用 & 分隔的 key-value 键值对。


比如，下面用于处理集合资源访问的视图函数就定义了两个查询参数：
'''
#http://127.0.0.1:8000/items/?skip=20&limit=15
#http://127.0.0.1:8000/items/  <———默认参数


#此外，因为我们在定义视图函数时，为查询参数 skip 和 limit 指定了默认值，因此查询参数将变为可选的，缺省时将使用默认值。
#https://www.baidu.com/
#https://www.baidu.com/s?wd=%E9%BB%98%E8%AE%A4%E5%80%BC%20%E8%8B%B1%E6%96%87&ie=utf-8&tn=15007414_2_pg
@app.get("/items/")
async def get_items(skip: int = 0, limit: int = 10):
    return {"items": [], "skip": skip, "limit": limit}



#uvicorn vf:app --reload