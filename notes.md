# RSA Factorization

## Overview

This program is designed to factor large integers using a method called Pollard's rho algorithm. It reads numbers from a file and tries to find their factors (other than 1 and themselves). 

## Code Breakdown

1. **Header Files**:
   ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include <math.h>
   ```
   - These lines include libraries necessary for input/output (`stdio.h`), memory management (`stdlib.h`) and mathematical operations (`math.h`).

2. **Greatest Common Divisor (GCD)**:
   ```c
   unsigned long gcd(unsigned long a, unsigned long b)
   {
       unsigned long temp;
    
       while (b != 0)
       {
           temp = b;
           b = a % b;
           a = temp;
       }
       return (a);
   }
   ```
   - This function computes the GCD of two numbers using the Euclidean algorithm. The GCD is the largest number that divides both numbers without leaving a remainder.

3. **Pollard's Rho Algorithm**:
   ```c
   unsigned long pollards_rho(unsigned long n)
   {
       unsigned long x = rand() % n + 1;
       unsigned long y = x;
       unsigned long c = rand() % n + 1;
       unsigned long d = 1;
       int i = 0;

       if (n % 2 == 0) return 2;

       while (d == 1 && i < 10000) {
           x = (x * x + c) % n;
           y = (y * y + c) % n;
           y = (y * y + c) % n;
           d = gcd(abs(x - y), n);
           i++;
       }
       
       return ((d == n) ? 0 : d);
   }
   ```
   - This function attempts to find a non-trivial factor of `n` using a random process.
   - It initializes two values (`x` and `y`) to random numbers and uses a constant `c`.
   - If `n` is even, it immediately returns 2 as a factor.
   - It enters a loop to compute new values of `x` and `y` and calculates the GCD of their difference.
   - If it finds a non-trivial factor (not 1 or `n`), it returns that; if not, it returns 0.

4. **Factorization Function**:
   ```c
   void factorize(unsigned long n)
   {
        unsigned long div;

        if (n <= 1) return;

        if (n % 2 == 0)
        {
            printf("%lu = 2 * %lu\n", n, n / 2);
            return;
        }
        
        div = pollards_rho(n);
        
        if (div == 0 || div == n)
        {
            printf("%lu = %lu * 1\n", n, n);
        }
        else
        {
            printf("%lu = %lu * %lu\n", n, div, n / div);
        }
    }
   ```
   - This function handles the factorization of a given number `n`.
   - It first checks if `n` is less than or equal to 1 (no factors to find).
   - If `n` is even, it quickly prints that `2` is a factor.
   - It calls the `pollards_rho` function to find a potential factor.
   - It then prints the result based on what it found.

5. **Main Function**:
   ```c
   int main(int argc, char *argv[])
   {
        unsigned long n;
        if (argc != 2)
        {
            fprintf(stderr, "Usage: %s <file>\n", argv[0]);
            return (1);
        }

        FILE *file = fopen(argv[1], "r");
        
        if (file == NULL)
        {
            perror("Error opening file");
            return (1);
        }

        while (fscanf(file, "%lu", &n) == 1)
        {
            if (n > 1)
            {
                factorize(n);
            }
        }

        fclose(file);
        return (0);
   }
   ```
   - The `main` function is where the program starts executing.
   - It checks if a filename was provided as a command-line argument. If not, it prints usage instructions.
   - It opens the specified file for reading. If the file can't be opened, it prints an error message.
   - It reads numbers from the file one by one and calls the `factorize` function on each valid number (greater than 1).
   - Finally, it closes the file and returns.

## Summary
In essence, this program:
- Reads integers from a file.
- Uses Pollard's rho algorithm to find and print non-trivial factors of those integers.
- Handles both even and odd numbers, providing a simple output format for the results.