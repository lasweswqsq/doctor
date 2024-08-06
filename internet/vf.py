from fastapi import FastAPI

app=FastAPI()

'''
当视图函数声明不属于 URL 路径参数的其他参数时，FastAPI 将自动解析为 Query 查询参数。



✍ 查询参数即 URL 地址中 ? 之后的一系列用 & 分隔的 key-value 键值对。


比如，下面用于处理集合资源访问的视图函数就定义了两个查询参数：
'''
@app.get("/items/")
async def get_items(skip: int = 0, limit: int = 10):
    return {"items": [], "skip": skip, "limit": limit}



#uvicorn vf:app --reload