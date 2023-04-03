class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int res=-1 , maxVal=INT_MIN,n=edges.size();
        vector<long long>ans(n,0ll);
        for(int i=0;i<edges.size();i++){
            ans[edges[i]]+=i;
        }
        
        return max_element(begin(ans), end(ans)) - begin(ans);
    }
};