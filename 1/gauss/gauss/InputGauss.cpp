#include "InputGauss.h"
#include <iostream>

using namespace std;

namespace PAKO
{

	CInputGauss::CInputGauss()
	{
	}


	CInputGauss::~CInputGauss()
	{
	}

	const bool PAKO::CInputGauss::InputData()
	{
		int nSize = 0;
		while (nSize < 2 || nSize > 100)
		{
			printf("\n¬введiть розмiрнiсть матрицi: ");
			cin >> nSize;
		}

		m_Matrix.resize(nSize);
		for (auto& it : m_Matrix)
		{
			it.resize(nSize);
		}

		m_FreeMember.resize(nSize);

		for (auto i = 0; i < nSize; ++i)
		{
			for (auto j = 0; j < nSize; ++j)
			{
				printf("¬ведiть елемент {%d, %d} :", i, j);
				cin >> m_Matrix[i][j];
			}
			printf("¬ведiть вiльний член %d :", i);
			cin >> m_FreeMember[i];
		}

		return validate();
	}
}