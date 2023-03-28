//DFS-Coloring Graph Intuitive version
// No color is -1 , white is 1 amd black is 0;
class Solution {
public:
    bool dfsColoring(int curr,int color,vector<int>& colors,vector<vector<int>>& graph){
        colors[curr]= color;
        for(auto adjNode: graph[curr]){
            if(colors[adjNode]==-1){
                if(!dfsColoring(adjNode,!color,colors,graph))
                    return false;
            }
            else if(colors[adjNode]==colors[curr]) return false;
        }
        
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n+1);
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0] , v=dislikes[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>colors(n+1,-1);
        
        for(int i=0;i<=n;i++){
            if(colors[i]!=-1) continue;
            
            if(!dfsColoring(i,1,colors,graph)) return false;
        }
        
        return true;
    }
};