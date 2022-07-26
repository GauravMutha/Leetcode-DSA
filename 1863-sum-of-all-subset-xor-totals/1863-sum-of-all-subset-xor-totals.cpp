class Solution {
public:
    int sum=0;
    
    void subsets(int ind,vector<int> arr,int n,vector<int> &ds){
        int num=0;
        if(ind==n){
            if(ds.size()==0){
                return;
            }
            else if(ds.size()==1){
                num=ds[0];
            }
            else{
                num=ds[0];
                for(int i=1;i<ds.size();i++){
                    num=ds[i]^num;
                }
            }
            sum+=num;
            return;
        }
    ds.push_back(arr[ind]);
    (subsets(ind+1,arr,n,ds));
    ds.pop_back();
    (subsets(ind+1,arr,n,ds)); 
}
    int subsetXORSum(vector<int>& nums) {
        vector <int> ds;
        int n=nums.size();
        subsets(0,nums,n,ds);
       return sum;
    }

};