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
void det(int x[3][3]) {
	int dd= x[0][0] * (x[1][1] * x[2][2] - x[2][1] * x[1][2])

		- x[0][1] * (x[1][0] * x[2][2] - x[1][2] * x[2][0])

		+ x[0][2] * (x[1][0] * x[2][1] - x[1][1] * x[2][0]);
	cout << dd;
}

int main() {
	char ta[3];
	int x[3][3];
	int y[3][3];
	int num = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			x[i][j] = uid(dre);
			cout << x[i][j];
		}cout << endl;
	}cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			y[i][j] = uid(dre);
			cout << y[i][j];
		}cout << endl;
	}cout << endl;

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
				det(x);
				cout << endl;

				det(y);
				cout << endl;
		
				continue;
			}
			//t: ��ġ ���(Transposed matrix)�� �� ��Ľ��� ���� �Է��� 2���� ��Ŀ� ��� �����Ѵ�.

			if (strcmp(ta, "t") == 0) {
				int r[3][3];
				int i, j;
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						r[i][j] = x[j][i];
						cout << r[i][j];
					}
					cout << endl;
				}
				cout << endl;
				continue;
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
