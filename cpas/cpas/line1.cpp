#include <iostream>
#include <random>
#include <chrono>
#include <cstring>

using namespace std;
using std::cout;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();

default_random_engine dre(seed);		//���������� seed ���� �����ȴ� ��������
uniform_int_distribution<int> uid(0, 2); //����������

// cout printf
// det ��Ľ� �� 
void det_three (int x[3][3]) {
	int dd= x[0][0] * (x[1][1] * x[2][2] - x[2][1] * x[1][2])

		- x[0][1] * (x[1][0] * x[2][2] - x[1][2] * x[2][0])

		+ x[0][2] * (x[1][0] * x[2][1] - x[1][1] * x[2][0]);
	cout << dd << endl;
}
void det_four(int x[3][3]) {



}

void rand(int x[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			x[i][j] = uid(dre);
			cout << x[i][j];
		}cout << endl;
	}
	cout << endl;
}
void Transposed(int x[3][3]) {
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << x[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void H(int x[3][3]) {
	int th[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			th[i][j] = x[i][j];
			if ((i == 3) || (j == 3)) {
				th[i][j] = 0;
			}
			if ((i == 3) && (j == 3)) {
				th[i][j] = 1;
			}
			cout << th[i][j];
		}cout << endl;
		cout << endl;
	}
}


int main() {
	char ta[3];
	int x[3][3];
	int y[3][3];
	
	//0,1,2 ���� �迭
	rand(x);
	rand(y);

	while (true) {

		cin >> ta;
		int ee = ta[0] - '0';
		// cin >> num;
		//�������� �������� ����

		if (isdigit(ta[0]) == 0) {

			//m: ����� ����
			if (strcmp(ta, "m") == 109) {
				int r[3][3];
					int i, j;
					for (i = 0; i < 3; i++)
					{
						for (j = 0; j < 3; j++)
						{
							r[i][j] = x[i][0] * y[0][j] + x[i][1] * y[1][j] + x[i][2] * y[2][j];
								cout << r[i][j];
						}
						cout << endl;
					}
				cout << endl;
				continue;
			}

			//a: ����� ����

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
			//d: ����� ����

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
			//r: ��Ľ��� �� (Determinant) void det 
			if (strcmp(ta, "r") == 0) {
				det_three(x);
				det_three(y);
				continue;
			}
			//t: ��ġ ���(Transposed matrix)�� �� ��Ľ��� ���� �Է��� 2���� ��Ŀ� ��� �����Ѵ�.
			if (strcmp(ta, "t") == 0) {
				Transposed(x);
				det_three(x);
				Transposed(y);
				det_three(y);
				continue;
			}
			//h: 3X3 ����� 4X4 ��ķ� ��ȯ�ϰ� ��Ľ��� �� (4��4�� ��Ľ� ��) ���
			if (strcmp(ta, "h") == 0) {
				H(x);
				H(y);
				continue;
			}
			//s: ����� ���� ���� �����ϰ� �����Ѵ�.
			if (strcmp(ta, "s") == 0) {
				rand(x);
				rand(y);
				continue;
			}
			//q: ���α׷� ����
			if (strcmp(ta, "q") == 0) {
				return 0;
			}

		}//���ڸ�
		else {//���� (1~9): �Է��� ���ڸ� ��Ŀ� ���Ѵ�.
			
				int r[3][3];
				int i, j;
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						r[i][j] = x[i][j] * ee;
						cout << r[i][j];
					}
					cout << endl;
				}
				cout << endl;
				continue;

			}


	}

}
