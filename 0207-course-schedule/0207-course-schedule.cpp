//Cycle detection in directed graph
//Simple DFS
//This answer is not based on TopoSort criteria/kahn's approach
//Although we can apply kahn's approach using DFS too.
class Solution {
public:
    bool dfs(int curr,vector<bool>&visited,vector<bool>&pathVis,vector<vector<int>>& graph){
        visited[curr]=true;
        pathVis[curr]=true;
        
        for(auto adjNode: graph[curr]){
            if(visited[adjNode]==true && pathVis[adjNode]==true)
                return false;
            else if(visited[adjNode]==false){
                if(!dfs(adjNode,visited,pathVis,graph)) return false;
            }
        }
        pathVis[curr]=false;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        int topSortedCount=0; //count nodes that are sorted topologically
        vector<vector<int>>graph(n);
        vector<bool>visited(n,false),pathVisited(n,false);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0] , v=pre[i][1];
            graph[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(!dfs(i,visited,pathVisited,graph))
                    return false;
            }
        }
        
        return true;
    }
};