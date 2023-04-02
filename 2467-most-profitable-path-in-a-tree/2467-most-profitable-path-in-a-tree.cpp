//2 DFS
class Solution {
public:
    int dfs2(int curr,int par,vector<int>& amount , vector<vector<int>>& graph){
        int currVal=amount[curr];
        int maxVal=INT_MIN;
        
        for(auto adj : graph[curr]){
            if(adj!=par)
                maxVal=max(maxVal,dfs2(adj,curr,amount,graph));
        }
        //if curr was a leaf node , it never entered for loop to update maxVal
        if(maxVal==INT_MIN) return currVal;
        else return maxVal+currVal;
    }
    void dfs1(int curr,int par,int d,vector<int>& parent,vector<int>& distances,vector<vector<int>>& graph){
        distances[curr]=d;
        parent[curr]=par;
        for(auto adj : graph[curr]){
            if(adj!=par) dfs1(adj,curr,d+1,parent,distances,graph);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>>graph(n);
        vector<int>dist(n),parent(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1]; 
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        dfs1(0,0,0,parent,dist,graph);
        
        int b=bob;
        int aliceDist=0;
        while(b!=0){
            //if alice ever meets bob at a node then that node amount is made half
            if(aliceDist==dist[b])
                amount[b]/=2;
            
            //if bob has crossed a node and alice has not
            else if(aliceDist<dist[b])
                amount[b]=0;    
            b=parent[b];
            aliceDist++;
        }
        
        return dfs2(0,0,amount,graph);
    }
};