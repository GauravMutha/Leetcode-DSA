//DFS
class Solution {
public:
    void dfs(int room , vector<vector<int>>&rooms,vector<bool>&visited,int &reached){
        reached++;
        visited[room]=true;
        for(auto adj : rooms[room]){
            if(!visited[adj])
                dfs(adj,rooms,visited,reached);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size());
        int reached=0;
        dfs(0,rooms,visited,reached);
        return (reached==rooms.size());
    }
};