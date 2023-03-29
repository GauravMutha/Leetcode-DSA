//Bellman Ford
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0; //k is source node
        for(int i=0;i<n-1;i++){
            for(int i=0;i<times.size();i++){
                int u=times[i][0] , v=times[i][1] , w=times[i][2];
                
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
                    dist[v]=dist[u]+w;
            }
        }
        int minTime= *max_element(begin(dist)+1,end(dist));
        
        return (minTime==INT_MAX)?-1:minTime;
    }
};