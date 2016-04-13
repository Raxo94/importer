
#include "stdafx.h"
#include "FishBox.h"





void FSHModel::LoadMeshes()
{
	//TEMP
	FSHMesh meshT;
	MeshList.push_back(meshT);
	//ENDTEMP

	meshes = new FSHMesh[HEADER.meshCount];// create the meshlist
	

	for (int i = 0; i < HEADER.meshCount; i++) //send the filestream to each mesh, in order
	{
		meshes[i] = FSHMesh(infile);
	}


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

FSHModel::FSHModel(char * filePath)
{
	infile = new std::ifstream;

	infile->open(filePath, std::ifstream::binary);
	infile->read((char*)&HEADER, sizeof(fileHeader));

	LoadMeshes();

	infile->close();
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
