# Day 3
### ZigZag Conversion
一开始算法没考虑清晰，而且还忽略了边界情况（numRows=1时会退化）。先设计好算法，证明好正确性，再开始写代码。


# Day 2
### Longest Substring Without Repeating Characters
最长不出现重复字母的子串，算法很简单，可以暴力从每个index开始都查找一遍这个子串（这是O(N^2)的复杂度），也可以打表，用前面已经打过的表来减少查找复杂度，每个下标最多会被访问一次，整体复杂度为O(N)。


# Day 1
### Two Sum
忽略了关键条件：同一个元素最多只能用一次

### Add Two Numbers
忽略了1 + 99 = 100这种最终会进位的情况，单纯模拟了按位加法，没有彻底清晰的算法流程意识。

