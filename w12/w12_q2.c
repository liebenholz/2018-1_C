// 강화게임
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void reinforce_powder(int *item);		//강화가루 사용
void reinforce_stone(int *item);		//강화석 사용
double success_probability(int *item);	//강화 확률

int main(void)
{
	int money = 2000;	//자금
	int item = 0;		//아이템 강화 단계 (값이 -1이면 파괴로 간주한다)
	int command = 0;	//강화가루 or 강화면석 선택

	srand((int)time(NULL));

	printf("---강화 게임---\n\n");
	printf("---강화 재료 가격---\n");
	printf("  강화가루    50\n");
	printf("   강화석     200\n\n");
	
	while(money > 0 && item >= 0) {
		printf("소유 자금 : %d\n",money);
		printf("사용할 강화 재료를 선택하세요 (1: 강화가루, 2: 강화석) : ");
		scanf("%d",&command);

		switch(command) {
		//강화 가루
		case 1:
			money -= 50;
			reinforce_powder(&item);
			break;
		//강화석
		case 2:
			money -= 200;
			reinforce_stone(&item);
			break;
		//입력 오류
		default:
			printf("잘못된 숫자를 입력받았습니다.\n");
			break;
		}
		printf("\n");
	}
	printf("최종 자금 : %d\n", money);

	return 0;
}
	
void reinforce_powder(int *item) {\
	int num = 0;
	double prob = success_probability(item);
	prob *= pow(10.0, *item);
//	printf("%lf\n", prob);

	//랜덤값 추출
	//추출한 값이 성공 확률보다 작으면 성공
	num = rand() % (int)pow(10.0, *item);

	if (num < prob) {
		//성공
		printf("성공!\n");
		(*item)++;
	}
	else {
		//실패
		printf("실패!\n");
		num = rand() % 2;
//		printf("%d",randNum);
		if (num == 0)
			(*item) = 0;
		else {
			printf("파괴되었습니다!\n");
			(*item) = -1;
		}
	}
	if (*item >= 0)
		printf("현재 강화 수치 : +%d\n", *item);
	
}

void reinforce_stone(int *item) { 
	int num = 0;
	double prob = success_probability(item);
	prob *= pow(10.0, *item);
//	printf("%lf\n", prob);

	//랜덤값 추출
	//추출한 값이 성공 확률보다 작으면 성공
	num = rand() % (int)pow(10.0, *item) + 0.1;

	if (num < prob) {
		//성공
		printf("성공!\n");
		(*item)++;
	}
	else {
		//실패
		printf("실패!\n");
		num = rand() % 2;
//		printf("%d",randNum);
		if (num == 0)
			(*item)--;
		else {
			printf("파괴되었습니다!\n");
			(*item) = -1;
		}
	}
	if (*item >= 0)
		printf("현재 강화 수치 : +%d\n", *item);
}
	

double success_probability(int *item) {
	double p = pow(0.8, *item);		//강화단계에 따른 다음 강화 성공 확률
	return p;
}