#include "Person.h"



CPerson::CPerson()
{
}

CPerson::~CPerson()
{
}

void CPerson::SetName(const string & sFirstName, const string & sLastName)
{
	m_sFirstName = sFirstName;
	m_sLastName = sLastName;
}

const void CPerson::GetBirthDate(unsigned short* nYear, unsigned char* nMonth, unsigned char* nDay) const
{
	*nYear = GetYear();
	*nMonth = GetMonth();
	*nDay = GetDay();
}

const void CPerson::GetBirthDate(unsigned short& nYear, unsigned char& nMonth, unsigned char& nDay) const
{
	nYear = GetYear();
	nMonth = GetMonth();
	nDay = GetDay();
}

ostream& operator << (ostream& os, const CPerson* p)
{
	os << "FirstName: " << p->GetFirstName() << "; LastName: " << p->GetLastName() << "; "
		"Date: (Year:" << p->GetYear() << "; Month: " << (int)p->GetMonth() << "; Day: " << (int)p->GetDay();
	return os;
}
