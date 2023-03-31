//BFS Kahn's
//Mapping all nodes to their ancestors using isReachable
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<bool>res(queries.size(),false);
        queue<int>q;
        vector<int>indeg(n,0);
        vector<vector<int>>graph(n);
        vector<vector<bool>>isReachable(n,vector<bool>(n,false));
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0] , v=pre[i][1];
            
            graph[u].push_back(v);
            indeg[v]++;
        }
        for(int i=0;i<n;i++)
            if(indeg[i]==0) 
                q.push(i);
        
        while(!q.empty()){
            int parent=q.front();
            q.pop();
            for(auto &child : graph[parent]){
                isReachable[parent][child]=true;
                //But also parent of current parent should be set true;
                for(int i=0;i<n;i++)
                    if(isReachable[i][parent]) isReachable[i][child]=true;
                indeg[child]--;
                if(indeg[child]==0) q.push(child);
            }
        }
        for(int i=0;i<queries.size();i++){
            res[i]=isReachable[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};

//Very similar to 2192. All ancestors of a node directed acyclic graph