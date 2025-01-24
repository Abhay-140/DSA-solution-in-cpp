/*
    Q : Repeat and missing number in array

    link : https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

// brute force
vector<int> findTwoElement(vector<int> arr, int n)
{
    // code here
    sort(arr.begin(), arr.end());

    int a, b = 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            a = arr[i];
        if (arr[i] + 2 == arr[i + 1])
        {
            b = arr[i + 1] - 1;
        }
    }
    if (arr[n - 1] != n)
        b = n;
    return {a, b};
}
