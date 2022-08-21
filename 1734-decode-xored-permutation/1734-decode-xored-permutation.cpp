class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
       int n=encoded.size(),val1=encoded[0],val2=0,first=0;
       vector<int>temp(n,0),res(n+1,0);
       temp[0]=encoded[0];
        
       for(int i=1;i<n;i++){
           temp[i]=temp[i-1]^encoded[i];
           val1^=temp[i];
       }
       for(int i=1;i<=n+1;i++){
           val2^=i;
       }
       res[0]=(val1^val2); 
       for(int i=0;i<n;i++){
           res[i+1]=res[i]^encoded[i];
       }
        return res;
    }


};