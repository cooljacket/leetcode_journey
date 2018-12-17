#include "comm_header.h"

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<bool> occur(256, false);
		int max_length = 0;
		int last_length = 0;
		int last_index = 0;
		for (size_t i = 0; i < s.length() && last_index < s.length(); ++i) {
			while (last_index < s.length()) {
				size_t index = char2index(s[last_index++]);
				if (!occur[index]) {
					++last_length;
					occur[index] = true;
				}
				else
				{
					--last_index;	// 回退一下
					break;
				}
			}

			if (last_length > max_length)
				max_length = last_length;
			--last_length;
			occur[char2index(s[i])] = false;
		}

		return max_length;
	}

private:
	size_t char2index(char ch)
	{
		return static_cast<size_t>(ch + 128);
	}
};

int main()
{
	int test_cases = input<int>();
	for (int i = 1; i <= test_cases; ++i)
	{
		string str = input<string>();
		int answer = input<int>();
		assert(Solution().lengthOfLongestSubstring(str) == answer);
		cout << "Nice! Pass case " << i << endl;
	}

	cout << "Excellent! All test cases pass." << endl;

	return 0;
}
