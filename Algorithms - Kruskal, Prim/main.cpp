#include "ExeSolution.h"

int main(int argc, char** argv)
{
	ExeSolution solution("InputFiles\\6006_6006_NoMST.txt"); //todo: static
	solution.runProgram();
	return 0;
}


//int main1(int argc, char** argv) // argv[0] progname argv[1] inputfile name
//{
//	ExeSolution solution(argv[1]); 
//	solution.runProgram();
//	return 0;
//}

//passed 15_15_15 
//passed 19_19_21
//passed 20_20_NoMst
//passed 43_43_46

//failed 47_47_NoMst: Prim gave 50 instead of 47 and hasn't found mst
