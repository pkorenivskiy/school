#pragma once
#include "Music.h"
#include "Person.h"
#include <string>

using namespace std;

class CMusicComposition : public CMusic, public CDate
{
public:
	CMusicComposition();
	~CMusicComposition();
	CMusicComposition(const CMusicComposition& p)
		: CMusic(p)
		, CDate(p)
	{
		m_sOpus = p.GetOpus();
		m_ulDuration = p.GetDuration();
		m_pComposer = nullptr;
		SetComposer(*p.GetComposer());
	}

public:
	const void SetComposer(const CPerson& person);
	const void SetOpus(const string& sOpus) { m_sOpus = sOpus; }
	const void SetDuration(const unsigned long& ulDuration) { m_ulDuration = ulDuration; }
	const void SetCreateDate(const CDate& date);

	const CPerson* GetComposer() const { return m_pComposer; }
	const string GetOpus() const { return m_sOpus; }
	const unsigned long GetDuration() const { return m_ulDuration; }

public:
	friend ostream& operator << (ostream& os, const CMusicComposition* comp);

protected:
	CPerson* m_pComposer;

private:
	string m_sOpus;
	unsigned long m_ulDuration;
};

