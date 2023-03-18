//Using DSU
//O(N^2(logN))
class Solution {
private:
    int groups;
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
    void doUnion(int x,int y,vector<int>& parent , vector<int>& rank){
        int xParent=findParent(x,parent);
        int yParent=findParent(y,parent);
        //If parents are equal we do nothing
        if(xParent==yParent) return;
        //otherwise we merge the parents using union by rank optimisation and update our answer i.e groups
        groups--;
        if(rank[xParent]<rank[yParent])
        parent[xParent]=yParent;
        else if(rank[yParent]<rank[xParent])
            parent[yParent]=xParent;
        else 
            parent[yParent]=xParent , rank[xParent]++; //we can make any one of the node parent
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        groups=n;
        vector<int>parent(n),rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        
        //we do union of every two connected city
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(M[i][j]==1) doUnion(i,j,parent,rank);
            }
        }
        
        return groups;
    }
};