
#include "FileGauss.h"

#include <fstream>
#include <string>
#include <sstream>
#include <io.h>

using namespace std;

namespace PAKO
{
	CFileGauss::CFileGauss()
	{
	}


	CFileGauss::~CFileGauss()
	{
	}

	const bool PAKO::CFileGauss::InputData()
	{
		FILE* fIn;

		if (fopen_s(&fIn, "data.dat", "r") != 0)
			return false;

		char pBuf[255] = { 0 };
		string sAllData;
		while (fread(pBuf, 1, 255, fIn) > 0);
		{			
			sAllData.append(pBuf);
			memset(pBuf, 0, 255);
		}

		string st;
		stringstream sData(sAllData);
		int nRow = 0;
		while (getline(sData, st))
		{
			stringstream sRow(st);

			string val;

			int nCol = 0;
			double dblVal = .0;
			TRow row;
			while (getline(sRow, val, ' '))
			{
				stringstream sVal(val);				
				sVal >> dblVal;
				row.push_back(dblVal);
			}
			m_FreeMember.push_back(dblVal);
			row.erase(row.end() - 1);
			m_Matrix.push_back(row);
		}

		fclose(fIn);
		
		return true;
	}
}