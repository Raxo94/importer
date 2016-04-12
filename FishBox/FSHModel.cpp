
#include "stdafx.h"
#include "FishBox.h"





void FSHModel::LoadMeshes()
{
	FSHMesh meshT;
	MeshList.push_back(meshT);
}

void FSHModel::LoadMaterials()
{
	FSHMaterial tMaterial;
	MaterialList.push_back(tMaterial);
}

FSHModel::FSHModel(void)
{
	this->LoadMeshes();
	this->LoadMaterials();
	return;
}

unsigned int FSHModel::GetMeshCount()
{
	return MeshList.size();
}

std::vector<FSHMesh>& FSHModel::GetMeshList()
{
	return this->MeshList;
}


std::vector<FSHMaterial>& FSHModel::GetMaterialList()
{
	return this->MaterialList;
}

void FSHModel::Release()
{
	this->MeshList.clear();
	this->MaterialList.clear();
}
