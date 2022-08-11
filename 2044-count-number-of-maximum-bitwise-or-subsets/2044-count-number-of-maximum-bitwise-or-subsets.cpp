class Solution {
public:
    //Using Bit manipulation
    //This solution has TC---->O(n*2^n) same as last one.
    //But here we use bit manipulation so that resuces SC to O(1)
    int res=0,maxi=INT_MIN;
    int countMaxOrSubsets(vector<int>& nums) {
        calc(nums);
        return res+1;
    }
   void calc(vector<int> &nums)
{
    for (int num = 1; num < pow(2, nums.size()); num++)
    {
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (num & (1 << i))
                x |= nums[i];
        }
        checker(x);
    }
}
    
    void checker(int x){
        if(x>maxi){res=0; maxi=x;}
        else if(x<maxi)return;
        else if(x==maxi)res++;
    }
};