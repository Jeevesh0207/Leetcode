//https://www.codingninjas.com/studio/problems/maximum-subarray-sum_630526

#include <bits/stdc++.h> 

long long Find(int a[], int size)
{
    long long max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
 

long long maxSubarraySum(int arr[], int n)
{
    long long d=Find(arr,n);
    return (d>=0)?d:0;
}
