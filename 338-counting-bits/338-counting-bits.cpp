class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int count=0;
            for(int k=0;(i==0)?k<1:k<(int)log2(i)+1;k++){
                int helper=1;
                helper<<=k;
                if((helper&i)!=0)count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};