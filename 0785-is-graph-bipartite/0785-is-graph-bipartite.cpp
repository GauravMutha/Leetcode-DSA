//DFS
class Solution {
public:
    bool dfs(int curr,int color,vector<int>& colors,vector<vector<int>>& graph){
        if(colors[curr]!=-1) return colors[curr]==color;
        
        colors[curr]=color;
        
        for(auto adjNode : graph[curr]){
            if(!dfs(adjNode,!color,colors,graph)) return false;
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colors(n,-1);
        
        for(int i=0;i<n;i++){
            if(colors[i]!=-1) continue;
            if(!dfs(i,1,colors,graph)) return false;
        }
        return true;
    }
};