

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
	unsigned int readFrom[] = { 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4 };

	for  (unsigned int i = 0; i < 6; i++)
	{
		this->indices.push_back(readFrom[i]);
	}
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

std::vector<unsigned int> FSHMesh::getIndices()
{

	return this->indices;
}

unsigned int FSHMesh::getIndexCount()
{
	return this->indexCount;
}

void FSHMesh::Test()
{
	printf("Hello its me i was wondering if after\n");
}





