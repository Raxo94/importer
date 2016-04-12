#include "stdafx.h"
#include "FishBox.h"


FSHMaterial::FSHMaterial(void)
{
	this->ambient[0] = this->ambient[1] = this->ambient[2] = 1.0f;
	this->diffuse[0] = this->diffuse[1] = this->diffuse[2] = 1.0f;
	this->specular[0] = this->specular[1] = this->specular[2] = 1.0f;
	this->shinyValue = 100;
	return;
}

std::string FSHMaterial::getMaterialName()
{
	return this->materialName;
}

std::string FSHMaterial::getTextureFilePath()
{
	return this->textureFilePath;
}

float * FSHMaterial::getAmbient()
{
	return this->ambient;
}

float * FSHMaterial::getDiffuse()
{
	return this->diffuse;
}

float * FSHMaterial::getSpecular()
{
	return this->specular;
}

float FSHMaterial::getShinyness()
{
	return this->shinyValue;
}

