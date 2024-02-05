#include <stdio.h>

//입력한 각 줄에 있는 단어의 수와 공백을 제외한 글자 수를 세어 출력하는 프로그램.

int main(void)
{
	int word = 1;	//단어 수를 세는 변수
	int letter = 0;	//글자 수를 세는 변수
	char ch;		//입력받는 문자

	while (scanf_s("%c", &ch, 1)!= EOF) {  //EOF가 들어오면 프로그램을 종료한다.
		if (ch==32) {
			word++;	//빈칸이 입력되면 단어 하나가 생성된 것으로 판단한다.
		}
		if (ch!=32 && ch!='\n') {
			letter++; //빈칸과 '\n'을 제외한 모든 문자는 글자로 취급하여 센다.
		}
		if (ch=='\n') {
			printf("%d %d\n", word, letter);	//결과를 출력한다.
			word = 1;
			letter = 0;
		}
	}
	return 0;
}
