#include "ExeSolution.h"
//void insertInputFilesFromLocalFiles(vector<string>& inputFiles);
//void testInputs(vector<string> inputFiles);

int main(int argc, char* argv[])
{
	cout << argv[1] << endl;
	ExeSolution solution(argv[1]);
	solution.runProgram();
	return 0;
}

/*TESTS */

//int main(int argc, char** argv)
//{
//	 vector<string> inputFiles;
//	 insertInputFilesFromLocalFiles(inputFiles);
//
//	//basic tests
//	 
//	 testInputs(inputFiles); //static size
//
//	//run single solution
//
//	//int testInputIndex = 1;
//	//cout << inputFiles[testInputIndex] << endl;
//	//ExeSolution solution(inputFiles[testInputIndex]); 
//	//solution.runProgram();
//	return 0;
//}
//
//void insertInputFilesFromLocalFiles(vector<string>& inputFiles)
//{
//	//inputFiles.emplace_back("InputFiles\\15_15_15.txt");
//	//inputFiles.emplace_back("InputFiles\\19_19_21.txt");
//	//inputFiles.emplace_back("InputFiles\\20_20_NoMst.txt");
//	//inputFiles.emplace_back("InputFiles\\43_43_46.txt");
//	//inputFiles.emplace_back("InputFiles\\47_47_49.txt");
//	//inputFiles.emplace_back("InputFiles\\47_47_NoMST.txt");
//	//inputFiles.emplace_back("InputFiles\\6006_6006_NoMST.txt");
//	//inputFiles.emplace_back("InputFiles\\badNumberOfVertex.txt");
//	//inputFiles.emplace_back("InputFiles\\EmptyFile.txt");
//	//inputFiles.emplace_back("InputFiles\\missingWeight.txt");
//	//inputFiles.emplace_back("InputFiles\\negativeAmountOfVertex.txt");
//	//inputFiles.emplace_back("InputFiles\\negativeVertexIdInSomeVertex.txt");
//	//inputFiles.emplace_back("InputFiles\\negativeVertexIdInVertexToRemove.txt");
//	//inputFiles.emplace_back("InputFiles\\noConnection.txt"); 
//	//inputFiles.emplace_back("InputFiles\\notADigitInInput.txt");
//	//inputFiles.emplace_back("InputFiles\\notADigitInWeight.txt");
//	//inputFiles.emplace_back("InputFiles\\wrongAmountOfEdges.txt");
//	//inputFiles.emplace_back("InputFiles\\wrongVertexIdInEdge.txt");
//
//	inputFiles.emplace_back("input2\\g1.txt");
//	inputFiles.emplace_back("input2\\g2.txt");
//	inputFiles.emplace_back("input2\\g3.txt");
//	inputFiles.emplace_back("input2\\g4.txt");
//
//
//}
//
//void testInputs(vector<string> inputFiles)
//{
//	for (int i = 0 ; i < inputFiles.capacity(); i++)
//	{
//		cout << inputFiles[i] << ": " << endl;
//		ExeSolution solution(inputFiles[i]);
//		solution.runProgram();
//	}
//}

/*******************************/