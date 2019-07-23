int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int x[] = {1, -1, -2, -2, -1, 1, 2, 2};
    int y[] = {2, 2, 1, -1, -2, -2, -1, 1};
    int MAX_ROW = A;
    int MAX_COL = B;
    bool visited[1002][1002];
    memset(visited,false,sizeof(visited));
    queue<pair<pair<int, int>,  int>> q;
    q.push(make_pair(make_pair(C, D), 0));
    while(!q.empty()) {
        pair<pair<int, int>,  int> temp = q.front(); q.pop();
        if(temp.first.first == E && temp.first.second == F) {
            return temp.second;
        }
        if(visited[temp.first.first][temp.first.second]) { continue; }
        visited[temp.first.first][temp.first.second] = true;
        
        for(int i=0; i<8; i++) {
            int nextx = temp.first.first + x[i];
            int nexty = temp.first.second + y[i];
            if(nextx <= MAX_ROW && nextx >= 1 && nexty <= MAX_COL && nexty >= 1 && visited[temp.first.first][temp.first.second]) {
                q.push(make_pair(make_pair(nextx, nexty), temp.second+1));
            }
        }
    }
    return -1;
}
