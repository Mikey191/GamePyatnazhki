//���� ��������. ����� � ���������� ������� ����������� � ���� ����� �� 1 �� 15.
//
#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

char gameField[4][4];
char standartField[4][4];
char symb[] = "123456789ABCDEF";

void fillField() {
	int k = 0;
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			standartField[i][j] = symb[k];
			gameField[i][j] = symb[k];
			k++;
		}
	}
	standartField[3][3] = '*';
	gameField[3][3] = '*';

	//����� ������������ ����
	cout << "Etalon field: " << endl;
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			cout << standartField[i][j];
		}cout << endl;
	}cout << endl;

	//for (size_t i = 0; i < 4; i++) {
	//	for (size_t j = 0; j < 4; j++) {
	//		cout << gameField[i][j];
	//	}cout << endl;
	//}cout << endl;
}

void shake() {
	srand(time(NULL));
	for (size_t i = 0; i < 100; i++)//���� � ������� ��������� ������� ��� ����� ������������ ������ 10
	{
		int x1 = rand() % 4;
		int x2 = rand() % 4;
		int y1 = rand() % 4;
		int y2 = rand() % 4;
		char temp = gameField[x1][y1];
		gameField[x1][y1] = gameField[x2][y2];
		gameField[x2][y2] = temp;
	}

	//����� ���� ��� ����
	cout << "Game field: " << endl;
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			cout << gameField[i][j];
		}cout << endl;
	}cout << endl;
}

void printGameField() {
	system("cls");
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << gameField[i][j];
		}cout << endl;
	}cout << endl;
}

bool chek() {
	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 4; j++)
			if (gameField[i][j] != standartField[i][j])
				return false;
	return true;
}

void location(int &x, int &y) { //������� ��� ���������� ������� ���� ������� ����� ������������
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (gameField[i][j] == '*') {
				x = i;
				y = j;
			}
		}
	}
}

void game() {
	char keyC, keyQ;
	int x, y;//x-������, y-�������
	location(x, y);
	printGameField();
	do {
		keyQ = _getch();
		if (keyQ == -32) {//-32 �������� �� ��, ��� ������ ������ �������
			keyC = _getch();
			if (keyC == 72 && x!=3) {//������� ����� UP (�������� ������) x!=3 ������ ����������� �� �����, ����������� �������� �.� �� ������ �� * � ���� �����
				gameField[x][y] = gameField[x + 1][y];
				gameField[x + 1][y] = '*';
				x++;//������ ������ ����������� x?
			}
			if (keyC == 80 && x!=0) {//������� ���� DOWN (�������� ������)
				gameField[x][y] = gameField[x - 1][y];
				gameField[x - 1][y] = '*';
				x--;
			}
			if (keyC == 75 && y!=3) {//������� ����� LEFT (�������� �������)
				gameField[x][y] = gameField[x][y + 1];
				gameField[x][y + 1] = '*';
				y++;
			}
			if (keyC == 77 && y!=0) {//������� ������� RIGHT (�������� �������)
				gameField[x][y] = gameField[x][y - 1];
				gameField[x][y - 1] = '*';
				y--;
			}
		}printGameField();

	}while(keyC != 13 || chek());
}


int main() {
	fillField();
	shake();
	game();

	return 0;
}