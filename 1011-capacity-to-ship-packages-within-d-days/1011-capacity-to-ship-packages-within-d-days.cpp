//Binary Search 
//BS on sum concept
//TC-->O(N*logN)
class Solution {
private:
    bool analyseCapacity(vector<int>& weights,int cap,int days){
        int sum=0,shifts=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>cap){
                shifts++;
                sum=weights[i];
            }
        }
        shifts+=1;
        if(shifts<=days) return true;
        return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lowest=*max_element(begin(weights),end(weights));
        int highest=accumulate(begin(weights),end(weights),0);
        int midCap=0 , leastCapacity=0;
        while(lowest<=highest){
            midCap= lowest+(highest-lowest)/2;
            if(analyseCapacity(weights,midCap,days)){
                leastCapacity=midCap;
                highest=midCap-1;
            }
            else lowest=midCap+1;
        }
        
        return leastCapacity;
    }
};