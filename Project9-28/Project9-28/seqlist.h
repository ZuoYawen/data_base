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

void checkCapicity(seqList* seq);//�������
void print(seqList* seq);//��ӡ����
int empty(seqList* seq);//�ж�˳����Ƿ�Ϊ��
int size(seqList* seq);//�鿴���ݸ���

void init(seqList* seq);//��ʼ��
void pushBack(seqList* seq, seqDataType c);//β�� 
void popBack(seqList* seq);//βɾ
void pushFront(seqList* seq, seqDataType c);//ͷ��
void popFront(seqList* seq);//ͷɾ
void insert(seqList* seq, int posion, seqDataType c);//�������
void delete(seqList* seq, int posion);//���ɾ��
seqDataType searchPos(seqList* seq, int position);//��λ�ò���ĳ�����ݷ�������ֵ
int searchValue(seqList* seq, seqDataType c);//��ֵ����ĳ�����ݷ�������λ��
void destory(seqList* seq);//˳��������
