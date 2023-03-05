class Solution {
public:
    int minimumSum(int num) {
        vector<int>dig;
        while(num){
            dig.push_back(num%10);
            num/=10;
        }
        sort(dig.begin(),dig.end());
        int num1=dig[0]*10+dig[3];
        int num2=dig[1]*10+dig[2];
        
        return (num1+num2);
    }
};