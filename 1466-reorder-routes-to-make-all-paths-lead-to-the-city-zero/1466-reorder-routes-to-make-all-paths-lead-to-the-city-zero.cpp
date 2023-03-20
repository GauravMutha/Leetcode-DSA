//DFS
class Solution {
private:
    vector<vector<int>>dirn;
    vector<int>parent;
    vector<bool>visited;
    int count=0;
public:
    void dfs(int curr,int parent,vector<vector<int>>& graph){
        visited[curr]=true;
        
        if(parent!=-1){
            if(find(begin(dirn[curr]),end(dirn[curr]),parent)==dirn[curr].end())
                count++;
        }
            
        for(auto &adjNode: graph[curr]){
            if(!visited[adjNode]) 
                dfs(adjNode,curr,graph);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n);
        
        parent.resize(n);
        visited.resize(n);
        dirn.resize(n);
        //make undirected 'graph' and directed map 'dirn'
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
            
            dirn[u].push_back(v);
        }
        dfs(0,-1,graph);
        
        return count;
    }
};