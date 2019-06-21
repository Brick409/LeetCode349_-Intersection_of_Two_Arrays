// Intersection_Two_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
/*
349题目：给定两个数组，查找两个数组中的公共元素。
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
*/
class Solution349 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

		set<int> record; //用于存放nums1中的数组元素

		set<int> result; //用于存放相同元素

		if (nums1.empty() || nums2.empty())
		{
			return res;
		}
		//set类型重复insert相同元素，最终只保存一个，所以可以多次插入
		for (int i = 0; i < nums1.size(); i++)
		{
			record.insert(nums1[i]);
		}

		for (int i = 0; i < nums2.size(); i++)
		{
			if (record.find(nums2[i])!=record.end())
			{
				result.insert(nums2[i]);
			}
		}

		return vector<int>(result.begin(), result.end());

	}
};

/*
350题目：给定两个数组，查找两个数组中的公共元素。
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
*/
class Solution350 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> record;//存储nums1中元素出现的对应频率
		vector<int> res; //存放两个数组的交集

		if (nums1.empty()||nums2.empty())
		{
			return res;
		}

		for (int i = 0; i < nums1.size(); i++)
		{
			record[nums1[i]]++;
		}

		for (int i = 0; i < nums2.size(); i++)
		{
			if (record[nums2[i]]>0)
			{
				res.push_back(nums2[i]);
				record[nums2[i]]--;
			}
		}

		return res;

	}
};
int main()
{
	int nums1[] = { 4, 9, 5 };
	int nums2[] = { 9, 4, 9, 8, 4 };

	vector<int> vec1(nums1, nums1 + sizeof(nums1) / sizeof(int));
	vector<int> vec2(nums2, nums2 + sizeof(nums2) / sizeof(int));

	vector<int> res1 = Solution349().intersection(vec1, vec2);

	for (int i=0;i<res1.size();i++)
	{
		cout << res1[i] << " ";
	}
	cout << endl;

	vector<int> res2 = Solution350().intersect(vec1, vec2);

	for (int i = 0;i < res2.size();i++)
	{
		cout << res2[i] << " ";
	}
	cout << endl;
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
