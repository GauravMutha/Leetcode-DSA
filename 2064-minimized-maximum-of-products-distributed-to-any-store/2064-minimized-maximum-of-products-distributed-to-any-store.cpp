//SAME AS PREVIOUS but more concise
class Solution {
private:
    bool validate(vector<int>q,int maxProduct,int totalShops){
        for(int i=0;i<q.size();i++){
            
            totalShops-=ceil((double)q[i]/maxProduct);
            
            if(totalShops<0) return false;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int low=1,high=*max_element(begin(q),end(q));
        int ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(validate(q,mid,n)) ans=mid, high=mid-1;
            else low=mid+1;
        }
        
        return ans;
    }
};