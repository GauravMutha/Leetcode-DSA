class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int start=1 ,mid,end=x;
        while(start<=end){
            mid=start+(end-start)/2;
            long long prod =(long long)mid*mid;
            cout<<start<<" "<<mid<<" "<<end<<endl;
            if(prod == x) return mid;
            else if(prod>x) end=mid-1;
            else start=mid+1;
        }
        return end;
    }
};