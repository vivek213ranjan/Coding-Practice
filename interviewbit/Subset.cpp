/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
*/
void subsetGenerate(vector<int> &A, vector<int> temp, int curr, vector<vector<int> > &result) {
    int size = A.size();
    result.push_back(temp);
    if(curr == size) {
        return;
    }
    for(int i=curr; i<size; i++) {
        vector<int> temp1(temp);
        temp1.push_back(A[i]);
        subsetGenerate(A, temp1, i+1, result);
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    if(A.size()) {
        sort(A.begin(), A.end());   
    }
    vector<vector<int> > result;
    vector<int> temp;
    subsetGenerate(A, temp, 0, result);
    return result;
}
