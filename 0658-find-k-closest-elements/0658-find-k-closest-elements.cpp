//Two pointers / shrinking sliding window
//O(n)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        int l=0,r=arr.size()-1;
        while((r-l+1)>k){
            if(abs(x-arr[l])<=abs(x-arr[r])) r--;
            else l++;
        }
        for(int i=l;i<=r;i++)
            res.push_back(arr[i]);
        
        return res;
    }
};