//Backtracking
//Without String
class Solution {
private:
    vector<int>ans;
public:
    void helper(int &num,int digCnt, int len,int k){
        if(digCnt==len){
            ans.push_back(num);
            return;
        }
        for(int i=0;i<=9;i++){
            if(digCnt==0 && i==0) continue;
            if(digCnt==0 || abs((num%10)-i)==k){
                num*=10;
                num+=i;
                digCnt++;
                helper(num,digCnt,len,k);
                num/=10;
                digCnt--;
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        int num=0;
        helper(num,0,n,k);
        
        return ans;
    }
};