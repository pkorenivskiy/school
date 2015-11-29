#include "MusicLibrary.h"



CMusicLibrary::CMusicLibrary()
	: m_pFirst(nullptr)
	, m_pNext(nullptr)
{
}


CMusicLibrary::~CMusicLibrary()
{
	while (m_pFirst != nullptr)
	{
		auto p = m_pFirst->m_pNext;
		delete m_pFirst;
		m_pFirst = p;
	}	
}

void CMusicLibrary::Add(const CMusicComposition& composition)
{
	CMusicLibrary* pItem = new CMusicLibrary(composition);

	if (m_pFirst == nullptr)
	{
		m_pFirst = pItem;		
	}
	else
	{
		m_pNext->m_pNext = pItem;		
	}
	m_pNext = pItem;
}

void CMusicLibrary::ShowAll()
{
	auto p = m_pFirst;
	while (p != nullptr)
	{
		//printf("compose = > %s\n", p->GetOpus().c_str());
		cout << p;
		p = p->m_pNext;
	}
}

CMusicComposition * CMusicLibrary::operator[](int index)
{
	auto p = m_pFirst;
	while (p != nullptr)
	{
		if (!index--)
			return p;
		p = p->m_pNext;
	}

	return nullptr;
}
