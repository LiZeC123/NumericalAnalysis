//#include "Handler.h"
//
///*                    ���û���ص�ȫ�ֱ���              */
//std::string UserName = "~";
//std::string ComputerName = "TK-S300";
//
//std::map<std::string, DynamicMatrix> UserValueSpace;
//std::map<std::string, Handler*> handlers;
//
//
///*                    �������ʵ��                      */
//void HandlerNew::doCmd(Arg args)
//{
//	for (auto & name : args) {
//		if ( handlers.find(name) != handlers.end()) {
//			std::cerr << name << "�ǹؼ��֣�������Ϊ��ʶ��" << std::endl;
//			return;
//		}
//	}
//	for (auto &name : args) {
//		DynamicMatrix NewM;
//		UserValueSpace[name] = NewM;
//	}
//}
//
//void HandlerLook::doCmd(Arg args)
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
//void HandlerReduce::doCmd(Arg args)
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
//void HandlerDet::doCmd(Arg args)
//{
//	for (const auto & name : args) {
//		if (UserValueSpace[name].IsEmpty()) {
//			std::cerr << name << "Ϊ�գ��Ը�����ʽ�ļ�����ֹͣ" << std::endl;
//		}
//		else {
//			UserValueSpace[name].det().ShowFraction();
//		}
//	}
//
//}
//
//void HandlerClean::doCmd(Arg args)
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
//void HandlerAppend::doCmd(Arg args)
//{
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
//void HandlerAppend::_Append(std::istream & in, DynamicMatrix & Mc)
//{	
//	std::cout << "�����������׷����ľ�������EOF����:" << std::endl;
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
//		std::cout << "������벻��һ������ľ���" <<std:: endl;
//
//	}
//
//	if (!in) {
//		in.clear();
//	}
//
//	Mc.ShowMatrix();
//
//}
//
//void Handler::doCmd(Arg args)
//{
//	return;
//}
//
//void HandlerAdd::doCmd(Arg args)
//{
//	DynamicMatrix Vc;
//	if (args.size() != 2) {
//		std::cerr << "����������ƥ��" << std::endl;
//	}
//	else {
//		try
//		{
//			Vc = UserValueSpace[args[0]] + UserValueSpace[args[1]];	
//		}
//		catch (const matrix_mismatch & e)
//		{
//			std::cout << e.what() << ",������ֹͣ";
//		}
//
//		Vc.ShowMatrix();
//		std::cout << std::endl;
//	}
//}
//
//void HandlerSub::doCmd(Arg args)
//{
//	DynamicMatrix Vc;
//	if (args.size() != 2) {
//		std::cerr << "����������ƥ��" << std::endl;
//	}
//	else {
//		try
//		{
//			Vc = UserValueSpace[args[0]] - UserValueSpace[args[1]];
//		}
//		catch (const matrix_mismatch & e)
//		{
//			std::cout << e.what() << ",������ֹͣ";
//		}
//
//		Vc.ShowMatrix();
//		std::cout << std::endl;
//	}
//}
//
//void HandlerMult::doCmd(Arg args)
//{
//	DynamicMatrix Vc;
//	if (args.size() != 2) {
//		std::cerr << "����������ƥ��" << std::endl;
//	}
//	else {
//		try
//		{
//			Vc = UserValueSpace[args[0]] * UserValueSpace[args[1]];
//		}
//		catch (const matrix_mismatch & e)
//		{
//			std::cout << e.what() << ",������ֹͣ";
//		}
//
//		Vc.ShowMatrix();
//		std::cout << std::endl;
//	}
//}
//
//
