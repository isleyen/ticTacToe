#include <iostream>
#include <string>

using namespace std;


int main() {
	char board[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	const char playerX = 'X';
	const char playerO = 'O';
	char currentPlayer = playerX;
	int r = -1; // -1 olmas� kullan�c�n�n ge�erli bir hamle yapmad���n� g�sterir. // row: sat�r 
	int c = -1; // r ve c s�ras�yla sat�r ve s�tun indexi tutar memoryde.    // column: s�tun
	char winner = ' ';
	for (int i = 0; i < 9; i++) {
		// Game Board  // MATR�S mant��� ile yaz�lm�� bir tahta yani benim XOX oyunu bu tahta �zerinde oynanacak
		cout << "    |    |    " << endl;
		cout << " " << board[0][0] << "  |  " << board[0][1] << " | " << board[0][2] << endl;
		cout << "____|____|____" << endl;
		cout << "    |    |    " << endl;
		cout << " " << board[1][0] << "  |  " << board[1][1] << " | " << board[1][2] << endl;
		cout << "____|____|____" << endl;
		cout << "    |    |    " << endl;
		cout << " " << board[2][0] << "  |  " << board[2][1] << " | " << board[2][2] << endl;
		cout << "    |    |    " << endl;

		if (winner != ' ') {
			break;
		}
		// Kullan�c� Inputlar�
		cout << "Current Player is " << currentPlayer << endl;
		while (true) {
			cout << "Enter r c from 0-2 for row and column: ";
			cin >> r >> c;
			if (r < 0 || r>2 || c < 0 || c>2) {
				cout << "Invalid input, try again.";
			}
			else if (board[r][c] != ' ') { // Hucre dolu mu de�il mi kontrol eder
				cout << "Title is full, try again.";
			}
			else {
				break;

			}
			r = -1;
			c = -1; // r ve c s�f�rlan�r, tekrardan kullan�c�dan de�er almak i�in haz�r hale getirilir.
			cin.clear(); // girdi ak���ndaki hatalar� temizler.
			cin.ignore(10000, '\n');  // Ak��taki gereksiz karakterleri temizler. 

		}

		board[r][c] = currentPlayer;
		currentPlayer = (currentPlayer == playerX) ? playerO : playerX; // Oyuncu s�ras� de�i�tirir.

		// Kazanan kontrolleri

		//Yatay sat�rtlar i�in:
		for (int r = 0; r < 3; r++) {
			if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
				winner = board[r][0];
				break;

			}
		}
		// Dikey s�tunlar i�in
		for (int c = 0; c < 3; c++) {
			if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
				winner = board[0][c];
				break;

			}
		}

		// �apraz Kontrol
		if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			winner = board[0][0];
		}
		else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			winner = board[0][2];
		}

		// Kazanan� Ekrana Yazd�rma
		if (winner != ' ') {
			cout << "Player " << winner << " is the WINNER!" << endl;

		}
		
	}
	return 0;
}