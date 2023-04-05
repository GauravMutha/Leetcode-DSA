//BFS
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<vector<int>>graph(n);
        vector<int>indeg(n,0);
        queue<int>q;
        
        if(n==1) return  {0};

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1];
            
            graph[u].push_back(v) , indeg[v]++;
            graph[v].push_back(u) , indeg[u]++;
        }
        
        for(int i=0;i<n;i++)
            if(indeg[i]==1) q.push(i);
        
        while(!q.empty()){
            int s = q.size();
            ans.clear();
            if(n <= 2) break;
            for(int i=0; i<s;i++){
               int curr = q.front(); q.pop();
               ans.push_back(curr);
               n--;
                for(auto child : graph[curr]){
                    indeg[child]--;
                    if(indeg[child]==1) q.push(child);   
                }
            }
        }
       while(!q.empty()){
           ans.push_back(q.front()); q.pop();
       }
        
        return ans;
    }
};