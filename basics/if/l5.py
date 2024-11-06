x = 54321
epsilon = 0.01
num_guesses = 0
guess = 12
increment = 0.00001
high = x
low = 0
while abs(guess**2 - x) >= epsilon: 
    if guess**2-x > 0:
        high = guess
    else:
        low = guess
    guess = (high + low) / 2
    num_guesses += 1

print('num_guesses =', num_guesses) 
if abs(guess**2 - x) >= epsilon:
    print('Failed on square root of', x)
else:
    print(guess, 'is close to square root of', x)