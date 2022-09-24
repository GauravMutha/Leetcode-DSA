class Solution {
public:
    bool checkIfPangram(string sentence) {
        int h=0;
        
        for(auto c:sentence){
            h|=1<<(c-'a');
            if(h==67108863) return true;
        }
        return false;
    }
};