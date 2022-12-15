#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	srand(time(NULL));

	///////////// СОЗДАНИЕ МАССИВА

	const int DIM1 = 6;
	const int DIM2 = 5;
	const int DIM3 = 5;

	int arr[DIM1][DIM2][DIM3];

	cout << "Хотите ли вы осуществить побитовый сдвиг двоичных чисел в сторону?" << "\n" <<
		"да - 1 " << "нет - 0" << endl;

	int choose = 0;
	int side = 0;
	int how = 2;


	///// ВВОД ПОЛЬЗОВАТЕЛСЯ 

	while (true)
	{

		cin >> choose;

		if (choose != 0 && choose != 1)
		{
			cout << "Введено некоректное значение" << endl << "да - 1 " << "нет - 0" << endl;
			continue;

		}

		cout << "========================================" << endl;
		break;

	}



	while (choose == 1)
	{
		cout << "В какую сторону осуществить сдвиг" << endl <<
			"1 - влево 0 - вправо" << endl;

		cin >> side;


		if (side != 1 && side != 0)
		{

			cout << "Введено некоректное значение" << endl << "1 - влево 0" << "0 - вправо" << endl;

			continue;

		}
		cout << "========================================" << endl;

		break;

	}



	while (choose == 1)
	{

		cout << endl << "на какое количество битов осуществить сдвиг влево" << endl;

		cin >> how;

		if (how > 10)
		{
			cout << "Введено очень большое значение" << endl <<
				"на какое количество битов осуществить сдвиг влево" << endl;


			continue;
		}
		cout << "========================================" << endl;

		break;

	}

	while (how == 0)
	{

		cout << endl << "на какое количество битов осуществить сдвиг вправо" << endl;

		cin >> how;

		if (how < 0 && how > 10)
		{
			cout << "Введено некоректное" << endl <<
				"На какое количество битов осуществить сдвиг вправо" << endl;

			continue;

		}

		cout << "========================================" << endl;
		break;

	}


	//////// ЗАПОЛНЕНИЕ И ВЫВОД МАСCИВА НА ЭКРАН
	for (int i = 0; i < DIM1; i++)
	{

		/////////// ДИАГОНАЛИ И ВЫЧИСЛЕНИЯ ИХ ЭЛЕМЕНТОВ
		int maxvalueD1 = 0;
		int minvalueD1 = 999;

		int maxvalueD2 = 0;
		int minvalueD2 = 999;

		for (int j = 0; j < DIM2; j++)
		{
			cout << endl << endl << endl;
			for (int k = 0; k < DIM3; k++)
			{

				arr[i][j][k] = rand() % 999;


				cout << "\t" << arr[i][j][k];
			}

			cout << endl;


		}

		/// ЦИКЛ ДЛЯ ДИОГОНАЛИ СЛЕВА (СВЕРХУ ВНИЗ) 
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j][j] < minvalueD1) minvalueD1 = arr[i][j][j];

			if (arr[i][j][j] > maxvalueD1) maxvalueD1 = arr[i][j][j];
		}
		/// ЦИКЛ ДЛЯ ДИОГОНАЛИ СПРАВА (СВЕРХУ ВНИЗ)
		for (int j = 0, k = 5 - 1; j < 5; j++, k--)
		{
			if (arr[i][j][k] < minvalueD2) minvalueD2 = arr[i][j][k];

			if (arr[i][j][k] > maxvalueD2) maxvalueD2 = arr[i][j][k];
		}


		cout << endl << "\t" << "TEST MAX1-" << "\t" << maxvalueD1;
		cout << endl << "\t" << "TEST MIN1-" << "\t" << minvalueD1;
		cout << endl << "\t" << "===================================";
		cout << endl << "\t" << "TEST MAX2-" << "\t" << maxvalueD2;
		cout << endl << "\t" << "TEST MIN2-" << "\t" << minvalueD2;


		cout << endl;
		cout << "\t" << "===================================" << endl;

		////// ПЕРЕВОД МАКСИМАЛЬНОГО ЗНАЧЕНИЯ ДЛЯ ДИОГОНАЛИ СЛЕВА (СВЕРХУ ВНИЗ)

		int d;

		d = 2;

		int k = 0;



		int dvo[100];

		while (true)
		{
			int dvoich;

			if (side == 1)
			{
				maxvalueD1 = (maxvalueD1 << how);
			}

			if (side == 0)
			{
				maxvalueD1 = (maxvalueD1 >> how);
			}

			while (maxvalueD1 > 1)
			{
				dvoich = maxvalueD1 % d;
				dvo[k] = dvoich;
				maxvalueD1 /= d;
				k++;
			}
			
			k--;


			cout << "Максимальное значение элемента в двоичной "
				"системе счисления для диогонали слева (Сверху вниз) = ";

			cout << 1;


			while (k >= 0)
			{

				cout << dvo[k];
				dvo[k] = 0;
				k--;

			}

			cout << endl << endl;

			dvoich = 0;

			k = 0;


			break;
		}



		////// ПЕРЕВОД МИНИМАЛЬНОГО ЗНАЧЕНИЯ ДЛЯ ДИОГОНАЛИ СЛЕВА (СВЕРХУ ВНИЗ)

		while (true)
		{

			int dvoich;

			if (side == 1)
			{
				minvalueD1 = (minvalueD1 << how);
			}

			if (side == 0)
			{
				minvalueD1 = (minvalueD1 >> how);
			}

			while (minvalueD1 > 1)
			{
				dvoich = minvalueD1 % d;
				dvo[k] = dvoich;
				minvalueD1 /= d;
				k++;
			}

			k--;

			cout << "Минимальное значение элемента в двоичной "
				"системе счисления для диогонали слева (Сверху вниз) = ";

			cout << 1;


			while (k >= 0)
			{

				cout << dvo[k];
				dvo[k] = 0;
				k--;

			}

			cout << endl << endl;

			dvoich = 0;

			k = 0;


			break;
		}


		////// ПЕРЕВОД МАКСИМАЛЬНОГО ЗНАЧЕНИЯ ДЛЯ ДИОГОНАЛИ СПРАВА (СВЕРХУ ВНИЗ)

		while (maxvalueD2 > 1)
		{
			int dvoich;

			if (side == 1)
			{
				maxvalueD2 = (maxvalueD2 << how);
			}

			if (side == 0)
			{
				maxvalueD2 = (maxvalueD2 >> how);
			}

			while (maxvalueD2 > 1)
			{
				dvoich = maxvalueD2 % d;
				dvo[k] = dvoich;
				maxvalueD2 /= d;
				k++;
			}

			k--;

			cout << "Максимальное значение элемента в двоичной "
				"системе счисления для диогонали справа (Сверху вниз) = ";

			cout << 1;


			while (k >= 0)
			{

				cout << dvo[k];
				dvo[k] = 0;
				k--;

			}

			cout << endl << endl;

			dvoich = 0;

			k = 0;


			break;

		}


		////// ПЕРЕВОД МИНИМАЛЬНОГО ЗНАЧЕНИЯ ДЛЯ ДИОГОНАЛИ СПРАВА(СВЕРХУ ВНИЗ)

		while (minvalueD2 > 1)
		{
			int dvoich;

			if (side == 1)
			{
				minvalueD2 = (minvalueD2 << how);
			}

			if (side == 0)
			{
				minvalueD2 = (minvalueD2 >> how);
			}

			while (minvalueD2 > 1)
			{
				dvoich = minvalueD2 % d;
				dvo[k] = dvoich;
				minvalueD2 /= d;
				k++;
			}

			k--;

			cout << "Минимальное значение элемента в двоичной "
				"системе счисления для диогонали справа (Сверху вниз) = ";

			cout << 1;


			while (k >= 0)
			{

				cout << dvo[k];
				dvo[k] = 0;
				k--;

			}

			cout << endl << endl;

			dvoich = 0;

			k = 0;

			break;
		}

	}
}