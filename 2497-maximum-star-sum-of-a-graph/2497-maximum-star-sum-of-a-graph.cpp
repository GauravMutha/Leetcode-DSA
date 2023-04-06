//Priority queue , min heap , max k element concept
class Solution {
public:
    int processPQ(priority_queue<int,vector<int>,greater<int>>&pq){
        int sum=0;
        while(!pq.empty()){
            if(pq.top()>0) sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int res=INT_MIN,n=vals.size();
        vector<vector<int>>graph(n);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int curr=0;curr<n;curr++){
            priority_queue<int,vector<int>,greater<int>> pq;
            for(auto adj : graph[curr]){
                pq.push(vals[adj]);
                if(pq.size()>k) pq.pop();
            }
            int sumFromNeighbours=processPQ(pq);
            
            res=max(res,vals[curr]+sumFromNeighbours);
        }
        
        return res;
    }
};