#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	srand(time(NULL));

	///////////// �������� �������

	const int DIM1 = 6;
	const int DIM2 = 5;
	const int DIM3 = 5;

	int arr[DIM1][DIM2][DIM3];

	cout << "������ �� �� ����������� ��������� ����� �������� ����� � �������?" << "\n" <<
		"�� - 1 " << "��� - 0" << endl;

	int choose = 0;
	int side = 0;
	int how = 2;


	///// ���� ������������� 

	while (true)
	{

		cin >> choose;

		if (choose != 0 && choose != 1)
		{
			cout << "������� ����������� ��������" << endl << "�� - 1 " << "��� - 0" << endl;
			continue;

		}

		cout << "========================================" << endl;
		break;

	}



	while (choose == 1)
	{
		cout << "� ����� ������� ����������� �����" << endl <<
			"1 - ����� 0 - ������" << endl;

		cin >> side;


		if (side != 1 && side != 0)
		{

			cout << "������� ����������� ��������" << endl << "1 - ����� 0" << "0 - ������" << endl;

			continue;

		}
		cout << "========================================" << endl;

		break;

	}



	while (choose == 1)
	{

		cout << endl << "�� ����� ���������� ����� ����������� ����� �����" << endl;

		cin >> how;

		if (how > 10)
		{
			cout << "������� ����� ������� ��������" << endl <<
				"�� ����� ���������� ����� ����������� ����� �����" << endl;


			continue;
		}
		cout << "========================================" << endl;

		break;

	}

	while (how == 0)
	{

		cout << endl << "�� ����� ���������� ����� ����������� ����� ������" << endl;

		cin >> how;

		if (how < 0 && how > 10)
		{
			cout << "������� �����������" << endl <<
				"�� ����� ���������� ����� ����������� ����� ������" << endl;

			continue;

		}

		cout << "========================================" << endl;
		break;

	}


	//////// ���������� � ����� ���C��� �� �����
	for (int i = 0; i < DIM1; i++)
	{

		/////////// ��������� � ���������� �� ���������
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

		/// ���� ��� ��������� ����� (������ ����) 
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j][j] < minvalueD1) minvalueD1 = arr[i][j][j];

			if (arr[i][j][j] > maxvalueD1) maxvalueD1 = arr[i][j][j];
		}
		/// ���� ��� ��������� ������ (������ ����)
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

		////// ������� ������������� �������� ��� ��������� ����� (������ ����)

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


			cout << "������������ �������� �������� � �������� "
				"������� ��������� ��� ��������� ����� (������ ����) = ";

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



		////// ������� ������������ �������� ��� ��������� ����� (������ ����)

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

			cout << "����������� �������� �������� � �������� "
				"������� ��������� ��� ��������� ����� (������ ����) = ";

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


		////// ������� ������������� �������� ��� ��������� ������ (������ ����)

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

			cout << "������������ �������� �������� � �������� "
				"������� ��������� ��� ��������� ������ (������ ����) = ";

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


		////// ������� ������������ �������� ��� ��������� ������(������ ����)

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

			cout << "����������� �������� �������� � �������� "
				"������� ��������� ��� ��������� ������ (������ ����) = ";

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