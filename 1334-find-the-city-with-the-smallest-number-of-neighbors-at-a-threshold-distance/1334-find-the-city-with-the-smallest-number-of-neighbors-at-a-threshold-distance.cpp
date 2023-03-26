//Djikstra
typedef pair<int,int> pii;
class Solution {
public:
    int djikstra(int src,int n,int k,vector<vector<pii>>& graph){
        
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<int>distances(n,INT_MAX);
        
        //these two lines below are specifically for this question
        int cityCount=0;
        vector<bool>counted(n,false);
        
        distances[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            auto [dist,curr]=pq.top();
            pq.pop();
            
            for(auto &[adjNode,wt]: graph[curr]){
                if (dist + wt < distances[adjNode]) {
                    distances[adjNode] = dist + wt;
                    pq.push({distances[adjNode], adjNode});
                    if (distances[adjNode] <= k && !counted[adjNode]) {
                        cityCount++;
                        counted[adjNode] = true;
                    }
                }
                
            }
        }
        return max(cityCount-1,0);
    }
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        int res=0,minCount=INT_MAX;
        vector<vector<pii>>graph(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1] ,w=edges[i][2];
            
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        
        for(int i=0;i<n;i++){
            int cityCount=djikstra(i,n,threshold,graph);
            if(cityCount<=minCount)
                res=i,minCount=cityCount;
        }
        return res;
    }
};