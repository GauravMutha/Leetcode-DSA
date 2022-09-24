class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        
        for(auto str : patterns)
            if(word.find(str) != string::npos) count++;
    
        return count;
    }
};