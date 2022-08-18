class Solution {
public:
vector<int> circularPermutation(int n, int start) {
        vector<int>res;
        vector<int>gc;
        int value,i=0,j=0;
        int x=pow(2,n);
        for(int j=0;j<x;j++){
            gc.push_back((j^(j>>1)));
            if((j^(j>>1))==start)
                value=j;
        }
        i=value;
        do{
            res.push_back(gc[i%x]);
            i++;
            j++;
        }while(j<x);
        return res;
    } 
};