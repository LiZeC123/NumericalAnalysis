//#include "Handle.h"
//#include "DynamicMatrix.h"
//#include<map>
//#include<set>
//#include <sstream>
//
//std::map<std::string, DynamicMatrix> UserValueSpace;
//DynamicMatrix Ans;
//
//static std::istream & _Append(std::istream & in, DynamicMatrix & Mc);
//
//
//void HandleNew::doCmd(Arg args)
//{
//	if (UserValueSpace.size() == 0) {
//		UserValueSpace["Ans"] = Ans;
//	}
//
//	for (auto &name : args) {
//		DynamicMatrix NewM;
//		UserValueSpace[name] = NewM;
//	}
//}
//
//void HandleLs::doCmd(Arg args)
//{
//	for (const auto & name : args) {
//		if (UserValueSpace.find(name) == UserValueSpace.end()) {
//			std::cerr << name << "�����ڻ��޷�����" << std::endl;
//		}
//		else {
//			UserValueSpace[name].ShowMatrix();
//			std::cout << std::endl;
//		}
//	}
//}
//
//void HandleReduce::doCmd(Arg args)
//{
//	for (const auto & name : args) {
//		if (UserValueSpace[name].IsEmpty()) {
//			std::cerr << name << "Ϊ�գ��Ըþ���Ļ�����ֹͣ" << std::endl;
//		}
//		else {
//			UserValueSpace[name].RowReduce();
//			UserValueSpace[name].ShowMatrix();
//			std::cout << std::endl;
//		}
//	}
//}
//
//void HandleDet::doCmd(Arg args)
//{
//	for (const auto & name : args) {
//		if (UserValueSpace[name].IsEmpty()) {
//			std::cerr << name << "Ϊ�գ��Ը�����ʽ�ļ�����ֹͣ" << std::endl;
//		}
//		else {
//			std::cout << UserValueSpace[name].det() << std::endl;
//		}
//	}
//}
//
//void HandleClear::doCmd(Arg args)
//{
//	for (const auto & name : args) {
//		if (UserValueSpace.find(name) == UserValueSpace.end()) {
//			std::cerr << name << "�����ڻ��޷�����" << std::endl;
//		}
//		else {
//			UserValueSpace[name].Clear();
//		}
//	}
//}
//
//void HandleAdd::doCmd(Arg args)
//{
//	DynamicMatrix Vc;
//	if (args.size() != 2) {
//		std::cerr << "����������ƥ��" << std::endl;
//	}
//	else {
//		try
//		{
//			Vc = UserValueSpace[args[0]]
//				+ UserValueSpace[args[1]];
//		}
//		catch (const matrix_mismatch & e)
//		{
//			std::cout << e.what() << ",������ֹͣ";
//		}
//
//		Vc.ShowMatrix();
//		std::cout << std::endl;
//		UserValueSpace["Ans"] = Vc;
//	}
//}
//
//void HandleSub::doCmd(Arg args)
//{
//	DynamicMatrix Vc;
//	if (args.size() != 2) {
//		std::cerr << "����������ƥ��" << std::endl;
//	}
//	else {
//		try
//		{
//			Vc = UserValueSpace[args[0]]
//				- UserValueSpace[args[1]];
//		}
//		catch (const matrix_mismatch & e)
//		{
//			std::cout << e.what() << ",������ֹͣ";
//		}
//
//		Vc.ShowMatrix();
//		std::cout << std::endl;
//		UserValueSpace["Ans"] = Vc;
//	}
//}
//
//void HandleMult::doCmd(Arg args)
//{
//	DynamicMatrix Vc;
//	if (args.size() != 2) {
//		std::cerr << "����������ƥ��" << std::endl;
//	}
//	else {
//		try
//		{
//			Vc = UserValueSpace[args[0]]
//				* UserValueSpace[args[1]];
//		}
//		catch (const matrix_mismatch & e)
//		{
//			std::cout << e.what() << ",������ֹͣ";
//		}
//
//		Vc.ShowMatrix();
//		std::cout << std::endl;
//		UserValueSpace["Ans"] = Vc;
//	}
//}
//
//void HandleLoadData::doCmd(Arg args)
//{
//	//args[0] : ValueName
//	//args[1] : filename
//	if (args.size() != 2) {
//		std::cerr << "����ָ������" << std::endl;
//		return;
//	}
//
//	std::string name = args[0];
//	std::string filename = args[1];
//
//	std::ifstream inputfile;
//	inputfile.open(filename);
//
//	_Append(inputfile, UserValueSpace[name]);
//
//
//}
//
//void HandleAppend::doCmd(Arg args)
//{
//	std::cout << "�����������׷����ľ�������EOF����:" << std::endl;
//
//	for (const auto & name : args) {
//		if (UserValueSpace.find(name) == UserValueSpace.end()) {
//			std::cerr << name << "�����ڻ��޷�����" << std::endl;
//		}
//		else {
//			_Append(std::cin, UserValueSpace[name]);
//		}
//	}
//}
//
//
//static std::istream & _Append(std::istream & in, DynamicMatrix & Mc)
//{
//	
//	std::string s;
//	while (std::getline(in, s)) {
//		std::istringstream sin(s);
//		int temp;
//		while (sin >> temp) {
//			Mc.GetOne(temp);
//		}
//		Mc.ReFlash();
//	}
//	if (!Mc.IsRegular()) {
//		std::cerr << "������벻��һ������ľ���" << std::endl;
//
//	}
//
//	if (!in) {
//		in.clear();
//	}
//
//	Mc.ShowMatrix();
//	std::cout << std::endl;
//
//	return in;
//}
//
//void HandleTranspose::doCmd(Arg args)
//{
//	for (const auto & name : args) {
//		if (UserValueSpace.find(name) == UserValueSpace.end()) {
//			std::cerr << name << "�����ڻ��޷�����" << std::endl;
//		}
//		else {
//			UserValueSpace[name].Transpose();
//			
//		}
//	}
//}
//
//void HandlePrint::doCmd(Arg args)
//{
//	for (const auto &i : args) {
//		std::cout << i << ' ';
//	}
//	std::cout << std::endl;
//}
//
//void HandlePause::doCmd(Arg args)
//{
//	system("pause");
//}
//
//void HandleDefine::doCmd(Arg args)
//{
//	if (args.size() != 2) {
//		std::cerr << "����������ƥ��" << std::endl;
//		return;
//	}
//
//	for (const auto & name : args) {
//		if (UserValueSpace.find(name) == UserValueSpace.end()) {
//			std::cerr << name << "�����ڻ��޷�����" << std::endl;
//			return;
//		}
//	}
//
//	UserValueSpace[args[0]] = UserValueSpace[args[1]];
//}
