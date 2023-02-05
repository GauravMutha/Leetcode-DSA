//without priority queue and queue
//here instead of using mao to map sum values we make explicitly an array whose inices are all the possible sum of digits in this question
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int res=-1,arr[82]={},num=0,sumOfDig=0;
        
        for(auto num : nums){
            sumOfDig=0;
            for(int n=num; n!=0 ;n/=10) sumOfDig+=(n%10);
            
            if(arr[sumOfDig])res=max(num+arr[sumOfDig],res);
            
            arr[sumOfDig]=max(num,arr[sumOfDig]);
        }
        
        return res;
    }
};