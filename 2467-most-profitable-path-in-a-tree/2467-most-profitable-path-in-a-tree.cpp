//1 DFS
class Solution {
public:
    int dfs(int curr,int par,int d,int bob,vector<int>&bobDist,vector<int>&amount,vector<vector<int>>& graph){
        int sum=0; //decided by comparison between depth aka d(alice distance from 0) and bobDist[curr]
        int maxRet=INT_MIN; //the sum that child of curr will return
        
        if(curr==bob) bobDist[curr]=0; //so nodes in the path upwards, from bob, have distance values starting 0;
        
        for(auto adj: graph[curr]){
            if(adj!=par){
                maxRet=max(maxRet,dfs(adj,curr,d+1,bob,bobDist,amount,graph));
                //nodes in bob to 0 path upwards get dist value wrt to bob which is 0, so 0,1,2....
                bobDist[curr]=min(bobDist[curr],bobDist[adj]+1);
            }
        }
        
        //if alice meet bob at curr node then half of the nodes value will be added into sum
        if(d==bobDist[curr]) sum+=amount[curr]/2;
        
        //If current node's distance is more than its d (distance of node form 0) then Alice reaches it first
        else if(d<bobDist[curr]) sum+=amount[curr];
        
        if(maxRet==INT_MIN) return sum;
        else return sum+maxRet;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size(),depth=0; //depth also represent distance of alice from 0
        vector<vector<int>>graph(n);
        
        /*distance of every node from bob init to maximum
         possible value i.e. n */
        vector<int>bobDist(n,n); 
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1]; 
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        return dfs(0,0,depth,bob,bobDist,amount,graph);
    }
};