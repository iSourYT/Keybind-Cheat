/*
Syn's AyyWare Framework 2015
*/

#pragma once
#include "SDK.h"


void LoadFromBuffer(KeyValues* keyValues, char const *resourceName, const char *pBuffer);

void LoadFromBufferNF(KeyValues* keyValues, char const *resourceName, const char *pBuffer);

void ForceMaterial(Color color, IMaterial* material, bool useColor = true, bool forceMaterial = true);

IMaterial *CreateMaterial(bool shouldIgnoreZ, bool isLit = true, bool isWireframe = false);
IMaterial *CreateMaterialNF(bool shouldIgnoreZ, bool isLit = true, bool isWireframe = false);