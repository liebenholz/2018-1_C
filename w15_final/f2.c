#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char order[100] = "";	//사용자가 메뉴를 입력받는다
	char number[100];		//몇 번째 메뉴를 받았는지 기록한다
	char buffer[100];		//메뉴의 번호를 거쳐가는 버퍼
	char list[10000] = "";	//주문 목록
	int num = 1;	//주문 번호
	int i, j;
	int loc;
	char c;
	char *p;
	

	while(1) {
		fgets(order,100,stdin);
		//메뉴 입력을 종료할 때(0)
		if (strstr(order,"end")!= NULL) break;

		//선택한 메뉴를 cancel 할 때
		
		else if (strstr(order,"cancel")!= NULL) {
			i=0;
			for(i=0; i<10; i++) {
				if(isdigit(order[i])!=0) {
					c = order[i];
					if ((int)c >= num || (int)c <=0)	//해당 주문 번호가 리스트에 없으면 에러
						printf("enter legal cancel number(1 ~ %d)\n", num-1);
					else {
						//해당 번호의 주문 지우기
						p = strchr(list, c);
						loc = (int)(p - list);
						list[loc-1] = '\0';
						j=loc;
						while (order[j] != '\n') {
							list[j] = '\0';
							j++;
						}
					}
				}
			}
		}
		

		//queue 안의 첫번째 요리를 내보낼 때 
		else if (strstr(order,"cook")!= NULL) {
			i=0;
			while (order[i] != '\n') {
				list[i] = '\0';
				i++;
			}
		}

		//주문을 받는다(0)
		else {
			strcpy(number,"[ ] ");
			sprintf(buffer, "%d", num);
			number[1] = buffer[0];
			num++;

			//주문 번호와 메뉴를 리스트에 추가
			strcat(number, order);
			printf("%s", number);
			strcat(list,number);
		}
	}
	printf("---order list------\n");
	printf("%s", list);
	printf("-------------------\n");
	return 0;
}