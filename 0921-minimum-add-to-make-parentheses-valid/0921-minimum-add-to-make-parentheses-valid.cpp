class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,closed=0;
        for(auto c:s){
            if(c=='(') open++;
            else if(open>0) open--;
            else  closed++;
        }
        return open + closed;
    }
};

//Optimization -> O(1)