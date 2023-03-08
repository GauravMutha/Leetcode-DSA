//Counting Sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int minVal=*min_element(begin(nums),end(nums));
        int maxVal=*max_element(begin(nums),end(nums));
        vector<int>freq(maxVal-minVal+1,0);
        
        for(int i=0;i<n;i++){
            freq[nums[i]-minVal]++;
        }
        int j=0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0) continue;
            int x=freq[i];
            while(x--) nums[j++]=i+minVal;
        }
        return nums;
    }
};