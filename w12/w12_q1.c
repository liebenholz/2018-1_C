//두 정수 x, y를 입력받고 그 내용을 서로 바꾸는 프로그램
#include <stdio.h>
void swap (int *a, int *b);

int main () {

	int x;
	int y;	//입력받는 두 정수

	//두 정수 입력받는다
	printf("두 정수를 입력하세요 :");
	scanf_s("%d %d", &x, &y);
	printf("\n");

	//전환 전
	printf("전 (x, y) = (%d, %d)\n", x, y);

	//전환 후
	swap(&x, &y);
	printf("후 (x, y) = (%d, %d)\n", x, y);

	return 0;
}

// 변수의 내용을 바꾸는 함수를 참조에 의한 호출 형태로 작성함
void swap (int *a, int *b) {
	int temp;

	temp = *a;	//temp = x
	*a = *b;	//x = y
	*b = temp;	//y = temp
}