
#include "stdafx.h"
#include "FishBox.h"

void FSHScene::LoadMeshes()
{
	
	for (int i = 0; i < HEADER.meshCount; i++) //send the filestream to each mesh, in order
	{
		meshes.push_back(new FSHMesh(infile));
	}
}

void FSHScene::LoadMaterials()
{

}

FSHScene::FSHScene(void)
{

}

FSHScene::FSHScene(char * filePath)
{
	infile = new std::ifstream;
	
	infile->open(filePath, std::ifstream::binary);
	infile->read((char*)&HEADER, sizeof(fileHeader));

	LoadMeshes();

	infile->close();
	delete infile;
}

unsigned int FSHScene::GetMeshCount()
{
	return HEADER.meshCount;
}

std::vector<FSHMesh*> FSHScene::GetMeshList()
{
	return meshes;
}

void FSHScene::Release()
{
	for (int i = 0; i < meshes.size(); i++)
		delete meshes[i];
	meshes.clear();
}
