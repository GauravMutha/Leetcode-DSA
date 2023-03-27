//DFS-Coloring Graph
// No color is -1 , white is 1 amd black is 0;
class Solution {
public:
    bool dfsColoring(int curr,int color,vector<int>& colors,vector<vector<int>>& graph){
        if(colors[curr]!=-1) return colors[curr]==color;
        colors[curr]= color;
        for(auto adjNode: graph[curr]){
            if(!dfsColoring(adjNode,!color,colors,graph))
               return false;
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colors(n,-1);
        
        for(int i=0;i<n;i++){
            if(colors[i]!=-1) continue;
            
            if(!dfsColoring(i,1,colors,graph)) return false;
        }
        
        return true;
    }
};