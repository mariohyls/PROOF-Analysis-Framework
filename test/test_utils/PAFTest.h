/**
	@brief PAF abstract test class to provide some common functions and main method.
	@file PAFTest.h
	@class PAFTest
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2015-06-01
 */

#pragma once

#include "TObject.h"
#include "TString.h"

class PAFTest
{
	public:
		static int Evaluate(PAFTest* test);

		virtual void Initialise();
		virtual void Test();
		virtual void Finalize();

	protected:
		void AssertEquals(bool expected, bool value);
		void AssertEquals(int expected, int value);
		void AssertEquals(float expected, float value);
		void AssertEquals(double expected, double value, double maxError = 1.0e-10);
		void AssertEquals(long expected, long value);
		void AssertEquals(TString& expected, TString& value);
		void AssertEquals(const char* expected, const char* value);
		void AssertEquals(void* expected, void* value);
		void AssertEquals(TObject* expected, TObject* value);
};
