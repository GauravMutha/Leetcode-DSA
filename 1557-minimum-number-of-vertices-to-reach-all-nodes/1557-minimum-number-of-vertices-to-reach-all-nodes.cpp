class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans; //counts nodes with no indegrees
        set<int>reachable,outdegrees;
        for(int i=0;i<edges.size();i++){
            reachable.insert(edges[i][1]);
            outdegrees.insert(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            if(outdegrees.count(i) && reachable.count(i)==0)
                ans.push_back(i);
        }
        return ans;
    }
};