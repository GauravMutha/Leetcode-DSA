//BFS
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans=0;
        vector<vector<int>>dirGraph(n) , reverse(n);
        vector<bool>visited(n,false);
        queue<int>q;
        q.push({0});
        
        for(int i=0;i<connections.size();i++){
            
            int u=connections[i][0];
            int v=connections[i][1];
            
            dirGraph[u].push_back(v);
            reverse[v].push_back(u);            
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            visited[node]=true;
            
            for(auto &adjNode : dirGraph[node]){
                if(!visited[adjNode]){
                    ans++;
                    q.push(adjNode);
                }
            }
            for(auto &adjNode : reverse[node]){
                if(!visited[adjNode]) q.push(adjNode);
            }
        }
        return ans;
    }
};