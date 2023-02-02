//Using a set instead of priority queue
struct  inter{
    static int N;
    int l,r;
    inter(int l ,int r) : l(l) , r(r) {};
    
    int getPos() const{
        if(l==0) return 0;
        if(r==N-1) return N-1;
        return l+(r-l)/2;
    }
    int getDist() const{
        if(l==0) return r;
        else if(r==N-1) return r-l; //or  (N-1)-l
        else if(r<l) return -1;
        return (r-l)/2;
     }
    bool operator < (const inter& in) const{
        int d1=getDist() ,  d2=in.getDist();
        if(d1!=d2) return d1>d2;
        return l<in.l;
    }
};
int inter::N=0;

class ExamRoom {
private:
    set<inter>s;
    unordered_map<int,int>r2l,l2r;
public:
    ExamRoom(int N) {
        inter::N=N;
        s.clear() , l2r.clear() , r2l.clear();
        s.insert(inter(0,N-1));
        l2r[0]=N-1 , r2l[N-1]=0;
    }
    
    int seat() {
        inter curr= *s.begin();
        s.erase(s.begin());
        int pos = curr.getPos();
        
        s.insert(inter(curr.l,pos-1));
        s.insert(inter(pos+1,curr.r));
        
        l2r[curr.l]=pos-1 , r2l[pos-1]= curr.l;
        l2r[pos+1]=curr.r , r2l[curr.r]=pos+1 ;
        
        return pos;
    }
    
    void leave(int p) {
        int l=r2l[p-1] , r=l2r[p+1];
        
        s.erase(inter(l,p-1)) , s.erase(inter(p+1,r));
        s.insert(inter(l,r));
        l2r[l]=r , r2l[r]=l;
        r2l.erase(p-1) , l2r.erase(p+1);
        
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */