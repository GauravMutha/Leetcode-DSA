class Solution {
public:
    int i=0;
    int xorOperation(int n, int start){
        if(i==n-1){return start;}
        i++;
        return start^xorOperation(n,start+2);
    }
};