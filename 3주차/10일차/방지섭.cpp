#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[100001];
vector<int> target, visit_order;
bool visited[100001];

void input(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visit_order.resize(n+1); 
    target.resize(n);
    for(int i=0;i<n;i++){int num; cin >> num; target[i] = num; visit_order[num] = i;}
}

int solve(){
    for(int i=1;i<=n;i++){
        sort(v[i].begin(), v[i].end(), [](int a, int b){
            return visit_order[a] < visit_order[b];
        });
    }

    queue<int> q;
    q.push(1); visited[1] = true;
    int idx = 0;
    while(!q.empty()){
        int f = q.front(); q.pop();
        if(f != target[idx++]) return 0;
        for(auto k : v[f]){
            if(visited[k]) continue;
            q.push(k);
            visited[k] = true;
        }
    }
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    
    input();
    cout << solve();

    return 0;
}