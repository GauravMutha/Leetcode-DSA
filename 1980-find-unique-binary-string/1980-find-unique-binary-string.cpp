//TC-->O(2^n + n^2)
//Brute force
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        int x=0;
        string ans;
        vector<bool>hash(pow(2,n));
        for(int i=0;i<nums.size();i++){
            hash[stoi(nums[i],0,2)]=true;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]==false){
                x=i;
                break;
            }
        }
        return bitset<16>(x).to_string().substr(16 - n);
    }
};