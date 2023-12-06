/*
    Q: find kth MInmum Number

    link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function

    // brute force - linear search



    // optimised code
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int> pq;
        
        for(int i=l ; i<=r ; i++){
            pq.push(arr[i]);
            if(pq.size() > k)
                pq.pop();
        }
            
            
        return pq.top();
    
    }


    

    // using Priority queue
    int kthSmallest2(int arr[], int l, int r, int k) {
        
        priority_queue<int> pq;
        
        for(int i=l ; i<=r ; i++)
            pq.push(-arr[i]);
            
        while(k-1){
             pq.pop();
            k--;
        }
            
        return -pq.top();
    
    }

    //optimised code -(best)
    int kthSmallest(int arr[], int l, int r, int k)
    {

        sort(arr, arr + r + 1);

        return arr[k - 1];
    }



};