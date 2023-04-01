//BFS
typedef pair<int,int>pii;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>dist(n,-1);
        vector<vector<pii>>graph(n);
        vector<vector<bool>>visited(n,vector<bool>(2,false));
        queue<vector<int>>q;
        
        for(int i=0;i<redEdges.size();i++){
            int u=redEdges[i][0] , v=redEdges[i][1];
            graph[u].push_back({v,0}); //0  because its red
        }
        
        for(int i=0;i<blueEdges.size();i++){
            int u=blueEdges[i][0] , v=blueEdges[i][1];
            graph[u].push_back({v,1}); //1  because its blue
        }
        
        dist[0]=0;
        visited[0][1]=visited[0][2]=true;
        q.push({0,0,-1});
        
        while(!q.empty()){
            int curr=q.front()[0] , steps=q.front()[1] , currCol=q.front()[2];
            q.pop();
            
            for(auto [adj,col]: graph[curr]){
                if(!visited[adj][col] && currCol != col){
                    visited[adj][col]=true;
                    q.push({adj,steps+1,col});
                    if(dist[adj]==-1) 
                        dist[adj]=steps+1;
                }
            }
        }
        
        return dist;
    }
};
//0--> Red color
//1--> Blue color