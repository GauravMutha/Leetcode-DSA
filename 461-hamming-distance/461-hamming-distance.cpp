class Solution {
public:
    int hammingDistance(int x, int y) {
        int num=x^y;
        int count=0;
        for(int i=0;i<log2(num)+1;i++){
            int helper=1;
            helper<<=i;
            if(num&helper)count++;
        }
        return count;
    }
};