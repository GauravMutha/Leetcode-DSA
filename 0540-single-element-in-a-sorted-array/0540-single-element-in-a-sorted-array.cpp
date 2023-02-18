//Binary search O(log(n))
class Solution {
public:
    int singleNonDuplicate(vector<int>& n) {
        int start=0,end=n.size()-1;
        
        while(start<end){
            int mid = start+ (end-start)/2;
            
            if(mid>=0 && mid<n.size() && n[mid]!=n[mid-1] && n[mid]!=n[mid+1])
                return n[mid];
            
            int k=(n[mid]==n[mid-1])?mid:mid+1;
            
            if(k%2==0) end=k-2;
            else start=k+1;
        }
        
        return n[start];
    }
};