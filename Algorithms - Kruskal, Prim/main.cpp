#include "ExeSolution.h"

int main(int argc, char** argv)
{
	ExeSolution solution("InputFiles\\notADigitInWeight.txt"); //todo: static
	solution.runProgram();
	return 0;
}


//int main1(int argc, char** argv) // argv[0] progname argv[1] inputfile name
//{
//	ExeSolution solution(argv[1]); 
//	solution.runProgram();
//	return 0;
//}

