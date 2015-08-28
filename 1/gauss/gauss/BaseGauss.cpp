#include "BaseGauss.h"


using namespace std;

namespace PAKO
{

	CBaseGauss::CBaseGauss()
	{
	}


	CBaseGauss::~CBaseGauss()
	{
	}

	void CBaseGauss::ShowInData()
	{
		printf("\n\n");

		for (auto i = 0; i < m_Matrix.size(); ++i)
		{
			for (auto j = 0; j < m_Matrix.size(); ++j)
			{
				printf("%g\t", m_Matrix[i][j]);
			}

			printf("\t\t%g\n", m_FreeMember[i]);
		}
	}

	void CBaseGauss::ShowResult()
	{

	}

	void CBaseGauss::SaveResult()
	{

	}

	const bool CBaseGauss::validate() const
	{
		// TODO: перевірити матрицю
		// TODO: переставити рядки, щоб не було нулів на діагоналі.
		return true;
	}

	const bool CBaseGauss::calc()
	{
		// forward run
		double dblVal = .0;
		for (auto i = 1; i < m_Matrix.size(); ++i)
		{
			double a = m_Matrix[i-1][i-1];

			for (auto j = 0; j < m_Matrix[i].size(); ++j)
			{
				m_Matrix[i][j] -= m_Matrix[i][j] * m_Matrix[i - 1][j];
			}

			m_FreeMember[i] -= m_FreeMember[i] * m_FreeMember[i - 1];

			ShowInData();
		}

		return true;
	}
}