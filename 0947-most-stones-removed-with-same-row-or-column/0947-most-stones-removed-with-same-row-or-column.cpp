//#1(a) DFS - Explicitly making a graph
//Counting components
//TC-->O(n^2) SC-->O(n^2)
class Solution {
private:
    int res=0;
public:
    void dfs(int curr,int& count,vector<vector<int>>& graph,vector<bool>&visited){
        visited[curr]=true;
        count++;
        
        for(auto& adjNode : graph[curr]){
            if(!visited[adjNode])
                dfs(adjNode,count,graph,visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
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
            int count=0; //nodes counter in a single component
            if(!visited[i]){
                dfs(i,count,graph,visited);
                res+=(count-1); //root of any component will not be deleted hence -1
            } 
        }
        return res;
    }
};