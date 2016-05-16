// FishBox.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FishBox.h"

FishBox::~FishBox()
{
	for (int i = 0; i < SceneList.size(); i++)
		SceneList[i].Release();

	for (int i = 0; i < textures.size(); i++)
	{

		//delete[] textures.at(i)->textureData;

		
		delete textures[i];
	}

	return;
}

FishBox::FishBox()
{
	LoadTextures();
	return;
}

void FishBox::release()
{
	for (int i = 0; i < textures.size(); i++)
	{
		delete textures[i]->textureData;
		delete textures[i];
	}

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
	tempScene.setTextureList(textures, textureNames);
	tempScene.setTextureIDs(textureIDs);
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

FSHData::material * FishBox::meshMaterial(unsigned int model, unsigned int mesh)
{
	for (int i = 0; i < SceneList[model].GetMaterialList().size(); i++)
	{
		//int mls = SceneList[model].GetMaterialList().size();

		//FSHData::mesh * tmesh = MeshData(model, mesh);
		//char* tsrting = SceneList[model].GetMaterialList()[i]->materialName;

		//bool tbool = (std::string(SceneList[model].GetMaterialList()[i]->materialName).find(std::string(MeshData(model, mesh)->materialName)) != std::string::npos);
		//if (tbool)
		//	printf("TRUE");

		if (std::string(SceneList[model].GetMaterialList()[i]->materialName).find(std::string(MeshData(model, mesh)->materialName)) != std::string::npos)
			return SceneList[model].GetMaterialList()[i];
		else if (SceneList[model].GetMaterialList().size() == 1)
			return SceneList[model].GetMaterialList()[i];
	}

}

texture* FishBox::meshTexture(unsigned int model, unsigned int mesh)
{
	for (int i = 0; i < SceneList[model].GetTexureNameList().size(); i++)
	{

		material * meshmaterial = meshMaterial(model, mesh);



		//printf("\n");
		//
		//printf("\n%s", std::string(meshmaterial->textureFilePath).c_str());

		//printf("\n");
		if (std::string(std::string(meshmaterial->textureFilePath).c_str()).find(SceneList[model].GetTexureNameList()[i].c_str()) != std::string::npos)
		{
			return SceneList[model].GetTexureList()[i];
		}
	}
}

GLuint FishBox::meshTextureID(unsigned int model, unsigned int mesh)
{
	for (int i = 0; i < SceneList[model].GetTexureNameList().size(); i++)
	{

		material * meshmaterial = meshMaterial(model, mesh);



		//printf("\n");
		//
		//printf("\n%s", std::string(meshmaterial->textureFilePath).c_str());

		//printf("\n");
		if (std::string(std::string(meshmaterial->textureFilePath).c_str()).find(SceneList[model].GetTexureNameList()[i].c_str()) != std::string::npos)
		{
			//GLuint test = SceneList[model].GetTextureIDs()[i];
			return SceneList[model].GetTextureIDs()[i];
		}
	}
}

FSHData::blendShape ** FishBox::meshBlendShapes(unsigned int model, unsigned int mesh)
{
	if (model >= SceneList.size() || mesh > SceneList[model].GetMeshCount())
	{
		printf("No model or mesh at index");
	}

	return SceneList[model].GetMeshList()[mesh]->GetBlendShapes();
}

void FishBox::clean() //cleans texture memory of all textures, use only after the textureData has been assigned
{
	for (int i = 0; i < extraTextures.size(); i++)
		SOIL_free_image_data(extraTextures[i]->textureData);


}

void FishBox::freeTextures()
{
	//for (int i = 0; i < textures.size(); i++)
	//	SOIL_free_image_data(textures[i]->textureData);
	for (int i = 0; i < textures.size(); i++)
	{
		
		delete[] textures[i]->textureData;
	}
}

texture * FishBox::loadTexure(char* filepath)
{
	FSHData::texture * tempTex = new texture;
	tempTex->textureData = SOIL_load_image(filepath, &tempTex->width, &tempTex->height, 0, SOIL_LOAD_RGBA);

	extraTextures.push_back(tempTex);
	return tempTex;
}

void FishBox::LoadTextures()
{
	_finddata_t data;

	int first = _findfirst("Models/Textures/*.FST", &data);
	int next = 0;
	int counter = 0;
	while (next != -1)
	{
		std::string temp;
		temp = data.name;
		GLuint tempglu;
		textureIDs.push_back(tempglu);
		textureNames.push_back(temp.c_str());

		next = _findnext(first, &data);

		temp = "Models/Textures/" + temp;

		FSHData::texture * tempTex = new texture;
		tempTex->textureData = SOIL_load_image(temp.c_str(), &tempTex->width, &tempTex->height, 0, SOIL_LOAD_RGBA);

		glGenTextures(1, &textureIDs[counter]);
		glBindTexture(GL_TEXTURE_2D, textureIDs[counter]);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tempTex->width, tempTex->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tempTex->textureData);


		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		textures.push_back(tempTex);

		SOIL_free_image_data(textures[counter]->textureData);
		//delete[] textures[counter]->textureData;
		counter++;
	}
}