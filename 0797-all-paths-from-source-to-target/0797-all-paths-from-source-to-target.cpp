class Solution {
public:
    void dfs(int node,vector<vector<int>>graph,vector<int>& picker,vector<vector<int>>& ans){
        picker.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(picker);
        }
        for(auto n : graph[node])
            dfs(n,graph,picker,ans);
        picker.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>picker;
        vector<vector<int>>ans;
        dfs(0,graph,picker,ans);
        return ans;
    }
};