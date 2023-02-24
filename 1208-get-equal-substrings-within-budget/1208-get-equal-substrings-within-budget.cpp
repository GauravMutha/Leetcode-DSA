//Binary search
class Solution {
private :
    vector<int>prefixCost;
    int binarySearch(string &s,string &t,int i,int maxCost){
        int low=i,high=s.size()-1,totalCost=0,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            totalCost=(i>0)?prefixCost[mid]-prefixCost[i-1]:prefixCost[mid];
            if(totalCost>maxCost) high=mid-1;
            else ans=mid , low=mid+1;
        }
        return ans;
    }
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost=0,maxLen=0,n=s.size();
        for(int i=0;i<n;i++){
            cost+=abs(s[i]-t[i]);
            prefixCost.push_back(cost);
        }
        for(int i=0;i<n;i++){
            int j=binarySearch(s,t,i,maxCost);
            if(j!=-1)maxLen=max(maxLen,j-i+1);
        }
        
        return maxLen;
    }
};