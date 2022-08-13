class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        vector<int>freq(24,0);
        
        for(int i=0;i<n;i++){
            int x=candidates[i];
            int k=-1;
            do{
                k++;
                if(x%2)freq[k]++;
                if(freq[k]==n){return freq[k];}
                x/=2;
            }while(x);
        }
        return *max_element(freq.begin(),freq.end());
    }
};
//Tc-->O(n*logm) where:
//n is vector size and m is max possible value of vector
//SC-->O(n) 
        