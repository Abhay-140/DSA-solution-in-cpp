/*
    Q: valid palindrome

    link : https://leetcode.com/problems/valid-parentheses/description/
*/



class Solution {
public:

    // brute force - using counters (doesn't apply for all strings) o(n)

    // using stack o(n)
    bool isValid(string s) {
        stack<char> par; //using stack for check parenthesis

        for(int i=0 ; i<s.length()  ; i++){
            if(par.empty()){
                par.push(s[i]); // that is for prevent error from empty stack (for par.top())
            }
            else if(s[i] == ')'){
                if(par.top() !='('){
                    return false;
                }else{
                    par.pop();
                }
            }else if(s[i] == ']'){
                if(par.top() !='['){
                    return false;
                }else{
                    par.pop();
                }
            }else if(s[i] == '}'){
                if(par.top() !='{'){
                    return false;
                }else{
                    par.pop();
                }
            }else{
                par.push(s[i]);// pushing opening parenthesis
            }

        } 

        return par.empty();// if parenthesis remains then is is invalid
    }
};