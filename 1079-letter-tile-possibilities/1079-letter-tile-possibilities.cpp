class Solution {
private:
    int count=0;
// vector<vector<int>>ans;
public:
    void helper(unordered_map<char,int>& freq,string& tiles){
        count++;
        set<char>taken;
        for(auto ch : tiles){
            if(taken.count(ch)) continue;
            if(freq[ch]==0) continue;
            taken.insert(ch);
            freq[ch]--;
            helper(freq,tiles);
            freq[ch]++;
        }
    }
    int numTilePossibilities(string tiles) {
        string ds="";
        unordered_map<char,int>m;
        for(int i=0;i<tiles.size();i++){
            m[tiles[i]]++;
        }
        
        helper(m,tiles);
        
        return count-1;
    }
};