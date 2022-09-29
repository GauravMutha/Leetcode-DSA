class Solution {
public:
    int convertTime(string current, string correct) {
        int minute= ( stoi(correct.substr(0,2)) - stoi(current.substr(0,2)) )*60 + stoi(correct.substr(3))-stoi(current.substr(3));
        int factor[4]={60,15,5,1},count=0;
        for(int x : factor){
            count+=(minute/x);
            minute%=x;
        }
        
        return count;
    }
};