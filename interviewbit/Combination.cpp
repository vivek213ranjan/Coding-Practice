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
