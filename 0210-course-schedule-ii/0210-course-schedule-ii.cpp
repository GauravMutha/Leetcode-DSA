//DFS
class Solution {
private:
    vector<int>res; //count nodes that are sorted topologically
public:
    bool dfs(int curr,vector<bool>&visited,vector<bool>&pathVis,vector<vector<int>>& graph){
        visited[curr]=true;
        pathVis[curr]=true;
        
        for(auto adjNode: graph[curr]){
            if(visited[adjNode]==true && pathVis[adjNode]==true)
                return false;
            else if(visited[adjNode]==false){
                if(!dfs(adjNode,visited,pathVis,graph)) return false;
            }
        }
        pathVis[curr]=false;
        res.push_back(curr);
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>graph(n);
        vector<bool>visited(n,false),pathVisited(n,false);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0] , v=pre[i][1];
            graph[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(!dfs(i,visited,pathVisited,graph))
                    return vector<int>();
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
/*Exactly similar question 207.Course Schedule I
Only difference is here we return the vector of 
topo sorted nodes if possible*/