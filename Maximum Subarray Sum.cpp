#include <iostream>
#include <set>
#include <vector>

long maximumSum(std::vector<long> a, long m) {
	long prefix = 0, maxSum = 0;
	std::set<long> S1; S1.insert(0);
	std::set<long>::iterator low;

	for (const auto &ax : a) {
		prefix = (prefix + ax) % m;
		maxSum = maxSum > prefix ? maxSum : prefix;

		low = S1.lower_bound(prefix + 1);
		if (low != S1.end()) {
			maxSum = maxSum > prefix - (*low) + m ?
				maxSum : prefix - (*low) + m;
		}
		S1.insert(prefix);
	}
	return maxSum;
}


