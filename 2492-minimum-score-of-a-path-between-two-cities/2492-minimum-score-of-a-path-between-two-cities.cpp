//Simple DFS
class Solution {
private:
    int res=INT_MAX;
public:
    void dfs(int curr,vector<vector<pair<int,int>>>& graph,vector<bool>& visited){
        visited[curr]=true;
        for(auto &[adjNode,dist] : graph[curr]){
            /*we might not want to visit a visited
            node but we must consider the untravelled 
            edges as they may have minimum path
            hence we update ans here too*/
            res=min(res,dist); 
            if(!visited[adjNode]){
                res=min(res,dist);
                dfs(adjNode,graph,visited);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>graph(n+1);
        vector<bool>visited(n+1,false);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0] ,v=roads[i][1], dist=roads[i][2];
            
            graph[u].push_back({v,dist});
            graph[v].push_back({u,dist});
        }
        
        dfs(1,graph,visited);
        
        return res;
    }
};