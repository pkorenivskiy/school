#pragma once
#include <iostream>
static const unsigned char g_DayOfMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class CDate
{
public:
	CDate();
	virtual ~CDate();

public:
	const unsigned short GetYear() const { return m_nYear; } 
	
	const unsigned char GetMonth() const { return m_nMonth; }
	
	const unsigned char GetDay() const { return m_nDay; }

	bool SetDate(const unsigned short& nYear, const unsigned char& nMonth, const unsigned char& nDay);

private:
	unsigned short m_nYear;
	unsigned char m_nMonth;
	unsigned char m_nDay;


private:
	const bool isYearLeap(const unsigned short& nYear) const;
};

