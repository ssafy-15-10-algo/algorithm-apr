#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int n;
    if(!(cin >> n)) return false;
    vector<int> v(n), dp; for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++){
        auto iter = lower_bound(dp.begin(), dp.end(), v[i]);
        if(iter == dp.end()) dp.push_back(v[i]);
        else *iter = v[i];
    }
    cout << dp.size() << "\n";

    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    while(solve());

    return 0;
}