#include <iostream>
#include <ctime>
using namespace std;

char board[3][3] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'} };

int row;
int col;
int player = 0;
int Gamestatus = 0;//0-igra prodoljayetsya, 1-nichya, 2-Igrok, 3-bot
int indicator = -1;

void showBoard() {
	cout << "______________" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i][j];
			if (j != 2) {
				cout << "  |  ";
			}
		}

		cout << endl;
		if (i != 2) {
			cout << "______________" << endl;
		}

	}
}

bool userChoise(int  num) {
	row = (num - 1) / 3;
	col = (num - 1) % 3;
	if (num > 9 || num < 1) {
		return false;
	}
	else if (board[row][col] != 'X' && board[row][col] != 'O') {
		return true;
	}
	else {
		return false;
	}
}

int WinCheck() {
	//Horizontal lines
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
			return 2;
		}
		else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
			return 3;
		}
	}

	//Vertical lines
	for (int j = 0; j < 3; j++) {
		if (board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X') {
			return 2;
		}
		else if (board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O') {
			return 3;
		}
	}
	//Diagonales
	if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
		return 2;
	}
	else if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
		return 3;
	}
	//Tie
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (char(board[i][j]) <= 57 && char(board[i][j]) >= 46) {
				indicator = 0;
			}
		}
	}
	if (indicator == -1) {
		indicator = 1;
	}
	return indicator;

}

void computerChoise() {
	srand(time(0));
	bool isFull = true;

	while (isFull) {
		if (WinCheck() != 0) {
			break;
		}
		int comp = rand() % 9 + 1;
		row = (comp - 1) / 3;
		col = (comp - 1) % 3;
		if (board[row][col] != 'X' && board[row][col] != 'O') {
			isFull = false;
		}
	}
}

void move() {
	if (player == 0 && WinCheck() == 0) {
		board[row][col] = 'X';
		player = 1;
	}
	else if (WinCheck() == 0) {
		board[row][col] = 'O';
		player = 0;
	}
}



int main()
{
	cout << "----Tic-Tac-Toe Game----" << endl;
	showBoard();
	do {
		int point;
		cout << "Write the position: ";
		cin >> point;
		if (userChoise(point)) {
			move();
		}
		else {
			continue;
		}
		computerChoise();
		move();
		system("cls");
		showBoard();
		switch (WinCheck()) {
		case 1:
			cout << "Draw!" << endl;
			break;
		case 2:
			cout << "Congratulations! Player Won!" << endl;
			break;
		case 3:
			cout << "Computer Won!" << endl;
			break;
		}

	} while (!WinCheck());
}
