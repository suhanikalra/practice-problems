class Solution {
public:void solve(string input,string op , vector<string> &output)
    {   if(input.size()== 0){
        output.push_back(op);
        return;
    }

    if( isalpha(input[0])){
        string op1 = op;
        string op2 = op;
        op1.push_back(tolower(input[0]));
        op2.push_back(toupper(input[0]));
        input.erase(input.begin()+0);
         solve(input,op1,output);
            solve(input,op2,output);
    }

    else{
         string op1 = op;
         op1.push_back(input[0]);
         input.erase(input.begin()+0);
         solve(input,op1,output);
    }
    }


    vector<string> letterCasePermutation(string s) {
       
        string op = "";
        vector<string> output;
        solve(s,op,output);
        return output;}
};