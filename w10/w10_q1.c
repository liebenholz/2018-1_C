// 수열을 출력하고 짝수, 홀수가 등장한 횟수와 최대값 출력하기
// 재귀함수를 사용할 것
#include <stdio.h>

void sequence(int n, int odd, int even, int max);

int main(void)
{
	int in;			//사용자가 입력하는 숫자
	int odd = 0;	//홀수 개수
	int even = 0;	//짝수 개수
	int max = 1;	//최대값

	printf(">> ");
	scanf("%d", &in);	//값 입력
	
	//수열을 출력하고 짝수 개수, 홀수 개수, 최대값을 출력하는 함수
	sequence(in, odd, even, max);

	return 0;
}

void sequence(int n, int odd, int even, int max)
{		

	printf("%d ", n);
	if (n==1) {   //종료 조건과 실행
		odd++;
		printf("\n");
		printf("짝수 %d회\n", even);
		printf("홀수 %d회\n", odd);
		printf("max : %d\n", max);
	}
	else {
	    if (n>max) {
			max = n;	//최대값 갱신하기
		}
		if(n%2 == 1) {  //홀수일 때
			n = n*3 +1;
			odd++;
			return sequence(n, odd, even, max);
		}
		else {          //짝수일 때
			n= n/2;
			even++;
			return sequence(n, odd, even, max);
		}
	}

}