//BFS Kahn's Algorithm
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>setVector(n); //initial res but is a vector of set
        vector<int>indeg(n);
        queue<int>q;
        vector<vector<int>>graph(n),res2(n); //this res2 is what we will return
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1];
            graph[u].push_back(v);
            indeg[v]++;
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(auto adjNode: graph[curr]){
                setVector[adjNode].insert(curr);
                for(auto it:setVector[curr])
                    setVector[adjNode].insert(it);
                
                indeg[adjNode]--;
                if(indeg[adjNode]==0) q.push(adjNode);
            }
            
        }
        for(int i=0;i<n;i++){
            res2[i]=vector<int>(setVector[i].begin(),setVector[i].end());
        }
        return res2;
    }
};