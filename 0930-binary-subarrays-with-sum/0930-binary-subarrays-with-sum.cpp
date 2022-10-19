class Solution {
public:
    int helper(vector<int>arr){
        int count=0,res=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                count++;
                res+=count;
            }
            else count=0;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& arr, int t) {
        //In case t=0
        if(t==0) return helper(arr);
        int prev=-1,lo=0,hi=0,sum=0,count=0;
        //dealing with cases like t>0 but S=[0,0,0,0,0] for example
        while(lo<arr.size() && arr[lo]==0)
            lo++,hi++;
        while(hi<arr.size()){
            if(sum+arr[hi]==t){
                sum+=arr[hi];
                hi++;
                count+=1+(lo-prev-1);
            }
            else if(sum + arr[hi]<t){
                sum+=arr[hi];
                hi++;
            }
            else {
                sum-=arr[lo];
                prev=lo;
                lo++;
                while(arr[lo]==0) lo++;
            }
        }
        return count;
    }
};

//TWO POINTERS