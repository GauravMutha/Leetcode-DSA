class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ldistmax=0,rdistmax=0;
        
        if(left.size()) ldistmax=*max_element(left.begin(),left.end());  //going left
        if(right.size()) rdistmax=n-*min_element(right.begin(),right.end()); //going right
        
        return max(ldistmax,rdistmax);
    
    }
};