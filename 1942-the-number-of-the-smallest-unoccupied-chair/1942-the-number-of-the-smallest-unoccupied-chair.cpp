//using set and priortiy queue min heap
typedef pair<int,int>p;
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<p,vector<p>,greater<p>>minh;
        set<int>vacant;
        int series=0,arrivalTime=0,leaveTime=0 ,chair=0;
        
        int targetArrival=times[targetFriend][0];
        sort(begin(times),end(times));
        
        for(auto vec : times){
            arrivalTime=vec[0];
            leaveTime=vec[1];
            chair=0;
            
            while(!minh.empty() && minh.top().first<=arrivalTime){
                vacant.insert(minh.top().second);
                minh.pop();
            }
            
            if(vacant.size()){
                chair=*(vacant.begin());
                vacant.erase(vacant.begin());
            }
            else{
                chair=series;
                series++;
            }
            minh.push({leaveTime,chair});
            if(targetArrival==arrivalTime) return chair;
        }
        
        return 0;
    }
};