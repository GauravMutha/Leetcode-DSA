//Multiple  dfs with graph making
//Less optimal than other two solutions (single dfs, UF)
//O(N^2) 
class Solution {
public:
    bool dfs(int curr,int parent,vector<int>& visited,vector<vector<int>>& graph){
        if(visited[curr]==true) {
            return true;
        }
        visited[curr]=true;
        for(auto &adjNode : graph[curr]){
            if(adjNode==parent) continue;
            if(dfs(adjNode,curr,visited,graph)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>visited(n+1,false);
        vector<vector<int>>graph(n+1);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
            
            fill(visited.begin(),visited.end(),false);
            if(dfs(u,-1,visited,graph)) return edges[i];
        }
        
        return {};
    }
};