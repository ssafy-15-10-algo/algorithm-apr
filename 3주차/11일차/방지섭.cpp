#include <bits/stdc++.h>
using namespace std;

int n; 
int room_cnt[100001];
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
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1; // 현재 진행 중인 스케쥴 <끝나는 시간, 방 idx>
    priority_queue<int, vector<int>, greater<int>> pq2; // 현재 사용 가능한(스케쥴이 끝난) 가장 작은 index를 고르는 용도

    int room_num = 0;
    for(int i=0;i<n;i++){
        while(!pq1.empty() && pq1.top().first <= v[i].first){ // 현재 v[i]의 입장 시간에 대해서 이미 스케쥴이 다 끝난 방을 pq2에 옮기기. 
            pq2.push(pq1.top().second); pq1.pop();
        }

        if(pq2.empty()){ // 만약 스케쥴이 다 끝난 방이 하나도 없으면 pq1에 새로운 방을 추가해야 함.
            pq1.push({v[i].second, room_num});
            room_cnt[room_num++]++;
        }
        else{ // 스케쥴이 다 끝난 방이 있으면 그 중에 가장 idx가 낮은 방을 선택해서 현재 진행 중인 스케쥴에 넣음.
            room_cnt[pq2.top()]++;
            pq1.push({v[i].second, pq2.top()});
            pq2.pop();
        }
    }
    cout << room_num << "\n";
    for(int i=0;i<room_num;i++) cout << room_cnt[i] << " ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}