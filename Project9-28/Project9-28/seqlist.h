#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int seqDataType;
typedef struct seqList
{
	seqDataType* data;
	int size;
	int capicity;
} seqList;

void checkCapicity(seqList* seq);//检查容量
void print(seqList* seq);//打印数据
int empty(seqList* seq);//判断顺序表是否为空
int size(seqList* seq);//查看数据个数

void init(seqList* seq);//初始化
void pushBack(seqList* seq, seqDataType c);//尾插 
void popBack(seqList* seq);//尾删
void pushFront(seqList* seq, seqDataType c);//头插
void popFront(seqList* seq);//头删
void insert(seqList* seq, int posion, seqDataType c);//随机插入
void delete(seqList* seq, int posion);//随机删除
seqDataType searchPos(seqList* seq, int position);//按位置查找某个数据返回数据值
int searchValue(seqList* seq, seqDataType c);//按值查找某个数据返回数据位置
void destory(seqList* seq);//顺序表的销毁
