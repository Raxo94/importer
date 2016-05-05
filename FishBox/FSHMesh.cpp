#include "stdafx.h"
#include "FishBox.h"



void FSHMesh::loadVertexData()
{
	vertices = new vertexData[meshHEADER.vertexCount];
	infile->read((char*)vertices, sizeof(vertexData)*meshHEADER.vertexCount);
}

void FSHMesh::loadIndices()
{
	indices = new unsigned int[meshHEADER.indexCount];
	infile->read((char*)indices, sizeof(unsigned int)*meshHEADER.indexCount);
}

void FSHMesh::loadBlendshapes()
{
	this->blendShapes = new blendShape*[meshHEADER.blendshapesCount];
	for (int i = 0; i < meshHEADER.blendshapesCount; i++)
	{
		this->blendShapes[i] = new blendShape[meshHEADER.vertexCount];
		infile->read((char*)blendShapes[i], sizeof(blendShape)*meshHEADER.vertexCount);
	}
}
FSHMesh::FSHMesh(void) //NEEEEEEEEVER USE!
{
	//NEVER USE
}

FSHMesh::FSHMesh(std::ifstream *& infile)
{
	this->infile = infile;

	this->infile->read((char*)&meshHEADER, sizeof(mesh));


	this->loadVertexData();
	this->loadIndices();
	if (meshHEADER.blendshapesCount > 0)
		this->loadBlendshapes();
	
}

FSHMesh::~FSHMesh(void)
{
	//if (this->vertexVector!=nullptr)
	delete[] indices;
	delete[] vertices;
	for (int i = 0; i < meshHEADER.blendshapesCount; i++)
		delete[] blendShapes[i];
	delete[] blendShapes;
}


unsigned int FSHMesh::getVertexCount()
{
	return this->meshHEADER.vertexCount;
}

vertexData * FSHMesh::GetVertices()
{
	return vertices;
}

mesh * FSHMesh::GetMeshData()
{
	return &meshHEADER;
}

unsigned int * FSHMesh::GetIndices()
{
	return indices;
}


unsigned int FSHMesh::getIndexCount()
{
	return this->meshHEADER.indexCount;
}

blendShape ** FSHMesh::GetBlendShapes()
{
	return blendShapes;
}





