class Solution {
public:
    int findComplement(int num) {
        int helper=pow(2,(int)(log2(num)+1))-1;
        return num^helper;
    }
};