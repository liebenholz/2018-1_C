#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char order[100] = "";	//����ڰ� �޴��� �Է¹޴´�
	char number[100];		//�� ��° �޴��� �޾Ҵ��� ����Ѵ�
	char buffer[100];		//�޴��� ��ȣ�� ���İ��� ����
	char list[10000] = "";	//�ֹ� ���
	int num = 1;	//�ֹ� ��ȣ
	int i, j;
	int loc;
	char c;
	char *p;
	

	while(1) {
		fgets(order,100,stdin);
		//�޴� �Է��� ������ ��(0)
		if (strstr(order,"end")!= NULL) break;

		//������ �޴��� cancel �� ��
		
		else if (strstr(order,"cancel")!= NULL) {
			i=0;
			for(i=0; i<10; i++) {
				if(isdigit(order[i])!=0) {
					c = order[i];
					if ((int)c >= num || (int)c <=0)	//�ش� �ֹ� ��ȣ�� ����Ʈ�� ������ ����
						printf("enter legal cancel number(1 ~ %d)\n", num-1);
					else {
						//�ش� ��ȣ�� �ֹ� �����
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
		

		//queue ���� ù��° �丮�� ������ �� 
		else if (strstr(order,"cook")!= NULL) {
			i=0;
			while (order[i] != '\n') {
				list[i] = '\0';
				i++;
			}
		}

		//�ֹ��� �޴´�(0)
		else {
			strcpy(number,"[ ] ");
			sprintf(buffer, "%d", num);
			number[1] = buffer[0];
			num++;

			//�ֹ� ��ȣ�� �޴��� ����Ʈ�� �߰�
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