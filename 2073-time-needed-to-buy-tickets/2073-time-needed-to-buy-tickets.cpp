class Solution {
public:
    int timeRequiredToBuy(vector<int>& tkt, int k) {
        int time=0;
        for(int i=0;i<tkt.size();i++){
            if(i<=k) time+=min(tkt[i],tkt[k]);
            else time+=min(tkt[i],tkt[k]-1);
        }
        
        return time;
    }
};

//TC-->O(n)
//SC-->O(1)