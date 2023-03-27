//Floyd Warshall algorithm
//O(N^3)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        int res=0,minCount=INT_MAX;
        vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1] , w=edges[i][2];
            matrix[u][v]=w;
            matrix[v][u]=w;
        }
        
        for(int k=0;k<n;k++){
            //k is the "via" node
            int cityCount=0;
            for(int j=0;j<n;j++){
                for(int i=0;i<n;i++){
                    if(i==j) 
                        matrix[i][j]=0;
                    else if(matrix[i][k]==INT_MAX || matrix[k][j]==INT_MAX)
                        continue;
                    else
                        matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            int cityCount=0;
            for(int j=0;j<n;j++){
                if(i!=j && matrix[i][j]<=k) 
                    cityCount++;
            }
            if(cityCount<=minCount) res=i , minCount=cityCount;
        }
        
        return res;
    }
};