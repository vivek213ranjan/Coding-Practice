/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
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
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    if(A.size()) {
        sort(A.begin(), A.end());   
    }
    vector<vector<int> > result;
    vector<int> temp;
    subsetGenerate(A, temp, 0, result);
    vector<vector<int> > final;
    set<vector<int> > s;
    for(int i=0; i<result.size(); i++) {
        if(s.find(result[i]) == s.end()) {
            final.push_back(result[i]);
        }
        s.insert(result[i]);
    }
    return final;
}
