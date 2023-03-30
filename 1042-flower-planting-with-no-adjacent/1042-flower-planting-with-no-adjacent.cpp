//Similar to graph coloring concept in problem 785 and 886
class Solution {
public:
    void dfs(int curr,vector<vector<int>>& graph,vector<int>& ans){
        int nextNode=-1,flowerType;
        bool available[5]={false};
        for(auto adjNode : graph[curr]){
            if(ans[adjNode-1]==-1) nextNode=adjNode;
            else available[ans[adjNode-1]]=true;
        }
        for(int i=1;i<5;i++) if(available[i]==false) flowerType=i;
        ans[curr-1]=flowerType;
        if(nextNode!=-1) dfs(nextNode,graph,ans);
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>graph(n+1);
        vector<int>ans(n,-1);
        
        for(int i=0;i<paths.size();i++){
            int u=paths[i][0] , v=paths[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i=1;i<=n;i++){
            if(ans[i-1]==-1)
                dfs(i,graph,ans);
        }
        return ans;
    }
};