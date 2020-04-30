#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//����˳���ʵ��ջ
//ջ:����ȳ�
typedef int TypeData;

typedef struct Stack {
	TypeData* _array;
	size_t _size;
	size_t _capacity;
}Stack;
//ջ�ĳ�ʼ��
void StackInit(Stack* sk, int n) {
	sk->_array = (TypeData*)malloc(sizeof(TypeData)*n);
	sk->_size = 0;
	sk->_capacity = n;
}
//ջ��β��
void StackBackPush(Stack* sk,TypeData data) {
	if (sk->_size == sk->_capacity) {
		sk->_capacity *= 2;
		sk->_array = (TypeData*)realloc(sk->_array, sk->_capacity*sizeof(TypeData));
	}
	sk->_array[sk->_size++] = data;
}
//ջ��β��
void StackBackPop(Stack* sk) {
	if(sk->_size)
	sk->_size--;
}
//��ȡջ��Ԫ��
TypeData StackTop(Stack* sk) {
		return sk->_array[sk->_size - 1];
}
//�п�
int StackEmpty(Stack* sk) {
	if (sk->_size == 0)
		return 1;
	return 0;
}
//ջ������
void StackDesory(Stack* sk) {
	free(sk->_array);
	sk->_array = NULL;
	sk->_capacity = sk->_size = 0;
}
