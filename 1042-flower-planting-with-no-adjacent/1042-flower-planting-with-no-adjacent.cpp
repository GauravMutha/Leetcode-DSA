//NO DFS OR BFS
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>graph(n);
        vector<int>ans(n,-1);
        
        for(int i=0;i<paths.size();i++){
            int u=paths[i][0] , v=paths[i][1];
            
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        for(int i=0;i<n;i++){
            bool available[5]={false};
            int flowerType=1;
            for(auto &adjNode: graph[i]){
                if(ans[adjNode]!=-1) 
                    available[ans[adjNode]]=true;
            }
            for(int i=1;i<5;i++){
                if(available[i]==true) continue;
                flowerType=i;
                break;
            }
            ans[i]=flowerType;
        }
        
        return ans;
    }
};