#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		int m = n * k;
		vector<int> a(m);
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		long long total = 0;
		// check if 'n' is equal to 2
		if (n == 2) {
			// if yes, then simply get the total of the elements in the even position (zero-based)
			for (int i = 0; i < m; i += 2) {
				total += (long long) (a[i]);
			}
			cout << total << '\n';
			continue;
		}
		// otherwise, find the median position
		int interval = (n + 1) / 2;
		// calculate the length of interval starting from the median to the last position
		int left = n - interval + 1;
		// set 'x' to 1 (for the first interval/set)
		int x = 1;
		// 'in' will be used to count the intervals/sets made (to make sure it does not exceed 'k')
		int in = 0;
		// start the loop from the end to the beginning of the sequence
		for (int i = m - 1; i >= 0; i--) {
			// check if the current 'x' is divisible by 'left'
			if (x % left == 0) {
				// if yes, then add the element at this position to 'total'
				total += a[i];
				// increment 'in'
				in++;
			}
			// increment 'x'
			x++;
			// check if 'in' is greater than or equal to 'k'
			if (in >= k) {
				// if yes, then break the loop
				break;
			}
		}
		cout << total << '\n';
	}
	return 0;
}
