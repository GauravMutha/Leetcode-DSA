//DFS
class Solution {
public:
    int dfs(int curr,vector<vector<int>>& graph,vector<int>& quiet,vector<int>& ans){
        if(ans[curr]!=-1) return ans[curr];
        int bestNode=curr;
        for(auto &adjNode: graph[curr]){
            int retNode=dfs(adjNode,graph,quiet,ans);
            if(quiet[retNode]<quiet[bestNode])
                bestNode=retNode;
        }
        ans[curr]=bestNode;
        return bestNode;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>graph(n);
        vector<int>ans(n,-1);
        vector<bool>visited(n);
        
        for(int i=0;i<richer.size();i++){
            int u=richer[i][0] ,v=richer[i][1];
            graph[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            dfs(i,graph,quiet,ans);
        }
        return ans;
    }
};