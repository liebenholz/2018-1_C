#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_board (char board[][8]);
int get_knight_move (char board[8][8]);
void disp_board (char board[][8]);
int x_position, y_position;

int main ()
{
	char board [8][8];
	int quit = 0;
	int i, j;

	srand( (unsigned) time( NULL ) );

	//초기의 나이트의 위치는 임의의 값으로 정해준다.
	x_position = rand()%8;
	y_position = rand()%8;

	do {
		//체스판을 초기화하고 나이트의 위치를 배열상에 표시한다.
		init_board(board);
		board[x_position][y_position] = 'A';
		
		//나이트가 움직일 수 있는 위치를 표시한다.
		for (i=0; i<8; i++) {
		for (j=0; j<8; j++) {
			if (x_position - i == 1 && y_position -j ==2 ) 
				board[i][j] = '0';
			if (x_position - i == 2 && y_position -j ==1 ) 
				board[i][j] = '0';
			if (x_position - i == -1 && y_position -j ==2 ) 
				board[i][j] = '0';
			if (x_position - i == -2 && y_position -j ==1) 
				board[i][j] = '0';
			if (x_position - i == 1 && y_position -j ==-2 ) 
				board[i][j] = '0';
			if (x_position - i == 2 && y_position -j ==-1 ) 
				board[i][j] = '0';
			if (x_position - i == -1 && y_position -j ==-2 ) 
				board[i][j] = '0';
			if (x_position - i == -2 && y_position -j ==-1 ) 
				board[i][j] = '0';
			}
		}
		disp_board(board);
		quit = get_knight_move(board);
	} while(quit == 0);

	return 0;

}

//체스판을 초기화한다.
void init_board(char board[][8])
{
	int x, y;
	for (x=0; x<8; x++) {
		for (y=0; y<8; y++) {
			board[x][y] = ' ';
		}
	}
}

//사용자가 어느 위치로 이동할 지 입력받는다.
int get_knight_move (char board[8][8]) {
	int x, y, done = 0;
	int i, j;
	while(done != 1) {
		printf("나이트를 움직일 좌표를 입력하세요\n");
		printf("0~7 범위 밖의 수를 입력하면 종료합니다 : ");
		scanf("%d %d", &x, &y);
		if (x<0 || x>7 || y<0 || y>7) {
			printf("종료합니다\n");
			return 1;
		}
		if (board[x][y] == '0') {
			x_position = x;
			y_position = y;
			return 0;
		}
		else {
			printf("움직일 수 없는 좌표입니다.\n\n");
		}
	}
	return 0;
}

//나이트의 위치와 나이트가 어디로 이동할 수 있는지 표시된 체스판을 출력한다.
void disp_board(char board[8][8])
{
	int i, j;
	for (i=0; i<8; i++) {
		printf("|---|---|---|---|---|---|---|---|\n");
		for (j=0; j<8; j++) {
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
	}
	printf("|---|---|---|---|---|---|---|---|\n");
}