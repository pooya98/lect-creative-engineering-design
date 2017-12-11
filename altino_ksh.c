#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int count1, count2;
typedef struct space {
	int dec;
	char hex[20];
	char oct[20];
	char cha;
}space;
void hex(space space[20], int n,int count) {
	int a,i;
	char b;
	for (i = 0;; i++) {
		a = n % 16;
		if (a >= 0 && a < 10) space[count].hex[i] = 48+a;
		else if (a == 10) space[count].hex[i] = 65;
		else if (a == 11) space[count].hex[i] = 66;
		else if (a == 12) space[count].hex[i] = 67;
		else if (a == 13) space[count].hex[i] = 68;
		else if (a == 14) space[count].hex[i] = 69;
		else if (a == 15) space[count].hex[i] = 70;
		n /= 16;
		count1=i;
		if (n == 0) break;
	}
	space[count].hex[count1 + 1] = NULL;
	a = strlen(space[count].hex)-1;
	for (i = 1;i<=a; i++) {
		b = space[count].hex[a-i];
		space[count].hex[a - i] = space[count].hex[i];
		space[count].hex[i] = b;
	}
}
void oct(space space[20], int n, int count) {
	int a, i,b;
	for (i = 0;; i++){
		a = n % 8;
		space[count].oct[i] = 48+a;
		n /= 8;
		count2 = i;
		if (n == 0) break;
	}
	space[count].oct[count2 + 1] = NULL;
	a = strlen(space[count].oct) - 1;
	for (i = 1; i <= a; i++) {
		b = space[count].oct[a - i];
		space[count].oct[a - i] = space[count].oct[i];
		space[count].oct[i] = b;
	}
}
int main() {
	int i, count;
	int n[2];
	space space[20];
	printf("n1부터 n2까지의 아스키코드를 출력합니다.\n");
	for (i = 0; i <= 1; i++) {
		printf("n%d : ", i + 1);
		scanf("%d", &n[i]);
	}
	printf("DEC	HEX	OCT	Char\n");
	for (i = n[0], count = 0; i <= n[1]; count++, i++) {
		if (count == 20) break;
		space[count].dec = i;
		hex(space, i, count);
		oct(space, i, count);
		space[count].cha = i;
	}
	for (i=0; i <= count-1; i++) {
		printf("%d	0x", space[i].dec);
		printf("%s",space[i].hex);
		printf("	0");
		printf("%s", space[i].oct);
		printf("	%c\n", space[i].cha);
	}
	return 0;
}