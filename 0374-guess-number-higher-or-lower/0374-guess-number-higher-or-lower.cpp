/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start=1,end=n;
        int temp;
        int pick=start+(end-start)/2;
        while(temp!=0){
            pick=start+(end-start)/2;
            temp=guess(pick); 
            if(temp>0){
                start=(pick)+1;
            }
            if(temp<0){
                end=pick-1;
            }
        }
        return pick;
    }
};