//Priority Queue
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>maxh;
        int num1,num2,score=0;
        
        maxh.push(a) , maxh.push(b) , maxh.push(c);
        
        num1=maxh.top() , maxh.pop();
        num2=maxh.top() , maxh.pop();
        
        while(num1!=0 && num2!=0) {
            score++;
            num1-- , num2--;
            
            maxh.push(num1) , maxh.push(num2);
            num1=maxh.top() , maxh.pop();
            num2=maxh.top() , maxh.pop();
        }
        
        return score;
    }
};