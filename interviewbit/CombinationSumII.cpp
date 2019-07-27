/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
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
        fillCombinations(A, temp1, i+1, result, target, curSum + A[i]);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    if(A.size()) {
        sort(A.begin(), A.end());
    }
    vector<vector<int> > result;
    vector<int> temp;
    fillCombinations(A, temp, 0, result, B, 0);
    set<vector<int> > s;
    vector<vector<int> > final;
    for(int i=0; i<result.size(); i++) {
        if(s.find(result[i]) == s.end()) {
            final.push_back(result[i]);
        }
        s.insert(result[i]);
    }
    return final;
}
