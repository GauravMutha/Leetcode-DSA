//sorting with neighbours count
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        vector<long long>adj(n); //keeps count of neighbour of ith city
        
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            
            adj[u]++ , adj[v]++;
        }
        
        sort(adj.begin(),adj.end());
        
        for(int i=0;i<n;i++){
            ans+=((i+1)*adj[i]);
        }
        
        return ans;
    }
};