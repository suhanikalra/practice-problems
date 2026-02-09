class SmallestInfiniteSet {
public:
set<int>pq;

    SmallestInfiniteSet() {
           for(int i=1;i<=1000;i++)pq.insert(i);
    }
    
    
    int popSmallest() {
        if(pq.empty())return -1;
        auto a= *pq.begin();
        pq.erase(a);
       return a;
    }
    
    void addBack(int num) {
        if(pq.find(num)==pq.end())pq.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */