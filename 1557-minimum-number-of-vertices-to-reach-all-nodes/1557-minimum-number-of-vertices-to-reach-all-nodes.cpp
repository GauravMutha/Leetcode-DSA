class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>vec(n,-1),ans;
        for(int i=0;i<edges.size();i++){
            if(vec[edges[i][0]]!=0) vec[edges[i][0]]=1;
            vec[edges[i][1]]=0;
        }
        for(int i=0;i<n;i++){
            if(vec[i]==1) 
                ans.push_back(i);
        }
        return ans;
    }
};