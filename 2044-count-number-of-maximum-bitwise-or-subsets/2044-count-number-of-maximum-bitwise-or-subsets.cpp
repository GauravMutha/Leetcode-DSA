class Solution {
public:
    int res=0,maxi=INT_MIN;
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int>ds;
        calc(nums,ds,0);
        return res+1;
    }
    void calc(vector<int>&nums,vector<int>&ds,int ind){
        int x=0;
        if(ind==nums.size()){
            if(ds.size()==0)
                return;
            else if(ds.size()==1)
                x=ds[0];
            else {
                x=ds[0];
                for(int i=1;i<ds.size();i++)
                    x|=ds[i];
            }
            checker(x);
            return;
        }
        ds.push_back(nums[ind]);
        calc(nums,ds,ind+1);
        ds.pop_back();
        calc(nums,ds,ind+1);
    }
    
    void checker(int x){
        if(x>maxi){res=0; maxi=x;}
        else if(x<maxi)return;
        else if(x==maxi)res++;
        return;
    }
};