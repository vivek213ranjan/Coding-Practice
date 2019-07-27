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
