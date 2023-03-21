//#1(b) DFS - Explicitly making a graph
//It is Counting components , 1(a) was counting nodes
//TC-->O(n^2) SC-->O(n^2)
class Solution {
private:
    int components=0;
public:
    void dfs(int curr,vector<vector<int>>& graph,vector<bool>&visited){
        visited[curr]=true;
        
        for(auto& adjNode : graph[curr]){
            if(!visited[adjNode])
                dfs(adjNode,graph,visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size()==1) return 0; //only one stone, cannot be removed
        int n=stones.size();
        vector<vector<int>> graph(n);
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int iRow=stones[i][0] , iCol=stones[i][1];
                int jRow=stones[j][0] , jCol=stones[j][1];
                
                if(iRow==jRow || jCol==iCol) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,visited);
                components++;
            } 
        }
        /*component count is bascially counting roots of components
        which will be left behind always , so n-components is all
        the stones that has beem removed*/
        return n-components;
    }
};