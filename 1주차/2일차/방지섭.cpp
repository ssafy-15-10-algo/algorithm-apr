#include <bits/stdc++.h>
using namespace std;

int n;
char A[50][50];
int min_cnt[50][50][4];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
pair<int,int> start_p, end_p;
struct node{
    int x, y, dir, cnt; // x, y : 좌표, dir : 방향(상,우,하,좌 = 0,1,2,3), cnt = 설치한 거울 수
};

void input(){
    cin >> n;
    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
            if(A[i][j] == '#'){
                if(flag){
                    end_p = {i,j};
                }
                else{
                    flag = true;
                    start_p = {i,j};
                }
            }
            for(int k=0;k<4;k++) min_cnt[i][j][k] = INT32_MAX;
        }
    }
}

void solve(){
    queue<node> q;
    for(int i=0;i<4;i++){
        min_cnt[start_p.first][start_p.second][i] = 0;
        q.push({start_p.first, start_p.second, i, 0});
    }

    while(!q.empty()){
        node f = q.front(); q.pop();
        int nx = f.x + dx[f.dir], ny = f.y + dy[f.dir];
        if(!(nx >= 0 && nx < n && ny >= 0 && ny < n)) continue;
        if(A[nx][ny] == '*') continue;

        if(A[nx][ny] == '!'){
            if(min_cnt[nx][ny][(f.dir + 1)%4] > f.cnt+1){
                min_cnt[nx][ny][(f.dir + 1)%4] = f.cnt+1;
                q.push({nx, ny, (f.dir + 1)%4, f.cnt+1});
            }
            if(min_cnt[nx][ny][(f.dir + 3)%4] > f.cnt+1){
                min_cnt[nx][ny][(f.dir + 3)%4] = f.cnt+1;
                q.push({nx, ny, (f.dir + 3)%4, f.cnt+1});
            }
        }
        if(min_cnt[nx][ny][f.dir] > f.cnt){
            min_cnt[nx][ny][f.dir] = f.cnt;
            q.push({nx, ny, f.dir, f.cnt});
        }
    }
    int ans = INT32_MAX;
    for(int i=0;i<4;i++) ans = min(ans, min_cnt[end_p.first][end_p.second][i]);
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}