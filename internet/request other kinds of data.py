from fastapi import FastAPI

app = FastAPI()



@app.get("/items/{item_id}")
async def get_item(item_id: int, q: str = None):
    return {"item_id": item_id, "q": q}

#uvicorn fastapi_conn:app --reload