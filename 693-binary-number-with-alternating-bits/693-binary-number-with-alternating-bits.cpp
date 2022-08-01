class Solution {
public:
    bool hasAlternatingBits(int n) {
        int helper=1;
        int x=(int)log2(n)+1;
        int highest=pow(2,x)-1;
        helper<<=(x-1);
        if(((n^highest)==(n>>1)) || ((n^highest)==(n<<1)))
                return true;
        return false;
    }
};