class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        int l=0,r=1;
        string templ=words[0],tempr;
        sort(begin(templ),end(templ));
        while(r<words.size()){
            tempr=words[r];
            sort(begin(tempr),end(tempr));
            
            if(templ!=tempr){
                ans.push_back(words[l]);
                l=r;
                templ=tempr;
            }
            r++;
        }
        ans.push_back(words[l]);
        return ans;
    }
};