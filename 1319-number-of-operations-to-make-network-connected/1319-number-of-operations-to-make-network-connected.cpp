//Almost similar to 647.Redundant connection
//We should find number of components

// #2 DFS with making adjecency lists
//O(n+e) e is edges or connections size ,and n is number of computers
class Solution {
private:
    int components=0;
    void dfs(int node,vector<vector<int>>& graph ,vector<bool>& visited){
        visited[node]=true;
        
        for(auto &adjNode: graph[node]){
            if(visited[adjNode]==false)
                dfs(adjNode,graph,visited);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) { 
        //there cannot be a connected graph,where edges are less than n-1
        if(connections.size()<(n-1)) return -1;
        
        vector<bool>visited(n,false);
        vector<vector<int>>graph(n);
        //making adjacency list
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(i,graph,visited);
                components++;
            }
        }
        return components-1;
    }
};