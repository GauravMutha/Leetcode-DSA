//Djikstra
//BFS
typedef pair<int,int>pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        vector<int>distances(n+1,INT_MAX);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i=0;i<times.size();i++){
            int u=times[i][0], v=times[i][1] , w=times[i][2];
            
            graph[u].push_back({v,w});
        }
        distances[k]=0;
        pq.push({distances[k],k});
        
        while(!pq.empty()){
            auto [dist,curr]=pq.top();
            pq.pop();
            
            for(auto [adjNode,w]:graph[curr]){
                if((dist+w)<distances[adjNode]){
                    distances[adjNode]=dist+w;
                    pq.push({distances[adjNode],adjNode});
                }
            }
        }
        
        int minTime= *max_element(begin(distances)+1,end(distances));
        
        return (minTime==INT_MAX)?-1:minTime;
    }
};