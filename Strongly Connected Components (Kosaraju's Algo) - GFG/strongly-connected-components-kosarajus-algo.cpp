//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs1(int curr,stack<int>& st,vector<bool>& vis1,vector<vector<int>>& graph){
	    vis1[curr]=true;
	    
	    for(int adjNode : graph[curr]){
	        if(vis1[adjNode]) continue;
	        dfs1(adjNode,st,vis1,graph);
	    }
	    
	    st.push(curr);
	}
	void dfs2(int curr,vector<bool>& vis2,vector<vector<int>>& revGraph){
	    vis2[curr]=true;
	    
	    for(int adjNode : revGraph[curr]){
	        if(vis2[adjNode]) continue;
	        dfs2(adjNode,vis2,revGraph);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& graph)
    {
        int res=0;
        stack<int>st;
        vector<bool>vis1(n,false),vis2(n,false);
        vector<vector<int>>revGraph(n);
        //making a reversed graph
        for(int i=0;i<graph.size();i++){
            int u=i;
            for(int j=0;j<graph[i].size();j++){
                int v= graph[i][j];
                revGraph[v].push_back(u);
            }
        }
        
        for(int i=0;i<n;i++){
            if(vis1[i]) continue;
            dfs1(i,st,vis1,graph);
        }
        
        while(st.size()){
            int node=st.top();
            st.pop();
            if(vis2[node]) continue;
            dfs2(node,vis2,revGraph);
            res++;
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends