#include "comm_header.h"

class Solution {
public:
	string longestPalindrome(string s) {
		int max_len = 0;
		int best_center = -1;
		string s2 = spanString(s);
		for (int i = 0; i < s2.size(); ++i)
		{
			int len = getLogestPalindromeLengthFromCenter(s2, i);
			if (len > max_len) {
				max_len = len;
				best_center = i;
			}
		}

		int half_len = (max_len - 1) >> 1;
		int start_index = revertIndex(best_center - half_len);
		return s.substr(start_index, half_len);
	}

private:
	int getLogestPalindromeLengthFromCenter(const string & s, int center) {
		int max_step = min(center, (int)(s.size() - center - 1));
		int i = 1;
		for (i = 1; i <= max_step; ++i) {
			if (s[center-i] != s[center+i])
				break;
		}

		return (i << 1) - 1;
	}

	string spanString(const string & s) {
		string str(s.length() * 2 + 1, '\0');
		for (int i = 0; i < s.length(); ++i)
			str[i*2+1] = s[i];
		return str;
	}

	int revertIndex(int index) {
		return index >> 1;
	}
};

int main()
{
	int test_cases = input<int>();
	for (int i = 1; i <= test_cases; ++i)
	{
		string str = input<string>();
		string answer = input<string>();
		assert(Solution().longestPalindrome(str) == answer);
		cout << "Nice! Pass case " << i << endl;
	}

	cout << "Excellent! All test cases pass." << endl;

	return 0;
}
