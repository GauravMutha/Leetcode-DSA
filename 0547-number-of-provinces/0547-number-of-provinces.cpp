// O(N^2)
//DFS only using given adjacecny matrix M
class Solution {
public:
    void dfs(int i,vector<vector<int>>& M,vector<bool>& visited){
        visited[i]=true;
        for(int j=0;j<M.size();j++){
            if(i!=j && M[i][j]==1 && visited[j]==false)
                dfs(j,M,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int ans=0,n=M.size();
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                ans++;
                dfs(i,M,visited);
            }
        }
        
        return ans;
    }
};