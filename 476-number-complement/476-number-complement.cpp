class Solution {
public:
    int findComplement(int num) {
        for(int i=0;i<log2(num)+1;i++){
            int helper=1;
            helper<<=i;
            if(helper&num){num&=~(1<<i);}
            else{num|=helper;}
        }
        return num;
    }
};