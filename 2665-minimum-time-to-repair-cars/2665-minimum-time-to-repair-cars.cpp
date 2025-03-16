class Solution {
public:
    bool canFixInTime(long long mid, const vector<int>& ranks, int cars) {
        long long totalCars = 0;
        for (long long r : ranks) {
            long long x = (long long)floorl(sqrtl((long double)mid / (long double)r));
            totalCars += x;
            if (totalCars >= cars) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long start = 0; 
        long long end = (long long)(*max_element(ranks.begin(), ranks.end())) 
                        * (long long)cars * (long long)cars;

       
        while (start < end) {
            long long mid = start + (end - start) / 2;
            if (canFixInTime(mid, ranks, cars)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};
