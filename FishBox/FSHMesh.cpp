

#include "stdafx.h"
#include "FishBox.h"



void FSHMesh::loadVertexData()
{
	this->vertexCount = 4;
	FSHVertexData LVertices[] =
	{
		-0.5f,  0.5f, 1.0f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, // Top-left
		0.5f,  0.5f, 0.0f, 0.5f,  0.5f, 0.0f, 1.0f , 1.0f, // Top-right
		0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 1.0f , 1.0f, // Bottom-right
		-0.5f, -0.5f, 1.0f, -0.5f, -0.5f, 1.0f, 1.0f,1.0f// Bottom-left
	};

	for (int vertIndex = 0; vertIndex < this->vertexCount; vertIndex++)
	{
		this->vertexVector.push_back(LVertices[vertIndex]);

	}


}

void FSHMesh::loadIndices()
{
	this->indexCount = 6;
	this->indices[0, 1, 2, 2, 3, 0];
}

FSHMesh::FSHMesh(void)
{
	this->loadVertexData();
	this->loadIndices();
}

FSHMesh::~FSHMesh(void)
{
	//if (this->vertexVector!=nullptr)
	//delete this->vertexVector;
}


unsigned int FSHMesh::getVertexCount()
{
	return this->vertexCount;
}

std::vector<FSHVertexData>& FSHMesh::GetVertices()
{

	return this->vertexVector;
}

unsigned int FSHMesh::getIndexCount()
{
	return this->indexCount;
}





