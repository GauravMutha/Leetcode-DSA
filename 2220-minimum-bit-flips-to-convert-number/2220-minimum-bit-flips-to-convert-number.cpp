class Solution {
public:
    int minBitFlips(int start, int goal) {
        //without bit manipulation --> TC=O(n);
        
        int steps=0;
        while(start && goal){
            if(start%2 != goal%2){
                steps++;
            }
            start/=2;
            goal/=2;
        }
        while(start){
            if(start%2){
                steps++;
            }
            start/=2;
        }
        while(goal){
            if(goal%2){
                steps++;
            }
            goal/=2;
        }
        return steps;
    }
};