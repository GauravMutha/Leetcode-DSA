//Simple DFS WITHOUT visited array
//Brute force type
//TC-> O(N^2)
class Solution {
public:
    void dfs(int curr,const int start,vector<vector<int>>& graph,vector<vector<int>>& ans){
        for(auto ch:graph[curr]){
            if(ans[ch].size()==0 || ans[ch].back()!=start){
                ans[ch].push_back(start);
                dfs(ch,start,graph,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n),ans(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1];
            graph[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            dfs(i,i,graph,ans);
        }
        return ans;
    }
};