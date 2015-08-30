// gauss.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <memory>

#include "InputGauss.h"
#include "FileGauss.h"


using namespace std;
using namespace PAKO;

int main(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "uk-UA");

	printf("Програма обчислення системи лiнiйних рiвнянь\n");

	do 
	{
		shared_ptr<CBaseGauss> pGaus = nullptr;

		do 
		{
			printf("Оберiть спосiб введення даних:\n\t1 - клавiатура\n\t2 - файл\n\t0 - Вихiд\n==>");
			const auto ch = _getch();

			if (ch == '1')
				pGaus = shared_ptr<CBaseGauss>(new CInputGauss());
			else if (ch == '2')
				pGaus = shared_ptr<CBaseGauss>(new CFileGauss());
			else if (ch == '0')
				return 0;

		} while (!pGaus);

		printf("\n");

		pGaus->InputData();

		printf("\n");

		pGaus->ShowInData();

		if (pGaus->Calc())
		{
			pGaus->ShowInData();
			pGaus->ShowResult();

			printf("Зберегти результат у файл?(y/n)");
			if (_getch() == 'y')
				pGaus->SaveResult();
			printf("\n");
		}
		else
		{
			printf("Вхiднi данi не коректнi\n\n");
			continue;
		}

		printf("Натиснiть Enter для наступного обчислення, або iншу клавiшу для завершення\n");
		
	} while (_getch() == 13);
	
	return 0;
}

