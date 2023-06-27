class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        vector<int>res;
        stack<int>st;
        
        for(int i=nums2.size()-1;i>=0;i--){
            while(st.size() && st.top()<nums2[i])st.pop();
            if(st.empty()) m[nums2[i]]=-1;
            else m[nums2[i]]=st.top();
            
            st.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++) res.push_back(m[nums1[i]]);
        
        return res;
    }
};