
 class NumberContainers {
public:
    map<int, set<int>> mp;
    map<int, int> idx;  
    
    NumberContainers() {   
    }
    
    void change(int index, int number) {
        if(idx.count(index)) mp[idx[index]].erase(index);  
        mp[number].insert(index);
        idx[index] = number;
    }
    
    int find(int number) {
        if(mp.find(number)!=mp.end() && !mp[number].empty()) return *mp[number].begin();
        return -1;
    }
};


/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */