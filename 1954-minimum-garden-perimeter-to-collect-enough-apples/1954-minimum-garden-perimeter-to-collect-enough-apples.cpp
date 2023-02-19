//TESTING THE APPROAXIMATE UPPER BOUND
//THIS TIME THE HIGH IS 1e5
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long low=1 , high=100000;
        long mid=0 ,apples=0;
        long ans=0;
        while(low<=high){
            mid= low + (high-low)/2;
            apples=4*pow(mid,3)+6*pow(mid,2) +2*mid;
            if(apples>=neededApples) ans=mid , high=mid-1;
            else low=mid+1;
        }
        
        return 8*ans;
    }
};