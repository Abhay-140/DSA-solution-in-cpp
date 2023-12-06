/*
    Q : space optimiser using bit manipulaition

    link : https://www.geeksforgeeks.org/space-optimization-using-bit-manipulations/
*/

class Solution{
    public:
        //brute force (|b-a|)
        vector <int> markMultiples(int a,int b){
            vector<int> ans;
            while(a <= b){
                if(a % 2 == 0 || a % 5 == 0){
                    ans.push_back(a);
                }
              
                a ++;
            }
            return ans;
        }

        //using bit manipulation

        

};