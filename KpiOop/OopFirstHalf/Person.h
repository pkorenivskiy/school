#pragma once
#include "Date.h"
#include <string>

using namespace std;

class CPerson :	public CDate
{
public:
	CPerson();
	~CPerson();

public:
	void SetName(const string& sFirstName, const string& sLastName);

	const string GetFirstName() const { return m_sFirstName; }
	const string GetLastName() const { return m_sLastName; }

	const void GetBirthDate(unsigned short* nYear, unsigned char* nMonth, unsigned char* nDay) const;
	const void GetBirthDate(unsigned short& nYear, unsigned char& nMonth, unsigned char& nDay) const;

public:
	friend ostream& operator << (ostream& os, const CPerson* p);

private:
	string m_sFirstName;
	string m_sLastName;
};

