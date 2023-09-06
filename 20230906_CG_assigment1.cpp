#include <iostream>
#include <random>
#include <chrono>
#include <cstring>

using namespace std;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();

default_random_engine dre(seed);		//랜던값엔진 seed 따라 고정된다 랜던값이
uniform_int_distribution<int> uid(0, 2); //랜덤값범위

// cout printf


int main() {
	char ta[30];
	int x[3][3];
	int y[3][3];
	int num=0;

	while (true) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				x[i][j] = uid(dre);
				cout << x[i][j];
			}cout << endl;
		}cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				y[i][j] = uid(dre);
				cout << x[i][j];
			}cout << endl;
		}cout << endl;

		cin >> ta;
		//cin >> num;

		//m: 행렬의 곱셈
		if (strcmp(ta, "m") == 0) {
			int r[3][3];
			int i, j;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					r[i][j] = x[i][0] * y[0][j] + x[i][1] * y[1][j] + x[i][2] * y[2][j];
					cout << r[i] [j];
				}
				cout << endl;
			}
			cout << endl;
			continue;
		}
		
		//a: 행렬의 덧셈

		if (strcmp(ta, "a") == 0) {
			int r[3][3];
			int i, j;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					r[i][j] = x[i][j] + y[i][j];
					cout << r[i][j];
				}
				cout << endl;
			}
			cout << endl;
			continue;
		}
		//d: 행렬의 뺄셈

		if (strcmp(ta, "d") == 0) {
			int r[3][3];
			int i, j;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					r[i][j] = x[i][j] - y[i][j];
					cout << r[i][j];
				}
				cout << endl;
			}
			cout << endl;
			continue;
		}
		//숫자 (1~9): 입력한 숫자를 행렬에 곱한다.
		if (num<10) {
			int r[3][3];
			int i, j;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					r[i][j] = x[i][j] *num;
					cout << r[i] [j];
				}
				cout << endl;
			}
			cout << endl;
			continue;

		}
		//r: 행렬식의 값 (Determinant) 

		if (strcmp(ta, "r") == 0) {
			int r[3][3];
			int r2[3][3];
			int tmp;
			int i, j;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					tmp = x[i][j];
					x[i][j] = x[j][i];
					x[j][i] = tmp;

					cout << r[i][j];
				}
				cout << endl;
			}
			cout << endl;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					r2[i][j] = y[j][i];
					cout << r2[i][j];
				}
				cout << endl;
			}
			cout << endl;

			continue;
		}
	}
	
}


