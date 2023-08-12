class Solution {
public:
    void helper(int num,int digSz,int n,int k,vector<int>& res){
        if(n==digSz){
            res.push_back(num);
            return;
        }
        
        for(int i=0;i<=9;i++){
            
            if(digSz==0 && i==0) continue;
            if(digSz==0 || abs((num%10)-i)==k){
                
                num*=10;
                num+=i;
                digSz++;
                
                helper(num,digSz,n,k,res);
                
                num/=10;
                digSz--;
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        helper(0,0,n,k,res);
        return res;
    }
};