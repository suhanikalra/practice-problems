class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int side1= pow(p1[0]-p2[0],2)+pow(p2[1]-p1[1],2);
        int side2= pow(p3[0]-p2[0],2)+pow(p2[1]-p3[1],2);
        int side3= pow(p3[0]-p4[0],2)+pow(p3[1]-p4[1],2);
        int side4= pow(p1[0]-p4[0],2)+pow(p4[1]-p1[1],2);
        int side5= pow(p1[0]-p3[0],2)+pow(p3[1]-p1[1],2);
        int side6= pow(p2[0]-p4[0],2)+pow(p4[1]-p2[1],2);
vector<int>arr={side1,side2,side3,side4,side5,side6};
sort(arr.begin(),arr.end());
if(arr[0]==arr[3] and arr[4]==arr[5] and arr[4]!=arr[3])return true;
return false;
          
    }
};