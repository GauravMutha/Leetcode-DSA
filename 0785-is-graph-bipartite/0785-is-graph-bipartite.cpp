//DSU
class Solution {
public:
    int findParent(int node,vector<int>& parent){
        if(parent[node]==node){
            return node;
        }
        int temp=findParent(parent[node],parent);
        parent[node]=temp;
        return temp;
    }
    void doUnion(int x,int y,vector<int>& parent,vector<int>& rank){
        int xParent=findParent(x,parent);
        int yParent=findParent(y,parent);
        
        if(xParent==yParent){
            return;
        }
        if(rank[xParent]<rank[yParent])
            parent[xParent]=yParent;
        else if(rank[yParent]<rank[xParent])
            parent[yParent]=xParent;
        else 
            parent[yParent]=xParent , rank[xParent]++;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>parent(n),rank(n,0);
        
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                if(parent[i]==parent[graph[i][j]]) return false;
                
                doUnion(graph[i][0],graph[i][j],parent,rank);
            }
        }
        
        return true;
    }
};