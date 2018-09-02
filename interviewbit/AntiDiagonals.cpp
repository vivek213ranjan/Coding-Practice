vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<vector<int> > result(2*n - 1);
    int i = 0;
    int ctr = 0;
    int k = 0;
    int j;
    while(ctr < n) {
        i=0;
        j = ctr;
        while(j >= 0) {
            result[k].push_back(A[i][j]);
            j--;
            i++;
        }
        k++;
        ctr++;
    }
    ctr = 1;
    // j = n - 1;
    while(ctr < n) {
        i=ctr;
        j = n-1;
        while(i < n) {
            result[k].push_back(A[i][j]);
            i++;
            j--;
        }
        k++;
        ctr++;
    }
    return result;
}