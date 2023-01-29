//Priority Queue + Comparator
typedef  pair<int,int> p;

class comp{
public:
    bool operator()(const p &above ,const  p &below){
        int aLast=above.second,aFirst= above.first;
        int bLast=below.second,bFirst= below.first;
        if(aLast==bLast){
            int sz1=aLast-aFirst +1;
            int sz2=bLast-bFirst +1;
                
            return sz1>sz2;
        }
            
        return aLast>bLast;
    }
};
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<p,vector<p>,comp>minh;
        
        for(auto &num : nums){
            //#1
            while(minh.size()>0 && (minh.top().second +1) <num){
                int fir=minh.top().first,last=minh.top().second;
                minh.pop();
                if((last-fir+1) < 3) return false;
            }
            //#2 insert a new sequence in pq starting from num if either of the                   following condition are true
            if(minh.size()==0 || minh.top().second==num)
                minh.push({num,num});
            //#3the num is one more than pq's topmost sequence's last insert it into               that topmost sequence
            else {
                int fir = minh.top().first , last=minh.top().second;
                minh.pop();
                minh.push({fir,num}); // or pq.push({first,last+1});
            }
        }
        
        //#4 last check to see if any remaining seq in minh has size less than 3
        while(!minh.empty()){
            int fir=minh.top().first , last=minh.top().second;
            minh.pop();
            if((last-fir+1) <3) return false;
        }
        
        return true;
    }
};


//#1 --->//while difference between the last number of topmost sequence and the num is either greater than 1 then keep popping as the numbers in nums further are even greater  so the top most sequence cannot be extended.//while doing this if any of the popped sequence size is less than 3 then simply return false as that sequence could not be made longer and was less than 3