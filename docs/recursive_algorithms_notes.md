# Recursive Algorithms Laboratory Notes

Students should implement each required function recursively, without using loops in the recursive versions.

## Required Algorithms

1. `factorial(n)`
2. `fibonacci(n)`
3. `binarySearch(array, target)`
4. `arraySum(array)`
5. `reverseArray(array)`

## Expected Design

- Identify and comment on the base case for each implementation.
- Identify and comment on the recursive case for each implementation.
- Use clear parameter names and return values.
- Include validation for invalid or unsupported inputs.
- For comparison, also implement iterative versions.

## Comparison Requirement

For each algorithm, the recursive and iterative implementations have the following characteristics:

- **Factorial:** Both forms are $O(n)$ time. The recursive form uses $O(n)$ call-stack space, while the iterative form uses $O(1)$ additional space. Recursion is easy to read but repeated calls can exhaust the stack for large inputs.
- **Fibonacci:** The direct recursive form is $O(2^n)$ time and $O(n)$ call-stack space because it repeats many subproblems. The iterative form is $O(n)$ time and $O(1)$ additional space, making it faster and safer for large inputs.
- **Binary search:** Both forms are $O(\log n)$ time for sorted arrays. Recursive binary search uses $O(\log n)$ call-stack space, while iterative binary search uses $O(1)$ additional space. The iterative form is less prone to stack overflow and generally easier to maintain for many searches.
- **Array sum:** Both forms are $O(n)$ time. The recursive form uses $O(n)$ call-stack space and the iterative form uses $O(1)$ additional space. Iteration is the clearer and more robust choice for this linear calculation.
- **Array reversal:** Both forms are $O(n)$ time. The recursive form performs $O(n/2)$ swaps and uses $O(n)$ call-stack space; the iterative form performs the same number of swaps and uses $O(1)$ additional space.

Recursion directly expresses divide-and-conquer and base-case structure, but deep recursion increases stack usage and can cause stack overflow. Iterative implementations are usually more efficient in auxiliary space, easier to reason about in this laboratory, and safer for large input sizes.
