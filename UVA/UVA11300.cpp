// UVA11300.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> buf(n,0);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> buf[i];
			sum += buf[i];
		}
		int avg = sum / n;
		for (int i = 0; i < n; i++)
		{

		}
 	}

}
