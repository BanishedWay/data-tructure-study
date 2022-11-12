#include "Function.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int A[11] = {1, 4, 2, 6, 3, 8, 12, 0, 5, 7, 11};
    MergeSort(A, 10);
    print(A, 10);
    return 0;
}
