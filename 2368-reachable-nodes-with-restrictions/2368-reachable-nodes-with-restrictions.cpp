//DFS without set
//marking restricted node as visited
//O(e+n) ,where e is the number of edges
class Solution {
public:
    int ans=0;
    void dfs(int curr , vector<vector<int>>& graph,vector<bool>& visited){
        visited[curr]=true;
        ans++;
        for(auto &adjNode: graph[curr]){
            if(!visited[adjNode])
                dfs(adjNode,graph,visited);
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        vector<bool>visited(n,false);
        
        for(auto &node: restricted) visited[node]=true;
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        dfs(0,graph,visited);
        
        return ans;
    }
};