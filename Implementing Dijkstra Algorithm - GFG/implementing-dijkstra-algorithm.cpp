//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution //using set instead of priority queue
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>st;
        vector<int>res(V,INT_MAX);
        res[S]=0;
        st.insert({res[S],S});
        
        while(!st.empty()){
            int curr=st.begin()->second;
            int distToCurr=st.begin()->first;
            st.erase(st.begin());
            for(auto p : adj[curr]){
                int adjNode=p[0];
                int distAhead=p[1];
                
                if((distToCurr + distAhead) < res[adjNode]){
                    if(res[adjNode]!=INT_MAX) st.erase({res[adjNode],adjNode});
                    res[adjNode]=distToCurr+distAhead;
                    st.insert({distToCurr+distAhead,adjNode});
                }
            }
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends