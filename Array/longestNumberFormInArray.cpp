/*
    Q : Largest Number formed from an Array
 

    link :https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1?
*/

class Solution{
public:
	// brute force (n^2)
	string printLargest(vector<string> &arr) {
	    
	    vector<int> index(arr.size(),1);
	    
	    for(int i=0 ; i<arr.size() ; i++){
	        for(int j=0 ; j<arr.size() ; j++){
	            if(i != j){
	                int a=stoi(arr[i]+arr[j]);
	                int b=stoi(arr[j]+arr[i]);
	                if(a>b){
	                    index[j]++;
	                }else if(b>a){
	                    index[i]++;
	                }
	                
	            }
	        }
	    }
	    string ans =""; 
	    
	    while(!arr.empty()){
	        
	      int idx=min_element(index.begin(),index.end())-index.begin();//index of min element
	      ans += arr[idx];//adding highest element
	      index.erase(min_element(index.begin(),index.end()));//remove the element
	      arr.erase(arr.begin()+idx);//removing the arr element also
	        
	    }
	    
	    
	    return ans;
	}


    // optimised code


    //create a fuction for comparing
    static bool comp(string a, string b){
	    return (a+b) > (b+a);
    }



	// The main function that returns the arrangement with the largest value as
	string printLargest(vector<string> &arr) {
	    
	    sort(arr.begin(), arr.end(), comp); // sort all element by comparator function
	    
	    string ans="";
	    for(string a : arr){
	        ans += a;
	    }
	    
	    return ans;
	}

};