class Solution {
private:
    bool validate(vector<int>q,int maxProduct,int totalShops){
        int shopCount=0,i=0;
        while(i<q.size() && shopCount<totalShops){
            if(q[i]>maxProduct) q[i]-=maxProduct;
            else q[i]=0 , i++;
            shopCount++;
        }
        if(i<q.size()) return false;
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int low=0,high=*max_element(begin(q),end(q));
        int ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(validate(q,mid,n)) ans=mid, high=mid-1;
            else low=mid+1;
        }
        
        return ans;
    }
};