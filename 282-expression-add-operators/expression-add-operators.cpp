class Solution {
public:
    vector<string>result;

void backtrack(string num, int target,int index, long long eval,long long prev,string expr){
    if(index==num.size()){
        if(eval==target)result.push_back(expr);
    }
        for(int i = index; i < num.size(); i++){
            if(i!=index && num[index]=='0')break;
            string curstr=num.substr(index,i-index+1);
            long long curnum=stoll(curstr);
            if(index==0)backtrack(num,target,i+1,curnum,curnum,curstr);
            else{
                backtrack(num,target,i+1,eval+curnum,curnum,expr+'+'+curstr);
                backtrack(num,target,i+1,eval-curnum,-curnum,expr+'-'+curstr);
                backtrack(num,target,i+1,eval-prev+prev*curnum,prev*curnum,expr+'*'+curstr);
            }

        }
    }




    vector<string> addOperators(string num, int target) {
        result.clear();
        backtrack(num, target, 0, 0, 0, "");
        return result;
        
    }
};