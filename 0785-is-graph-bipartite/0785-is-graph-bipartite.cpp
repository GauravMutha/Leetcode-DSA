//DFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colors(n,-1);
        queue<int>q;

        for(int i=0;i<n;i++){
            if(colors[i]!=-1) continue;
            q.push(i);
            colors[i]=1;
            
            while(!q.empty()){
                int curr=q.front() , color=colors[curr];
                q.pop();
                
                for(auto adjNode : graph[curr]){
                    int adjColor=colors[adjNode];
                    
                    if(adjColor!=-1 && (adjColor!=color)) continue;
                    else if(adjColor!=-1 && (adjColor==color)) return false;
                    
                    colors[adjNode]=!color;
                    q.push(adjNode);
                }
                
            }
        }
        return true;
    }
};