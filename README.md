# RSA Factoring Challenge

## Understanding the Challenge

#### The format
The numbers in the challenge is generally in the form `n = p * q`.
`p` and `q` are prime numbers.

#### The Approach

There are several avenues I can use to approach this challenge. These include:
1. Trial division:
2. Pollard's rho algorithm
3. Quadratic Seive
4. General Number Sieve

The sieve methods are more advanced.

### Simpler Implementations

#### Trial Division
- loop through small prime numbers.
- for each prime `p`, check if `n % p = 0`
- If true, then `q = n / p` and yu have a factored `n`

```pseudocode
function trial_division(n):
    for each prime p up to sqrt(n):
        if n % p == 0:
            return (o, n / p) #found factors
    return None #No factors found
```

#### Pollard's Rho Algorithm
- Initialize variables `x`, `y` and `d`.
- Use a polynomial function to generate a sequence
- Calculate the GCD of `|x - y|` and `n`
- If `d` is greater than 1, you have a nontrivial factor.

```pseudocode
functiom pollards_rho(n):
    x = random() #Random start
    y = x
    d = 1
    f(x) = (x^2 + 1) % n #Polynomial function

    while d == 1:
        x = f(x)
        y = (f(y))
        d= gcd(abs(x - y), n)
    if d == n:
        return None #no factors found
    return (d, n / d) #found factors
```

#### Other Considerations
- Implement optimizations like sieving techniques for trial division.
- Use efficient libraries for GC calculations.
