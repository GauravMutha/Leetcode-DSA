class Solution {
private:
    bool validSpeed(vector<int>&piles,int speed ,int h){
        long timeTaken=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<speed) timeTaken+=1;
            else if((piles[i]%speed)==0) timeTaken+=(piles[i]/speed);
            else if(piles[i]%speed) timeTaken+=(piles[i]/speed)+1;
        }
        return timeTaken<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=*max_element(begin(piles),end(piles)),ans=high;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(validSpeed(piles,mid,h)) ans=mid , high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
};