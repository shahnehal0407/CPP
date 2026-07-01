class Solution {
public:


    bool can(vector<int>& position, int m,int mid){
        int ball=1;
        int last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=mid){
                ball++;
                last=position[i];
                if(ball==m)return true;
            }
        }
        return false;
    }





    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;
        int high=position.back()-position[0];
        int answer=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(can(position, m,mid)){
                answer=mid;
                low=mid+1;
            }
            else high=mid-1;
            
        }
        return answer;

    }
};