/*
    Q : Next permutation

    link : https://practice.geeksforgeeks.org/problems/next-permutation5226/1
*/


class Solution{
public:

    //brute force - find all permutaion/combination and arrange it in ascendending order  O(n^2)


    // optimised code - O(n)
    vector<int> nextPermutation(int N, vector<int> arr){
        int i=N-1,idx=N-1;
        
        // 1 - find the peak/pivot point
        while(i-1 >= 0 and arr[i-1] >= arr[i]){
            i--;
        }
        
        //if arr is in descending order
        if(i == 0){
            sort(arr.begin(),arr.end());
            return arr;
        }
        
        /// 2- check the max element and swap
        while(idx >= i){
            //swap the element 
            if(arr[idx] > arr[i-1]){
                arr[idx] += arr[i-1] ;
                arr[i-1] = arr[idx] - arr[i-1];
                arr[idx] = arr[idx] - arr[i-1];
                break;
            }
            idx--;
        }
        
        // 3 -  sort the array from ith to N-1 elemnt 
        sort(arr.begin()+i,arr.end());
        return arr;
    }
};