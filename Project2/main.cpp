#include<iostream>
#include<cstdio>
#include<fstream>
#include"elevector.h"
int time1 = 0;
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ofstream outFile;
	elevector lift;
	lift.time = 0;lift.floor = 0;
	int a[3][100];
	int n, i;
	int temp0, temp1, temp3;
	cin >> n;
	for (i = 0;i<n;i++)
	{
		cin>>a[0][i]>>a[1][i]>>a[2][i];

	}
	for (i = 0;i < n-1;i++)
	{
		if(a[2][i]-a[1][i]>0&&a[2][i+1]-a[1][i+1]>0)
			if (a[0][i + 1]-a[0][i] <= abs(a[2][i] - a[1][i]) && a[2][i] == a[2][i + 1])
				a[2][i] = a[1][i + 1];
		if (a[2][i] - a[1][i] < 0 && a[2][i + 1] - a[1][i + 1] < 0)
		{
			if(a[0][i + 1] - a[0][i] <= abs(a[2][i] - a[1][i]) && a[2][i] == a[2][i + 1])
				a[2][i] = a[1][i + 1];
		}
	}
	for (i = 0;i < n;i++)
	{
		lift.requestTime = a[0][i];
		lift.passengerFloor = a[2][i];
		lift.targetFloor = a[1][i];
		if (lift.floor != lift.targetFloor)
		{
			lift.goToFloor1(lift.passengerFloor, lift.targetFloor, lift.requestTime, &lift.time, &lift.floor);//电梯的运行
			printf("%d %d\n", lift.time, lift.floor);//电梯运行到离他最近的地方
			lift.stop(&lift.time);
		}
			lift.goToFloor2(lift.passengerFloor, lift.targetFloor, lift.requestTime, &lift.time, &lift.floor);
			printf("%d %d\n", lift.time, lift.floor);

			lift.stop(&lift.time);
	}
	
	return 0;
}