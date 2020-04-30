#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//利用顺序表实现栈
//栈:后进先出
typedef int TypeData;

typedef struct Stack {
	TypeData* _array;
	size_t _size;
	size_t _capacity;
}Stack;
//栈的初始化
void StackInit(Stack* sk, int n) {
	sk->_array = (TypeData*)malloc(sizeof(TypeData)*n);
	sk->_size = 0;
	sk->_capacity = n;
}
//栈的尾插
void StackBackPush(Stack* sk,TypeData data) {
	if (sk->_size == sk->_capacity) {
		sk->_capacity *= 2;
		sk->_array = (TypeData*)realloc(sk->_array, sk->_capacity*sizeof(TypeData));
	}
	sk->_array[sk->_size++] = data;
}
//栈的尾插
void StackBackPop(Stack* sk) {
	if(sk->_size)
	sk->_size--;
}
//获取栈顶元素
TypeData StackTop(Stack* sk) {
		return sk->_array[sk->_size - 1];
}
//判空
int StackEmpty(Stack* sk) {
	if (sk->_size == 0)
		return 1;
	return 0;
}
//栈的销毁
void StackDesory(Stack* sk) {
	free(sk->_array);
	sk->_array = NULL;
	sk->_capacity = sk->_size = 0;
}
