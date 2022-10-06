//Brute force
class Solution {
public:
    bool rotate(string s , string goal , int j){
        for(int i=0;i<goal.size();i++,j++)
            if(goal[i]!=s[j%s.size()]) return false;
        return true;
        
    }
    bool rotateString(string s, string goal) {
        int sze =s.size(),gze=goal.size();
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<s.size();i++)
            if(rotate(s,goal,i)) return true;
        
        return false;
    } 
};