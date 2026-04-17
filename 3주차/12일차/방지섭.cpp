#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;
vector<int> for_sort;
unordered_map<int, int> um, reverse_um;

void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        v[i] = {a,b};
        for_sort.push_back(a);
        for_sort.push_back(b);
    }
    sort(for_sort.begin(), for_sort.end());
    for(int i=0;i<2*n;i++){
        um[for_sort[i]] = i;
        reverse_um[i] = for_sort[i];
    }
}

void solve(){
    vector<int> sum(2*n, 0);
    for(int i=0;i<n;i++){
        auto p = v[i];
        int s = um[p.first], e = um[p.second];
        sum[s]++, sum[e]--;
    }
    int mx = sum[0];
    for(int i=1;i<2*n;i++){
        sum[i] += sum[i-1];
        mx = max(mx, sum[i]);
    }
    cout << mx << '\n';

    bool flag = false;
    pair<int,int> ans;
    for(int i=0;i<2*n;i++){
        if(sum[i] == mx && !flag){
            flag = true;
            ans.first = reverse_um[i];
        }
        if(sum[i] != mx && flag){
            ans.second = reverse_um[i];
            break;
        }
    }
    cout << ans.first << " " << ans.second;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}