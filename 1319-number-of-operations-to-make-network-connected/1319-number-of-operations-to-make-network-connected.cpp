//Almost similar to 647.Redundant connection
//We should find Number of redundant connections

// #1 Disjoint set + Union find
//O(e*(log(n)) e is edges or connections size ,and n is number of computers
class Solution {
private:
    int detach=0;
public:
    int findParent(int node,vector<int>& parent){
        if(parent[node]==node){
            return node;
        }
        //path compression can distort the given network which can affect answer
        return findParent(parent[node],parent);
    }
    void doUnion(int x,int y,vector<int>& parent,vector<int>& rank){
        int xParent=findParent(x,parent);
        int yParent=findParent(y,parent);
        
        //if parents are equal for x and y nodes
        if(xParent==yParent){
            detach++;
        }
        //Union by rank optimisation
        //if parents are not equal for x and y nodes
            
            if(rank[xParent]<rank[yParent])
                parent[xParent]=yParent;
            else if(rank[yParent]<rank[xParent])
                parent[yParent]=xParent;
            else 
                parent[yParent]=xParent , rank[xParent]++;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n),rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<connections.size();i++){
            doUnion(connections[i][0],connections[i][1],parent,rank);
        }
        int failryConnected=connections.size()-detach+1;
        int isolated=n-failryConnected;
        return (isolated<=detach) ? isolated : -1;
    }
};