//(x0)^3 - 2(x0)^2 + 3^(x1)^2의 각 변수에 대한 편미분을 구하는 프로그램
#include <stdio.h>

void partial_differentiation(float x0, float x1, float *dx0, float *dx1);

int main(void) {

	float x0;
	float x1;
	float dx0;	//x0에 대한 편미분계수
	float dx1;	//x1에 대한 편미분계수

	printf("두 실수를 입력하세요 : ");
	scanf("%f %f",&x0, &x1);

	partial_differentiation(x0, x1, &dx0, &dx1);

	printf("(%f, %f)에서 x0의 편미분 : %f\n", x0, x1, dx0);
	printf("(%f, %f)에서 x1의 편미분 : %f\n", x0, x1, dx1);

	return 0;
}

//주어진 다항식을 각 변수에 대하여 편미분하는 함수
void partial_differentiation(float x0, float x1, float *dx0, float *dx1) {
	*dx0 = 3 * x0 * x0 - 4 * x0;	//x0에 대한 편미분
	*dx1 = 6 * x1;	//x1에 대한 편미분
}