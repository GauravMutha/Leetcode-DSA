typedef pair<int,string> psi;
class myComparator {
  public:
    bool operator() (const psi &p1, const psi &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      
      return p1.first > p2.first;
}
};
class Solution {
    
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
  int n = words.size();

  /* First we will find the frequency of all the strings then we will keep track of the top k frequent strings with the help of priority queue */

  unordered_map<string, int> freq;

  for(string word : words) {
    freq[word]++;
  }

  priority_queue<psi, vector<psi>, myComparator> pq;
  /* Since here we want to order the elements in a different way we will write our own custom comparator function */
  /* For defining our own comparator function we would have to declare it in the class as done above */

  for(auto it : freq) {
    pq.push({it.second, it.first});

    if(pq.size() > k) {
      pq.pop();
    }
  }

  /* Now at this point the priority queue will contain the top k frequent elements or strings of the set */

  /* Since, we know that we want to find the top k frequent strings hence we can directly declare the size of the answer vector 
  and while psing we will get the strings in ascending order of the frequency hence we will put the strings from back side 
  so that we don't have to do an extra work to reverse the vector before returning  */
  vector<string> ans(k);
  int m = k-1;

  while(pq.size() > 0) {
    ans[m--] = pq.top().second;
    pq.pop();
  }

  return ans;
}
};