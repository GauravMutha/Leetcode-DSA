//BFS
//uses reached count just like dfs approach
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int reached=0;
        vector<bool>visited(rooms.size());
        queue<int>q({0});
        
        while(!q.empty()){
            int room=q.front();
            if(visited[room]==false) reached++;
            q.pop(), visited[room]=true;
            for(auto adj : rooms[room]){
                if(visited[adj]==false)
                    q.push(adj);
            }
        }
        return (reached==rooms.size());
    }
};