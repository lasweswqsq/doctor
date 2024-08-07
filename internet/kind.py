from pydantic import BaseModel

#这定义了一件商品 的 姓名，描述，宽，高
#不用初始化__init__
class Item(BaseModel):
    name: str
    description: str = None
    width: float
    height: float



from fastapi import FastAPI

app = FastAPI()

#这其实是用html创建了一个网页，用户可以在 http://127.0.0.1:8000/items/  上面输入上述商品对应信息

@app.post("/items/")
async def create_item(item: Item):

    return item

#这是当用户输入特定的  比如说   http://127.0.0.1:8000/items/apple  时，其能够修改对应的苹果信息

@app.put("/items/{name}")
async def modify_item(name: str, item: Item):
    return {'name': name, **item.dict()}


#**item.dict()代表展示字典中所有项
#中间划横线代表此段低吗已经被淘汰，但仍然能够被使用

#uvicorn kind:app --reload




