//DFS WITHOUT REVERSING GRAPH
//A brute force dfs to get all ancestors of all nodes
class Solution {
public:
    void dfs(int curr,int start,vector<bool>& vis,vector<vector<int>>& graph,vector<vector<bool>>& isReachable){
        vis[curr]=true;
        for(auto &adjNode : graph[curr]){
            if(!vis[adjNode]){
                isReachable[start][adjNode]=true;
                dfs(adjNode,start,vis,graph,isReachable);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<bool>res(queries.size(),false);
        vector<vector<int>>graph(n);
        vector<vector<bool>>isReachable(n,vector<bool>(n,false));
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0] , v=pre[i][1];
            
            graph[u].push_back(v);
        }
        
        for(int i=0;i<n;i++){
            vector<bool>visited(n,false);
            dfs(i,i,visited,graph,isReachable);
        }
        
        for(int i=0;i<queries.size();i++)
            res[i]=isReachable[queries[i][0]][queries[i][1]];
        
        return res;
    }
};

/*Again similar to 2192. All ancestors of a node directed acyclic 
graph. The above code is just that brute force dfs code of 2192
but note that here we definitly require visited array ,although
there are no cycles as per constraints but not using visited array
in dfs can increase its TC from n^2 to n^3 leading to TLE* ,whereas 
the question 2192 too require avoiding dfs for processsed nodes but
there visited is substitut-able*/