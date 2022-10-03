public class Solution {
        public int findPeakElement(int[] num) {
            if(num.length == 0){
                return 0;
            }
            
            int[] temp = new int[num.length];
            for(int i = 0; i < num.length; i++){
                temp[i] = num[i];
            }
            
            Arrays.sort(temp);
            int max = temp[temp.length -1];
            int count = 0;
            for(int i = 0; i < num.length; i++){
                if(num[i] == max){
                    count = i;
                    break;
                }
            }
            
            return count;
        }
    }

// question link:
// https://leetcode.com/problems/find-peak-element/
