/**
	@brief Implementation of PAFIExecutionEnvironment to work in sequential mode.
	@file PAFSequentialEnvironment.h
	@class PAFSequentialEnvironment
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2015-02-02
 */

#include "PAFIExecutionEnvironment.h"

#include "TTree.h"

class PAFSequentialEnvironment : public PAFIExecutionEnvironment 
{
	public:
		PAFSequentialEnvironment();
		virtual ~PAFSequentialEnvironment();

		void Initialise() {}
		void Dispose() {}

		virtual void AddInput(TObject* obj);
		virtual void AddFeedback(const char* name);
		virtual TDrawFeedback* CreateDrawFeedback();

		virtual void SetProgressUpdated(PAFIProgressUpdated* progressUpdated);
		virtual PAFIProgressUpdated* GetProgressUpdated();

		virtual void Process ( PAFBaseSelector* selector, Long64_t nentries );
		virtual void Process(PAFBaseSelector* selector, TDSet* dataFiles, Long64_t firstEvent, Long64_t nEvents);

		virtual Bool_t UploadPackage(PAFPackage* package);
		virtual Bool_t EnablePackage(PAFPackage* package);

		virtual Bool_t LoadLibrary(PAFLibrary* library);

	protected:
		void InitMembers();

		Long64_t GetEntriesFrom(Long64_t passedEntries, Long64_t firstEvent);
		Long64_t GetEntriesTo(Long64_t entriesTree, Long64_t passedEntries, Long64_t firstEvent, Long64_t nEvents);
		Long64_t GetEntriesTotal(TDSet* dataFiles);

		TTree* GetTree(TDSet* dataFiles, Int_t i);

		virtual void DrawFeedback(TSelector* selector);

	protected:
		TList*			fInputList;
		PAFVariableContainer* 	fFeedbackCanvas;
		PAFIProgressUpdated*	fProgressUpdated;
};
