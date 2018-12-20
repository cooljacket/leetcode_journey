#include "comm_header.h"

// Manacher算法（8ms） https://segmentfault.com/a/1190000003914228
class Solution {
public:
	string longestPalindrome(string s) {
		int max_right = 0;
		int pos = 1;
		string s2 = spanString(s);
		vector<int> RL(s2.size(), 0);

		for (int i = 0; i < s2.size(); ++i)
		{
			if (i < max_right)
				RL[i] = min(RL[2*pos-i], max_right - i);
			else
				RL[i] = 1;
			
			while (i-RL[i] >= 0 
					&& i+RL[i] < s2.size() 
					&& s2[i-RL[i]] == s2[i+RL[i]])
				++RL[i];

			if (RL[i]+i-1 > max_right) {
				max_right = RL[i] + i - 1;
				pos = i;
			}
		}

		// 找到最棒的一个中心点（注意pos对应的只是覆盖最远的，而不是最长的）
		int best_center = 0;
		int max_len = 0;
		for (int i = 0; i < RL.size(); ++i) {
			if (RL[i] > max_len) {
				max_len = RL[i];
				best_center = i;
			}
		}

		--max_len;
		int start_index = (best_center - max_len) >> 1;

		// cout << "hahaha " << max_len << ", " << start_index << ", " << best_center << ", " << RL[best_center] << endl;
		return s.substr(start_index, max_len);
	}

private:
	string spanString(const string & s) {
		string str(s.length() * 2 + 1, '\0');
		for (int i = 0; i < s.length(); ++i)
			str[i*2+1] = s[i];
		return str;
	}
};

/*
// 自己写的笨算法 + 优化（12ms）
class Solution {
public:
	string longestPalindrome(string s) {
		int max_len = 3;
		int best_center = 1;
		string s2 = spanString(s);
		for (int i = 2; i < s2.size(); ++i)
		{
			int len = getLogestPalindromeLengthFromCenter(s2, i, max_len);
			if (len > max_len) {
				max_len = len;
				best_center = i;
			}
		}

		int half_len = (max_len - 1) >> 1;
		int start_index = revertIndex(best_center - half_len);
		// cout << "hahah " << half_len << ", " << start_index << ", " << best_center 
		// 	<< ", " << s.substr(start_index, half_len) << endl;
		return s.substr(start_index, half_len);
	}

private:
	int getLogestPalindromeLengthFromCenter(const string & s, int center, int max_len_now) {
		int max_step_now = (max_len_now - 1) >> 1;
		int max_step = min(center, (int)(s.size() - center - 1));
		
		// 如果长度比当前最长的小，没必要查找
		if (max_step <= max_step_now)
			return 1;

		for (int j = max_step_now; j > 0; --j) {
			if (s[center-j] != s[center+j])
				return 1;
		}

		int i = max_step_now + 1;
		for (; i <= max_step; ++i) {
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
*/

/*
// 自己写的笨算法，没优化（28ms）
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
*/

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
