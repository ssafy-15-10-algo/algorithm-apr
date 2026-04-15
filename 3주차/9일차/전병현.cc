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

int t, w;

int dp[31];

int main() {
	cin.tie(0);cout.tie(0)->sync_with_stdio(0);
	cin >> t >> w;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		x--;
		if (x == 0) {
			dp[0] += 1;
		}
		for (int j = 1; j <= w; j++) {
			if (x == (j&1)) {
				dp[j] = max(dp[j-1]+1, dp[j]+1);
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i <= w; i++) {
		maxi = max(maxi, dp[i]);
	}
	cout << maxi;
}
