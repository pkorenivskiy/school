#include "MusicComposition.h"



CMusicComposition::CMusicComposition()
	: m_pComposer(nullptr)
	, m_ulDuration(0)
{
}


CMusicComposition::~CMusicComposition()
{
	if (m_pComposer)
		delete m_pComposer;
}

const void CMusicComposition::SetComposer(const CPerson & person)
{
	if (!m_pComposer)
		m_pComposer = new CPerson();

	m_pComposer->SetDate(person.GetYear(), person.GetMonth(), person.GetDay());
	m_pComposer->SetName(person.GetFirstName(), person.GetLastName());
}

const void CMusicComposition::SetCreateDate(const CDate & date)
{
	SetDate(date.GetYear(), date.GetMonth(), date.GetDay());
}

ostream& operator << (ostream& os, const CMusicComposition* comp)
{
	os << "Opus: " << comp->m_sOpus << "; Duration: " << comp->m_ulDuration
		<< "; Compositor(" << comp->m_pComposer << ");"
		<< " Music: (Concert: " << comp->GetConcert() << "; Symphony: " << comp->GetSymphony() << "; Sonata: " << comp->GetSonata() << ")"
		<< " CreateDate(Year: " << comp->GetYear() << "; Month:" << (int)comp->GetMonth() << "; Day: " << (int)comp->GetDay() << ");"
		<< "\n";

	return os;
}
