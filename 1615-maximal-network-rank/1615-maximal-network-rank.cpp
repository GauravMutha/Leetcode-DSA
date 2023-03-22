//Brute force - the only way
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int res=-1;
        vector<vector<bool>>adj(n,vector<bool>(n,false));
        vector<int>adjCount(n,0);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            
            adjCount[u]++ ,adjCount[v]++;
            adj[u][v]=true; 
            adj[v][u]=true;
        }
        
        /* following method does not work as it does not consider
        two non-connected cities in one components with two highest 
        neighbours count*/
        
        // for(int i=0;i<n;i++){
        //     if(adjCount[i]>=maxVal1){
        //         maxVal2=maxVal1 ,  maxVal1=adjCount[i];
        //         ind2=ind1 , ind1=i;
        //     }
        //     else if(adjCount[i]>=maxVal2){
        //         maxVal2=adjCount[i];
        //         ind2=i;
        //     }
        // }
        
        //using brute force to find the pair , no other  optimised way
        for(int i=0;i<n;i++){
            for(int j=i+1l;j<n;j++){
                res=max(adjCount[i]+adjCount[j]-adj[i][j],res);
            }
        }
        return res;
    }
};