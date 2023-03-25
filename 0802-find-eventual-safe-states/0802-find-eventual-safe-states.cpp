// BFS Topological sort
//Cycle detections
//Graph reversed
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>indeg(n),ans;
        vector<vector<int>>revGraph(n);
        queue<int>q;
        
        for(int i=0;i<graph.size();i++){
            for(auto v: graph[i]){
                revGraph[v].push_back(i);
                indeg[i]++;
            }
        }
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            ans.push_back(curr);
            q.pop();
            for(auto adjNode: revGraph[curr]){
                indeg[adjNode]--;
                if(indeg[adjNode]==0) q.push(adjNode);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};