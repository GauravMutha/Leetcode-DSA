class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size(), majorElement=nums[0],count=1;
        unordered_map<int,int>freq,liveFreq;
        vector<int>candidates;
        
        candidates.push_back(majorElement);
        freq[nums[0]]++;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]==majorElement) count++;
            else count--;
            
            if(count==0) majorElement=nums[i] , count=1;
            candidates.push_back(majorElement);
            freq[nums[i]]++;
        }
        
        for(int i=0;i<n;i++){
            liveFreq[nums[i]]++;
            int c=candidates[i];
            int leftFreq=liveFreq[c] , rightFreq=freq[c]-liveFreq[c];
            
            if(leftFreq>(i+1)/2 && rightFreq>(n-i-1)/2) return i;
        }
        
        return -1;
    }
};