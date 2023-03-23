//BFS
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int res=INT_MAX;
        vector<vector<pair<int,int>>>graph(n+1);
        vector<bool>visited(n+1,false);
        queue<int>q;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0] ,v=roads[i][1], dist=roads[i][2];
            
            graph[u].push_back({v,dist});
            graph[v].push_back({u,dist});
        }
        visited[1]=true;
        q.push(1);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &[adjNode,dist] : graph[node]){
                res=min(res,dist);
                if(!visited[adjNode]) 
                    q.push(adjNode) , visited[adjNode]=true;
            }
        }
        
        return res;
    }
};