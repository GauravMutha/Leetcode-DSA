//DFS
//Cycle detection in graph
class Solution {
public:
    bool dfs(int curr,vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& pathVis){
        visited[curr]=true;
        pathVis[curr]=true;
        for(auto adjNode: graph[curr]){
            if(visited[adjNode]!=true){
                if(dfs(adjNode,graph,visited,pathVis)==true) return true;
            }
            else if(pathVis[adjNode]==true) return true;
        }
        pathVis[curr]=false; //as curr node pops out of stack we make it false given no cycle was detected previously
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        vector<bool>visited(n,false),pathVis(n,false); //pathVis tracks which nodes are in current dfs path
        
        for(int i=0;i<n;i++){
            dfs(i,graph,visited,pathVis);
        }
        
    
        for(int i=0;i<n;i++){
            //if safe node
            if(pathVis[i]==false) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};