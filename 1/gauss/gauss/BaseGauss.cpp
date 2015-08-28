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
		// TODO: ��������� �������
		// TODO: ����������� �����, ��� �� ���� ���� �� �������.
		return true;
	}

	const bool CBaseGauss::calc()
	{
		//https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%93%D0%B0%D1%83%D1%81%D1%81%D0%B0
		//https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%93%D0%B0%D1%83%D1%81%D1%81%D0%B0_%E2%80%94_%D0%96%D0%BE%D1%80%D0%B4%D0%B0%D0%BD%D0%B0
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