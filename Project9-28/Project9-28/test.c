#include "seqlist.h"
int main()
{
	//����
	seqList* pSeq = (seqList*)malloc(sizeof(seqList));
	//��ʼ��
	init(pSeq);
	//ʹ��
	pushBack(pSeq, 1);
	print(pSeq);
	pushBack(pSeq, 2);
	print(pSeq);
	pushBack(pSeq, 3);
	print(pSeq);
	pushBack(pSeq, 4);
	print(pSeq);
	pushFront(pSeq, 0);
	print(pSeq);
	popBack(pSeq);
	print(pSeq);
	popFront(pSeq);
	print(pSeq);
	insert(pSeq, 2, 8);
	print(pSeq);
	delete(pSeq, 2);
	print(pSeq);
	printf("data:%d \n", searchPos(pSeq, 2));
	int result1 = searchValue(pSeq, 8);
	if (result1 != -1)
	{
		printf("The posion is %d.\n", result1 + 1);
	}
	int result2 = searchValue(pSeq, 3);
	if (result2 != -1)
	{
		printf("The posion is %d.\n", result2 + 1);
	}
	//����
	destory(pSeq);
	free(pSeq);
	pSeq = NULL;

	return 0;
}