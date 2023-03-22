#include <iostream>
#include <chrono>

#include "func.h"

using namespace std;

int main()
{
    int MAX = 100000;
    int shag = 1000;
    FILE* f = fopen("Xerb.txt", "w+");

for (int N=100; N<MAX; N=N+shag)
{
    int* arr = new int[N];
    for(int i=0; i<N; i++)
    {
        arr[i]=i;
    }
    auto start = chrono::steady_clock::now( );
    for (int i = 0; i < 1000; i++)
    {
        search_line_sum(arr, N, -1);
    }
    
    auto stop = chrono::steady_clock::now( );
    auto time_span = chrono::duration_cast < chrono::nanoseconds> (stop - start);
    long long time = time_span.count();
    fprintf (f, "%d\n", time);
    }

}
