

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

FSHMesh::FSHMesh(void)
{
	this->loadVertexData();
	this->loadIndices();
}

FSHMesh::FSHMesh(std::ifstream * infile)
{
	this->infile = infile;

	this->infile->read((char*)&meshHEADER, sizeof(mesh));
	this->loadVertexData();
	this->loadIndices();
	//this->materialName = meshHEADER.materialName; //later
}

FSHMesh::~FSHMesh(void)
{
	//if (this->vertexVector!=nullptr)
	//delete this->vertexVector;
}


unsigned int FSHMesh::getVertexCount()
{
	return this->meshHEADER.vertexCount;
}

std::vector<FSHVertexData>& FSHMesh::GetVertices()
{

	return this->vertexVector;
}

unsigned int FSHMesh::getIndexCount()
{
	return this->meshHEADER.indexCount;
}





