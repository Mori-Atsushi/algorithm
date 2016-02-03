/* E1237 森篤史 */

#include <stdio.h>
#include <stdlib.h>

#define N 1000000
int seed;

void change(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void init(int A[]) {
	int i;
	srand((unsigned int) seed);

	for(i = 1; i <= N; i++) {
		A[i] = rand();
	}
}

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

void downheap(int *h, int k) {
	int i = 1, l = i * 2, r = i * 2 + 1, v = i;
	while(l <= k) {
		if(*(h + l) > *(h + v))
			v = l;
		if(k > r && *(h + r) > *(h + v))
			v = r;
		if(v == i)
			break;
		change(h + v, h + i);
		i = v;
		l = i * 2;
		r = i * 2 + 1;
	}
}

void all(int *h, int k) {
	int i;

	for(i = 2; i <= k; i++)
		upheap(h, i);
}

int main(void) {
	int a[N + 1], i;
	scanf("%d", &seed);
	init(a);

	all(a, N);
	for(i = N; i > 1; i--) {
		downheap(a, i);
		change(&a[1], &a[i]);
	}

	printf("%d\n", a[N / 2]);

	return 0;
}