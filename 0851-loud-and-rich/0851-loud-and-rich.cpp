//DFS (it corrects the first submission that gave wrong answer)
//O(N^2)
class Solution {
public:
    int dfs(int curr,vector<vector<int>>& graph,vector<int>& quiet,vector<bool>& visited,vector<int>& ans){
        int bestNode=curr;
        if (visited[curr]) return ans[curr];
        visited[curr]=true;
        for(auto &adjNode: graph[curr]){
            int retNode=dfs(adjNode,graph,quiet,visited,ans);
            if(quiet[retNode]<quiet[bestNode])
                bestNode=retNode;
        }
        ans[curr]=bestNode;
        return bestNode;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>graph(n);
        vector<int>ans(n);
        vector<bool>visited(n);
        
        for(int i=0;i<richer.size();i++){
            int u=richer[i][0] ,v=richer[i][1];
            graph[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i])
                dfs(i,graph,quiet,visited,ans);
        }
        return ans;
    }
};