#include "seqlist.h"


void checkCapicity(seqList* seq)//检查容量，扩容
{
	if (seq->capicity == seq->size)
	{
		seqDataType* tmp = NULL;
		int n = (seq->capicity == 0 ? 1 : 2 * seq->capicity);

		//tmp = (seqDataType*)malloc(n * sizeof(seqDataType));
		//memcpy(tmp, seq->data, seq->size * sizeof(seqDataType));
		//free(seq->data);


		tmp = (seqDataType*)realloc(seq->data, n*sizeof(seqDataType));
		if (tmp == NULL)
		{
			perror("Realloc is wrong!");
			return;
		}
		seq->data = tmp;
		seq->capicity = n;
	}
}

void print(seqList* seq)//打印数据
{
	if (seq == NULL)
	{
		perror("Print is wrong!");
		return;
	}
	for (int i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->data[i]);
	}
	printf("\n");
}

int empty(seqList* seq)//判断顺序表是否为空
{
	if (seq == NULL || seq->size == 0)
		return 0;
	else
		return 1;
}

int size(seqList* seq)//查看数据个数
{
	if (seq == NULL)
		return 0;
	else
		return seq->size;
}

void init(seqList* seq)//动态顺序表初始化
{
	if (seq == NULL)
	{
		perror("Seq is null!");
		return;
	}
	seq->data = NULL;
	seq->capicity = 0;
	seq->size = 0;
}

void pushBack(seqList* seq, seqDataType c)//尾插 
{
	if (seq == NULL)
	{
		perror("Pushback is wrong!");
		return;
	}
	checkCapicity(seq);
	seq->data[seq->size] = c;
	seq->size++;
}

void popBack(seqList* seq)//尾删
{
	if (empty(seq)== 0)
	{
		perror("Seq is empty!");
		return;
	}
	else
	{
		seq->size--;
	}

}

void pushFront(seqList* seq, seqDataType c)//头插
{
	if (empty(seq) == 0)
	{
		perror("Seq is null!");
		return;
	}
	checkCapicity(seq);
	int end = seq->size;
	while (end > 0)
	{
		seq->data[end] = seq->data[end - 1];
		end--;
	}
	seq->data[0] = c;
	seq->size++;
}

void popFront(seqList* seq)//头删
{
	if (empty(seq) == 0)
	{
		perror("Seq is null!");
		return;
	}
	int start = 1;
	while (start < seq->size)
	{
		seq->data[start - 1] = seq->data[start];
		start++;
	}
	seq->size--;
}

void insert(seqList* seq, int posion, seqDataType c)//随机插入
{
	if (empty(seq) == 0)
	{
		perror("Seq is null!");
		return;
	}
	if (posion >= 0 && posion <= size)
	{
		checkCapicity(seq);
		int end = seq->size;
		while (end > posion)
		{
			seq->data[end] = seq->data[end - 1];
			end--;
		}
		seq->data[posion] = c;
		seq->size++;
	}
	
}

void delete(seqList* seq, int posion)//随机删除
{
	if (empty(seq) == 0)
	{
		perror("Seq is null!");
		return;
	}
	if (posion >= 0 && posion < seq->size)
	{
		int start = posion;
		while (start < seq->size)
		{
			seq->data[start] = seq->data[start + 1];
			start++;
		}
		seq->size--;
	}
}

seqDataType searchPos(seqList* seq, int position)//按位置查找某个数据返回数据值
{
	if (seq->data == NULL)
	{
		perror("Search is wrong!");
		return;
	}
	return seq->data[position];
}

int searchValue(seqList* seq, seqDataType c)//按值查找某个数据返回数据位置
{
	if (empty(seq) == 0)
	{
		perror("Seq is null!");
		return -1;
	}
	for (int i = 0; i < seq->size; i++)
	{
		if(seq->data[i] == c)
		{
			return i;
		}
	}
	printf("No this data!\n");
	return - 1;
}

void destory(seqList* seq)//顺序表的销毁
{
	if (empty(seq) == 0)
	{
		perror("Seq is null!");
		return;
	}
	free(seq->data);
	seq->data = NULL;
}