// leetcode69.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Solution {
public:
	int mySqrt(int x) {
		long long left = 1, right = x;
		if (x == 0) return 0;//if x<0 return false

		while (left <= right)
		{
			long long mid = (left + right) / 2;
			if (mid*mid == x || (mid*mid<x && (mid + 1)*(mid + 1)>x))
				return mid;
			else
				if (mid*mid<x)
					left = mid + 1;
				else
					right = mid - 1;

		}
		return (left + right) / 2;
	}
};
int main()
{
	Solution sl;
	cout << sl.mySqrt(2147395599) << endl;
}