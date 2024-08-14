'''
def f(size,font):
    print('your T-shirt has size in',size,f"and font in {font}.\n")
w=input('input size')
y=input('input font')
f(w,y)


所在位置 行:1 字符: 2
+ a& C:/Users/Sunny/AppData/Local/Programs/Python/Python312/python.exe  ...
+  ~
不允许使用与号(&)。& 运算符是为将来使用而保留的；请用双引号将与号引起来("&")，以将其作为字符串的一部分传递。
    + CategoryInfo          : ParserError: (:) [], ParentContainsErrorRecordException
    + FullyQualifiedErrorId : AmpersandNotAllowed

    '''

def f(x,y=886):
    print('your T-shirt has size in',x,f"and font in {y}.\n")

f(y=6,x='24runc487cvbq')


