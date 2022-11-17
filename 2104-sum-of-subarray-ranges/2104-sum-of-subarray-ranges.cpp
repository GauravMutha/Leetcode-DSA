class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0; 
        int n=nums.size();
        stack<int>st;
        vector<int> sl(n,-1) , sr(n,n), gl(n,-1) , gr(n,n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()) sl[i]=st.top();
            st.push(i);
        } 
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            if(!st.empty()) sr[i]=st.top();
            st.push(i);
        }        
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty()) gl[i]=st.top();
            st.push(i);
        } 
        while(!st.empty()) st.pop();        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(!st.empty()) gr[i]=st.top();
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            long long leftMin=i-sl[i] , rightMin=sr[i]-i;
            long long leftMax=i-gl[i] , rightMax=gr[i]-i;
            sum+=((leftMax*rightMax)-(leftMin*rightMin))*nums[i];
        }
        return sum;
    }
};
//5 pass
//TC-->O(n)
//SC-->O(1)