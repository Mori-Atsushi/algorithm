/* E1237 森篤史 */

#include <stdio.h>

#define MAX 5 //データ数

/*iコマンド*/
void i(int **h, int **t, int *r, int *d) {
	int x;
	int *tmp;
	if(*t == d) {
		*h = r;
		*t = r;
	} else {
		tmp = r + ((*t - r + 1) % MAX);
		if(tmp == *h) {
			printf("キューが満杯です。\n");
			return ;
		}
		*t = tmp;
	}
	printf("入力データ：");
	scanf(" %d", &x);
	**t = x;
	return;
}

/*dコマンド*/
void d(int **h, int **t, int *r, int *d) {
	int *tmp;
	if(*h == d) {
		printf("キューが空です。\n");
		return;
	}

	if(*h == *t) {
		*h = d;
		*t = d;
	} else {
		*h = r + ((*h - r + 1) % MAX);
	}
}

/*pコマンド*/
void p(int *h, int *t, int *r, int *d) {
	int *tmp;
	int i;
	if(h == d) {
		printf("キューが空です。\n");
		return;
	}
	if(h == t) {
		printf("%d, \n", *h);
		return;
	}
	for(i = 0; i < 5; i++) {
		tmp = r + ((h - r + i) % MAX);
		printf("%d, ", *tmp);	
		if(tmp == t)
			break;
	}
	printf("\n");
}

int main(void) {
	int ring[MAX], dummy; //データ
	int *head = &dummy, *tail = &dummy; //リングバッファの現在地
	char c;

	while(1) {
		printf("コマンド：");
		scanf(" %c", &c);
		switch(c) {
			case 'i':
				i(&head, &tail, ring, &dummy);
				break;
			case 'd':
				d(&head, &tail, ring, &dummy);
				break;
			case 'p':
				p(head, tail, ring, &dummy);
				break;
			case 'q':
				return 0;
			default :
				printf("i,d,p,qのいずれかを入力してください。\n");
		}
	}
	return 0;
}