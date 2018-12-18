#include "comm_header.h"

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int left1 = 0, right1 = nums1.size() - 1;
		int left2 = 0, right2 = nums2.size() - 1;
		int left_num, right_num;

		while (left1 <= right1 || left2 <= right2)
		{
			int tmp1 = INT_MAX, tmp2 = INT_MAX;
			if (left1 <= right1 && nums1[left1] < tmp1) {
				tmp1 = nums1[left1];
			}
			if (left2 <= right2 && nums2[left2] < tmp2) {
				tmp2 = nums2[left2];
			}
			if (tmp1 < tmp2)
				++left1;
			else
				++left2;
			left_num = min(tmp1, tmp2);

			tmp1 = INT_MIN, tmp2 = INT_MIN;
			if (left1 <= right1 && nums1[right1] > tmp1) {
				tmp1 = nums1[right1];
			}
			if (left2 <= right2 && nums2[right2] > tmp2) {
				tmp2 = nums2[right2];
			}
			if (tmp1 > tmp2)
				--right1;
			else
				--right2;
			right_num = max(tmp1, tmp2);
		}

		if ((nums1.size() + nums2.size()) % 2 == 1) {
			return left_num;
		}

		return (left_num + right_num) / 2.0;
	}
};

int main()
{
	int test_cases = input<int>();
	for (int i = 1; i <= test_cases; ++i)
	{
		vector<int> nums1 = input_vec<int>();
		vector<int> nums2 = input_vec<int>();
		double answer = input<double>();
		assert(equal(Solution().findMedianSortedArrays(nums1, nums2), answer));
		cout << "Nice! Pass case " << i << endl;
	}

	cout << "Excellent! All test cases pass." << endl;

	return 0;
}
