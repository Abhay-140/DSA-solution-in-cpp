/*
    Q: Search Pattern (R)

    link: https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
*/

class Solution
{
    public:

        // optimised code O(N)
        vector <int> search(string pattern, string text)
        {
            int p_hash = 0;
            int t_hash = 0;
            int q = 101;
            int d = 256;
            int h = 1;
            
            vector<int> ans;
            
            for(int i=0 ; i<pattern.size()-1 ; i++){
                h = (h * d) % q;
            }
            
            for(int i=0 ; i < pattern.length() ; i++){
                p_hash = (d * p_hash + pattern[i]) % q; 
                t_hash = (d * t_hash + text[i]) % q;    
            }
            
            for(int i=0 ; i <= text.length() - pattern.length() ; i++){
                
                if(p_hash == t_hash){
                    if(pattern == text.substr(i,pattern.length())){
                        ans.push_back(i+1);
                    }
                }
                
                t_hash = (d * (t_hash - text[i] * h) + text[i + pattern.length()]) % q; 
                
                if(0 > t_hash){
                    t_hash += q;
                }
                    
            }
            
            return ans;
        }

        // Optimized and Sort 
        vector <int> search(string pattern, string text)
        {
            int n= text.size();
            int k= pattern.size();
            vector<int> res;

            for(int i=0; i<n; i++){
                if(pattern== text.substr(i,k)){
                    res.push_back(i+1);
                }
            }
          
            return res;
        }
     
};