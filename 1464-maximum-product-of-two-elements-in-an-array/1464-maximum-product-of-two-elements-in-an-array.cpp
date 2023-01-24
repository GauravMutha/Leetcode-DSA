//TC-->O(N)
//SC-->O(1)
//No priority queue
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal1=-1, maxVal2=-1;
        
        for(auto n : nums){
            if(n>maxVal1) maxVal2=maxVal1 , maxVal1=n;
            else if(n>maxVal2) maxVal2=n;
        }
        return (maxVal1-1)*(maxVal2-1);
    }
};