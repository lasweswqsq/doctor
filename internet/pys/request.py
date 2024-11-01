from fastapi import FastAPI
 
app = FastAPI()
 
@app.get("/items/")
async def read_items(q: str = None):
    """
    q：查询参数
    """
 
    results = {"items": [{"item_id": "Foo"}, {"item_id": "Bar"}]}
    if q:
        results.update({"q": q})
    return results

#uvicorn request:app --reload