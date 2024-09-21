#include <stdio.h>

void test(int *i) {
	int aa = 0;	
	int dd = 0;
	*i = 10;
}

int main(void) {
	int bb = 1;
	int cc = 99;

	test(&bb);
	printf("bb = %d\n", bb);

	return 0;
}
