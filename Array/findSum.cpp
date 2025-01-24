/*
   Q:Maximum and Minimum Element in an Array

   link : https://practice.geeksforgeeks.org/problems/max-min/1

*/

// brute code
int findSum(int A[], int N)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    for (int j = 0; j < N; j++)
    {
        if (A[j] > max)
            max = A[j];
    }

    return min + max;
}

// optimised code
int findSum(int A[], int N)
{
    // code here.
    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        if (A[i] >= max)
            max = A[i];
        if (A[i] <= min)
            min = A[i];
    }

    return max + min;
}
