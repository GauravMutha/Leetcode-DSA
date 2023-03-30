//Simple DFS with visited array
//Brute force type
//TC-> O(N^2)
class Solution {
public:
    void dfs(int curr,const int start,vector<bool>& visited,vector<vector<int>>& graph,vector<vector<int>>& ans){
        visited[curr]=true;
        for(auto ch:graph[curr]){
            if(!visited[ch]){
                ans[ch].push_back(start);
                dfs(ch,start,visited,graph,ans);
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
            vector<bool>visited(n,false);
            dfs(i,i,visited,graph,ans);
        }
        return ans;
    }
};