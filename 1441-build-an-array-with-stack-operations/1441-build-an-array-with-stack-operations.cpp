class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        for(int i=1,k=0;k<target.size() && i<=n;i++){
            ans.push_back("Push");
            if(i!=target[k]) ans.push_back("Pop");
            else k++;
        }
        return ans;
    }
};