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

    long start_time = current_time();

    for (int i = 0; i < 100; i++)
    {
        cout << "Hello World" << endl;
    }

    long end_time = current_time();

    cout << end_time - start_time << endl;
}