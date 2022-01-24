import random
import timeit

global n
n = 512

def print_random_matrix(n, matrix):
    for i in range(n):
        for j in range(n):     
            print (matrix[i][j], end = " ")       

        print()


def multiply(n, matrix1, matrix2):
 
    result = [[0 for x in range(n)]
              for y in range (n)]
     
    for i in range(n):
        for j in range(n):
            result[i][j] = 0
            for x in range(n):           
                result[i][j] += (matrix1[i][x] * matrix2[x][j])
            
    for i in range(n):
        for j in range(n):     
            print (result[i][j], end = " ")       
        print()


if __name__ == "__main__":

    # there is no double in python, hence using float 
    matrix1 = [[float(random.randint(0,15) + random.random()) for x in range(n)]
              for y in range (n)]

    matrix2 = [[float(random.randint(0,15) + random.random()) for x in range(n)]
              for y in range (n)]

    print_random_matrix(n, matrix1)
    print()
    print_random_matrix(n, matrix2)
    print()
    t = timeit.timeit(lambda: multiply(n, matrix1, matrix2), number = 1)

    print("Time in sec = ",t)
