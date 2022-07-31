class Solution {
public:
    int bitwiseComplement(int n) {
        int helper=(n>0)?pow(2,(int)(log2(n)+1))-1:1;
        return n^helper;
    }
};