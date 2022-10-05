class Solution {
public:
    string thousandSeparator(int n) {
        string temp=to_string(n);
        
        if(temp.size()<4) return temp;
        
        int sz1=temp.size(),sz2=sz1+(sz1-1)/3,i=sz1-1,j=sz2-1,count=0;
        string res(sz2,'.');
        while(i>=0){
            if(count==3){
                count=0;
                j--;
                continue;
            }
            res[j--]=temp[i--] , count++;
        }
        return res;
    }
};