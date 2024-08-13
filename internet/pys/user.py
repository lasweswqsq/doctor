from fastapi import FastAPI
 
app = FastAPI()


@app.get("/users/me")
async def get_user_me():
    return {"user_id": "current_user info..."}

@app.get("/users/{user_id}")
async def get_user(user_id: str):
    return {"user_id": user_id}
#uvicorn user:app --reload


'''
路由匹配是按顺序进行的，这意味着如果某个静态的 URL 刚好可以匹配到另一个动态的 URL 规则，为了能够正确触发静态 URL 规则对应的视图函数，应确保该 URL 在动态 URL 规则之前声明。

比如：一个固定 URL 的 /users/me 获取当前用户的数据，还有一个动态路由 /users/{user_id} 获取指定 ID 的用户数据。

我们需要确保 /users/me 路径在 /users/{user_id} 路径之前已声明，否则 /users/{user_id} 也将匹配 users/me 。
'''



