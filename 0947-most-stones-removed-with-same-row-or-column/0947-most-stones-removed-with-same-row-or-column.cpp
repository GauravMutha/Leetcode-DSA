//#1(a) DFS - without making making a graph
//Counting nodes
//TC-->O(n^2) SC-->O(1)
typedef vector<vector<int>> vvi;
class Solution {
public:
    void dfs(int i,int& count,vvi& stones,vector<bool>&visited){
        visited[i]=true;
        count++;
        
        for(int j=0;j<stones.size();j++){
            int iRow=stones[i][0] , iCol=stones[i][1];
            int jRow=stones[j][0] , jCol=stones[j][1];
            
            if(i!=j && (iRow==jRow || jCol==iCol) && !visited[j]){
                dfs(j,count,stones,visited);
            }
        }
    }
    int removeStones(vvi& stones) {
        int n=stones.size() , res=0;
        vvi graph(n);
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            int count=0; //nodes counter in a single component
            if(!visited[i]){
                dfs(i,count,stones,visited);
                res+=(count-1); //root of any component will not be deleted hence -1
            } 
        }
        return res;
    }
};