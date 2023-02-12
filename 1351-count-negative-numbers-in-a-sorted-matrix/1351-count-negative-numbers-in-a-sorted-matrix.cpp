//Binary search
//O(m*logn)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res=0;
        for(auto vec : grid){
            auto ind=lower_bound(rbegin(vec),rend(vec),0)-vec.rbegin();
            res+=ind;
        }
        return res;
    }
};