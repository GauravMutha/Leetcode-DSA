//using set
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden)     {
        unordered_set<string>hash(forbidden.begin(),forbidden.end());
        int ans=0;
        
        int rmax=word.size()-1;
        
        for(int left=word.size()-1;left>=0;left--){
            for(int right=left;right<=min(rmax,left+9);right++){
                string currSub=word.substr(left,right-left+1);
                if(hash.count(currSub)==0) continue;
                rmax=right-1;
                break;
            }
            ans=max(ans,rmax-left+1);
        }
        
        return ans;
    }
};