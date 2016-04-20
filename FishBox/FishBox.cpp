// FishBox.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FishBox.h"

FishBox::~FishBox()
{
	for (int i = 0; i < SceneList.size(); i++)
		SceneList[i].Release();
	return;
}

FishBox::FishBox()
{
	return;
}

void FishBox::release()
{
	for (int i = 0; i < SceneList.size(); i++)
		SceneList[i].Release();
	return;
}

void FishBox::Test()
{
	printf("Get pikachuuu");
}

void FishBox::LoadScene(char * filePath) //meshCount will be set to the amount of meshes in the scene
{
	FSHScene tempScene(filePath);

	SceneList.push_back(tempScene);
}

int FishBox::GetModelCount()
{
	return SceneList.size();
}

void FishBox::MeshData(unsigned int model, unsigned int mesh, vertexData *&vertexData, unsigned int *&indexData)
{
	if (model >= SceneList.size() || mesh > SceneList[model].GetMeshCount())
	{
		printf("No model or mesh at index");
	}

	vertexData = SceneList[model].GetMeshList()[mesh]->GetVertices();
	indexData = SceneList[model].GetMeshList()[mesh]->GetIndices();
}

FSHData::mesh * FishBox::MeshData(unsigned int model, unsigned int mesh)
{
	if (model >= SceneList.size() || mesh > SceneList[model].GetMeshCount())
	{
		printf("No model or mesh at index");
	}
	return SceneList[model].GetMeshList()[mesh]->GetMeshData();
}

FSHData::vertexData * FishBox::VertexData(unsigned int model, unsigned int mesh)
{
	if (model >= SceneList.size() || mesh > SceneList[model].GetMeshCount())
	{
		printf("No model or mesh at index");
	}
	return SceneList[model].GetMeshList()[mesh]->GetVertices();
}

unsigned int * FishBox::IndexData(unsigned int model, unsigned int mesh)
{
	if (model >= SceneList.size() || mesh > SceneList[model].GetMeshCount())
	{
		printf("No model or mesh at index");
	}
	return SceneList[model].GetMeshList()[mesh]->GetIndices();
}

unsigned int FishBox::ModelMeshCount(unsigned int model)
{
	return SceneList[model].GetMeshCount();
}

