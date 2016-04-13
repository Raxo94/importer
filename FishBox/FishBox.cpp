// FishBox.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FishBox.h"



FishBox::FishBox()
{
	this->LoadScene(".\Scenes\TestBin.FSH");
	return;
}

void FishBox::Test()
{
	printf("Get pikachuuu");
}


void FishBox::LoadScene(char * filePath)
{
	SceneCount++;
	FSHScene tempScene(filePath);
}


void FishBox::LoadScene(char * filePath)
{
	SceneCount++;
	FSHScene tempScene(filePath);
}