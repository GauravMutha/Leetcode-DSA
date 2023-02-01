//similar to 767.Reorganize string
//TC--> O(N)
//SC--> o(1)
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>m;
        int maxFreq=-1, maxCode=0 ,sz=barcodes.size(),ind=0;
        
        for(auto &code : barcodes){
            m[code]++;
            if(m[code]>=maxFreq){
                maxFreq=m[code];
                maxCode=code;
            }
        }
        while(maxFreq>0){
            barcodes[ind]=maxCode;
            ind+=2;
            maxFreq--;
        }
        m.erase(maxCode);
        for(auto &[code,freq]:m){
            while(freq>0){
                if(ind>=sz) ind=1;
                barcodes[ind]=code;
                ind+=2;
                freq--;
            }
        }
        
        return barcodes;
    }
};