from fastapi import FastAPI, Header,Body
from pydantic import BaseModel

app = FastAPI()


@app.get("/iteems/")
def get_items(user_agent: str = Header(None),user: str = Body(None)):
    return {'User-Agent': user_agent,'wjheuhe':user}


@app.get("/items/")
def get_items(user_agent: str = Header(None, convert_underscores=False)):
    return {'User-Agent': user_agent}
#{"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 SLBrowser/9.0.3.5211 SLBChan/112","wjheuhe":null}


#uvicorn head:app --reload