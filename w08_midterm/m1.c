#include <stdio.h>

//10000 이하의 양의 정수를 여러 개 입력받아 최소값, 최대값을 출력하는 프로그램.

int main(void)
{
	int x = 0;			//스캔하여 입력받는 값
	int max = 0;		//입력받은 정수 중 최댓값이 들어감.
	int min = 10000;	//입력받은 정수 중 최소값이 들어감.

	printf("여러 개의 정수를 입력하시오.(입력의 끝은 -1): ");
	while (x >= 0) {    //입력받은 수가 0 이상일 동안에만 반복한다.
		scanf("%d", &x);	//정수 대입
		if (x>max && x>=0) {
			max = x;		//최대값 대입
		}
		if (x<min && x>=0) {
			min = x;		//최소값 대입
		}
	}
	printf("min = %d, max = %d\n", min, max);	//결과를 출력한다.

	return 0;
	
}