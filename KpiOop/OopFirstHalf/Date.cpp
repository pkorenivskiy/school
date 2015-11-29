#include "Date.h"

CDate::CDate()
	: m_nYear(1900)
	, m_nMonth(1)
	, m_nDay(1)
{
}


CDate::~CDate()
{
}

bool CDate::SetDate(const unsigned short & nYear, const unsigned char & nMonth, const unsigned char & nDay)
{
	if (nYear < 1900 || nYear > 2015)
		return false;	

	if (nMonth < 1 || nMonth > 12)
		return false;

	if (nMonth == 2 && nDay == 29 && !isYearLeap(nYear)) // febrary
		return false;
	else
		if (nDay < 1 || nDay > g_DayOfMonth[nMonth - 1])
			return false;

	m_nYear = nYear;
	m_nMonth = nMonth;
	m_nDay = nDay;

	return true;
}

const bool CDate::isYearLeap(const unsigned short & nYear) const
{
	return ((nYear % 4 == 0 && nYear % 100 != 0) || (nYear % 400 == 0));
}

