//Re//
//Using simple hash array instead of map and it avoids set
class Solution {
private:
    int count=0;
public:
    void helper(vector<int>& freq,string& tiles){
        count++;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            freq[i]--;
            helper(freq,tiles);
            freq[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        string ds="";
        vector<int>freq(26,0);
        for(int i=0;i<tiles.size();i++){
            freq[tiles[i]-'A']++;
        }
        
        helper(freq,tiles);
        
        return count-1;
    }
};