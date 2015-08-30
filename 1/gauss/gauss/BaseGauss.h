#pragma once

#include <vector>

using namespace std;

namespace PAKO
{

	class CBaseGauss abstract
	{
	protected:
		typedef vector<double> TRow;
		typedef vector<TRow> TMatrix;

	public:
		CBaseGauss();
		virtual ~CBaseGauss();

	public:
		void ShowInData();
		void ShowResult();
		void SaveResult();
		virtual const bool InputData() abstract;
		virtual const bool Calc() { return calc(); }
	
	protected:
		virtual const bool validate() const;
		virtual const bool calc();

	private:
		const size_t findNonZCol(size_t n) const;

	protected:		
		TMatrix m_Matrix;		
		TRow m_FreeMember;
	};

}