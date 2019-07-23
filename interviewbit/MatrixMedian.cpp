int Solution::findMedian(vector<vector<int> > &A) {
    int minele = A[0][0];
    int maxele = A[0][0];
    int row = A.size();
    int col = A[0].size();
    for(int i=0; i<row; i++) {
        minele = min(minele, A[i][0]);
        maxele = max(maxele, A[i][col-1]);
    }
    int numOfLessElements = (row*col + 1)/2;
    while(minele < maxele) {
        int mid = (minele + maxele)/2;
        int count = 0;
        for(int i=0; i<row; i++) {
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        if(count < numOfLessElements) {
            minele = mid+1;
        } else {
            maxele = mid;
        }
    }
    return minele;
}
