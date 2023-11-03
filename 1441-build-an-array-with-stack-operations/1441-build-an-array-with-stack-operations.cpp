class Solution {
public:
    void addremove(int x, vector<string>& ans){
        while(x--){
            ans.push_back("Push");
            ans.push_back("Pop");
        }
    }
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        for(int k=0;k<target.size();k++){
            if(k==0) addremove(target[k]-0-1,ans);
            else addremove(target[k]-target[k-1]-1,ans);
            ans.push_back("Push");
        }
        return ans;
    }
};