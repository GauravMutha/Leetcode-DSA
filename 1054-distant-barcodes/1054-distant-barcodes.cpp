//Priority Queue maxheap
//Same as 767.Reorganize string
typedef pair<int,int>p;
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int>res;
        unordered_map<int,int>m;
        priority_queue<p>maxh;
        int prev=-1;
        
        //Codes and their frequence are stored
        for(auto &code : barcodes) m[code]++;
        //Stored in maxheap
        for(auto &[num,freq] :m) maxh.push({freq,num});
        
        while(!maxh.empty()){
            auto [cnt1,num1] = maxh.top();
            maxh.pop();
            if(prev==num1){
                auto [cnt2,num2]=maxh.top();
                maxh.pop();
                res.push_back(num2);
                prev=num2;
                
                cnt2--;
                if(cnt2>0) maxh.push({cnt2,num2});
                maxh.push({cnt1,num1});
            }
            else{
                res.push_back(num1);
                prev=num1;
                cnt1--;
                if(cnt1>0) maxh.push({cnt1,num1});
            }
        }
        return res;
    }
};