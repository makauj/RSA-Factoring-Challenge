import sys
import random
import math

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def pollards_rho(n):
    if n % 2 == 0:
        return 2
    x = random.randint(1, n-1)
    y = x
    c = random.randint(1, n-1)
    d = 1
    while d == 1:
        x = (x * x + c) % n
        y = (y * y + c) % n
        y = (y * y + c) % n
        d = gcd(abs(x - y), n)
        if d == n:
            return None  # Failure to find a factor
    return d

def factorize(num):
    """ Generate two factors for a given number using Pollard's Rho """
    if num <= 1:
        return None
    if num % 2 == 0:
        return (2, num // 2)

    factor1 = pollards_rho(num)
    if factor1 is None or factor1 == num:
        return (num, 1)
    factor2 = num // factor1
    return (factor1, factor2)

if len(sys.argv) != 2:
    sys.exit(f"Wrong usage: {sys.argv[0]} <file_path>")

filename = sys.argv[1]

with open(filename, 'r') as file:
    lines = file.readlines()

for line in lines:
    num = int(line.rstrip())
    factor1, factor2 = factorize(num)
    print(f"{num} = {factor1} * {factor2}")
