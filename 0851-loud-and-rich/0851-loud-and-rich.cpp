//Toplogical Sort using BFS - Kahn's Algorithm
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>graph(n);
        vector<int>ans(n,-1);
        vector<int>indeg(n);
        queue<int>q;
        
        //making graph and indegree vector
        for(int i=0;i<richer.size();i++){
            int u=richer[i][0] ,v=richer[i][1];
            
            graph[u].push_back(v);
            indeg[v]++;
        }
        //pushig 0 indegree nodes in queue AND initialising ans vector
        for(int i=0;i<n;i++){
            ans[i]=i;
            
            if(indeg[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto &adjNode : graph[curr]){
                if(quiet[ans[adjNode]]>quiet[ans[curr]])
                    ans[adjNode]=ans[curr];
                indeg[adjNode]--;
                if(indeg[adjNode]==0) q.push(adjNode);
            }
        }
        
        return ans;
    }
};