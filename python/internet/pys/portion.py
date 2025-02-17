from fastapi import FastAPI

app = FastAPI()

#this is the wrong writing mode
#@app.get("/items/{item_id}")
#async def get_item(item_id: int, q: str):
#    return {"item_id": item_id, "q": q}



@app.get("/items/{item_id}/{q}")
async def get_item(item_id: int, q: str):
    return {"item_id": item_id, "q": q}

#uvicorn portion:app --reload