#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n;
int f;
priority_queue<pair<int, int>> pq; //-종료시각, 번호
priority_queue<int> avail; //-이용가능 컴퓨터 번호
int cnt[100001];
int ss[100001];
int es[100001];

int main() {
	cin.tie(0);cout.tie(0)->sync_with_stdio(0);
	cin >> n;
	pair<int, int> tmp[100001];
	for (int i = 0; i < n; i++) {
		cin >> tmp[i].first >> tmp[i].second;
	}
	sort(tmp, tmp + n);
	for (int i = 0; i < n; i++) {
		ss[i] = tmp[i].first; es[i] = tmp[i].second;
		while (avail.size() && -avail.top() < ss[i]) {
			avail.pop();
		}
		avail.push(-es[i]);
		f = max(f, (int)avail.size());
	}
	while (avail.size()) {
		avail.pop();
	}
	for (int i = 0; i < f; i++) {
		avail.push(-i);
	}
	for(int i=0;i<n;i++){
		while (pq.size() && -pq.top().first <= ss[i]) {
			avail.push(-pq.top().second);
			pq.pop();
		}
		cnt[-avail.top()]++;
		pq.push({ -es[i], -avail.top() });
		avail.pop();
	}
	cout << f << "\n";
	for (int i = 0; i < f; i++) {
		cout << cnt[i] << " ";
	}
}
