#include "comm_header.h"


class Solution {
public:
	vector<int> twoSum(vector<int> & nums, int target) {
		vector<int> answer;
		// 用unordered_map的话，假设了所有的元素都是不相同的，但其实题目里并没有说
		// 由于这一次需要做O(N)的查找，而不需要有序遍历元素，所以用unorderd_map是很好的选择
		unordered_map<int, int> nums_map;
		for (int i = 0; i < nums.size(); ++i) {
			// 注意插入的时候用insert，而不要用nums_map[nums[i]] = i这样的方式，否则会多一次查找
			nums_map.insert(make_pair(nums[i], i));
		}

		for (int i = 0; i < nums.size(); ++i) {
			auto iter = nums_map.find(target - nums[i]);
			// 注意关键条件：每个元素只能用一次
			if (iter != nums_map.end() && iter->second != i) {
				answer.push_back(i);
				answer.push_back(iter->second);
				break;
			}
		}

		return answer;
	}
};


int main()
{
	int test_cases = input<int>();
	for (int i = 1; i <= test_cases; ++i)
	{
		vector<int> nums = input_vec<int>();
		int target = input<int>();
		vector<int> answer = input_vec<int>();
		assert(equal(Solution().twoSum(nums, target), answer));
		cout << "Nice! Pass case " << i << endl;
	}

	cout << "Excellent! All test cases pass." << endl;

	return 0;
}
