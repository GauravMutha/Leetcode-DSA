//#1(d) DFS - without making making a graph
//Counting components
//TC-->O(n^2) SC-->O(1)
typedef vector<vector<int>> vvi;
class Solution {
public:
    void dfs(int i,vvi& stones,vector<bool>&visited){
        visited[i]=true;
        
        for(int j=0;j<stones.size();j++){
            int iRow=stones[i][0] , iCol=stones[i][1];
            int jRow=stones[j][0] , jCol=stones[j][1];
            
            if(i!=j && (iRow==jRow || jCol==iCol) && !visited[j]){
                dfs(j,stones,visited);
            }
        }
    }
    int removeStones(vvi& stones) {
        int n=stones.size()  ,components=0;
        vvi graph(n);
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,stones,visited);
                components++;
            } 
        }
        return n-components;
    }
};