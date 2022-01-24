#include <bits/stdc++.h>
using namespace std;
unsigned long long Array[1000];

long current_time()
{
    struct timespec time;
    timespec_get(&time, CLOCK_MONOTONIC);
    return time.tv_sec * 1000000000 + time.tv_nsec;
}

unsigned long long fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (Array[n] != 0)
    {
        return Array[n];
    }
    else
    {
        Array[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return Array[n];
    }
}

int main()
{
    int n;
    cin >> n;

    long start_time = current_time();

    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }

    long end_time = current_time();

    cout << endl
         << "Time taken(in ns) " << end_time - start_time << endl;
    return 0;
}