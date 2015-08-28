#pragma once
#include "BaseGauss.h"

using namespace std;

namespace PAKO
{
	class CFileGauss : public CBaseGauss
	{
	public:
		CFileGauss();
		virtual ~CFileGauss();

		virtual const bool InputData() override final;
	};
}
