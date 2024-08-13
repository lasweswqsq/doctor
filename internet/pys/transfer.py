from fastapi import FastAPI

app=FastAPI()
@app.get("/items/{item_id}")
async def get_item(item_id: int, q:str= '', short: bool = False):
    item = {"item_id": item_id}
    #if q: item.update({'q': q}) 这段代码的含义是检查变量 q 是否存在（‌即是否为真）‌，‌如果存在，‌则更新一个字典 item，‌将键 'q' 的值设置为变量 q 的值。‌这里，‌item.update({'q': q}) 是 Python 中字典的一个方法，‌用于更新字典中的键值对。‌如果 q 变量不为空（‌即存在）‌，‌则该语句将 q 的值赋给字典 item 中的 'q' 键。‌如果 q 不存在（‌即为空或假）‌，‌则该语句不会执行任何操作，‌字典 item 保持不变。‌
    if q:
        item.update({'q': q})
    item.update({'short': short})
    return item



#可以添加语句以用来输出更多信息
#update 的信息要和原来的格式相同
#uvicorn transfer:app --reload