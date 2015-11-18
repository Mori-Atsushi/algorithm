/* E1237 森篤史 */

#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
	int item;
	struct cell *next;
} cell_t;

/*メモリ確保*/
cell_t *lalloc(void) {
	return (cell_t *)malloc(sizeof(cell_t));
}

/*先頭にデータ挿入*/
cell_t *push(int x, cell_t *top) {
	cell_t *p;
	p = lalloc();
	p->item = x;
	p->next = top;
	return(p);
}

/*先頭のデータを取り出す*/ 
cell_t *pop(cell_t *top) {
	int x;

	x = top->item;
	top = top->next;
	printf("%d, ", x);

	return (top);
}

/*iコマンド*/
cell_t *i(cell_t *top) {
	int x;
	printf("入力データ：");
	scanf(" %d", &x);
	return push(x, top);
}

/*dコマンド*/
cell_t *d(cell_t *top) {
	cell_t *tmp;

	if(top == NULL) {
		printf("スタックは空です。\n");
		return top;
	}

	tmp = top->next;
	free(top);

	return tmp;
}

/*mコマンド*/
cell_t *m(cell_t *top) {
	cell_t *tmp = top, *next;
	int i, x;

	if(top == NULL) {
		printf("スタックは空です。\n");
		return top;
	}

	printf("削除数：");
	scanf(" %d", &x);
	for(i = 0; i < x; i++) {
		next = tmp->next;
		free(tmp);
		tmp = next;

		if(tmp == NULL) {
			printf("スタックが空になりました。\n");
			return tmp;
		}
	}
	return tmp;
}

/*pコマンド*/
void p(cell_t *top) {
	cell_t *tmp;
	if(top == NULL) {
		printf("スタックは空です。\n");
		return ;
	}
	tmp = top;
	while(tmp != NULL) {
		tmp = pop(tmp);
	}
	printf("\n");
}

int main(void) {
	cell_t *top = NULL; //スタックの先頭
	char c;
	int x;

	while(1) {
		printf("コマンド：");
		scanf(" %c", &c);
		switch(c) {
			case 'i':
				top = i(top);
				break;
			case 'd':
				top = d(top);
				break;
			case 'm':
				top = m(top);
				break;
			case 'p':
				p(top);
				break;
			case 'q':
				return 0;
			default :
				printf("入力はi,d,m,p,qのいずれかを入力してください。\n");
		}
	}

	return 0;
}