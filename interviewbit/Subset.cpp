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
