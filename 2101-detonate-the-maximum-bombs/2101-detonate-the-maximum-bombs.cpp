class Solution {
private:
    
    bool intersect(vector<int>& bomb1,vector<int>& bomb2){
        long long x1=bomb1[0] , y1=bomb1[1] ,r1=bomb1[2];
        long long x2=bomb2[0] , y2=bomb2[1] ,r2=bomb2[2];
        
        
        
        return ((x2-x1)*(x2-x1) +(y2-y1)*(y2-y1)) <= r1*r1;
    }
    
    void dfs(int curr,int& count,vector<bool>& visited,vector<vector<int>>& graph){
        if(visited[curr]==true) return;
        
        visited[curr]=true;
        count++;
        
        for(auto adj : graph[curr]){
            if(!visited[adj])
                dfs(adj,count,visited,graph);
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size(),nodeCount=0,maxNodes=INT_MIN;
        vector<vector<int>>graph(n);
        
        //connect bomb ranges/circles into a graph
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && intersect(bombs[i],bombs[j])){
                    graph[i].push_back(j);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            vector<bool>visited(n,false);
            nodeCount=0;
            dfs(i,nodeCount,visited,graph);
            maxNodes=max(maxNodes,nodeCount);
        }
        return maxNodes;
    }
};