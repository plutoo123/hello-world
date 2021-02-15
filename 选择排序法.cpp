#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void get(int *p, int n);//获取随机数传给数组
void fun(int *p, int n);//选择排序法，数组元素从小到大排序
void fun1(int *p, int n);//选择排序法，数组元素从小到大排序*改进版
void pri(int *p, int n);//打印数组元素

int main(void) {
	int a[20];
	get(a, 20);
	fun1(a, 20);
	pri(a, 20);
	return 0;
}

void get(int *p, int n) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		p[i] = rand() % 100;
	}
}

void fun(int *p, int n) {
	/*
		原理：第一个数依次和后面的数依次比较大小，若有比第一个数还小的，就交换数组元素的
		数据（需要三行的交换代码段），以此类推第二个数、第三个数···直到比较到倒数第二个数和
		最后一个数的比较。

		可以改进的地方：定义一个变量min，将第一个数组元素开始，依次将下标赋值给min,和上面
		类似的，但是将交换数组元素改为将比它还小的数组元素的下标赋值给min，再用if语句判断
		是否有比第一个还小的数，表现为min不等于第一个数组元素的下标，因为这时数组中其他元素
		的下标赋值给了min，而其他下标一定不等于第一个数组元素的下标，如果判断有比第一个数还
		小的数，则运行交换代码段。改进的版本将反复n次的3行交换代码段换成了反复n次的给min赋
		值的一行代码，更简洁，运行更快速；另外，第二个if语句判断了是否需要交换，尽管不用if
		语句，直接将这个if语句内的代码块单独拿出来也不会有什么问题，但是if语句避免了没有必要
		的操作，比如交换同一个数组：a[min]与a[i]交换等价于a[i]与a[i]交换，就很没有必要了。
	*/
	int min;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[j] < p[i]) {
				min = p[j];
				p[j] = p[i];
				p[i] = min;
			}

		}
	}
}

void fun1(int *p, int n) {//改进版
	int min, temp;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (p[j] < p[min]) {
				min = j;
			}
		}
		if (min != i) {
			temp = p[i];
			p[i] = p[min];
			p[min] = temp;

		}
	}
}

void pri(int *p, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\n", p[i]);
	}
}

