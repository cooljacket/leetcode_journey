#include "comm_header.h"

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;

		string zz(s.length(), '\0');
		int global_index = 0;
		for (int row_index = 0; row_index < numRows; ++row_index)
		{
			int current_count = 0;
			int index = row_index;
			while (index < s.length())
			{
				zz[global_index++] = s[index];
				index = next_index(row_index, numRows, ++current_count);
			}
		}

		return zz;
	}

private:
	int next_index(int row_index, int numRows, int current_count) {
		int block = (numRows == 1) ? 1 : ((numRows-1) << 1);
		int N = (row_index == 0 || row_index == numRows-1) ? (current_count-1) : ((current_count-1) >> 1);
		int total = block * (N + 1);	// 当前所在的这个zigzag块所占用的全部元素个数	
		// 第一行或者最后一行，每个块里都只有一个元素
		if (row_index == 0 || row_index == numRows-1)
			return total + row_index;

		if ((current_count & 1) == 1)
			return total - row_index;
		else
			return total + row_index;
	}
};

int main()
{
	int test_cases = input<int>();
	for (int i = 1; i <= test_cases; ++i)
	{
		string ori = input<string>();
		int numRows = input<int>();
		string answer = input<string>();
		assert(Solution().convert(ori, numRows) == answer);
		cout << "Nice! Pass case " << i << endl;
	}

	cout << "Excellent! All test cases pass." << endl;

	return 0;
}
