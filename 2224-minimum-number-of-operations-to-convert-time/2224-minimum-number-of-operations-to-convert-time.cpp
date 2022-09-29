class Solution {
public:
    int convertTime(string current, string correct) {
        int minute= ( stoi(correct.substr(0,2)) - stoi(current.substr(0,2)) )*60 + stoi(correct.substr(3))-stoi(current.substr(3));
        int x[4]={60,15,5,1};
        int count=0,i=0;
        while(minute){
            count+=(minute/x[i]);
            minute%=x[i];
            i++;
        }
        
        return count;
    }
};