#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include"Ways.h"
#include"Body.h"
#include"Friends.h"
#include"Admin.h"
#include"Time.h"
#include"UI.h"
#include"Action.h"
using namespace std;
int class_PlatformBody::ConstID = 1;
int class_Group::GroConstID = 20000;
bool Exit = false;
int main() {
	string Option;//ѡ��
	string Account;//������˻�
	int AccountID;//������˻����ص�ƽ̨ID
	string Password;//��õ�����
	int FalseTime = 0;//����������
	bool axz = true;
	do {
		system("cls");
		HomePage(axz);
		axz = false;
		cin >> Option;
		getchar();
		switch (Str2Num(Option))
		{
			//QQ
		case 1: {
			WriteLog("����QQ");
			Transition_1(15, 21, 1);
			do {
				SecondHomePage("QQ");
				cin >> Option;
				getchar();
				switch (Str2Num(Option))
				{
					//����
				case 1: {
					WriteLog("QQ����");
					Transition_2(41, 14, 7);
					do {
						//�����˺�
						LoginPage("account", "������������ӡ���������������дҲ�ǿ��ԵĶ԰�(*��3��)�q");
						//�����˺�
						if (cin >> Account) {
							//�˳�
							if (Account.compare("$exit$") == 0)
								break;
							class_Admin* Admin;
							Admin = new(class_Admin);
							AccountID = (*Admin).ReturnPlatformID(Account);
							delete(Admin);
							//�˺Ŵ���
							if (AccountID != 0) {
								//��ȡ����
								const string Password_ = GetLoginInfo(Num2Str(AccountID), "Password");
								//��ȡ����ɹ�
								if (Password.compare("$Wrong$") != 0) {
									//�����������
									do {
										LoginPage("password", GetLoginInfo(Num2Str(AccountID), "Name"));
										//��������
										int aa = 22;
										do {
												Locate(aa++, 8);
												Password.push_back(_getch());
												if (Password.back() == 13) {
													Password.pop_back();
													break;
												}
												if (Password.back() == 8) {
													if (!Password.empty()) {
														Password.pop_back();
														aa--;
														Locate(aa, 8);
														cout << " ";
													}
													if (!Password.empty()) {
														Password.pop_back();
														aa--;
														Locate(aa, 8);
														cout << " ";
													}
												}
												else cout << "*";
											} while (1);
										if (Password.compare("$exit$") == 0) {
											Password.clear();
											Exit = true;
											break;
										}
										//�ɹ�����
										if (Password.compare(Password_) == 0) {
											Password.clear();
											QQAction(QQAction_Plus(AccountID));
											Exit = true;
											break;
										}
										//�������
										else {
											Password.clear();
											continue;
										}
									} while (1);
									if (Exit) {
										break;
									}
								}
								//û�ҵ����룬һ�㲻����
								else {
									Warning(" ���˻���Ϣ��������ϵ����Ա ", "yellow");
									cout << "                 ";
									system("pause");
								}
							}
							else {
								Warning(" û�в��ҵ����˺� ", "red");
								cout << "                 ";
								system("pause");
							}
						}
					} while (Account.compare("$exit$") != 0);
					Exit = false;
					break;
				}
					//ע��
				case 2: {
					WriteLog("QQע��");
					Transition_2(41, 14, 8);
					QQSignUpPage();
					string temp;
					//*****************************************
					class_PlatformBody NewAccount("new");
					//�����ǳ�
					while (1) {
						Locate(26, 7);
						cin >> temp;
						if ((temp.compare("$empty$") == 0)) {
							Locate(26, 7);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
							cout << "�ǳƲ��Ϸ�                   ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							Sleep(1000);
							Locate(26, 7);
							cout << "                             ";
							continue;
						}
						else if ((temp.compare("�ӽ�") == 0) || (temp.compare("zj") == 0)) {
							Locate(26, 7);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
							cout << "�ǳ�̫�߹�                   ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							Sleep(1000);
							Locate(26, 7);
							cout << "                             ";
							continue;
						}
						else if (temp.compare("$exit$") == 0) {
							Exit = true;
							break;
						}
						else {
							temp = NewAccount.ModifyName(temp);
							Exit = false;
							break;
						}
					}
					//*****************************************
					if (Exit) {
						Exit = false;
						break;
					}
					//*****************************************
					//��������
					while (1) {
						Locate(26, 8);
						cin >> temp;
						if (temp.compare("$exit$") != 0) {
							int a = Str2Num(temp);
							if (NewAccount.ModifyBirthday(a / 10000, (a % 10000) / 100, a % 100) != a) {
								Locate(26, 8);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
								cout << "�����ʱ�䲻�Ϸ�";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
								Sleep(1000);
								Locate(26, 8);
								cout << "                    ";
							}
							else break;
						}
						else {
							Exit = true;
							break;
						}
					}
					//*****************************************
					if (Exit) {
						Exit = false;
						break;
					}
					//*****************************************
					//���������
					while (1) {
						Locate(28, 9);
						cin >> temp;
						if ((temp.compare("$empty$") == 0) || (temp.compare("�ӽ�") == 0) || (temp.compare("zj") == 0)) {
							Locate(28, 9);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
							cout << "���벻�Ϸ�                   ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							Sleep(1000);
							Locate(28, 9);
							cout << "                             ";
							continue;
						}
						else if (temp.compare("$exit$") == 0) {
							Exit = true;
							break;
						}
						else {
							temp = NewAccount.ModifyBirthplace(temp);
							Exit = false;
							break;
						}
					}
					//*****************************************
					if (Exit) {
						Exit = false;
						break;
					}
					//*****************************************
					//��������
					Transition_1(8, 19, 4);
					system("cls");
					PasswordInputPage("first");
					string Password_1;
					string Password_2;
					int aa = 20;
					//��һ������
					do {
						Locate(aa++, 8);
						Password_1.push_back(_getch());
						if (Password_1.back() == 13) {
							Password_1.pop_back();
							break;
						}
						if (Password_1.back() == 8) {
							if (!Password_1.empty()) {
								Password_1.pop_back();
								aa--;
								Locate(aa, 8);
								cout << " ";
							}
							if (!Password_1.empty()) {
								Password_1.pop_back();
								aa--;
								Locate(aa, 8);
								cout << " ";
							}
						}
						else cout << "*";
					} while (1);
					if (Password_1.compare("$exit$") == 0) {
						break;
					}
					Transition_1(8, 19, 4);
					system("cls");
					PasswordInputPage("again");
					aa = 20;
					//�ڶ���ȷ��
					do {
						Locate(aa++, 8);
						Password_2.push_back(_getch());
						if (Password_2.back() == 13) {
							Password_2.pop_back();
							break;
						}
						if (Password_2.back() == 8) {
							if (!Password_2.empty()) {
								Password_2.pop_back();
								aa--;
								Locate(aa, 8);
								cout << " ";
							}
							if (!Password_2.empty()) {
								Password_2.pop_back();
								aa--;
								Locate(aa, 8);
								cout << " ";
							}
						}
						else cout << "*";
					} while (1);
					if (Password_2.compare("$exit$") == 0) {
						break;
					}
					if (Password_1.compare(Password_2) == 0) {
						temp = NewAccount.ModiFyPassword(Password_1);
					}
					else {
						do {
							aa = 20;
							Password_2.clear();
							system("cls");
							PasswordInputPage("wrong");
							do {
								Locate(aa++, 8);
								Password_2.push_back(_getch());
								if (Password_2.back() == 13) {
									Password_2.pop_back();
									break;
								}
								if (Password_2.back() == 8) {
									if (!Password_2.empty()) {
										Password_2.pop_back();
										aa--;
										Locate(aa, 8);
										cout << " ";
									}
									if (!Password_2.empty()) {
										Password_2.pop_back();
										aa--;
										Locate(aa, 8);
										cout << " ";
									}
								}
								else cout << "*";
							} while (1);
							if (Password_1.compare(Password_2) == 0) {
								temp = NewAccount.ModiFyPassword(Password_1);
								break;
							}
						} while (1);
					}
					//*****************************************
					//��¼��ע��
					class_Admin* Admin;
					Admin = new(class_Admin);
					(*Admin).AddNewMember(Str2Num(NewAccount.ReturnInfo("PlatformID")), Str2Num(NewAccount.ReturnInfo("ID")), "$empty$");
					delete(Admin);
					//*****************************************
					//����QQ��
					Warning("���QQ������" + NewAccount.ReturnInfo("ID"), "blue");
					Sleep(1000);
					cout << "                ";
					system("pause");
					break;
				}
					//����
				case 3: {
					WriteLog("QQ����");
					Transition_2(41, 14, 5);
					QQHelpPage();
					getchar();
					Exit = false;
					break;
				}
					//�˳�
				case 4: {
					WriteLog("QQ����");
					Exit = true;
					break;
				}
				default: {
					Warning("�Ƿ��������㼴����������", "red");
					cout << "                 ";
					system("pause");
					break;
				}
				}
				if (Exit) {
					Exit = false;
					break;
				}
			}while (1);
			Exit = false;
			break;
		}
			//΢��
		case 2: {
			WriteLog("����΢��");
			Transition_1(15, 21, 1);
			do {
				SecondHomePage("WeChat");
				cin >> Option;
				getchar();
				switch (Str2Num(Option))
				{
					//����
				case 1: {
					WriteLog("΢�ŵ���");
					Transition_2(41, 14, 7);
					do {
						//�����˺�
						LoginPage("account", "������������ӡ���������������дҲ�ǿ��ԵĶ԰�(*��3��)�q");
						//�����˺�
						if (cin >> Account) {
							//�˳�
							if (Account.compare("$exit$") == 0)
								break;
							class_Admin* Admin;
							Admin = new(class_Admin);
							AccountID = (*Admin).ReturnPlatformID(Account);
							delete(Admin);
							//�˺Ŵ���
							if (AccountID != 0) {
								//��ȡ����
								const string Password_ = GetLoginInfo(Num2Str(AccountID), "Password");
								//��ȡ����ɹ�
								if (Password.compare("$Wrong$") != 0) {
									//�����������
									do {
										LoginPage("password", GetLoginInfo(Num2Str(AccountID), "Name"));
										//��������
										int aa = 22;
										do {
											Locate(aa++, 8);
											Password.push_back(_getch());
											if (Password.back() == 13) {
												Password.pop_back();
												break;
											}
											if (Password.back() == 8) {
												if (!Password.empty()) {
													Password.pop_back();
													aa--;
													Locate(aa, 8);
													cout << " ";
												}
												if (!Password.empty()) {
													Password.pop_back();
													aa--;
													Locate(aa, 8);
													cout << " ";
												}
											}
											else cout << "*";
										} while (1);
										if (Password.compare("$exit$") == 0) {
											Password.clear();
											Exit = true;
											break;
										}
										//�ɹ�����
										if (Password.compare(Password_) == 0) {
											Password.clear();
											WeChatAction(WeChatAction_Plus(AccountID));
											Exit = true;
											break;
										}
										//�������
										else {
											Password.clear();
											continue;
										}
									} while (1);
									if (Exit) {
										break;
									}
								}
								//û�ҵ����룬һ�㲻����
								else {
									Warning(" ���˻���Ϣ��������ϵ����Ա ", "yellow");
									cout << "                 ";
									system("pause");
								}
							}
							else {
								Warning(" û�в��ҵ����˺� ", "red");
								cout << "                 ";
								system("pause");
							}
						}
					} while (Account.compare("$exit$") != 0);
					Exit = false;
					break;
				}
					  //ע��
				case 2: {
					WriteLog("΢��ע��");
					Transition_2(41, 14, 8);
					WeChatSignUpPage();
					string temp;
					//*****************************************
					class_PlatformBody NewAccount("new");
					//����΢�ź�
					while (1) {
						Locate(26, 7);
						cin >> temp;
						if ((temp.compare("$empty$") == 0)) {
							Locate(28, 7);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
							cout << "΢�źŲ��Ϸ�                   ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							Sleep(1000);
							Locate(28, 7);
							cout << "                             ";
							continue;
						}
						else if ((temp.compare("�ӽ�") == 0) || (temp.compare("zj") == 0)) {
							Locate(26, 7);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
							cout << "΢�ź�̫�߹�                   ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							Sleep(1000);
							Locate(26, 7);
							cout << "                             ";
							continue;
						}
						else if (temp.compare("$exit$") == 0) {
							Exit = true;
							break;
						}
						else {
							temp = NewAccount.ModifyID(temp);
							Exit = false;
							break;
						}
					}
					//*****************************************
					if (Exit) {
						Exit = false;
						break;
					}
					//�����ǳ�
					while (1) {
						Locate(26, 8);
						cin >> temp;
						if ((temp.compare("$empty$") == 0)) {
							Locate(26, 8);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
							cout << "�ǳƲ��Ϸ�                   ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							Sleep(1000);
							Locate(26, 8);
							cout << "                             ";
							continue;
						}
						else if ((temp.compare("�ӽ�") == 0) || (temp.compare("zj") == 0)) {
							Locate(26, 7);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
							cout << "�ǳ�̫�߹�                   ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							Sleep(1000);
							Locate(26, 7);
							cout << "                             ";
							continue;
						}
						else if (temp.compare("$exit$") == 0) {
							Exit = true;
							break;
						}
						else {
							temp = NewAccount.ModifyName(temp);
							Exit = false;
							break;
						}
					}
					//*****************************************
					if (Exit) {
						Exit = false;
						break;
					}
					//*****************************************
					//��������
					while (1) {
						Locate(26, 9);
						cin >> temp;
						if (temp.compare("$exit$") != 0) {
							int a = Str2Num(temp);
							if (NewAccount.ModifyBirthday(a / 10000, (a % 10000) / 100, a % 100) != a) {
								Locate(26, 9);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
								cout << "�����ʱ�䲻�Ϸ�";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
								Sleep(1000);
								Locate(26, 9);
								cout << "                    ";
							}
							else break;
						}
						else {
							Exit = true;
							break;
						}
					}
					//*****************************************
					if (Exit) {
						Exit = false;
						break;
					}
					//*****************************************
					//���������
					while (1) {
						Locate(28, 10);
						cin >> temp;
						if ((temp.compare("$empty$") == 0) || (temp.compare("�ӽ�") == 0) || (temp.compare("zj") == 0)) {
							Locate(28, 10);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
							cout << "���벻�Ϸ�                   ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							Sleep(1000);
							Locate(28, 10);
							cout << "                             ";
							continue;
						}
						else if (temp.compare("$exit$") == 0) {
							Exit = true;
							break;
						}
						else {
							temp = NewAccount.ModifyBirthplace(temp);
							Exit = false;
							break;
						}
					}
					//*****************************************
					if (Exit) {
						Exit = false;
						break;
					}
					//*****************************************
					//��������
					Transition_1(8, 19, 4);
					system("cls");
					PasswordInputPage("first");
					string Password_1;
					string Password_2;
					int aa = 20;
					//��һ������
					do {
						Locate(aa++, 8);
						Password_1.push_back(_getch());
						if (Password_1.back() == 13) {
							Password_1.pop_back();
							break;
						}
						if (Password_1.back() == 8) {
							if (!Password_1.empty()) {
								Password_1.pop_back();
								aa--;
								Locate(aa, 8);
								cout << " ";
							}
							if (!Password_1.empty()) {
								Password_1.pop_back();
								aa--;
								Locate(aa, 8);
								cout << " ";
							}
						}
						else cout << "*";
					} while (1);
					if (Password_1.compare("$exit$") == 0) {
						break;
					}
					Transition_1(8, 19, 4);
					system("cls");
					PasswordInputPage("again");
					aa = 20;
					//�ڶ���ȷ��
					do {
						Locate(aa++, 8);
						Password_2.push_back(_getch());
						if (Password_2.back() == 13) {
							Password_2.pop_back();
							break;
						}
						if (Password_2.back() == 8) {
							if (!Password_2.empty()) {
								Password_2.pop_back();
								aa--;
								Locate(aa, 8);
								cout << " ";
							}
							if (!Password_2.empty()) {
								Password_2.pop_back();
								aa--;
								Locate(aa, 8);
								cout << " ";
							}
						}
						else cout << "*";
					} while (1);
					if (Password_2.compare("$exit$") == 0) {
						break;
					}
					if (Password_1.compare(Password_2) == 0) {
						temp = NewAccount.ModiFyPassword(Password_1);
					}
					else {
						do {
							aa = 20;
							Password_2.clear();
							system("cls");
							PasswordInputPage("wrong");
							do {
								Locate(aa++, 8);
								Password_2.push_back(_getch());
								if (Password_2.back() == 13) {
									Password_2.pop_back();
									break;
								}
								if (Password_2.back() == 8) {
									if (!Password_2.empty()) {
										Password_2.pop_back();
										aa--;
										Locate(aa, 8);
										cout << " ";
									}
									if (!Password_2.empty()) {
										Password_2.pop_back();
										aa--;
										Locate(aa, 8);
										cout << " ";
									}
								}
								else cout << "*";
							} while (1);
							if (Password_1.compare(Password_2) == 0) {
								temp = NewAccount.ModiFyPassword(Password_1);
								break;
							}
						} while (1);
					}
					//*****************************************
					//��¼��ע��
					class_Admin* Admin;
					Admin = new(class_Admin);
					(*Admin).AddNewMember(Str2Num(NewAccount.ReturnInfo("PlatformID")), -1, NewAccount.ReturnInfo("ID"));
					delete(Admin);
					//*****************************************
					//����QQ��
					Warning("��ӭ����΢��", "blue");
					Sleep(1000);
					cout << "                ";
					system("pause");
					break;
				}
					  //����
				case 3: {
					WriteLog("΢�Ű���");
					Transition_2(41, 14, 5);
					WeChatHelpPage();
					getchar();
					Exit = false;
					break;
				}
					  //�˳�
				case 4: {
					WriteLog("΢���˳�");
					Exit = true;
					break;
				}
				default: {
					Warning("�Ƿ��������㼴����������", "red");
					cout << "                 ";
					system("pause");
					break;
				}
				}
				if (Exit) {
					Exit = false;
					break;
				}
			} while (1);
			Exit = false;
			break;
		}
			//΢��
		case 3: {
			WriteLog("����΢��");
			Transition_1(15, 21, 1);
			do {
				SecondHomePage("WeiBo");
				cin >> Option;
				getchar();
				switch (Str2Num(Option))
				{
					//����
				case 1: {
					Transition_2(41, 14, 7);
					do {
						//�����˺�
						LoginPage("account", "������������ӡ���������������дҲ�ǿ��ԵĶ԰�(*��3��)�q");
						//�����˺�
						if (cin >> Account) {
							//�˳�
							if (Account.compare("$exit$") == 0)
								break;
							class_Admin* Admin;
							Admin = new(class_Admin);
							AccountID = (*Admin).ReturnPlatformID(Account);
							delete(Admin);
							//�˺Ŵ���
							if (AccountID != 0) {
								//��ȡ����
								const string Password_ = GetLoginInfo(Num2Str(AccountID), "Password");
								//��ȡ����ɹ�
								if (Password.compare("$Wrong$") != 0) {
									//�����������
									do {
										LoginPage("password", GetLoginInfo(Num2Str(AccountID), "Name"));
										//��������
										int aa = 22;
										do {
											Locate(aa++, 8);
											Password.push_back(_getch());
											if (Password.back() == 13) {
												Password.pop_back();
												break;
											}
											if (Password.back() == 8) {
												if (!Password.empty()) {
													Password.pop_back();
													aa--;
													Locate(aa, 8);
													cout << " ";
												}
												if (!Password.empty()) {
													Password.pop_back();
													aa--;
													Locate(aa, 8);
													cout << " ";
												}
											}
											else cout << "*";
										} while (1);
										//�ɹ�����
										if (Password.compare("$exit$") == 0) {
											Password.clear();
											Exit = true;
											break;
										}
										if (Password.compare(Password_) == 0) {
											Password.clear();
											WeiBoAction();
											Exit = true;
											break;
										}
										//�������
										else {
											Password.clear();
											continue;
										}
									} while (1);
									if (Exit) {
										break;
									}
								}
								//û�ҵ����룬һ�㲻����
								else {
									Warning(" ���˻���Ϣ��������ϵ����Ա ", "yellow");
									cout << "                 ";
									system("pause");
								}
							}
							else {
								Warning(" û�в��ҵ����˺� ", "red");
								cout << "                 ";
								system("pause");
							}
						}
					} while (Account.compare("$exit$") != 0);
					Exit = false;
					break;
				}
					  //ע��
				case 2: {
					WriteLog("΢��ע��");
					Transition_2(41, 14, 11);
					WeiBoSignUpPage();
					Locate(16, 9);
					system("pause");
					//*****************************************
					if (Exit) {
						Exit = false;
						break;
					}
					break;
				}
					  //����
				case 3: {
					WriteLog("΢������");
					Transition_2(41, 14, 5);
					QQHelpPage();
					getchar();
					Exit = false;
					break;
				}
					  //�˳�
				case 4: {
					WriteLog("΢���˳�");
					Exit = true;
					break;
				}
				default: {
					Warning("�Ƿ��������㼴����������", "red");
					cout << "                 ";
					system("pause");
					break;
				}
				}
				if (Exit) {
					Exit = false;
					break;
				}
			} while (1);
			Exit = false;
			break;
		}
		//����
		case 4: {
			Transition_2(41, 14, 13);
			CMD();
			break;
		}
		default: {
			Warning("�Ƿ��������㼴����������", "red");
			cout << "                 ";
			system("pause");
		}
			   break;
		}
		if (Exit) {
			Exit = false;
			break;
		}
	} while (1);
}