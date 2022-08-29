class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>S;
        vector<int>empty;
        vector<vector<int>>res;
        S.insert(empty);
        for(int val=0;val<(1<<(nums.size()));val++){
            vector<int>vect;
            for(int i=0;i<nums.size();i++){
                if(val&(1<<i))vect.push_back(nums[i]);
            }
            if(vect.size()!=0)S.insert(vect);
        }
        res.assign(S.begin(),S.end());
        return res;
    }
};