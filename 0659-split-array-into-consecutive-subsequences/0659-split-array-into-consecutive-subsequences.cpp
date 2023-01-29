//2 Map
//No PQ
//TC--> O(n) 
//SC-->O(1)
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>hash;
        unordered_map<int,int>ready;
        
        for(auto &num : nums) hash[num]++;
        
        for(auto  &x : nums){
            if(hash[x]==0) continue;
            
            if(ready[x-1]>0){
                hash[x]--;
                ready[x-1]--;
                ready[x]++;
            }
            else{
                if(hash[x+1]==0 || hash[x+2]==0) return false;
                hash[x]-- , hash[x+1]-- , hash[x+2]--;
                ready[x+2]++;
            }
        }
        
        return true;
    }
};