from fastapi import FastAPI, Form

app = FastAPI()

@app.post("/login/")
async def login(username: str = Form('admin'), password: str = Form()):
    return {"username": username, "password": password}

#uvicorn exe:app --reload