class FrontMiddleBackQueue {
public:
    class Node{
        public:
        Node *next;
        int val;
        Node(){};
        Node(int x){
            this->val=x;
            this->next=NULL;
        }
    };
    
    Node *front , middle , *back;
    int count=0;
    
    FrontMiddleBackQueue() {
        this->front=NULL;
        this->back=NULL;
        this->count=0;
        this->middle=NULL;
    }
    
    void pushFront(int val) {
        if(this->count==0){
            this->front=new Node(val);
            this->back=this->front;
        }
        else {
            auto temp=new Node(val);
            temp->next=this->front;
            this->front=temp;
        }
        
        this->count+=1;
    }
    
    void pushMiddle(int val) {
        if(this->count==1 || this->count==0)
            pushFront(val);
        else{
            int x=this->count/2-1;
            Node *p=this->front;
            while(p!=NULL && x--)
                p=p->next;
            auto temp=new Node(val);
            temp->next=p->next;
            p->next=temp;
            this->count+=1;
        }
    }
    
    void pushBack(int val) {
        if(this->count==0){
            this->pushFront(val);
        }
        else {
            auto temp=new Node(val);
            this->back->next=temp;
            this->back=temp;
            this->count+=1;
        }
    }
    
    int popFront() {
        if(this->count==0)
            return -1;
        Node *temp=this->front;
        if(this->front==this->back) this->back=temp->next;
        this->front=temp->next;
        int x=temp->val;
        delete temp;
        this->count-=1;
        return x;
    }
    
    int popMiddle() {
        if(this->count == 0) return -1;
        Node *pre = NULL;
        Node *ahead = front;
        int x=(this->count-1)/2;
        while(x--){
          pre = ahead;
          ahead = ahead->next;
        }
        int midVal = ahead->val;
        if(pre == NULL) front = ahead->next;
        else pre->next = ahead->next;
        ahead->next = NULL;
        delete ahead;
        this->count -= 1;
        return midVal;
    }
    
    int popBack() {
        if(this->count==0) return -1;
        Node dummy(-1),*curr;
        dummy.next=this->front;
        curr=&dummy;
        while(curr->next!=this->back) curr=curr->next;
        int x=back->val;
        back=curr;
        curr=curr->next;
        if(curr==this->front) this->front=NULL,this->back=NULL;
        else back->next=NULL;
        delete curr;
        this->count-=1;
        return x;
    }
};

//Using Linked List

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */