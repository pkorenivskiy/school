#pragma once
#include "MusicComposition.h"

class CMusicLibrary : public CMusicComposition
{
	friend class CMusicLibrary;
public:
	CMusicLibrary();
	~CMusicLibrary();
	CMusicLibrary(const CMusicComposition& composition)		
		: CMusicComposition(composition)
		, m_pFirst(nullptr), m_pNext(nullptr)
	{		
	}

public:
	void Add(const CMusicComposition& composition);
	void ShowAll();

public:
	CMusicComposition* operator[](int index);

private:
	CMusicLibrary* m_pFirst;
	CMusicLibrary* m_pNext;	
};

