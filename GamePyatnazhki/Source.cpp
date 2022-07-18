//Игра пятнажки. нужно в правилбном порядке расположить в поле цифры от 1 до 15.
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

	//вывод стандартного поля
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
	for (size_t i = 0; i < 100; i++)//цикл в котором указываем сколько раз будем перемешивать цифрой 10
	{
		int x1 = rand() % 4;
		int x2 = rand() % 4;
		int y1 = rand() % 4;
		int y2 = rand() % 4;
		char temp = gameField[x1][y1];
		gameField[x1][y1] = gameField[x2][y2];
		gameField[x2][y2] = temp;
	}

	//вывод поля для игры
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

void location(int &x, int &y) { //функция для нахождения пустого поля которое будет перемещаться
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
	int x, y;//x-строка, y-столбец
	location(x, y);
	printGameField();
	do {
		keyQ = _getch();
		if (keyQ == -32) {//-32 отвечает за то, что нажаты именно стрелки
			keyC = _getch();
			if (keyC == 72 && x!=3) {//стрелка вверх UP (меняется строка) x!=3 делаем ограничения по линии, наблюдается реверсия т.к мы меняем не * а саму цифру
				gameField[x][y] = gameField[x + 1][y];
				gameField[x + 1][y] = '*';
				x++;//вопрос почему увеличиваем x?
			}
			if (keyC == 80 && x!=0) {//стрелка вниз DOWN (меняется строка)
				gameField[x][y] = gameField[x - 1][y];
				gameField[x - 1][y] = '*';
				x--;
			}
			if (keyC == 75 && y!=3) {//стрелка влево LEFT (меняется столбец)
				gameField[x][y] = gameField[x][y + 1];
				gameField[x][y + 1] = '*';
				y++;
			}
			if (keyC == 77 && y!=0) {//стрелка впрааво RIGHT (меняется столбец)
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