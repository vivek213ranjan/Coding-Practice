/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
*/
void generateCombinations(vector<int> &A, vector<int> temp, int cur, vector<vector<int> > &result, int B) {
    int bsize = temp.size();
    if(bsize == B) {
        result.push_back(temp);
    }
    if(cur == A.size()) {
        return;
    }
    for(int i=cur; i<A.size(); i++) {
        vector<int> temp1(temp);
        temp1.push_back(A[i]);
        generateCombinations(A, temp1, i+1, result, B);
    }
    
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> ar;
    for(int i=1; i<=A; i++) {
        ar.push_back(i);
    }
    if(ar.size()) {
        sort(ar.begin(), ar.end());
    }
    vector<vector<int> > result;
    vector<int> temp;
    generateCombinations(ar, temp, 0, result, B);
    return result;
}
