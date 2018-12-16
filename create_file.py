# encoding: utf-8
import sys
import os


test_case_dir = 'test_cases'
title = '_'.join(sys.argv[1:])
cpp_filename = title + '.cpp'
test_case_file = os.path.join(test_case_dir, title + '.txt')

if not os.path.isdir(test_case_dir):
	os.mkdir(test_case_dir)

# 创建cpp文件
cpp_content = """#include "comm_header.h"



int main()
{
	int test_cases = input<int>();
	for (int i = 1; i <= test_cases; ++i)
	{
		
		cout << "Nice! Pass case " << i << endl;
	}

	cout << "Excellent! All test cases pass." << endl;

	return 0;
}
"""
with open(cpp_filename, 'a') as cpp:
	cpp.write(cpp_content)

# 创建测试文件（只是追加文件，确保重入的时候不会冲毁已写的代码）
with open(test_case_file, 'a') as test_case:
	pass
