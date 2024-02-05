//야구 게임
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game (int record);

int main()
{
	char command = 'y';		//y/n 입력받는 문자
	int record = 100;		//최고기록
	int previous;			//game을 통해 나온 기록

	printf("-----야구게임-----\n");

	while (command != 'n') {
		previous = game(record);	//게임의 결과를 저장
		if (previous < record) {    //기록 갱신
			record = previous;
		}
		
		printf("계속하시겠습니까?(Y/N) : ");
		scanf(" %c", &command);     //게임 계속의 여부

		if (command == 'n') {
			printf("최고기록 : %d회\n", record);	//최고기록 출력 후 종료
		}
		else if (command != 'y') {
			printf("잘못된 값이 입력되었습니다.\n");	//y,n 이외의 문자는 종료
		}

	}

}

int game (int record)
{
	int r1 = 0;	//1번 수
	int r2 = 0;	//2번 수
	int r3 = 0; //3번 수
	int n1 = 0; //사용자 입력 1번 수
	int n2 = 0; //사용자 입력 2번 수
	int n3 = 0; //사용자 입력 3번 수
	int ball = 0; //ball 개수
	int strike = 0; //strike 수
	int count = 0; //시도 횟수

	srand( (unsigned) time( NULL ) );

	printf("게임 시작!\n");
	//무작위 숫자 3개가 중복되지 않도록 지정한다.
	r1 = 1+rand()%9;
	while (r2 == 0 || r1 == r2)
		r2 = 1+rand()%9;
	while (r3 == 0 || r1 == r3 || r2 == r3)
		r3 = 1+rand()%9;

	printf("%d %d %d\n", r1, r2, r3);

	while (r1!=n1 || r2!=n2 || r3!=n3) {
		printf("세 숫자를 입력하세요 : ");  //사용자가 숫자를 입력한다.
		scanf("%d %d %d", &n1, &n2, &n3);

		//ball, strike 개수 세기
		if (n1 == r1) 
			strike++;
		else if (n1 == r2 || n1 ==r3)
			ball++;
		if (n2 == r2)
			strike++;
		else if (n2 == r1 || n2 ==r3)
			ball++;
		if (n3 == r3)
			strike++;
		else if (n3 == r1 || n3 ==r2)
			ball++;

		if (n1 <1 || n1>9 || n2 <1 || n2>9 || n3 <1 || n3 >9) 	// 1부터 9 사이의 수가 입력되지 않은 경우
			printf("주의 : 적절한 범위 내에서 입력되지 않은 수가 있습니다.\n");

		else if (n1 == n2 || n1 == n3 || n2 == n3)				// 입력된 숫자 중에서 중복되는 숫자가 있는 경우
			printf("주의 : 입력한 숫자 중에 서로 중복되는 수가 있습니다.\n");

		else {   //시도횟수에 1을 더하고 ball, strike 개수를 출력한다.
			count++; 	
			if (ball != 0)
				printf("%d ball", ball);
			if (strike == 0)
				printf("!\n");

			if (strike != 0 && strike!=3) {
				if (ball != 0)
					printf(" ");
				printf("%d strike!\n", strike);
			}
		}

		//ball, strike 초기화
		ball = 0;
		strike = 0;
	}
	//정답이 입력되면
	printf("승리!\n");
	printf("%d회!\n", count);
	printf("\n");

	//시도횟수를 반환한다.
	return count;

}