//Single  dfs with graph making
//Better solution than Union find because UF was O(N*log(N))
//O(N)
class Solution {
private:
    int  cycleStart=-1;
    unordered_set<int>cycleNodes;
    void makeGraph(vector<vector<int>>& graph,vector<vector<int>>& edges){
        for(int i=0;i<edges.size();i++){
            int v=edges[i][1];
            int u=edges[i][0];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
public:
    void dfs(int curr,int parent,vector<int>& visited,vector<vector<int>>& graph){
        if(visited[curr]==true) {
            cycleStart=curr;
            return;
        }
        visited[curr]=true;
        for(auto &adjNode : graph[curr]){
            if(adjNode==parent) 
                continue;
            //If cycle is not empty then no need for traversing further so need for anymore dfs calls
            if(cycleNodes.empty()) 
                dfs(adjNode,curr,visited,graph);
            
            if(cycleStart != -1) 
                cycleNodes.insert(curr);
            
            if(cycleStart==curr){
                cycleStart=-1;
                return;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>visited(n+1,false);
        vector<vector<int>>graph(n+1);
        
        makeGraph(graph,edges);
        
        dfs(1,-1,visited,graph);
        
        for(int i=edges.size()-1;i>=0;i--){
            
            if(cycleNodes.count(edges[i][0]) && cycleNodes.count(edges[i][1])) 
                return edges[i];
        }
        
        return {};
    }
};