class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        
        for(int i=1;i<=n;i++) q.push(i); //queue of n players
        
        while(q.size()!=1){
            int x=(k-1)%q.size();
            
            while(x){
                int temp=q.front();
                q.pop();
                q.push(temp);
                x--;
            }
            q.pop();
        }
        
        return q.front();
    }
};

//USing Queue
//SC--> O(n)
//TC-->O(n*k)