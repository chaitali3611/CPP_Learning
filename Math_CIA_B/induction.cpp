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
    if (n == 0)
        return 0;

    return n + recursiveSum(n - 1);
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    long long formula = formulaSum(n);
    long long iterative = iterativeSum(n);
    long long recursive = recursiveSum(n);

    cout << "\nSum using Formula Method: " << formula << endl;
    cout << "Sum using Iterative Method: " << iterative << endl;
    cout << "Sum using Recursive Method: " << recursive << endl;

    // Verification
    if (formula == iterative && iterative == recursive)
    {
        cout << "\nAll methods produce the same result." << endl;
        cout << "Result verified successfully!" << endl;
    }
    else
    {
        cout << "\nResults do not match." << endl;
    }

    return 0;
}