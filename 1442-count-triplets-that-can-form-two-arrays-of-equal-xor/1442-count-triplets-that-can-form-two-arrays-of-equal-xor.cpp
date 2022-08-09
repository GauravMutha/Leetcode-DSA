class Solution {
public:
    int countTriplets(vector<int>& arr) {
        //TC --->O(n^2) SC--->O(1)
        //This method DO NOT use prefix array/vector ,instead it does "on the spot" xor calculation
        int n=arr.size(),count=0;
        for(int i=0;i<n;i++){
            int subarrxor=arr[i];
            for(int k=i+1;k<n;k++){
                subarrxor^=arr[k];
                if(subarrxor==0)count+=(k-i);
            }
        }
        return count;
    }
};