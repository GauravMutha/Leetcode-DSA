//Odd loop detection - Similar to previous dfs
class Solution {
public:
    bool dfs(int curr,vector<int>& dist,vector<vector<int>>& graph){
        for(auto &adjNode : graph[curr]){
            if(dist[adjNode]>-1 && (dist[adjNode]-dist[curr]+1)%2)
                return false;
            else if(dist[adjNode]==-1){
                dist[adjNode] = dist[curr] + 1;
                if(!dfs(adjNode,dist,graph)) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n+1);
        vector<int>dist(n+1,-1);
        
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0] , v=dislikes[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i=0;i<=n;i++){
            if(dist[i]>-1) continue;
            dist[i]=0;
            if(!dfs(i,dist,graph)) return false;
        }
        
        return true;
    }
};