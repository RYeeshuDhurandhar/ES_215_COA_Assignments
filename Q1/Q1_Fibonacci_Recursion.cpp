#include <iostream>
using namespace std;

long current_time()
{
    struct timespec time;
    timespec_get(&time, CLOCK_MONOTONIC);
    return time.tv_sec * 1000000000 + time.tv_nsec;
}

unsigned long long fibonacci(int n, int a = 0, int b = 1)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibonacci(n - 1, b, a + b);
}

int main()
{
    int x;
    cin >> x;

    long start_time = current_time();
    for (int i = 0; i < x; i++)
    {
        cout << fibonacci(i) << " ";
    }

    long end_time = current_time();
    cout << endl
         << "Time required(in ns) = " << end_time - start_time << endl;

    return 0;
}