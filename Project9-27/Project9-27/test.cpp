#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void A(int N, int M)  //ʱ�临�Ӷ�M+N
{
	int count = 0;
	for (int i = 0; i < M; ++i) //M��
	{
		++count;
	}
	for (int j = 0; j < N; ++j) //N��
	{
		++count;
	}
	printf("%d\n", count);
}

void BubbleSort(int* arr, int n) //ʱ�临�Ӷ�n^2
{
	assert(arr);
	int tmp = 0;
	for (int i = 0; i < n; i++) 
	{
		int flag = 0;//�Ż�
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

int BinarySearch(int* arr, int num, int c)//ʱ�临�Ӷȣ�log2n����2Ϊ�ף�
{
	//arr���Ź���
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

long long B(int n) //ʱ�临�Ӷȣ�n
{
	return n < 2 ? n : B(n - 1) * n;
}

long long C(int n) //ʱ�临�Ӷȣ�2^n
{
	return n < 2 ? n : C(n - 1) + C(n - 2);
}

long long D(int n) //�ռ临�Ӷȣ�n
{
	//�ǵݹ�쳲���������
	

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