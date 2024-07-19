'''
import math

pi = math.pi
print(pi,10000)


def calculate_pi(n):
    sum = 0
    for k in range(n):
        sum += 4 * ((-1) ** k) / (2 * k + 1)
    return sum

print(calculate_pi(10000))

import random

def calculate_pi(n):
    num_points_circle = 0
    num_points_total = 0
    for _ in range(n):
        x = random.uniform(0, 1)
        y = random.uniform(0, 1)
        distance = x ** 2 + y ** 2
        if distance <= 1:
            num_points_circle += 1
        num_points_total += 1
    return 4 * num_points_circle / num_points_total

import random

def generate_random_point():
    x = random.uniform(-1, 1)
    y = random.uniform(-1, 1)
    return x, y

def estimate_pi(num_points):
    points_inside_circle = 0
    total_points = 0

    for _ in range(num_points):
        x, y = generate_random_point()
        distance = x**2 + y**2

        if distance <= 1:
            points_inside_circle += 1
        total_points += 1

    circle_area = points_inside_circle / total_points
    pi_estimation = circle_area * 4
    return pi_estimation

num_points = 1000000
pi = estimate_pi(num_points)

print(f"圆周率的近似值为: {pi:.10000f}")
'''

from decimal import getcontext, Decimal
 
# 设置精度为10000位
getcontext().prec = 10000
 
# 使用自定义函数计算圆周率
def bpi(n):
    a, b, t, s, num, den = 1, 0, 1, 1, n, n
    while s != t:
        s = a / b
        a, b = a * (num + den), b * (den + num)
        num, den = num + 1, den + 1
        t = a / b
    return s
 
# 打印出圆周率的10000位
print(bpi(10000))