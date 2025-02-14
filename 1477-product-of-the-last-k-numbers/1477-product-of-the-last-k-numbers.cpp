class ProductOfNumbers {
public:
 vector<int>nums;int count=0;
    ProductOfNumbers() {
     
    }
    
    void add(int num) {
        nums.push_back(num);
        count++;
        
    }
    
    int getProduct(int k) {
        int ans=1;
        for(int j=count-k;j<count;j++){
            ans=ans*nums[j];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */