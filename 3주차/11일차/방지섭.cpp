#include <bits/stdc++.h>
using namespace std;

int n; 
int computer_cnt[100001];
vector<pair<int,int>> v;
void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        v[i] = {a,b};
    }
    sort(v.begin(), v.end());
}

void solve(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1; // 현재 사용 중인 컴퓨터 <끝나는 시간, 방 idx>
    priority_queue<int, vector<int>, greater<int>> pq2; // 현재 사용 가능한(스케쥴이 끝난) 가장 작은 index를 가진 컴퓨터를 고르는 용도

    int computer_idx = 0;
    for(int i=0;i<n;i++){
        while(!pq1.empty() && pq1.top().first <= v[i].first){ // 현재 v[i]의 입장 시간에 대해서 이미 사용이 다 끝난 컴퓨터를 pq2에 옮기기. 
            pq2.push(pq1.top().second); pq1.pop();
        }

        if(pq2.empty()){ // 만약 사용이 다 끝난 컴퓨터가 하나도 없으면 pq1에 새로운 방을 추가해야 함.
            pq1.push({v[i].second, computer_idx});
            computer_cnt[computer_idx++]++;
        }
        else{ // 사용이 다 끝난 컴퓨터가 있으면 그 중에 가장 idx가 낮은 컴퓨터를 선택해서 현재 진행 중인 스케쥴(pq1)에 넣음.
            computer_cnt[pq2.top()]++;
            pq1.push({v[i].second, pq2.top()});
            pq2.pop();
        }
    }
    cout << computer_idx << "\n";
    for(int i=0;i<computer_idx;i++) cout << computer_cnt[i] << " ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}