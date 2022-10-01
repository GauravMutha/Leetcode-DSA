class Solution {
public:
    int getsum(int num) {
       int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    
    int getLucky(string s, int k) {
        int sum=0;
        for(auto c:s){
            int val=c-'a'+1;
            sum+=(val<9)?val:(val%10+val/10);
        }
        
        while(--k && sum>9)
            sum=getsum(sum);
        return sum;
    }
};