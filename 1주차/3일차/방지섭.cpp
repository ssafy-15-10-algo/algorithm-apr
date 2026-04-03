#include <bits/stdc++.h>
using namespace std;

int n;
double dis[16][16], dp[16][1<<16];

void input(){
    cin >> n;
    vector<pair<double, double>> v(n); 
    for(int i=0;i<n;i++){
        double a,b; cin >> a >> b;
        v[i] = {a,b};
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i != j){
                dis[i][j] = sqrt((v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second - v[j].second)*(v[i].second - v[j].second));
            }
        }
    }
    for(int i=0;i<16;i++){
        for(int j=0;j<(1<<16);j++){
            dp[i][j] = -1;
        }
    }
}

double dfs(int cur, int visit){
    if(visit == (1 << n) - 1){
        return dis[cur][0];
    }

    if(dp[cur][visit] > -0.5) return dp[cur][visit];

    dp[cur][visit] = 1000000000;

    for(int i=0;i<n;i++){
        if((visit & (1 << i)) != 0) continue;
        dp[cur][visit] = min(dp[cur][visit], dis[cur][i] + dfs(i, visit | (1 << cur)));
    }
    return dp[cur][visit];
}

void solve(){
    cout << fixed << setprecision(10) << dfs(0, 1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}