//DSU
//O(N) , most optimised
class Solution {
public:
    //finding parent
    int findParent(int node,vector<int>& parent){
        if(parent[node]==node){
            return node;
        }
        //path compression optimisation before returning
        int temp=findParent(parent[node],parent);
        parent[node]=temp;
        return temp;
    }
    void doUnion(int x,int y,vector<int>& parent,vector<int>& rank){
        int xParent=findParent(x,parent);
        int yParent=findParent(y,parent);
        
        if(xParent==yParent)
            return;
        
        if(rank[xParent]<rank[yParent])
            parent[xParent]=yParent;
        else if(rank[yParent]<rank[xParent])
            parent[yParent]=xParent;
        else 
            parent[yParent]=xParent , rank[xParent]++;
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,bool>validNodes;
        int maxRow=0,maxCol=0 , components=0;
        for(auto &coordinate : stones){
            maxRow=max(coordinate[0],maxRow);
            maxCol=max(coordinate[1],maxCol);
        }
        int n=maxRow+maxCol+2;
        vector<int>parent(n),rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(int i=0;i<stones.size();i++){
            int nodeRow=stones[i][0] ,nodeCol=stones[i][1]+maxRow+1;
            validNodes[nodeRow]=true , validNodes[nodeCol]=true;
            doUnion(nodeRow,nodeCol,parent,rank);
        }
        
        for(auto &[node,val] : validNodes){
            if(findParent(node,parent)==node) components++;
        }
        return (stones.size()-components);
    }
};