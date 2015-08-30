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

	void CBaseGauss::ShowInData() const
	{
		for (size_t i = 0; i < m_Matrix.size(); i++)
		{
			for (size_t j = 0; j < m_Matrix.size(); j++)
			{
				printf("%.2f\t", m_Matrix[i][j]);
			}

			printf("\t\t%.2f\n", m_FreeMember[i]);
		}
	}

	void CBaseGauss::ShowResult() const
	{
		for (size_t i = 0; i < m_Matrix.size(); i++)
		{
			printf("\t\t%.2f\n", m_FreeMember[i]);
		}
	}

	void CBaseGauss::SaveResult() const
	{
		FILE* fOut;		
		if (fopen_s(&fOut, "result.dat", "w") == 0)
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
		// TODO: перевiрити матрицю
		return true;
	}

	const bool CBaseGauss::calc()
	{
		//https://uk.wikipedia.org/wiki/Метод_Гауса_—_Жордана
		//https://uk.wikipedia.org/wiki/Система_лінійних_алгебраїчних_рівнянь

		// прямий хід

		for (size_t i = 0; i < m_Matrix.size() - 1; ++i)
		{
			// 1.	Обирається перша зліва колонка, що містить хоч одне ненульове значення
			size_t nCol = findNonZCol(i);

			if (nCol == -1)
				return false;

			// 2.	Якщо верхнє число у цій колонці - нуль, то обмінюється увесь перший 
				// рядок матриці з іншим рядком матриці, де у цій колонці нема нуля.
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

			//3.	Усі елементи першого рядка діляться на верхній елемент обраної колонки.
			auto a = m_Matrix[i][nCol];
			for (size_t j = i; j < m_Matrix.size(); ++j)
			{
				m_Matrix[i][j] /= a;
			}
			m_FreeMember[i] /= a;

			//4.	Від рядків, що залишились, віднімається перший рядок, помножений на перший
			// елемент відповідного рядка, з метою отримання у якості першого елемента кожного
			// рядка (крім першого) нуля.
			for (size_t j = i + 1; j < m_Matrix.size(); ++j)
			{
				auto a = m_Matrix[j][i];
				for (size_t k = i; k < m_Matrix.size(); ++k)
				{
					m_Matrix[j][k] -= m_Matrix[i][k] * a;
				}
				m_FreeMember[j] -= m_FreeMember[i] * a;
			}
		}


		// backward run
		// 6.5 Ділимо останній рядок на останній елемент в цьму рядку
		m_FreeMember[m_Matrix.size() - 1] /= 
			m_Matrix[m_Matrix.size() - 1][m_Matrix.size() - 1];
		m_Matrix[m_Matrix.size() - 1][m_Matrix.size() - 1] = 1;
		
		//7.	Віднімаємо від передостаннього рядка останній рядок
		//, помножений на відповідний коефіцієнт, 
		//щоб у передостанньому рядку залишилась лише 1 на головній діагоналі.

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
