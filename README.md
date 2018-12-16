# 提高效率，专注解题
这个代码库是本人自己挑战leetcode训练的过程记录。但我觉得这里有一些做法是值得新手来关注和使用的，它们可以帮助你专注解题的实现，减少时间浪费在不必要的环节上。ps，虽然我是写C++的，不过下面所讲的**三个思想是普适的**，你可以在别的语言里运用它们来帮助你高效应对leetcode训练。


## 快速创建代码模板
以题目`ZigZag Conversion`为例，只需在网页上复制题目的名字，然后到命令行里运行`python create_file.py ZigZag Conversion`，则可以生成一个空的测试文件以及一个模板代码文件`ZigZag_Conversion.cpp`，cpp的内容如下：
```C++
#include "comm_header.h"



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
```

main函数之所以这样子写，是因为这样可以支持测试一个或多个测试用例。


## 快速编写测试代码
以`Two Sum`这道题为例，利用生成的模板测试框架代码和`comm_header.h`里提供的输入工具函数，可以快速写出测试代码如下：
```C++
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
```

## 快速构建与测试
由于测试是在本地，已生成了cpp文件和测试数据文件，自行补充好测试数据文件之后就可以简单运行（以以`Two Sum`这道题为例）：
```
3

2 4 3
5 6 4 1
7 0 8 1

5
5 5
0 6

1
9 9
0 0 1
```
上边是测试数据，第一行固定是测试用例的个数，然后可以用任意空行隔开，每一行是一个数组的输入或单一变量的输入，或多个单一变量的输入。

写完测试数据文件，只需要运行构建&测试脚本即可。
```shell
./build_and_run.sh Two_Sum.cpp
```

之所以用cpp文件名作为脚本的输入，是因为在命令行可以用TAB键自动补全当前目录下的文件名。

这个shell脚本会做两件事情：
1. 编译代码；
2. 将测试数据作为标准输入，执行编译后的二进制文件。

