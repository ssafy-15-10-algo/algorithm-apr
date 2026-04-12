#include <bits/stdc++.h>
using namespace std;

int m, n;
int sum[700][700];
void input(){
    cin >> m >> n;
}

void solve(){
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<3;j++){
            int num; cin >> num;
            if(j == 2) continue;
            cnt += num;
            if(cnt == 0) continue;
            if(cnt > m) sum[0][cnt-m]++;
            else sum[m-cnt][0]++;
        }
    }

    // 누적합

    // (0, m-1) -> (0, 0)
    for(int i=m-2;i>=0;i--){
        sum[0][i] += sum[0][i+1];
    }

    // (0, 0) -> (m-1, 0)
    for(int i=0;i<m-1;i++){
        sum[i+1][0] += sum[i][0];
    }
    

    for(int i=1;i<m;i++){
        for(int j=1;j<m;j++){
            sum[i][j] = min({sum[i-1][j-1], sum[i-1][j], sum[i][j-1]});
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout << 2*n + 1 - sum[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}