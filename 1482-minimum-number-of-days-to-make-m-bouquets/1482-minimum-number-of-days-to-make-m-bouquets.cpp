class Solution {
public:

bool canMake(int day, vector<int>& bloomDay, int m, int k) {
        int count = 0, bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
    return -1;
        int low=1; int high = *max_element(bloomDay.begin(), bloomDay.end());
        int mid= ( high-low)/2+low;
        while( low<high){
            mid= ( high-low)/2+low;
            if (canMake(mid, bloomDay, m, k))high= mid;
            else{
                low=mid+1;
            }
        }
        return low;
    }
};