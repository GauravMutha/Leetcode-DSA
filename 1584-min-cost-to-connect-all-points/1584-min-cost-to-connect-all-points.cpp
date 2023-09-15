typedef pair<int,int>pii;
class Solution {
public:
    int getDist(int curr,int next,vector<vector<int>>& p){
        return (abs(p[curr][0]-p[next][0])+abs(p[curr][1]-p[next][1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size(), connected=0, curr=0,res=0;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<bool>visited(n,false);
        
        while(++connected<n){
            
            visited[curr]=true;
            
            for(int next=0;next<n;next++){
                if(visited[next]==true) continue;
                int dist=getDist(curr,next,points);
                pq.push({dist,next});
            }
            
            while(visited[pq.top().second]) pq.pop();
            int shortestDist=pq.top().first;
            res+=shortestDist;
            curr=pq.top().second;
            pq.pop();
        }
        
        return res;
    }
};