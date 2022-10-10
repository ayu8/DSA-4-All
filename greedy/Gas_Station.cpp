// Problem link: https://www.interviewbit.com/problems/gas-station/

/* 
Problem Description
Given two integer arrays A and B of size N. There are N gas stations along a circular route, where the amount of gas at station i is A[i].
You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.
You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2.. Completing the circuit means starting at i and ending up at i again.

Input Format
The first argument given is the integer array A. The second argument given is the integer array B.

Output Format
Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.

Example Input
A = [1, 2] B = [2, 1]

Example Output
1

Example Explanation
If you start from index 0, you can fill in A[0] = 1 amount of gas. Now your tank has 1 unit of gas. But you need B[0] = 2 gas to travel to station 1. If you start from index 1, you can fill in A[1] = 2 amount of gas. Now your tank has 2 units of gas. You need B[1] = 1 gas to get to station 0. So, you travel to station 0 and still have 1 unit of gas left over. You fill in A[0] = 1 unit of additional gas, making your current gas = 2. It costs you B[0] = 2 to get to station 1, which you do and complete the circuit.

*/

//Solution

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int curr=0, left=0, res=0; 
    for(int i=0;i<A.size();i++){
        curr+=A[i]-B[i];
        if(curr<0){
            left+=curr;
            curr=0;
            res=i+1;
        }
    }
    
    return curr+left>=0 ? res: -1; 
}
