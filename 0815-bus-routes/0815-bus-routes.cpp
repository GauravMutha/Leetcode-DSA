class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        unordered_map<int,vector<int>>stop2route;//stop->circle(or route) no.
        queue<pair<int,int>>q; //{stop,bus number}
        unordered_map<int,bool>vis;
        
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                stop2route[routes[i][j]].push_back(i);
            }
        }
        
        q.push({source,0});
        vis[source]=true;
        
        while(q.size()){
            int stop=q.front().first , busNumber=q.front().second;
            q.pop();
            if(stop==target) return busNumber;
            for(auto r : stop2route[stop]){
                for(auto stops : routes[r]){
                    if(vis[stops]==true) continue;
                    vis[stops]=true;
                    q.push({stops,busNumber+1});
                }
                routes[r].clear();
            }
        }
        return -1;
    }
};