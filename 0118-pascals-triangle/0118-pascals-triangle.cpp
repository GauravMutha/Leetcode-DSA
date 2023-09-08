//For daily problem
//Simple iterative
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int k=1;k<=numRows;k++){
            vector<int>bag(k,1);
            for(int i=0;k>1 && (i<res.back().size()-1) ;i++){
                bag[i+1]=res.back()[i]+res.back()[i+1];
            }
            res.push_back(bag);
        }
        
        return res;
    }
};