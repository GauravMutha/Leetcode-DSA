class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        uint32_t k=n;
        for(int i=0;i<log2(k)+1;i++){
            if(n%2==0){n/=2;continue;}
            else{count++;n/=2;}
        }
        return count;
    }
};