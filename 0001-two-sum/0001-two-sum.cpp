//sorting - binary search
class Solution {
public:
    int binarySearch(int i,long target, vector<pair<int,int>>& vec){
        int start=i+1,end=vec.size()-1,mid=0;
        while(start<=end){
            mid=start+(end-start)/2;
            if((long)vec[mid].first==target) return vec[mid].second;
            else if((long)vec[mid].first>target) end=mid-1; 
            else if((long)vec[mid].first<target) start=mid+1; 
        }
        
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();i++)
            vec.push_back({nums[i],i});
        
        sort(vec.begin(),vec.end());
        
        for(int i=0;i<vec.size();i++){
            int j=binarySearch(i,target-vec[i].first,vec);
            if(j!=-1) return vector<int>({vec[i].second,j});
        }
        
        return {};
    }
};