class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start==goal)return 0;
        int temp=start^goal;
        int steps=0;
        for(int i=0;i<log2(temp)+1;i++){
            if((temp&(1<<i))!=0)steps++;
        }
        return steps;
    }
};