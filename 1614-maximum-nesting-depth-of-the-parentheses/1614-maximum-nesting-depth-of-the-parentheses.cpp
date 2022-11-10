class Solution {
public:
    int maxDepth(string s) {
        int res=0 , lb=0 , rb=0;
        for(auto c :s){
            if(c=='(') lb++;
            else if(c==')') rb++;
            res=max(lb-rb,res);
        }
        return res;
    }
};

//Without using stack