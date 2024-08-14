import pprint


def f(x,z,**y):
    y['first_name']=x
    y['last name']=z
    return y
passenger=f('s', 'special week', p=239, profile=666, lancer= 'hinata')
  #SyntaxError: invalid syntax':'  
pprint.pprint(passenger)
print(passenger)
