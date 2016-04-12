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
	this->LoadModel();
	return;
}

void FishBox::Test()
{
	printf("Get pikachuu");
}

void FishBox::LoadModel()
{
	FSHModel tmodel;
	this->ModelList.push_back(tmodel);

}


std::vector<FSHModel>& FishBox::GetModelList()
{
	return this->ModelList;
}
