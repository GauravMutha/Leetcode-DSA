class Solution {
public:
    int countTriplets(vector<int>& arr) {
        //TC --->O(n^3) SC--->O(n)
        //This method uses prefix array/vector to store and access xor of subarray pairs
        int n=arr.size(),count=0;
        vector<int>prexor(n);
        prexor[0]=arr[0];
        for(int i=1;i<n;i++){
            prexor[i]=prexor[i-1]^arr[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j;k<n;k++){
                    if((prexor[i]^arr[i]^prexor[j-1])==(prexor[k]^prexor[j]^arr[j]))count++;
                }
            }
        }
        return count;
    }
};