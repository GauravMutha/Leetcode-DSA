//DFS optimised
//Approach similar to previous BFS solution
typedef vector<vector<int>> vvi;
class Solution {
    int ans=0;
public:
    void dfs(int node, vvi & dirGraph, vvi & reverse, vector<bool>& visited){
        visited[node]=true;
        
        for(auto &adjNode : dirGraph[node]){
            if(!visited[adjNode]){
                ans++;
                dfs(adjNode,dirGraph,reverse,visited);
            }
        }
        for(auto adjNode : reverse[node]){
            if(!visited[adjNode]){
                dfs(adjNode,dirGraph,reverse,visited);
            }
        }
    }
    int minReorder(int n,vvi& connections) {
        vvi dirGraph(n) , reverse(n);
        vector<bool>visited(n,false);
        
        for(int i=0;i<connections.size();i++){
            
            int u=connections[i][0];
            int v=connections[i][1];
            
            dirGraph[u].push_back(v);
            reverse[v].push_back(u);            
        }
        
        dfs(0,dirGraph,reverse,visited);
        
        return ans;
    }
};