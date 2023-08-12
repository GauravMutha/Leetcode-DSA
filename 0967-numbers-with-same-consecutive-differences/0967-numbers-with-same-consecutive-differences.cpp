class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int>q;
        for(int i=1;i<=9;i++) q.push(i);
        n--;
        while(n--){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                
                int num=q.front();
                q.pop();
                int lastDig=num%10 , x1=0,x2=0;
                
                if((lastDig+k)<10) x1=num*10+lastDig+k,q.push(x1);
                if((lastDig-k)>=0){
                    x2=num*10+lastDig-k;
                    if(x1!=x2) q.push(x2);
                }
                
            }
        }
        vector<int>res;
        while(q.size()) res.push_back(q.front()) , q.pop();
        
        return res;
    }
};