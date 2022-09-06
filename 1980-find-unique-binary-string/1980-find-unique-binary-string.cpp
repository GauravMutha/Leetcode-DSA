class Solution {
public:
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string test;
        for(int i=0;i<pow(2,n);i++){
            test=bitset<16>(i).to_string();
            test=test.substr(16-n,n);
            if(std::find(nums.begin(),nums.end(),test)==nums.end())break;
        }
            return test;
    }
};

//Logic-->Converting all the possible n bit numbers into string and then
//checking if its present in nums vector

//TC-->n*2^n
//SC-->1