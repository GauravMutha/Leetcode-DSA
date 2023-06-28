typedef vector<bool> vbool;
class Solution {
public:
    bool dfsCycleDetection(int curr,vbool &vis,vbool &pathVis,vector<vector<int>>& graph){
        
        vis[curr]=true;
        pathVis[curr]=true;
        
        for(auto adj:graph[curr]){
        
            if(vis[adj]==false){
                if(dfsCycleDetection(adj,vis,pathVis,graph)) 
                    return true;
            }
            
            else if(pathVis[adj]==true) return true;
        }
        pathVis[curr]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vbool vis(n,false),pathVis(n,false);
        
        vector<vector<int>>graph(n);
        //making graph
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1];
            graph[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==false){
            //if cycleDetection returns true , it means we CANNOT complete courses
                if(dfsCycleDetection(i,vis,pathVis,graph)) 
                    return false;
            }
        }
        return true;
    }
};