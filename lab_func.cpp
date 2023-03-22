#include <iostream>
#include <chrono>

#include "func.h"

using namespace std;

bool search_line (int* beg_ptr, int n, int elem)
{
    for (int i = 0; i < n; i++)
    {
        if (elem == *(beg_ptr + i))
        {
            return true;
        }
    }

    return false;
}

bool search_bin (int* beg_ptr, int n, int elem)
{
    if (n == 1)
    {
        return elem == *beg_ptr;
    }

    int mid = *(beg_ptr + n/2);

    if (elem > mid) return search_bin (beg_ptr + n/2, n/2 + 1, elem);

    if (elem < mid) return search_bin (beg_ptr, n/2, elem);

    if (elem == mid) return true;
}

bool search_line_sum (int* arr, int n, int sum)
{
    int l_ptr = 0, r_ptr = n-1;
    
    while (l_ptr != r_ptr)
    {
        int cur_sum = arr[l_ptr] + arr[r_ptr];
        
        if (cur_sum > sum) r_ptr--;
        
        else if (cur_sum < sum) l_ptr++;
        
        else return true;
    }
    
    return false;
}