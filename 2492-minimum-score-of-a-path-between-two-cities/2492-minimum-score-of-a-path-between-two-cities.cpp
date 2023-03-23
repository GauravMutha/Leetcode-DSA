//DSU
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
    int minScore(int n, vector<vector<int>>& roads) {
        int res=INT_MAX;
        vector<vector<pair<int,int>>>graph(n+1);
        vector<int>parent(n+1),rank(n+1,0);
        
        for(int i=0;i<n+1;i++) parent[i]=i;
        /*to always favour 1 to be a parent 
        when a case of merging arises in union
        process,we give it the largest possible 
        pseudo rank,a short trick to avoid extra
        condition statement in the doUnion function*/
        rank[1]=100000; 
        
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0] , v=roads[i][1];
            doUnion(u,v,parent,rank);
        }
        
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0] , v=roads[i][1] , dist=roads[i][2];
            if(findParent(u,parent)==1 || findParent(v,parent)==1) 
                res=min(res,dist);    
        }
        
        return res;
    }
};