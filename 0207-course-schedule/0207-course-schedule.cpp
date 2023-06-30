class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<vector<int>>graph(n);
        queue<int>q;
        vector<int>indeg(n);
        int topoSorted=0;
        
        for(int i=0;i<prereq.size();i++){
            int u=prereq[i][0] , v=prereq[i][1];
            graph[v].push_back(u);
            indeg[u]++;
        }
        
        for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            topoSorted++;          
            for(auto &adjNode:graph[curr]){
                indeg[adjNode]--;
                if(indeg[adjNode]==0) q.push(adjNode);
            }
        }
        
        return topoSorted==n;
    }
};