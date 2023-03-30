// DFS Reversed graph  + Using visited array for count sort 
//TC ~ O(n^2)
class Solution {
public:
    void dfs(int curr,vector<bool>& visited,vector<vector<int>>&graph){
        visited[curr]=true;
        for(auto adj:graph[curr]){
            if(!visited[adj]) 
                dfs(adj,visited,graph);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n),res(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1];
            graph[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            vector<bool>visited(n,false);
            /*visited picks children of ith node which are parents in          
            normal graph; in COUNT SORT manner so it wiil store
            child in pth index of visited vector.Its applicable as 
            all node are positive and unique*/ 
            dfs(i,visited,graph);
            for(int j=0;j<n;j++) 
                if(visited[j]==true && j!=i) res[i].push_back(j);
        }
        
        return res;
    }
};