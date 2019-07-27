/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 

*/
void fillCombinations(vector<int> &A, vector<int> temp, int curr, vector<vector<int> > &result, int target, int curSum) {
    if(curSum == target) {
        result.push_back(temp);
    }
    if(curr == A.size() || curSum > target) {
        return;
    }
    for(int i=curr; i<A.size(); i++) {
        vector<int> temp1(temp);
        temp1.push_back(A[i]);
        fillCombinations(A, temp1, i, result, target, curSum + A[i]);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    map<int, int> mp;
    vector<int> modA;
    for(int i=0; i<A.size(); i++) {
        int elem = A[i];
        if(mp[elem] == 0) {
            modA.push_back(elem);
            mp[elem]++;
        }
    }
    if(modA.size()) {
        sort(modA.begin(), modA.end());
    }
    vector<vector<int> > result;
    vector<int> temp;
    fillCombinations(modA, temp, 0, result, B, 0);
    return result;
}
