class po:
    def __init__ (x,y,z):
        x.pr=y
        x.cmd=z
    def f1(x):
        x.pr += 'whioehfowifh'
        print(x.pr)
    def f2(x):
        x.cmd=`int(x.cmd)
        print(x.cmd+114514)

mabey=po('83274782346','0')
fire=po('extinguisher',37826478745)
print(mabey.pr,mabey.cmd)
print(fire.cmd)
po.f1(mabey)
po.f2(mabey)

po.f1(fire)
po.f2(fire)