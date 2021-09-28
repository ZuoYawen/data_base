#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void A(int N, int M)  //时间复杂度M+N
{
	int count = 0;
	for (int i = 0; i < M; ++i) //M次
	{
		++count;
	}
	for (int j = 0; j < N; ++j) //N次
	{
		++count;
	}
	printf("%d\n", count);
}

void BubbleSort(int* arr, int n) //时间复杂度n^2
{
	assert(arr);
	int tmp = 0;
	for (int i = 0; i < n; i++) 
	{
		int flag = 0;//优化
		for (int j = 1; i < i; j++)
		{
			if (arr[i - 1] > arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

int BinarySearch(int* arr, int num, int c)//时间复杂度：log2n（以2为底）
{
	//arr已排过序
	assert(arr);
	int begin = 0;
	int end = num - 1;
	while (begin < end) 
	{
		int mid = (begin + end) / 2;
		if (arr[mid] < c)
			begin = mid + 1;
		else if (arr[mid] > c)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

long long B(int n) //时间复杂度：n
{
	return n < 2 ? n : B(n - 1) * n;
}

long long C(int n) //时间复杂度：2^n
{
	return n < 2 ? n : C(n - 1) + C(n - 2);
}

long long D(int n) //空间复杂度：n
{
	//非递归斐波那契数列
	

	long long* f =(long long*)malloc((n + 1) * sizeof(long long));
	if (f == NULL)
	{
		perror("malloc-error:");
		return NULL;
	}
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

long long E(int n) 
{
	return n < 2 ? n : E(n - 1) * n;
}

int main()
{
	//int arr[10] = { 1,2,3,4,5,6 };
	//int ret = BinarySearch(arr, 6, 5);
	//printf("%d", ret);
	printf("%lld",D(-1));
	return 0;
}