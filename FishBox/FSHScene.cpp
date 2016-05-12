
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

void FSHScene::LoadTextures()
{
	_finddata_t data;

	int first = _findfirst("Models/Textures/*.FST", &data);
	int next = 0;
	while (next != -1)
	{
		std::string temp;
		temp = data.name;
		textureNames.push_back(temp.c_str());

		next = _findnext(first, &data);

		temp = "Models/Textures/" + temp;

		FSHData::texture * tempTex = new texture;
		tempTex->textureData = SOIL_load_image(temp.c_str(), &tempTex->width, &tempTex->height, 0, SOIL_LOAD_RGBA);

		textures.push_back(tempTex);
	}
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
	//LoadTextures();

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

std::vector<texture*> FSHScene::GetTexureList()
{
	return textures;
}

std::vector<std::string> FSHScene::GetTexureNameList()
{
	return textureNames;
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
