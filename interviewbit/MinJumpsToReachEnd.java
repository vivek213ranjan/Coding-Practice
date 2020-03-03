/*
Minimum number of jumps to reach end
Given an array of non-negative integers A where each element represents your maximum jump length at that position. The initial position is the first index of the array and goal is to reach the last index of the array with the minimum number of jumps. Note: If it not possible to reach the last index return -1 instead. 
Input Format
The only argument given is the integer array A.
Output Format
Return the minimum number of jumps to reach the last index or -1 if it is not possible.
Constraints
1 <= length of the array <= 100000
0 <= A[i] <= 10^9 
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
Output 1:
    3

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    1
*/
public class Solution {
    public int solve(ArrayList<Integer> A) {
        int n = A.size();
        if (n <= 1) {
            return 0;
        }
        int ladder = A.get(0);
        int stairs = A.get(0);
        if(stairs == 0) { return -1; }
        
        int jump = 1;
        for(int level = 1; level < n; level++) {
            if(level == n-1) {
                return jump;
            }
            if(level + A.get(level) > ladder) {
                ladder = level + A.get(level);
            }
            stairs--;
            if(stairs == 0) {
                jump++;
                if(level >= ladder) {
                   return -1; 
                }  
                stairs = ladder-level;
            }
        }
        return jump;
    }
}
