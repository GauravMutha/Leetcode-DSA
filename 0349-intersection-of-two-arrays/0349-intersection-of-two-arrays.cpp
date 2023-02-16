//using maps
//O(m+n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        vector<int>res;
        int sz1=nums1.size() , sz2=nums2.size();
        //putting into map as per bigger array
        for(int i=0;i<max(sz1,sz2);i++){
            if(sz1>sz2)
                m[nums1[i]]++;
            else m[nums2[i]]++;
        }
        
        // checking as per smaller array
        for(int i=0;i<min(sz1,sz2);i++){
            if(sz1<sz2){
                if(m[nums1[i]]) 
                    res.push_back(nums1[i]) , m.erase(nums1[i]);
            }
            else{
                if(m[nums2[i]])
                    res.push_back(nums2[i]) , m.erase(nums2[i]);
            }
        }
        
        return res;
    }
};