//Cycle detection in directed graph
//BFS Kahn's Algorithm
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        int topSortedCount=0; //count nodes that are sorted topologically
        vector<vector<int>>graph(n);
        vector<int>indeg(n);
        queue<int>q;
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0] , v=pre[i][1];
            graph[v].push_back(u);
            indeg[u]++;
        }
        
        for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            topSortedCount++;
            
            for(auto &adjNode: graph[curr]){
                indeg[adjNode]--;
                if(indeg[adjNode]==0) q.push(adjNode);
            }
        }
        return (topSortedCount==n);
    }
};