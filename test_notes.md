### Test Suite Structure

1. **Test Input File Creation**: Create test input files for different scenarios.
2. **Expected Output**: Define the expected output for each test case.
3. **Automated Test Function**: Write a function that runs the program with the test files and compares the output to the expected results.

### Test Cases

Here’s a set of test cases to cover a range of scenarios:

1. **Basic Cases**:
   - Input: `6` (Expected: `6=2*3`)
   - Input: `15` (Expected: `15=3*5`)
   - Input: `28` (Expected: `28=4*7`)

2. **Prime Numbers** (should return `n=1*n`):
   - Input: `11` (Expected: `11=1*11`)
   - Input: `13` (Expected: `13=1*13`)

3. **Large Composites**:
   - Input: `100` (Expected: `100=10*10`)
   - Input: `144` (Expected: `144=12*12`)

4. **Perfect Squares**:
   - Input: `49` (Expected: `49=7*7`)
   - Input: `64` (Expected: `64=8*8`)

5. **Even and Odd Composites**:
   - Input: `18` (Expected: `18=2*9`)
   - Input: `21` (Expected: `21=3*7`)

6. **Numbers with Multiple Factorizations**:
   - Input: `30` (Expected: `30=5*6`)
   - Input: `42` (Expected: `42=6*7`)

### Example Test Suite Implementation in Python

Here’s how you might implement the test suite:

```python
import subprocess
import os

def create_test_file(filename, numbers):
    with open(filename, 'w') as f:
        for number in numbers:
            f.write(f"{number}\n")

def run_test(filename, expected_output):
    # Run the factors program
    result = subprocess.run(['python', 'factors.py', filename], capture_output=True, text=True)
    output = result.stdout.strip()

    # Compare output with expected output
    if output == expected_output:
        print(f"Test passed for {filename}")
    else:
        print(f"Test failed for {filename}\nExpected:\n{expected_output}\nGot:\n{output}")

def main():
    # Define test cases
    tests = [
        {
            "filename": "test_basic.txt",
            "numbers": [6, 15, 28],
            "expected": "6=2*3\n15=3*5\n28=4*7"
        },
        {
            "filename": "test_prime.txt",
            "numbers": [11, 13],
            "expected": "11=1*11\n13=1*13"
        },
        {
            "filename": "test_large_composite.txt",
            "numbers": [100, 144],
            "expected": "100=10*10\n144=12*12"
        },
        {
            "filename": "test_perfect_squares.txt",
            "numbers": [49, 64],
            "expected": "49=7*7\n64=8*8"
        },
        {
            "filename": "test_even_odd.txt",
            "numbers": [18, 21],
            "expected": "18=2*9\n21=3*7"
        },
        {
            "filename": "test_multiple.txt",
            "numbers": [30, 42],
            "expected": "30=5*6\n42=6*7"
        },
    ]

    # Run each test case
    for test in tests:
        create_test_file(test["filename"], test["numbers"])
        run_test(test["filename"], test["expected"])

        # Clean up the test file
        os.remove(test["filename"])

if __name__ == "__main__":
    main()
```

### Explanation of the Test Suite

1. **Creating Test Files**: The `create_test_file` function creates a test input file containing the specified numbers.

2. **Running Tests**: The `run_test` function executes the `factors.py` program with the generated file and captures the output. It then compares the output to the expected result.

3. **Test Cases**: Each test case specifies a filename, a list of numbers to include in the file, and the expected output format.

4. **Cleanup**: After each test, the temporary test file is deleted to keep the environment clean.

### How to Use the Test Suite

1. Save the test suite code in a file (e.g., `test_factors.py`).
2. Ensure the `factors.py` program is in the same directory.
3. Run the test suite:
   ```bash
   python test_factors.py
   ```
