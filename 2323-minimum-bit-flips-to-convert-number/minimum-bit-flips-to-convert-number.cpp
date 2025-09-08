class Solution {
public:
    int minBitFlips(int a, int b) {
        int x= (a ^ b);
        int count=0;
        while(x>0){
            if(x & 1) count++;
            x>>=1;

        }
        return count;
    }
};