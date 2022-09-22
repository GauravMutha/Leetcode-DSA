class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto str:operations){
            if(str[1]=='+')
                x++;
            else
                x--;
        }
        return x;
    }
};