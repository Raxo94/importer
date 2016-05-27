
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

void FSHScene::LoadCameras()
{
	for (int i = 0; i < HEADER.cameraCount; i++)
	{
		cameras.push_back(new camera);
		infile->read((char*)cameras.at(i), sizeof(camera));
	}
}

void FSHScene::LoadDirectionalLights()
{
	for (int i = 0; i < HEADER.directionalLightCount; i++)
	{
		directionalLights.push_back(new directionalLight);
		infile->read((char*)directionalLights.at(i), sizeof(directionalLight));
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
	LoadCameras();
	LoadDirectionalLights();
	infile->close();
	delete infile;
}

unsigned int FSHScene::GetMeshCount()
{
	return HEADER.meshCount;
}

unsigned int FSHScene::GetCameraCount()
{
	return HEADER.cameraCount;
}

unsigned int FSHScene::GetDirectionalLightCount()
{
	return HEADER.directionalLightCount;
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

std::vector<camera*> FSHScene::GetCameraList()
{
	return cameras;
}

std::vector<directionalLight*> FSHScene::GetDirectionalLightList()
{
	return directionalLights;
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
