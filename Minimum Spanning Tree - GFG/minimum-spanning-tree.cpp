//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findParent(int node,vector<int>& parent){
	    if(parent[node]==node) return node;
	    
	    int temp=findParent(parent[node],parent);
	    parent[node]=temp;
	    return temp;
	}
	bool doUnion(int u,int v,vector<int>& parent,vector<int>& rank){
	    int uParent=findParent(u,parent);
	    int vParent=findParent(v,parent);
	    
	    if(uParent==vParent) return false;
	    
	    if(rank[uParent]<rank[vParent])
	        parent[uParent]=vParent;
	    else if(rank[uParent]>rank[vParent])
	        parent[vParent]=uParent;
	    else parent[vParent]=uParent , rank[uParent]++;
	    
	    return true;
	}
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        int res=0;
        vector<pair<int,pair<int,int>>> edges;
        vector<int>parent(n) , rank(n,0);
        
        for(int u=0;u<n;u++){
            for(auto vec : adj[u]){
                int v=vec[0] , wt=vec[1];
                edges.push_back({wt,{u,v}});
            }
        }
        sort(edges.begin(),edges.end());
        
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(int i=0;i<edges.size();i++){
            auto p=edges[i];
            int wt=p.first , u=p.second.first , v=p.second.second;
            
            if(doUnion(u,v,parent,rank)) res+=wt;;
        }
        
        
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends