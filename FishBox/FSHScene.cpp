
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
	for (int i = 0; i < HEADER.materialCount; i++)
	{
		materials.push_back(new material);
		infile->read((char*)materials.at(i), sizeof(material));
	}
}


void FSHScene::setTextureIDs(std::vector<GLuint> textureIDs)
{
	this->textureIDs = textureIDs;
}

void FSHScene::setTextureList(std::vector<texture*> textures, std::vector<std::string> textureNames)
{
	this->textureNames = textureNames;
	this->textures = textures;
}

FSHScene::FSHScene(char * filePath)
{
	infile = new std::ifstream;
	
	infile->open(filePath, std::ifstream::binary);
	infile->read((char*)&HEADER, sizeof(fileHeader));

	LoadMeshes();
	LoadMaterials();

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

std::vector<material*> FSHScene::GetMaterialList()
{
	return materials;
}


std::vector<std::string> FSHScene::GetTexureNameList()
{
	return textureNames;
}

std::vector<GLuint> FSHScene::GetTextureIDs()
{
	return textureIDs;
}

void FSHScene::Release()
{

	for (int i = 0; i < materials.size(); i++)
	{
		delete materials.at(i);
	}
	materials.clear();
	materials.resize(0);

	for (int i = 0; i < meshes.size(); i++)
		delete meshes[i];
	meshes.clear();

	textures.clear();
}
