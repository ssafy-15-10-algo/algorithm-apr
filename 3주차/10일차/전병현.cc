#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n;
set<int> e[100001];
queue<int> q;

int main() {
	cin.tie(0);cout.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		e[a].insert(b);
		e[b].insert(a);
	}
	int inputs[100001];
	for (int i = 0; i < n; i++) {
		cin >> inputs[i];
	}
	if (inputs[0] != 1) {
		cout << 0;
		return 0;
	}
	q.push(1);
	for (int i = 1; i < n; i++) {
		int x = inputs[i];
		while (e[q.front()].empty()) {
			q.pop();
		}
		if (e[q.front()].find(x) == e[q.front()].end()) {
			cout << 0;
			return 0;
		}
		e[q.front()].erase(x); e[x].erase(q.front());
		q.push(x);
	}
	cout << 1;
}
