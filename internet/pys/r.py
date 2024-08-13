from fastapi import FastAPI

app = FastAPI()



@app.get("/items/{book_id}")
#async def 的含义是用户可以用网址的方式调用函数
#like http://127.0.0.1:8000/items/1

async def get_book_info(book_id:int, title:str = None):
    return {"book_id":book_id, "title": "pass"},{"hsgdh":book_id,"jddhq93":"iw"}
    return {"hsgdh":book_id,"jddhq93":"iw"}
#this down one would not count

#same website name only counts the first
@app.get("/items/{book_id}")
async def get_book_info(book_id:int, title:str = None):
    return {"hsgdh":book_id,"jddhq93":"iw"}
#get_item(12,'3gfwyug')

#error:{"detail":[{"type":"int_parsing","loc":["path","book_id"],"msg":"Input should be a valid integer, unable to parse string as an integer","input":"2w"}]}

'''
from fastapi import FastAPI


app = FastAPI()


@app.get("/")
async def index():
    return {"msg": "Hello World!"}


@app.get("/items/{item_id}")
async def get_item(item_id: int, q: str = None):
    return {"item_id": item_id, "q": q}
#get_item(23,'23None')

#Usage: uvicorn [OPTIONS] APP
#Try 'uvicorn --help' for help.

#Error: Got unexpected extra arguments (other kinds of data:app)

#字符串 hello 无法被转换为整型，因此类型校验失败，返回的错误消息也清晰地指出了这一点，还是非常友好的。

'''
#cd internet
#uvicorn r:app --reload
'''
@app.get("/users/me")
async def get_user_me():
    return {"user_id": "current_user info..."}

@app.get("/users/{user_id}")
async def get_user(user_id: str):
    return {"user_id": user_id}
'''


