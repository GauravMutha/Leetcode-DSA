
class Solution {
public:
    int findParent(int node,vector<int>& parent){
        if(parent[node]==node) return node;
        int temp=findParent(parent[node],parent);
        return parent[node]=temp;
    }
    bool doUnion(int x,int y,vector<int>& parent, vector<int>& rank){
        int xParent=findParent(x,parent);
        int yParent=findParent(y,parent);
        
        if(xParent==yParent) return false;
        
        if(rank[xParent]>rank[yParent])
            parent[yParent]=xParent;
        else if(rank[xParent]<rank[yParent])
            parent[xParent]=yParent;
        else parent[xParent]=yParent, rank[yParent]++;
        
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(), res=0;
        vector<vector<int>>edges;
        vector<int>parent(n),rank(n,0);
        
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back(vector<int>({dist,i,j}));
            }
        }
        
        sort(edges.begin(),edges.end());
        
        for(int i=0;i<edges.size();i++){
            int dist=edges[i][0], u=edges[i][1], v=edges[i][2];
            if(doUnion(u,v,parent,rank)) res+=dist;
        }
        
        return res;
    }
};