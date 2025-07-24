class Solution {
public:
    int minMoves(int target, int maxDoubles) {
      int target1=target;
      int countm=0;
      int counta=0;

   while(maxDoubles>0 && target1>1){
    int temp=target1;
    target1= target1/2;
    countm++;
    counta+=temp-2*target1;
   maxDoubles--;
   }
   counta+=target1-1;
   return counta+countm;


    }
};