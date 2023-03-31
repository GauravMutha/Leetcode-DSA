//DFS Reversing Graph
class Solution {
public:
    bool dfs(int curr,int target,vector<bool>& visited,vector<vector<int>>& revGraph){
        visited[curr]=true;
        if(curr==target) return true;
        for(auto adjNode : revGraph[curr]){
            if(!visited[adjNode]){
                if(dfs(adjNode,target,visited,revGraph)) return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>>revGraph(n);
        vector<bool>res(queries.size(),false);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0] , v=pre[i][1];
            
            revGraph[v].push_back(u);
        }
        
        for(int i=0;i<queries.size();i++){
            int start=queries[i][1] , target=queries[i][0];
            vector<bool>visited(n,false);
            res[i]=dfs(start,target,visited,revGraph);
        }
        
        return res;
    }
};
//Concept of starting dfs traversal from a node and checking if target can be reached
//Similar to 2192.All Ancestors of a node in a directed Acyclic Graph