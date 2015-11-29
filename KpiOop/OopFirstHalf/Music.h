#pragma once

#include <string>

using namespace std;

class CMusic
{
public:
	CMusic();
	virtual ~CMusic();

public:
	void SetSymphony(const string& sSymphony) { m_sSymphony = sSymphony; }
	const string GetSymphony() const { return m_sSymphony; }

	void SetConcert(const string& sConcert) { m_sConcert = sConcert; }
	const string GetConcert() const { return m_sConcert; }

	void SetSonata(const string& sSonata) { m_sSonata = sSonata; }
	const string GetSonata() const { return m_sSonata; }

	void SetDivertissement(const string& sDivertissement) { m_sDivertissement = sDivertissement; }
	const string GetDivertissement() const { return m_sDivertissement; }

private:
	string m_sSymphony;
	string m_sConcert;
	string m_sSonata;
	string m_sDivertissement;
};

