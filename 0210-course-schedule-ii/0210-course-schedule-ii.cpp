//BFS kahn's
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>res; //stores nodes that are sorted topologically
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
            res.push_back(curr);
            
            for(auto &adjNode: graph[curr]){
                indeg[adjNode]--;
                if(indeg[adjNode]==0) q.push(adjNode);
            }
        }
        return (res.size()==n)?res:vector<int>();
    }
};
/*Exactly similar question 207.Course Schedule I
Only difference is here we return the vector of 
topo sorted nodes if possible*/