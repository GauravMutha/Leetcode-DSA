class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth=0,res=0;
        char prev;
        
        for(auto c:s){
            if(c=='(') depth++;
            else{
                if(prev=='(')  res+=pow(2,depth-1); 
                depth--;
            }
            prev=c;
        }
        return res;
    }
};

//WITHOUT STACK
//SC-->O(1)
//TC-->O(n)