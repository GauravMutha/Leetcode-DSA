class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        while(tickets[k]){
            for(int i=0;i<tickets.size();i++){
                if(tickets[i]==0) continue;
                tickets[i]--;
                time++;
                
                if(tickets[k]==0) return time;
            }
        }
        
        return time;
    }
};

//TC-->O(m*n)
//SC-->O(1)