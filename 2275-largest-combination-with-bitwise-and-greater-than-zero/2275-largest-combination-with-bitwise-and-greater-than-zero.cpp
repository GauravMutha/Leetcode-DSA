class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res=0;
        
        for(int i=1;i<=pow(10,7);i<<=1){
            int curr=0;
            for(auto elem:candidates)
                if((elem&i)>0)curr++;
            res=max(curr,res);
        }
        return res;
    }
};
//Tc-->O(n*logm) where:
//n is vector size and m is max possible value of vector
//SC----->O(1)
        