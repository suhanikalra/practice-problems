class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0, twenty = 0;

        for(auto b: bills){
            if(b== 5)five++;
            if(b==10){if(five){five--; ten++;}else return false;}
            if(b==20){if(ten>=1 and five>=1){twenty++;ten--;five--;}
                    else if (five>=3){five-=3;twenty++;}
                    else return false;}

        }

return true;;
    }
};