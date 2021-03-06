/**
	@brief Internal PAF class to holds TLeafElements type.
	@file PAFElementType.cxx
	@class PAFElementType
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2014-06-17
 */

#include "PAFElementType.h"
#include "TBranch.h"

ClassImp(PAFElementType);

PAFElementType::PAFElementType()
	: PAFAbstractType()
{

}

PAFElementType::PAFElementType(TLeaf* leaf)
	: PAFAbstractType(leaf)
{

}

PAFElementType::~PAFElementType()
{

}

void* PAFElementType::GetPointer()
{
	EnableBranch();
	return fLeaf->GetBranch()->GetAddress();
}

void* PAFElementType::GetPointer(int /*pos*/)
{
	EnableBranch();
	return fLeaf->GetBranch()->GetAddress();
}

int PAFElementType::GetNData()
{
	return 0;
}
