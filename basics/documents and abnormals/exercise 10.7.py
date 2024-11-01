while True:
    a=input('please enter the first number:')
    b=input('please enter the second number:')
    if (a=='q'):
        break
    elif b=='q':
        break
    else:
        try:
            a=float(a)
            b=float(b)
            print('your answer is:',a+b)
        except ValueError:
            print("You've print the wrong data.")
    