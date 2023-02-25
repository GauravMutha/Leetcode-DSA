//preifix and suffix
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int LC,RC,sz=s.size(),preIndx=-1,suffIndx=sz,q=queries.size(),pCount=0;
        vector<int>res(q),rMost(sz),lMost(sz),prePlate(sz);
        
        for(int i=0,j=sz-1;i<sz && j>=0;i++,j--){
            if(s[i]=='|') preIndx=i;
            else pCount++;
            if(s[j]=='|') suffIndx=j; 
            rMost[i]=preIndx;
            lMost[j]=suffIndx;
            prePlate[i]=pCount;
        }
        
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0], end=queries[i][1];
            RC=rMost[end] , LC=lMost[start];
            if(RC<start || LC>end || (RC==LC)) res[i]=0;
            else res[i]=(LC==0)?prePlate[RC]:prePlate[RC]-prePlate[LC-1];
        }
        
        return res;
    }
};