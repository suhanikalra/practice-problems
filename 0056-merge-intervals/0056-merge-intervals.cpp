
class Solution {
public:
   vector<vector<int>> merge(vector<vector<int>>& intervals) {
          sort(intervals.begin(),intervals.end());
        int firststart= intervals[0][0];
        int firstend= intervals[0][1],count=0;
        vector<vector<int>>v;

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=firstend){count++;firstend=max(firstend,intervals[i][1]);
           }
            else{ v.push_back({firststart,firstend});
                firststart= intervals[i][0];
         firstend= intervals[i][1];

            }
        }v.push_back({firststart,firstend});

        
        
        return v;
    }
};
