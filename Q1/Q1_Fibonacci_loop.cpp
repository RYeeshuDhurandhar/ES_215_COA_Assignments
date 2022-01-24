
#include <iostream>
using namespace std;

long current_time()
{
    struct timespec time;
    timespec_get(&time, CLOCK_MONOTONIC);
    return time.tv_sec * 1000000000 + time.tv_nsec;
}

int main()
{
    int n;
    unsigned long long a1 = 0, a2 = 1, next_term = 0;

    cin >> n;

    long start_time = current_time();

    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            cout << a1 << " ";
            continue;
        }
        if (i == 2)
        {
            cout << a2 << " ";
            continue;
        }
        next_term = a1 + a2;
        a1 = a2;
        a2 = next_term;

        cout << next_term << " ";
    }

    long end_time = current_time();
    cout << endl
         << "Total time taken(in ns) = " << end_time - start_time << endl;
    return 0;
}