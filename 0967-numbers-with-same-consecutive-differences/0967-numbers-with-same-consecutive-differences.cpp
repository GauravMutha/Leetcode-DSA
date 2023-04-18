//bfs using queue
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        queue<int>q;
        for(int i=1;i<=9;i++) q.push(i);
        n--;
        while(n--){
            int qSz=q.size();
            for(int i=0;i<qSz;i++){
                int num=q.front();
                q.pop();
                int lastDig=num%10 , newDig=-1;
                
                if((lastDig-k)>=0){
                    newDig=lastDig-k;
                    q.push(num*10 + newDig);
                }
                /*For n-2,k=0 testcase , not
                applying k!=0 condition results
                in duplicate value insertion as
                1-0 and 1+0  both gives 1 as newDig*/
                if((lastDig+k)<=9 && k!=0){ 
                    newDig=lastDig+k;
                    q.push(num*10 + newDig);
                }
            }
        }
        
        while(!q.empty()) ans.push_back(q.front()) , q.pop();
        
        return ans;
    }
};