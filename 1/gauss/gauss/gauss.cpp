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
	//setlocale(LC_ALL, "uk-UA");

	printf("�������� ���������� ������� ������ ������\n");

	do 
	{
		shared_ptr<CBaseGauss> pGaus = nullptr;

		do 
		{
			printf("������ ����� �������� �����:\n\t1 - ���������\n\t2 - ����\n\t0 - �����\n==>");
			const auto ch = getch();

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

			printf("�������� ��������� � ����?(y/n)");
			if (getch() == 'y')
				pGaus->SaveResult();
			printf("\n");
		}
		else
		{
			printf("����� ��� �� �������\n\n");
			continue;
		}

		printf("�������� Enter ��� ���������� ����������, ��� ���� ������ ��� ����������\n");
		
	} while (getch() == 13);
	
	return 0;
}

