#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

void rot(vi& v, int i, int j, int k) {
	const auto& c = j - i + 1;

	auto temp = vi(c);
	for (auto w = 0; w < c; ++w) {
		auto idx = k + w;
		if (j < idx) {
			idx -= c;
		}

		temp[w] = v[idx];
	}

	for (auto w = 0; w < c; ++w) {
		auto idx = i + w;
		v[idx] = temp[w];
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	auto v = vi(n);
	for (auto i = 0; i < n; ++i) {
		v[i] = i + 1;
	}

	while (0 < (m--)) {
		int i, j, k;
		cin >> i >> j >> k;

		rot(v, i - 1, j - 1, k - 1);
	}

	for (const auto& x : v) {
		cout << x << ' ';
	}

	return 0;
}