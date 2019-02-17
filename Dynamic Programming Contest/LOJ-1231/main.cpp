#include <bits/stdc++.h>
using namespace std;

std::vector<int> tail(15, 0);
int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
	if (v.size() == 0)
		return 0;

	int length = 1; // always points empty slot in tail

	tail[0] = v[0];
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i] > tail[length - 1])
			tail[length++] = v[i];
		else {
			// TO check whether the element is not present before hand
			auto it = find(tail.begin(), tail.begin() + length, v[i]);
			if (it != tail.begin() + length) {
				continue;
			}
			// If not present change the tail element to v[i]
			it = upper_bound(tail.begin(), tail.begin() + length, v[i]);
			*it = v[i];
		}
	}

	return length;
}

int main()
{
	std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
	std::cout << "Length of Longest Increasing Subsequence is "
			<< LongestIncreasingSubsequenceLength(v);

	for(auto a : tail)
		cout<<a<<" "; cout<<endl;
	return 0;
}
