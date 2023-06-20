//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    //DIRECTED GRAPH CYCLE DETECTION DFS
  public:
    bool dfs(int curr,int par,vector<bool>& vis,vector<int> adj[]){
        vis[curr]=true;
        for(auto adjNode: adj[curr]){
            if(vis[adjNode] && par==adjNode) continue;
            if(vis[adjNode] && par!=adjNode) return true;
            if(dfs(adjNode,curr,vis,adj)) return true;
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==true) continue;
            if(dfs(i,-1,vis,adj)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends