class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int,int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;   
        this->nums2 = nums2; 
        for(auto k: nums2){
            freq[k]++;
        }
    }
    
    void add(int index, int val) {
       freq[nums2[index]]--;
        nums2[index]+=val;
        freq[nums2[index]]++;
        
        
    }
    
    int count(int tot) {
        int coun=0;
        for(int i=0;i<nums1.size();i++){
            if(freq.find(tot-nums1[i])!=freq.end()){
                coun+=freq[tot-nums1[i]];
            }
            
        }
        return coun;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */