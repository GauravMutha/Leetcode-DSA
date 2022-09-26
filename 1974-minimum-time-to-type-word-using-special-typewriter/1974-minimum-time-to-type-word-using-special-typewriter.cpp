class Solution {
public:
    int minTimeToType(string word) {
        int time=0,clock,anticlock;
        char curr='a';
        
        for(auto des : word){
            clock = abs(curr-des);
            anticlock= 26 - abs(curr-des);
            
            time+=(min(clock,anticlock) + 1);
            
            curr=des;
        }
        
        return time;
    }
};