// FishBox.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FishBox.h"


//// This is an example of an exported variable
//FISHBOX_API int nFishBox=0;
//
//// This is an example of an exported function.
//FISHBOX_API int fnFishBox(void)
//{
//    return 42;
//}


FishBox::FishBox()
{
	this->LoadModel(".\Models\TestBin.FSH");
	return;
}

void FishBox::Test()
{
	printf("Get pikachuuu");
}

void FishBox::LoadModel(char * filePath)
{
	

	//TEMP
	FSHModel tmodel;
	this->ModelList.push_back(tmodel);
	//ENDTEMP

	

	FSHModel tempModel(filePath);



	
}


std::vector<FSHModel>& FishBox::GetModelList()
{
	return this->ModelList;
}
