//Binary search O(n*log(d)) where d is our binary seacrh space = difference between maximum and minimum position in given array
class Solution {
private:
    int checkMinDistance(vector<int>&position,int minDistance,int balls){
        /*we need to check if (balls-1) position pairs can be found or not
        with in-between distance=minDistance*/
        int i=0 , j=1;
        for(int posPairs=1;posPairs<balls;posPairs++){
            while(j<position.size() && (position[j]-position[i])<minDistance)
                j++;
            if(j>=position.size()) return false;
            i=j;
        }
        return true;
    }
public:
    int maxDistance(vector<int>& position, int balls) {
        sort(position.begin(),position.end());
        
        int start=1, end=position.back()-position[0],ans=1;
        
        while(start<=end){
            //mid signifies minimum distance aspired between any two balls
            int mid=start+(end-start)/2;
            
            if(checkMinDistance(position,mid,balls)){
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        
        return ans;
    }
};