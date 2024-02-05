//안전한 my_strcat() 함수 시험 프로그램.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100	//문자열 배열의 크기

char * my_strcat(char *target, const char *src, const int len) {
	int i = strlen(target);	//target 문자열 길이
	int j = strlen(src);	//src 문자열 길이
	int k = 0;
	//문자열 공간이 충분한 경우에는 strcat(dest, src)를 그대로 사용하여 문자열을 연결한다.
	if (i+j < len)
		strcat(target, src);
	//문자열 공간이 충분하지 않다면 정해진 크기만큼만 잘러서 문자열을 연결한다.
	else {
		printf("경고 : 문자열 공간을 초과하여 일부 잘린 문자열을 출력합니다.\n");
		while (i+k < len-1) {
			target[i+k++] = src[k];	//해당 값까지만 대입한다.
		}
		target[i+k] = NULL;			//문자열 배열의 마지막 자리에는 NULL을 삽입해 입력을 마친다.
	}
}

int main(void){
	char str1[SIZE], str2[SIZE];
 
	while(1) {
		//첫번쨰 문자열 입력(q가 입력되면 종료)
		printf("Enter string1:");
		gets(str1);
		if (str1[0] == 'q')
			return 0;

		//두번째 문자열 입력
		printf("Enter string2:");
		gets(str2);
		//문자열 안전하게 연결
		my_strcat(str1, str2, SIZE);
		//연결된 문자열 출력
		printf("result:%s\n", str1);
	}
	return 0;
}