//Binary search + Two pointers / expanding sliding window
//O(log(n) + k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        int R=lower_bound(begin(arr),end(arr),x)-begin(arr);
        int L=R-1;
        
        while(k--){
            if(R>=arr.size() || (L>=0 && abs(x-arr[L])<=abs(arr[R]-x)) )
                L--;
            else R++;
        }
        L++;
        return vector<int>(begin(arr)+L ,begin(arr)+R);
    }
};