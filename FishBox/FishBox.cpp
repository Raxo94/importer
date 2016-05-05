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

texture * FishBox::loadTexure(char* filepath)
{
	FSHData::texture * tempTex = new texture;
	tempTex->textureData = SOIL_load_image(filepath, &tempTex->width, &tempTex->height, 0, SOIL_LOAD_RGBA);

	extraTextures.push_back(tempTex);
	return tempTex;
}
