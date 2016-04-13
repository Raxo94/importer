// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the FISHBOX_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// FISHBOX_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef FISHBOX_EXPORTS
#define FISHBOX_API __declspec(dllexport)
#else
#define FISHBOX_API __declspec(dllimport)
#endif

#include <vector>
#include <iostream>
#include "stdio.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
//#include "GLUtil.h"


class FISHBOX_API FSHMaterial
{
private:
	struct material
	{
		char materialName[256];
		char textureFilePath[256];
		char normalFilePath[256];

		float ambient[3];
		float diffuse[3];
		float spec[3];
		float shinyness;
	};

private: //variables
	std::string materialName = "MaterialName";
	std::string textureFilePath;
	std::string normalFilePAth;
	float ambient[3];
	float diffuse[3];
	float specular[3];
	float shinyValue;
public: //functions
	FSHMaterial(void);
	std::string getMaterialName();
	std::string getTextureFilePath();
	float* getAmbient();
	float* getDiffuse();
	float* getSpecular();
	float getShinyness();
};



struct FSHVertexData
{
	float pos[3];
	float normal[3];
	float uv[2];
};



class FISHBOX_API FSHMesh {
private: //structs
	struct mesh
	{
		char materialName[256];
		unsigned int vertexCount;
		unsigned int blendshapesCount;
		unsigned int indexCount;
	};
	struct vertexData
	{
		float pos[3];
		float normal[3];
		float uv[2];
	};
	struct index
	{
		unsigned int vertexIndex;
	};
	struct blendShape
	{
		float pos[3];
	};

private: //variables 
	std::ifstream * infile;

	mesh meshHEADER;
	std::vector<FSHVertexData> vertexVector;
	unsigned int* indices = nullptr;
	vertexData * vertices = nullptr;

private: //functions
	void loadVertexData();
	void loadIndices();

public: //functiuons
	FSHMesh(void);
	FSHMesh(std::ifstream* infile);
	~FSHMesh(void);
	unsigned int getVertexCount();
	std::vector<FSHVertexData>& GetVertices();
	unsigned int getIndexCount();
	//getUVs();
	//getMaterial();
	//getTexture();
};








class FISHBOX_API FSHModel
{
private: 
	struct fileHeader
	{
		unsigned int meshCount;
		unsigned int materialCount;
		unsigned int directionalLightCount;
		unsigned int pointLightCount;
		unsigned int areaLightCount;
		unsigned int cameraCount;
	};

private:
	fileHeader HEADER;
	std::ifstream * infile;
	FSHMesh * meshes;


	std::vector <FSHMesh> MeshList;
	std::vector<FSHMaterial> MaterialList;
private:

	void LoadMeshes();
	void LoadMaterials();
public:
	FSHModel(void);
	FSHModel(char * filePath);
	unsigned int GetMeshCount();
	std::vector<FSHMesh>& GetMeshList();
	std::vector<FSHMaterial>& GetMaterialList();
	void Release();
};








class FISHBOX_API FishBox {
private:


private: //varaibles
	
	unsigned int modelCount = 0;
	FSHModel * Models;
	std::vector<FSHModel> ModelList;
public: //variables
	FishBox(void);
	void Test();
	void LoadModel(char * filePath);

public: //functions 
	std::vector<FSHModel>& GetModelList();

};






//extern FISHBOX_API int nFishBox;
//
//FISHBOX_API int fnFishBox(void);