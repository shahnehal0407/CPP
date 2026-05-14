class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;

        int i=0;

        long long sum=0;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(i<k){
            sum+=pq.top();
            int s= ceil(pq.top()/3.0);
            pq.pop();
            pq.push(s);
            i++;


        }

        return sum;
    }
};