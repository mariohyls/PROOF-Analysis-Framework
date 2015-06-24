/**
	@brief Internal PAF class to hold TLeafs of a TTree in order to be used by PAF.
	@file PAFIType.h
	@class PAFIType
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2014-06-17
*/

#pragma once

#include "TObject.h"

#include "TLeaf.h"

class PAFIType : public TObject
{
	public:
		virtual void* GetPointer(int pos = 0);

		virtual TLeaf* GetLeaf();
		
		virtual int GetNData();

	ClassDef(PAFIType, 1);
};
