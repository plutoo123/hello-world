#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void get(int *p, int n);//��ȡ�������������
void fun(int *p, int n);//ð�����򷨣�����Ԫ�شӴ�С����
void pri(int *p, int n);//��ӡ����Ԫ��

int main(void) {
	int a[20];
	get(a, 20);
	fun(a, 20);
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
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (p[j] < p[j + 1]) {
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void pri(int *p, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\n", p[i]);
	}
}