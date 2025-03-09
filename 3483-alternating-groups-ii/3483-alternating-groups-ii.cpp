class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) { 
    if (k > colors.size()) return 0;
    int n= colors.size();
    int count = 0;
    int start = 0;
    int end = 0;
    
    while (end < colors.size()+k-1) {
        if (end > 0 && colors[end%n] == colors[(end-1)%n]) {
            start = end;
        }
        
        if (end - start + 1 >= k) {
            count++;
        }
        
        end++;
    }
    
    return count;
}
  
};