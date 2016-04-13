// FishBox.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FishBox.h"



FishBox::FishBox()
{
	unsigned int temp;

	this->LoadScene("Models/TestBin.FSH", temp);
	return;
}

void FishBox::Test()
{
	printf("Get pikachuuu");
}



void FishBox::LoadScene(char * filePath, unsigned int& meshCount) //meshCount will be set to the amount of meshes in the scene
{

	FSHScene tempScene(filePath);

	SceneList.push_back(tempScene);
	meshCount = tempScene.GetMeshCount();

}

int FishBox::GetSceneCount()
{
	return SceneList.size();
}

void FishBox::MeshData(unsigned int model, unsigned int mesh, vertexData * vertexData, unsigned int * indexData)
{
	if (model >= SceneList.size() || mesh > SceneList[model].GetMeshCount())
	{
		printf("No model or mesh at index");
	}

	vertexData = SceneList[model].GetMeshList()[mesh].GetVertices();
	indexData = SceneList[model].GetMeshList()[mesh].GetIndices();
}