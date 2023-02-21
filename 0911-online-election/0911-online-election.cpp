//binary search using STL upper bound on times array
class TopVotedCandidate {
    private:
    vector<int>times;
    vector<int>updateLeader;
    unordered_map<int,int>m;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times=times;
        int topVotes=-1,leader=-1;
        for(int i=0;i<persons.size();i++){
            m[persons[i]]++;
            if(m[persons[i]]>=topVotes)
                topVotes=m[persons[i]], leader=persons[i];
            
            updateLeader.push_back(leader);
        }
    }
    
    int q(int t) {
        auto it=upper_bound(begin(times),end(times),t)-begin(times);
        if(it==-1) return updateLeader.back();
        it--;
        return updateLeader[it];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */