#include "PAFInspectTree.h"

#include "TTree.h"
#include "TFile.h"
#include "TLeaf.h"

#include <iostream>

void printError(){
	std::cout << "Arguments unrecognized." << std::endl;
}

void printHelp(){
	std::cout << "-\t\"-h | --help\" to show command help." << std::endl;
	std::cout << "-\t\"-b | --branch branchname\" to retrieve information about specified branch." << std::endl;
	std::cout << "-\t\"-t | --tree treename\"  to retrieve information about specified tree." << std::endl;
}

void printVariables(const char* fileName, const char* branchName, const char* treeName){
	if(treeName == NULL){
		treeName = "Tree";
	}

	TFile* file = new TFile(fileName);
	TTree* tree = (TTree*)file->Get(treeName);
	
	TObjArray* leaves = tree->GetListOfLeaves();
	Int_t nb = leaves->GetEntriesFast();
	for (Int_t i = 0; i < nb; ++i) {
		TLeaf* leaf = (TLeaf*)leaves->UncheckedAt(i);
		if(branchName == NULL || TString(leaf->GetName()).EqualTo(branchName)) {
			std::cout << "Type: " << leaf->GetTypeName() << " \t\tVariable: " << leaf->GetName() <<  std::endl;
		}
	}
	
	delete tree;
	delete file;
}

int main(int argc, const char* argv[]){
	if(argc == 1){
		printHelp();
		return 1;
	}
	
	if(argc == 2 && (TString(argv[1]).EqualTo("-h") || TString(argv[1]).EqualTo("--help")) ){
		printHelp();
		return 0;	
	}
	
	const char* branchName = NULL;
	const char* treeName = NULL;
	
	for(int i = 1; i < argc; i = i + 2){
		TString item = argv[i];		
		if(item.EqualTo("-b") || item.EqualTo("--branch")){
			branchName = argv[i + 1];
		} else if (item.EqualTo("-t") || item.EqualTo("--tree")) {
			treeName = argv[i + 1];
		}
	}
	
	printVariables(argv[argc - 1], branchName, treeName);
	
	return 0;
}
