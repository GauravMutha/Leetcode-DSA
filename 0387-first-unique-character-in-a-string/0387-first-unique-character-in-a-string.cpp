class Solution {
public:
    int firstUniqChar(string s) {
        int ans=INT_MAX;
        vector<pair<int,int>>vec(26,pair<int,int>({0,-1}));
        for(int i=0;i<s.size();i++){
            vec[s[i]-'a'].first++;
            vec[s[i]-'a'].second=i;
        }
        
        for(auto p : vec){
            if(p.first==1)
                ans=min(ans,p.second);
        }
        
        return (ans==INT_MAX)?-1:ans;
    }
};

//SC-->O(1)
//TC-->O(N)