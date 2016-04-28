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
	
}

FSHMesh::~FSHMesh(void)
{
	//if (this->vertexVector!=nullptr)
	delete[] indices;
	delete[] vertices;
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





