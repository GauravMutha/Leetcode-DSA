class Solution {
public:
    //2 Liner
    int minFlips(int a, int b, int c) {
        int num=(a|b)^c;
        return __builtin_popcount(num)+__builtin_popcount(a&b&num);
    }
};