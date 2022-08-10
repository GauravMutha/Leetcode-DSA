class Solution {
public:
    int sum=0;
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>ds;
        
        calc(nums,ds,0);
        return sum;
    }
    void calc(vector<int>&nums,vector<int>&ds,int ind){
        int x=0;
        if(ind==nums.size()){
            if(ds.size()==0){
                return; 
            }
            else if(ds.size()==1){
                x=ds[0];
            }
            else{
                x=ds[0];
                for(int i=1;i<ds.size();i++){
                    x^=ds[i];
                }
            }
            sum+=x;
            return;
        }
        ds.push_back(nums[ind]);
        calc(nums,ds,ind+1);
        ds.pop_back();
        calc(nums,ds,ind+1);    
    }
};