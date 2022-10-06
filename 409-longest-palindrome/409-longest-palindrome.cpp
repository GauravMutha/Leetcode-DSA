class Solution {
public:
    int longestPalindrome(string s) {
        int odds=0;
        for(char c ='A';c<='z';c++)
            odds+=count(begin(s),end(s),c) & 1;
        return s.size()-odds + (odds>0);
    }
};

//FD
//Better Code , O(128n) ~ O(n) TC , SC is O(1) and this is the improvement.