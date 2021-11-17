#include <iostream>
#include <array>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	int i, j, M;
	double N;
	cout << "Введите кол-во критериев: "; //ввод количества строк
	cin >> N;
	if (N <= 0) {
		cout << "Ошибка! Введите число больше 0" << endl;
		system("pause");
		return 0;
	}
	double** a = new double* [N];
	M = -1;
	j = 0;
	int g = 2, h = 1;
	for (i = 0; i < N; i++) {
		//цикл по переменной j, в котором перебираем элементы внутри строки
		j = i + 1;
		g = j + 1;
		a[i] = new double[N];
		for (j; j < N; j++) {
			cout << "Сравнение №" << i + 1 << " с №" << g << ": ";
			cin >> a[i][j]; //ввод очередного элемента матрицы
			g = g + 1;
			if (a[i][j] <= 0) {
				cout << "Ошибка! Введите число больше 0" << endl;
				system("pause");
				return 0;
			}
		}
	}
	for (int i = 0; i < N; i++) // ставит 1 по диагонали
	{
		for (int j = 0; j < N; j++) {
			if (i == j) {
				a[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++)// расчитывает 2-ю половину матрицы
	{
		M = M + 1;
		for (int j = 0; j < M; j++) {
			a[i][j] = 1 / a[j][i];
		}
	}
	double* b = new double[N];// массив суммы строк
	for (i = 0; i < N; i++) {// считаем сумму
		b[i] = 0;
		for (j = 0; j < N; j++) {
			b[i] = b[i] + a[i][j];
		}
	}
	double k = 0;//общая сумма
	for (i = 0; i < N; i++) {
		k = k + b[i];
	}
	for (i = 0; i < N; i++) {
		b[i] = b[i] / k;
	}
	cout << "Весовые коэфиценты :" << endl;
	for (i = 0; i < N; i++) {
		cout << fixed;
		cout.precision(2);
		cout << b[i] << endl;
	}
	delete[] b;
	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	system("pause");
	return 0;
}