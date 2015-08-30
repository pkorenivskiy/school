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
				printf("%.2f\t", m_Matrix[i][j]);
			}

			printf("\t\t%.2f\n", m_FreeMember[i]);
		}
	}

	void CBaseGauss::ShowResult()
	{

	}

	void CBaseGauss::SaveResult()
	{
		FILE* fOut = fopen("result.dat", "w");
		if (fOut != nullptr)
		{
			for (const auto& it : m_FreeMember)
			{
				fprintf_s(fOut, "%.2f\n", it);
			}

			fclose(fOut);
		}
	}

	const bool CBaseGauss::validate() const
	{
		// TODO: �����i���� �������
		return true;
	}

	const bool CBaseGauss::calc()
	{
		//https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%93%D0%B0%D1%83%D1%81%D1%81%D0%B0
		//https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%93%D0%B0%D1%83%D1%81%D1%81%D0%B0_%E2%80%94_%D0%96%D0%BE%D1%80%D0%B4%D0%B0%D0%BD%D0%B0

		// ������ ���

		for (size_t i = 0; i < m_Matrix.size() - 1; ++i)
		{
			// 1.	��������� ����� ���� �������, �� ������ ��� ���� ��������� ��������
			size_t nCol = findNonZCol(i);

			if (nCol == -1)
				return false;

			// 2.	���� ����� ����� � ��� ������� - ����, �� ���������� ����� ������ ����� ������� � ����� ������ �������, �� � ��� ������� ���� ����.
			if (m_Matrix[i][nCol] == 0)
			{
				size_t nRow = -1;
				for (size_t j = i; j < m_Matrix.size(); j++)
				{
					if (m_Matrix[j][nCol] == 0)
						continue;
					nRow = j;
					break;
				}
				if (nRow == -1)
					return false;

				// swap row
				swap(m_Matrix[i], m_Matrix[nRow]);
			}

			//3.	�� �������� ������� ����� ������� �� ������ ������� ������ �������.
			auto a = m_Matrix[i][nCol];
			for (size_t j = i; j < m_Matrix.size(); ++j)
			{
				m_Matrix[i][j] /= a;
			}
			m_FreeMember[i] /= a;

			//4.	³� �����, �� ����������, ��������� ������ �����, ���������� �� ������ ������� ���������� �����, 
			//� ����� ��������� � ����� ������� �������� ������� ����� (��� �������) ����.
			for (size_t j = i + 1; j < m_Matrix.size(); ++j)
			{
				auto a = m_Matrix[j][i];
				for (size_t k = i; k < m_Matrix.size(); ++k)
				{
					m_Matrix[j][k] -= m_Matrix[i][k] * a;
				}
				m_FreeMember[j] -= m_FreeMember[i] * a;
			}

			printf("\n\n------%d-------", i);
			ShowInData();
		}


		printf("backward run\n");
		// backward run
		// 6.5 ĳ���� ������� ����� �� ������� ������� � ���� �����
		m_FreeMember[m_Matrix.size() - 1] /= m_Matrix[m_Matrix.size() - 1][m_Matrix.size() - 1];
		m_Matrix[m_Matrix.size() - 1][m_Matrix.size() - 1] = 1;
		//7.	³������ �� ��������������� ����� ������� �����, ���������� �� ��������� ����������, 
		//��� � ��������������� ����� ���������� ���� 1 �� ������� �������.

		for (size_t i = m_Matrix.size() - 1; i > 0; i--)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (m_Matrix[i][i] == 0)
					continue;
				auto a = m_Matrix[j][i] / m_Matrix[i][i];
				m_Matrix[j][i] = 0;
				m_FreeMember[j] -= m_FreeMember[i] * a;
			}

			printf("\n\n------%d-------", i);
			ShowInData();
		}

		return true;
	}

	// private function
	const size_t CBaseGauss::findNonZCol(size_t n) const
	{
		for (size_t i = n; i < m_Matrix.size(); i++)
		{
			for (size_t j = n; j < m_Matrix.size(); j++)
			{
				if (m_Matrix[j][i] != 0)
					return i;
			}
		}

		return -1;
	}
}
