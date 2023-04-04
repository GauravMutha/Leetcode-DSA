//DFS
//Making a graph
class Solution {
public:
    void dfs(int curr,int& nodeCount,vector<vector<int>>& graph){
        nodeCount++;
        for(auto adj : graph[curr]){
            dfs(adj,nodeCount,graph);
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        vector<vector<int>> graph(n);
        vector<int>indegree(n,0);
        int rootCount=0,root=-1,nodeCount=0;
        for(int i=0;i<n;i++){
            if(left[i]!=-1){
                graph[i].push_back(left[i]);
                indegree[left[i]]++;
                if(indegree[left[i]]>1) return false;
            }
            if(right[i]!=-1){
                graph[i].push_back(right[i]);
                indegree[right[i]]++;
                if(indegree[right[i]]>1) return false;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(root==-1) root=i;
                else return false;
            }
        }
        if(root==-1) return false;
        
        dfs(root,nodeCount,graph);
        
        return (nodeCount==n);
    }
};