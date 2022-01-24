#include <iostream>
using namespace std;
unsigned long long array[1000];

long current_time()
{
    struct timespec time;
    timespec_get(&time, CLOCK_MONOTONIC);
    return time.tv_sec * 1000000000 + time.tv_nsec;
}

int main()
{
    int n;
    array[0] = 0;
    array[1] = 1;

    cin >> n;
    long start_time = current_time();

    for (int i = 0; i < n; i++)
    {

        if (i == 0)
        {
            cout << array[0] << " ";
            continue;
        }
        if (i == 1)
        {
            cout << array[1] << " ";
            continue;
        }
        array[i] = array[i - 1] + array[i - 2];

        cout << array[i] << " ";
    }

    long end_time = current_time();
    cout << endl
         << "Time taken(in ns)= " << end_time - start_time << endl;
    return 0;
}