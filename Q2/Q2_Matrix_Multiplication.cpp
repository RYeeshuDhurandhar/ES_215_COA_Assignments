#include <iostream>
#include <time.h>

using namespace std;

#define N 512

long current_time()
{
    struct timespec time;
    timespec_get(&time, CLOCK_MONOTONIC);
    return time.tv_sec * 1000000000 + time.tv_nsec;
}

void multiply(double matrix1[N][N],
              double matrix2[N][N],
              double result[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            result[i][j] = 0;
            for (k = 0; k < N; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

void random_matrix(double matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = (rand() % 100) * 0.21;
        }
    }
}

int main()
{
    int i, j;
    double result[N][N];
    double matrix1[N][N];
    double matrix2[N][N];
    random_matrix(matrix1);
    random_matrix(matrix2);
    srand(time(0));

    long start_time = current_time();

    multiply(matrix1, matrix2, result);

    long end_time = current_time();

    cout << "Multiplied matrix is \n";
    for (i = 0; i < N; i++)
    {
        cout << "[";
        for (j = 0; j < N; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "]"
             << "\n";
    }

    cout << endl
         << "Total time taken in ns = " << end_time - start_time << endl;

    return 0;
}