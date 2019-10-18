/*ƽ̨������岿��
/*������Ϣ
/*���ֲ���*/
#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"Time.h"
#include"Ways.h"
#include"Friends.h"

using namespace std;

class class_PlatformBody {
protected:
	string ID;
	string BindingID;//�󶨵�ID
	int PlatformID = -1;//ƽ̨ID
	string Password;//����
	string Name;//�ǳ�
	class_Time Birthday;//����
	class_Time RegistrationDate;//ע������
	string Birthplace;//������
public:
	class_Friends LocalFriendsList;//���غ����б�
	vector<class_Group> LocalGroupsList;//����Ⱥ�б�
	static int ConstID;
	class_PlatformBody(const string a) {
		if (a.compare("new") == 0) {
			ifstream file_;
			//ȷ��ĿǰID
			for (int i = 1;; i++) {
				file_.open(Num2Str(i), ios::in);
				if (!file_.is_open()) {
					ConstID = i;
					break;
				}
				file_.close();
			}
			PlatformID = ConstID;
			ID = Num2Str(ConstID + 100000);
			ConstID++;
		}
		else if (a.compare("login") == 0) {
			//��O��
		}
	}
	~class_PlatformBody() {
		SaveThis();
	}
	//�޸Ļ򷵻ذ󶨵�ID
	string ModifyID (const string a) {
		if (a.compare("$empty$") != 0)
			ID = a;
		return ID;
	}
	string ModifyName(const string a) {
		if (a.compare("$empty$") != 0)
			Name = a;
		return Name;
	}
	string ModifyBindingID(const int a) {
		if (a > 0)
			BindingID = Num2Str(a);
		return BindingID;
	}
	string ModiFyPassword(const string a) {
		if (a.compare("$empty$") != 0) {
			Password = a;
		}
		return Password;
	}
	//�޸Ļ򷵻�����
	int ModifyBirthday(const int year, const int mon, const int day) {
		Birthday.Modify_Year(year);
		Birthday.Modify_Mon(mon);
		Birthday.Modify_Day(day);
		return (int)Birthday.OutDate();
	}
	//�޸Ļ򷵻س�����
	string ModifyBirthplace(const string a) {
		if (a.compare("$empty$") != 0)
			Birthplace = a;
		return Birthplace;
	}
	//���浽�ļ�
	int SaveThis() {
		ofstream Save;
		Save.open(Num2Str(PlatformID), ios::trunc);
		if (Save.is_open()) {
			Save << "ID:" << ID << "\n";
			Save << "Password:" << Password << "\n";
			Save << "BindingID:" << BindingID << "\n";
			Save << "PlatformID:" << PlatformID << "\n";
			Save << "Name:" << Name << "\n";
			Save << "Birthplace:" << Birthplace << "\n";
			Save << "Birthday:" << Num2Str((int)Birthday.OutDate()) << "\n";
			Save << "RegistrationDate:" << Num2Str((int)RegistrationDate.OutDate()) << "\n";
			Save << "LocalFriendsList:" << "\n";
			vector<int> x = LocalFriendsList.ExportFriendsData();
			for (unsigned int i = 0; i < x.size(); i++) {
				Save << x[i] << "\n";
			}
			Save << "#" << "\n";
			Save << "LocalGroupsList:" << "\n";
			for (unsigned int i = 0; i < LocalGroupsList.size(); i++) {
				Save << LocalGroupsList[i].ReturnGroupID() << "\n";
			}
			Save.close();
			return 0;
		}
		else return -1;
	}
	//���ļ�����
	int ReadNew(const int ID_){
		ifstream Acc;
		string GetStr = "$empty$";
		string TempStr = "$empty$";
		Acc.open(Num2Str(ID_), ios::in);
		if (Acc.is_open()) {
			while (!Acc.eof()) {
				Acc >> GetStr;
				if (GetStr.compare(0, 3, "ID:", 0, 3) == 0) {
					TempStr = GetStr.substr(3, GetStr.size() - 3);
					ID = TempStr;
					continue;
				}
				if (GetStr.compare(0, 9, "Password:", 0, 9) == 0) {
					TempStr = GetStr.substr(9, GetStr.size() - 9);
					Password = TempStr;
					continue;
				}
				if (GetStr.compare(0, 10, "BindingID:", 0, 10) == 0) {
					TempStr = GetStr.substr(10, GetStr.size() - 10);
					BindingID = TempStr;
					continue;
				}
				if (GetStr.compare(0, 11, "PlatformID:", 0, 11) == 0) {
					TempStr = GetStr.substr(11, GetStr.size() - 11);
					PlatformID = Str2Num(TempStr);
					continue;
				}
				if (GetStr.compare(0, 5, "Name:", 0, 5) == 0) {
					TempStr = GetStr.substr(5, GetStr.size() - 5);
					Name = TempStr;
					continue;
				}
				if (GetStr.compare(0, 9, "Birthday:", 0, 9) == 0) {
					TempStr = GetStr.substr(9, GetStr.size() - 9);
					Birthday.InDate(Str2Num(TempStr));
					continue;
				}
				if (GetStr.compare(0, 17, "RegistrationDate:", 0, 17) == 0) {
					TempStr = GetStr.substr(17, GetStr.size() - 17);
					RegistrationDate.InDate(Str2Num(TempStr));
					continue;
				}
				if (GetStr.compare(0, 11, "Birthplace:", 0, 11) == 0) {
					TempStr = GetStr.substr(11, GetStr.size() - 11);
					Birthplace = TempStr;
					continue;
				}
				if (GetStr.compare(0, 17, "LocalFriendsList:", 0, 17) == 0) {
					Acc >> TempStr;
					while (TempStr.compare("#") != 0) {
						LocalFriendsList.PushInFriend(Str2Num(TempStr));
						Acc >> TempStr;
					}
					continue;
				}
				if (GetStr.compare(0, 16, "LocalGroupsList:", 0, 16) == 0) {
					while (!Acc.eof()) {
						Acc >> TempStr;
						if (Acc.eof()) {
							break;
						}
						switch (GetGroup(Str2Num(TempStr), ID_))
						{
						case 1: {
							class_QQGroup4Manager aa(-1);
							aa.ReadData(Str2Num(TempStr));
							LocalGroupsList.push_back(aa);
							break;
						}
						case 2: {
							class_QQGroup4Admin bb;
							bb.ReadData(Str2Num(TempStr));
							LocalGroupsList.push_back(bb);
							break;
						}
						case 3: {
							class_QQGroup4Member cc;
							cc.ReadData(Str2Num(TempStr));
							LocalGroupsList.push_back(cc);
							break;
						}
						default: {
						//	Warning("ȥ������־", "red");
							break; 
						}
						}
					}
					continue;
				}
			}
			Acc.close();
		}
		return 0;
	}
	string ReturnInfo(const string a) {
		if (a.compare("ID") == 0) {
			return ID;
		}
		else if (a.compare("PlatformID") == 0) {
			return Num2Str(PlatformID);
		}
		else if (a.compare("BindingID") == 0) {
			return BindingID;
		}
		else if (a.compare("name") == 0) {
			return Name;
		}
		return "$empty$";
	}
	vector<int> ReturnInfo() {
		return LocalFriendsList.ExportFriendsData();
	}
};

//��õ�����Ϣ��һ��������õ�������
//a-ƽ̨ID b-Ŀ��
string GetLoginInfo(const string a, const string b) {
	ifstream AccFile;
	string c;
	AccFile.open(a, ios::in);
	if (AccFile.is_open()) {
		do {
			AccFile >> c;
			if (c.compare(0, b.size(), b, 0, b.size()) == 0) {
				c = c.substr(b.size() + 1, c.size() - b.size());
				break;
			}
		} while (1);
		AccFile.close();
		return c;
	}
	return "$Wrong$";
}