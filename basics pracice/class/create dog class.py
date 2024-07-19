class X:
    def __init__(x,y,z):
        x.sf=y
        x.sa=z
#you must print x.()
    def sit(x):
        print(f"{x.sf} go to become literary") # type: ignore
    def play(x):
        print(f"is this what you want {x.sa}")

pt=X('wihsper','whistling')
#now x=pt  y='wihsper'  z='whistling'


print(f"my dog likes to fabric {pt.sf}")
#my dog likes to fabric wihsper

X.sit(pt)
#wihsper go to become literary

X.play(pt)
#is this what you want whistling

pt.sa

















    