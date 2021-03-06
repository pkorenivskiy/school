// OopFirstHalf.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include "MusicLibrary.h"


int main()
{
	CMusicLibrary musicLibrary;

	for (int i = 0; i < 12; ++i)
	{
		CMusicComposition composition;
		char lpszOpus[50];
		sprintf_s(lpszOpus, 50, "sonata # %d", i);
		composition.SetOpus(lpszOpus);
		composition.SetDuration(i * 1024);
		composition.SetDate(2010 + i, 1 + i, (1 + i) * 2);

		composition.SetSymphony("simphony");
		composition.SetConcert("Concert");
		composition.SetSonata("Sonata");
		composition.SetDivertissement("Divertissement");

		CPerson composer;
		composer.SetDate(1976 + i, 1 + i, (1 + i) * 5);
		composer.SetName("First", "Last");

		composition.SetComposer(composer);

		musicLibrary.Add(composition);
	}

	musicLibrary.ShowAll();

	auto p = musicLibrary[4];

	cout << "\n\n\n";

	cout << p;

	CMusicComposition* pMusics = new CMusicComposition[10];

	for (int i = 0; i < 10; ++i)
	{
		char lpszOpus[50];
		sprintf_s(lpszOpus, 50, "sonata # %d", i);
		pMusics[i].SetOpus(lpszOpus);
		pMusics[i].SetDuration(i * 1024);
		pMusics[i].SetDate(2010 + i, 1 + i, (1 + i) * 2);

		pMusics[i].SetSymphony("simphony");
		pMusics[i].SetConcert("Concert");
		pMusics[i].SetSonata("Sonata");
		pMusics[i].SetDivertissement("Divertissement");

		CPerson composer;
		composer.SetDate(1976 + i, 1 + i, (1 + i) * 5);
		composer.SetName("First", "Last");

		pMusics[i].SetComposer(composer);
	}
	
	char lpszFileName[260];
	cout << "Enter out file name :";
	cin >> lpszFileName;

	FILE* f = fopen(lpszFileName, "wb");
	auto pIt = pMusics;
	for (int i = 0; i < 10; ++i)
	{
		fwrite(pIt++, 1, sizeof(pMusics[i]), f);
	}	
	fclose(f);

	delete[] pMusics;

    return 0;
}

