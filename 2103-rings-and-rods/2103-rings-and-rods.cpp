class Solution {
public:
    int countPoints(string rings) {
        vector<int>vec(10,0);
        int rod=0,count=0;
        for(int i=1;i<rings.size();i+=2){
            rod=rings[i]-'0';
            if(vec[rod]==7)continue;
            if(rings[i-1]=='R'){
                vec[rod]|=1;
            }
            else if(rings[i-1]=='G'){
                vec[rod]|=2;
            }
            else if(rings[i-1]=='B'){
                vec[rod]|=4;
            }
            
            if(vec[rod]==7)count++;
        }
        
        return count;
    }
};