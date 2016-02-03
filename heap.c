/* E1237 森篤史 */

#include <stdio.h>
#define MAX 10
#define NUM 7

void upheap(int *h, int k) {
	int i = k / 2, v = *(h + k);
	while(i >= 1) {
		if(*(h + i) >= v)
			break;
		*(h + k) = *(h + i);
		k = i;
		i = k / 2;
	}
	*(h + k) = v;
}

void all(int *h, int k) {
	int i;

	for(i = 2; i <= k; i++)
		upheap(h, i);
}

/*iコマンド*/
int ic(int *h, int k) {
	int x, n = k + 1;
	if(k == MAX) {
		printf("ヒープが満杯です。\n");
		return k;
	}
	printf("入力データ：");
	scanf(" %d", &x);
	*(h + n) = x;
	upheap(h, n);

	return n;
}

/*dコマンド*/
int dc(int *h, int k) {
	int n = k - 1;
	if(k == 0) {
		printf("ヒープが空です。\n");
		return k;
	}
	*(h + 1) = *(h + k);
	all(h, n);
	return n;
}

/*pコマンド*/
void pc(int *h, int k) {
	int i;
	if(k == 0) {
		printf("ヒープが空です。\n");
		return;
	}
	for(i = 1; i <= k; i++)
		printf("%d, ", *(h + i));
	printf("\n");
}

int main(void) {
	int i, now = NUM;
	int h[MAX + 1];
	char c;

	for(i = 1; i <= NUM; i++)
		h[i] = i;

	all(h, now);

	while(1) {
		printf("コマンド：");
		scanf(" %c", &c);
		switch(c) {
			case 'i':
				now = ic(h, now);
				break;
			case 'd':
				now = dc(h, now);
				break;
			case 'p':
				pc(h, now);
				break;
			case 'q':
				return 0;
			default:
				printf("i,d,p,qのいずれかを入力してください。\n");
		}
	}

	return 0;
}