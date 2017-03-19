//#include "DynamicMatrix.h"
//#include "Handle.h"

#include <iostream>
#include <sstream>
#include <map>

#include <fstream>

#include "matrix.h"
#include <time.h>
//
//using std::string; using std::istringstream;
//using std::vector; using std::map;
//
//using  Arg = std::vector<std::string>;
//
//const std::string UserName = "Admin";
//const std::string ComputerName = "LAR-FMS";
//
//
//
//map<string, Handle*> handlers;
//
//void PrintPrompt();
//void initCmd();
//void DoUserCmd(std::istream &in,bool needPrompt = true);

void test()
{
	DynamicMatrix<int> DMc;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			DMc.GetOne(rand()%5);
		}
		DMc.ReFlash();
	}
	Matrix<int, 3, 2> Rc(DMc);
	
	DMc.Clear();
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			DMc.GetOne(rand() % 5);
		}
		DMc.ReFlash();
	}

	Matrix<int, 2, 4> Mc(DMc);

	Rc.temp_display();
	std::cout << std::endl;
	Mc.temp_display();
	std::cout << std::endl;

	auto Fc = Rc.operator*(Mc);

	Fc.temp_display();

	swap(Rc, Mc);
	Rc.temp_display();
	std::cout << std::endl;
	Mc.temp_display();
	std::cout << std::endl;

	//int * p = new int[2];
	//int * q = nullptr;
	//std::swap(p, q);
	//if (p == nullptr) {
	//	std::cout << "successful to swap" << std::endl;
	//}
}

int main(int argc, char ** argv)
{
	srand((unsigned)time(NULL));
	test();
	//std::cout << "LAR Far DynamicMatrix System 3.5.0" << "(" << __DATE__ << "," << __TIME__ << ")";
	//std::cout << "\n[MSC v." << _MSC_VER << " 32 bit(Intel)] on win32" << std::endl;
	//initCmd();
	//
	//if (argc > 1) {
	//	std::ifstream infile;
	//	infile.open(argv[1]);
	//	DoUserCmd(infile,false);
	//}
	//else {
	//	PrintPrompt();
	//	DoUserCmd(std::cin);
	//}
	
}
//
//void PrintPrompt()
//{
//	std::cout << UserName << "@" << ComputerName << "~:";
//}
//
//void initCmd()
//{
//	handlers["DynamicMatrix"] = new HandleNew;
//	handlers["append"] = new HandleAppend;
//	handlers["ls"] = new HandleLs;
//	handlers["reduce"] = new HandleReduce;
//	handlers["det"] = new HandleDet;
//	handlers["cls"] = new HandleClear;
//	handlers["transpose"] = new HandleTranspose;
//	handlers["+"] = new HandleAdd;
//	handlers["-"] = new HandleSub;
//	handlers["*"] = new HandleMult;
//	handlers["loadData"] = new HandleLoadData;
//	handlers["print"] = new HandlePrint;
//	handlers["pause"] = new HandlePause;
//	handlers["define"] = new HandleDefine;
//
//}
//
//void DoUserCmd(std::istream & in, bool needPrompt)
//{
//	std::string cmdline;
//	while (std::getline(in, cmdline)) {
//
//		std::istringstream cmdin(cmdline);
//		string cmd;
//		cmdin >> cmd;
//		if (handlers.find(cmd) == handlers.end()) {
//			if (cmd != "") {
//				std::cout << "无效的关键字" << std::endl;
//			}
//		}
//		else {
//			vector<string> args;
//			string temp;
//			while (cmdin >> temp)
//				args.push_back(temp);
//
//			handlers[cmd]->doCmd(args);
//		}
//
//		if (needPrompt) {
//			PrintPrompt();
//		}
//
//		
//	}
//}
//
//
//
