class Solution {
public:
    bool canBeValid(string s, string locked) {
        int bal=0;
        if(s.size()%2) return false;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0' || s[i]=='(') bal++;
            else bal--;
            if(bal<0) return false;
        }
        bal=0;
        for(int i=s.size()-1;i>=0;i--){
            if(locked[i]=='0' || s[i]==')') bal++;
            else bal--;
            if(bal<0) return false;
        }
        return true;    
    }
};