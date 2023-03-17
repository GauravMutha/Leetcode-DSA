//BFS
//Unordered set instead of reached count
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>reached;
        queue<int>q({0});
        
        while(!q.empty()){
            int room=q.front();
            q.pop() , reached.insert(room);
            for(auto adj : rooms[room]){
                /*since room adj might have keys of the already visited room
                hence the following condition avoids pushing such rooms in queue*/
                if(reached.find(adj)==reached.end())
                    q.push(adj);
            }
        }
        return (reached.size()==rooms.size());
    }
};