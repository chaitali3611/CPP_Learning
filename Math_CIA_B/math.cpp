#include <iostream>
using namespace std;

// Formula Method
long long formulaSum(int n)
{
    return (long long)n * (n + 1) / 2;
}

// Iterative Method
long long iterativeSum(int n)
{
    long long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    return sum;
}

// Recursive Method
long long recursiveSum(int n)
{
    // Base case
    if (n == 0)
    {
        return 0;
    }

    // Recursive case
    return n + recursiveSum(n - 1);
}

int main()
{
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    // Calculate using all three methods
    long long formula = formulaSum(n);
    long long iterative = iterativeSum(n);
    long long recursive = recursiveSum(n);

    // Display results
    cout << "\n--- Results ---" << endl;

    cout << "Formula Method    : " << formula << endl;
    cout << "Iterative Method  : " << iterative << endl;
    cout << "Recursive Method  : " << recursive << endl;

    // Verify results
    if (formula == iterative && iterative == recursive)
    {
        cout << "\nAll three methods produce the same result." << endl;
        cout << "Result verified successfully!" << endl;
    }
    else
    {
        cout << "\nResults do not match." << endl;
    }

    return 0;
}