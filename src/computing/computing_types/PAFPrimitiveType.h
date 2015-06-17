/**
	@brief Internal PAF class to holds ROOT types (Float_t, Double_t...) TLeafs.
	@file PAFPrimitiveType.h
	@class PAFPrimitiveType
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2014-06-17
*/

#pragma once

#include "PAFAbstractType.h"

template <class T>
class PAFPrimitiveType : public PAFAbstractType
{
	public:
		PAFPrimitiveType() : PAFAbstractType() {}
		PAFPrimitiveType(TLeaf* leaf) : PAFAbstractType(leaf) {}
		virtual ~PAFPrimitiveType() {}

		virtual void* GetPointer(int pos = 0);

	ClassDef(PAFPrimitiveType<T>, 1);
};

template <class T>
inline void* PAFPrimitiveType<T>::GetPointer(int pos)
{
	T* values = (T*)fLeaf->GetValuePointer();
	return &values[pos];
}

