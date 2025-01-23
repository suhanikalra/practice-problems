class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        if(skill.size()%2==1)return -1;
        int start=0,end=skill.size()-1;
        set<int>st;long long chem=0;
        while(start<end){
            
                st.insert(skill[start]+skill[end]);
                chem= chem+skill[start]*skill[end];
                if(st.size()>1)return -1;
            

            start++;end--;
        }
        return chem;
        
    }
};