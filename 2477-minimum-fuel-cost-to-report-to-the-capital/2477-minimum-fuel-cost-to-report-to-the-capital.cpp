//DFS
class Solution {
private:
    long long ans=0;
public:
    int dfs(int parentCity,int currCity,int seats,vector<vector<int>>& network){
        int people=1;
        for(auto adjacentCity: network[currCity]){
            if(adjacentCity==parentCity) continue;
            people+=dfs(currCity,adjacentCity,seats,network);
        }
        if(currCity!=0)
            ans+= ceil((double)people/seats);
        
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        //making adjacency list
         vector<vector<int>>network(roads.size()+1);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            
            network[u].push_back(v);
            network[v].push_back(u);
        }
        
        dfs(-1,0,seats,network);
        
        return ans;
    }
};