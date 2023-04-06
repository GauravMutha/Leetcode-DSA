//Sort STL using comparator
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int res=INT_MIN,sum=0,n=vals.size();
        vector<vector<int>>graph(n);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0] , v=edges[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        auto comp = [&](const int& a, const int& b) {
            return vals[a]>vals[b];
        };
        for(int i=0;i<n;i++){
            sum=vals[i];
            sort(graph[i].begin(), graph[i].end(),comp);
            for(int j=0;j<min(int(graph[i].size()),k);j++)
                sum=max(sum,sum+vals[graph[i][j]]);
            
            res=max(res,sum);
        }
        
        return res;
    }
};