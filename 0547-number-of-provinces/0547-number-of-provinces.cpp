// O(N^2)
//making adjacency list then performin dfs
class Solution {
public:
    void dfs(int node,vector<vector<int>>& adjList,vector<bool>& visited){
        visited[node]=true;
        for(auto adjNode : adjList[node]){
            if(visited[adjNode]==false)
                dfs(adjNode,adjList,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int ans=0,n=M.size();
        vector<bool>visited(n,false);
        vector<vector<int>>adjList(n);
        //making adjacency list
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]==1) adjList[i].push_back(j);
            }
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(i,adjList,visited);
                ans++;
            }
        }
        
        return ans;
    }
};