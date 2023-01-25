//MATH
//O(1) TC
//O(1) SC
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int largest=max({a,b,c});
        int sumOfSmallestTwo=(a+b+c)- largest;
        
        return (sumOfSmallestTwo<=largest) ? sumOfSmallestTwo : (a+b+c)/2;
    }
};