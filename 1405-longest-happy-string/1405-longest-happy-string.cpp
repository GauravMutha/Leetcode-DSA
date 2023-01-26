//Priority Queue --> max heap
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res="";
        priority_queue<pair<int,char>>maxh;
        
        int A[]={a,b,c};
        for(int i=0;i<3;i++) if(A[i]) maxh.push({A[i],i+'a'});
        
        char prev1='#',prev2='#';
        while(!maxh.empty()){
            auto [cnt1,c1]=maxh.top(); maxh.pop();
            if(prev1==c1 && prev2==c1){
                if(maxh.empty()) return res;
                auto [cnt2,c2]=maxh.top(); maxh.pop();
                res.push_back(c2);
                prev1 = prev2;
                prev2 = c2;
                maxh.push({ cnt1, c1 });
                cnt2--;
                if(cnt2>0) maxh.push({cnt2,c2});
            }
            else{
                prev1=prev2;
                prev2=c1;
                res.push_back(c1);
                cnt1--;
                if(cnt1>0) maxh.push({cnt1,c1});
            }
        }
        
        return res;
    }
};