//Disjoint set + Union Find
//O(e*log(n)) n is number of node and e is number of edges
class Solution {
public:
    int findParent(int node,vector<int>& parent){
        if(parent[node]==node){
            return node;
        }
        //path compression optimisation before returning
        int temp=findParent(parent[node],parent);
        parent[node]=temp;
        return temp;
    }
    bool doUnion(int x,int y,vector<int>& parent,vector<int>& rank){
        int xParent=findParent(x,parent);
        int yParent=findParent(y,parent);
        
        //if parents are equal for x and y nodes
        if(xParent==yParent){
            return true;
        }
        //Union by rank optimisation
        //if parents are not equal for x and y nodes
        if(rank[xParent]<rank[yParent])
            parent[xParent]=yParent;
        else if(rank[yParent]<rank[xParent])
            parent[yParent]=xParent;
        else 
            parent[yParent]=xParent , rank[xParent]++;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>ans(2);
        vector<int>parent(n+1),rank(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
        
        for(int i=0;i<n;i++){
            if(doUnion(edges[i][0],edges[i][1],parent,rank))
               ans=edges[i];
        }       
        return ans; //code excution will never reach here
    }
};