class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int d=0;
        for(int i=0;i<s.size();i++){
            d=distance[s[i]-'a'];
            
            if( (i+d+1 > s.size()) || (s[i+d+1] != s[i]) )
                return false;
            
            distance[s[i]-'a']=-1;
        }
        
        return true;
    }
};

//Reduces Space complexity from O(N) to O(!)
