class Solution {
public:
    int countPrimes(int n) {
        vector<bool>v(n+1,true);
        v[0]=false;v[1]=false;

        for(int i=2;i<n;i++){
            if(v[i]==true){int p=i; 
            for(int j=2;j<n;j++){
                if(j*p>n)break;
                v[j*p]=false;
            }

            }

        }
int count=0;
        for(int i=0;i<n;i++){
            
            if(v[i]==true)count++;
        }
        return count;
        
    }
};