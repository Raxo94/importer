
#include "stdafx.h"
#include "FishBox.h"

void FSHScene::LoadMeshes()
{
	meshes = new FSHMesh[HEADER.meshCount];// create the meshlist
	

	for (int i = 0; i < HEADER.meshCount; i++) //send the filestream to each mesh, in order
	{
		meshes[i] = FSHMesh(infile);
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
}

unsigned int FSHScene::GetMeshCount()
{
	return HEADER.meshCount;
}

FSHMesh * FSHScene::GetMeshList()
{
	return meshes;
}

void FSHScene::Release()
{
	delete[] meshes;
}
