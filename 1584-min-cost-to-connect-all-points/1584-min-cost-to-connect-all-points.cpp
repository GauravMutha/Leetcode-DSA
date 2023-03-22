//prim
typedef pair<int,int>pii;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size() , connected=0 ,curr=0,next=0,dist=0,res=0;
        vector<bool>visited(n);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        
        while(++connected<n){
            visited[curr]=true;
            for(next=0;next<n;next++){
                if(!visited[next]){
                    dist=abs(points[curr][0]-points[next][0])+abs(points[curr][1]-points[next][1]);
                    pq.push({dist,next});
                }
            }
            
            while(visited[pq.top().second]) pq.pop();
            curr=pq.top().second;
            res+=pq.top().first;
            pq.pop();
        }
        
        return res;
    }
};