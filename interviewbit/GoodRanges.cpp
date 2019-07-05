/*
Given a set S. A range is said to be good, if it is the largest range containing only one element.

Now, given a number A, denoting the range 1 to A, and array of B queries where each element is a query having a number X in the range 1 to A. 
X is to be added to the set S.

For each query, the answer would be the sum of the upper and lower bound of the good ranges possible modulo 1000000007.

Finally, you need to return an array where element at i-th position represents the answer to i-th query.

CONSTRAINTS
1 <= A, size of array B <= 10^5
1 <= X <= A

SAMPLE INPUT
A: 10
B: [2, 7, 5, 9, 6, 1, 8, 10, 3, 4]

SAMPLE OUTPUT
[11, 20, 30, 46, 58, 61, 77, 96, 102, 110]

EXPLANATION
First 2 is added to the set and the largest range containing only 2 is [1, 10] .

Then 7 is added and the range containing only 2 becomes [1,6] and containing only 7 becomes [3, 10].

Then 5 is added and the ranges are:

    For 2 : [1,4]
    For 5 : [3,6]
    For 7 : [6,10]
    
Similarly for all other queries.

*/
vector<int> Solution::solve(int A, vector<int> &B) {
    vector<int> final;
    int n = B.size();
    set<int> s;
    int result = 0;
    int minVal = 1;
    int maxVal = A;
    vector<bool> present(100009, false);
    int modval = 1000000007;
    for(int i=0; i<n; i++) {
        if(i == 0) { 
            result += (1+A);
            maxVal = B[i];
            minVal = B[i];
        } else {
            if(!present[B[i]]) {
                if(B[i] > maxVal) {
                    result = (result%modval + (maxVal + 1)%modval)%modval;
                    result = (result%modval + (B[i] - 1)%modval)%modval;
                    maxVal = B[i];
                } else if(B[i] < minVal) {
                    result = (result%modval + (B[i] + 1)%modval)%modval;
                    result = (result%modval + (minVal - 1)%modval)%modval;
                    minVal = B[i];
                } else {
                    result = (result%modval + (B[i]%modval + B[i]%modval)%modval)%modval;
                }
            }
        }
        present[B[i]] = true;
        final.push_back(result);
    }
    return final;
}
