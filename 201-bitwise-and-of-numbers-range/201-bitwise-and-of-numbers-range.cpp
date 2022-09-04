class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right)return left;
        else{
        unsigned int res=left;
        for(unsigned int i=left+1;i<=right;i++){
            res&=i;
            if(!res)break;
        }
         return res;
        }
    }
};