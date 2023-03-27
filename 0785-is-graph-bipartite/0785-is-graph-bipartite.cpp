//BFS-Coloring Graph
// No color is -1 , white is 1 amd black is 0;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {    
        int n=graph.size();
        vector<int>colors(n,-1);
        queue<int>q;
        
        //multiple components possible hence this for loop
        for(int i=0;i<n;i++){
            if(colors[i]!=-1) continue;//already colored node
            
            q.push(i);
            colors[i]=1; //start node can be colored with any of the color
            while(!q.empty()){
                int curr=q.front() , currColor=colors[curr];
                q.pop();
                for(auto &adjNode : graph[curr]){
                    int adjColor=colors[adjNode];
                    
                    if(adjColor==-1) {
                        colors[adjNode]=!currColor;
                        q.push(adjNode);
                    }
                    else if(adjColor==currColor) return false;
                }
            }
        }
        
        return true;
    }
};