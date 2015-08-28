#pragma once

#include "BaseGauss.h"

using namespace std;

namespace PAKO
{

	class CInputGauss : public CBaseGauss
	{
	public:
		CInputGauss();
		virtual ~CInputGauss();

		virtual const bool InputData() override final;
	};
}
