#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;
bool check;
void updatefile(string email, string newdata, int lineno)
{
	int i = 0;
	string line, edit, src;
	email.append(".txt");
    file.open(email.c_str());
	while (getline(file, line))
	{
		i++;
		if (i == lineno)
		{
			edit = line;
		}
	}
	file.close();
	ifstream file1(email + ".txt");
	ofstream write(email + "temp.txt");
	while (getline(file1, src))
	{
		if (src == edit)
		{
			write << newdata << endl;
		}
		else
		{
			write << src << endl;
		}
	}
	file1.close();
	write.close();
	cout << "Updated Successfully" << endl;
}
class person {
private:
	string fname;
	string lname;
	int age;
	string email;
	string cnic;
	string gender;
	int salary;
	string phone_no;
	string address;
public:
	person():fname(""),lname(""), age(0),email(""),cnic(""), gender(""), salary(0), phone_no(""), address("")
	{}
	void setfname()
	{
		cin >> fname;
	}
	void setlname()
	{
		cin >> lname;
	}
	void setage()
	{
		cin >> age;
	}
	void setgender()
	{
		getline(cin >> ws, gender);
	}
	void setsalary()
	{
		cin >> salary;
	}
	void setemail(string a)
	{
		email = a;
	}
	void setemail()
	{
		cin >> email;
	}
	void setcnic()
	{
		cin >> cnic;
	}
	void setphone()
	{
		cin >> phone_no;
	}
	void setaddress()
	{
		getline(cin >> ws, address);
	}
	string getfname()
	{
		return fname;
	}
	string getlname()
	{
		return lname;
	}
	int getage()
	{
		return age;
	}
	string getgender()
	{
		return gender;
	}
	string getcnic()
	{
		return cnic;
	}
	string getemail()
	{
		return email;
	}
	int getsalary()
	{
		return salary;
	}
	string getphone()
	{
		return phone_no;
	}
	string getaddress()
	{
		return address;
	}
};
class branch {
private:
	string branchcode;
	string city;
public:
	branch() :branchcode(""), city("") {}
	void setbranch()
	{
		cin >> branchcode;
	}
	string getbranch()
	{
		return branchcode;
	}
};
class customer:public person {
private:
	string Cus_id;
	string Card_no;
	int AccBal;
	string AccNo;
	string pass;
public:
	customer():Cus_id(""),Card_no(""),AccBal(0), AccNo(""), pass("")
	{}
	void setAccNo()
	{
		cin >> AccNo;
	}
	string getAccNo()
	{
		return AccNo;
	}
	int getbalance()
	{
		return AccBal;
	}
	void setpass()
	{
		cin >> pass;
	}
	string getpass()
	{
		return pass;
	}
	void checkbalance(string a)
	{
		int i = 0;
		string line;
		setemail(a);
		ifstream file(getemail() + ".txt");
		while (getline(file, line))
		{
			i++;
			if (i == 8)
			{
				cout <<"Balance: "<< line << endl;
			}
		}
		file.close();
	}
};
class cashier :public person {
private:
	customer c1;
	branch b1;
	string cid;
public:
	cashier():cid("")
	{}
	void setcid()
	{
		cin >> cid;
	}
	string getcid()
	{
		return cid;
	}
	void createAcc()
	{
		system("cls");
		cout << "Enter the following" << endl;
		cout << "First Name: "; c1.setfname();
		cout << "Last Name: "; c1.setlname();
		char again = ' ';
	re_enter_again:
		cout << "Email: "; c1.setemail();
		if (c1.getemail().find("@") != string::npos)
		{
			ifstream checkfile;
			checkfile.open(c1.getemail() + ".txt");
			if (checkfile)
			{
				cout << "An account with this eamil already exists" << endl;
				cout << "Do you want to enter another email(Y/N)"; cin >> again;
				if (again == 'y' || again == 'Y')
					goto re_enter_again;
			}
			else {
				do {
					cout << "Password: "; c1.setpass();
					if (c1.getpass().length() < 8)
					{
						cout << "Password should be atleast 8 characters!!!" << endl;
					}
				} while (c1.getpass().length() < 8);
				cout << "Enter Age: "; c1.setage();
				cout << "Gender: "; c1.setgender();
				cout << "Cnic: "; c1.setcnic();
				cout << "Phone No.: "; c1.setphone();
				cout << "Adress: "; c1.setaddress();
				cout << "Salary: "; c1.setsalary();
				cout << "Branch Code(6 Digit): "; b1.setbranch();
				cout << "Acc No.(9 Digit): "; c1.setAccNo();
				cout << "Confirm Create Account(Y/N): "; cin >> again;
				if (again == 'y' || again == 'Y')
				{
					system("cls");
					ofstream file(c1.getemail() + ".txt");
					file << c1.getfname() << endl << c1.getlname() << endl << c1.getemail()
						<< endl << c1.getpass() << endl << c1.getphone() << endl << c1.getage()
						<< endl << c1.getgender() << endl << c1.getbalance() << endl << c1.getcnic()
						<< endl << c1.getsalary() << endl << c1.getaddress() << endl
						<< b1.getbranch() << c1.getAccNo() << endl;
					file.close();
					cout << "Account Successfully Created!!" << endl;
				}
				checkfile.close();
				ofstream file("Accounts.txt", ios::app);
				{
					file << c1.getemail() << endl
						<< b1.getbranch() << c1.getAccNo() << endl;

				}
			}
		}
		else
		{
			cout << "Invalid Email!!!" << endl;
			goto re_enter_again;
		}
	}

	void update()
	{
		int select = 0;
		string newdata;
		char again;
	re_enter_select:
		cout << "Enter Customer Email: "; c1.setemail();
		ifstream filecheck;
		filecheck.open(c1.getemail() + ".txt");
		if (filecheck)
		{
		re_enter_again:
			check = true;
			cout << "Press 1 to Update Email Adress" << endl;
			cout << "Press 2 to Update Pasword" << endl;
			cout << "Press 3 to Update Phone No." << endl;
			cout << "Press 4 to Update Balance" << endl;
			cout << "Press 5 to Update Salary" << endl;
			cout << "Press 6 to Update Address" << endl;
			cout << "Press 7 to go to Main Menu" << endl;
			cout << "Select: "; cin >> select;
			switch (select)
			{
			case 1:
				cout << "Enter New Email: "; cin >> newdata;
				//u1.update(c1.getemail(), newdata, 3);
				break;
			case 2:
				cout << "Enter New Password: "; cin >> newdata;
				//u1.update(c1.getemail(), newdata, 4);
				break;
			case 3:
				cout << "Enter New Phone No.: "; cin >> newdata;
				//u1.update(c1.getemail(), newdata, 10);
				break;
			case 4:
				cout << "Enter New Balance: "; cin >> newdata;
				//u1.update(c1.getemail(), newdata, 8);
				break;
			case 5:
				cout << "Enter New Salary: "; cin >> newdata;
				//u1.update(c1.getemail(), newdata, 11);
				break;
			case 6:
				cout << "Enter New Address: "; cin >> newdata;
				//u1.update(c1.getemail(), newdata, 12);
			case 7:
				check = false;
			default:
				cout << "Wrong Input" << endl;
				system("cls");
				goto re_enter_select;
			}
			filecheck.close();
			if (select == 1)
			{/*
				remove((c1.getemail() + ".txt").c_str());
				remove((c1.getemail() + ".txt").c_str());
				rename((c1.getemail() + "temp.txt").c_str(), (newdata + ".txt").c_str());
				c1.setemail(newdata);
			}
				if (select < 7&&select!=1)
			{
				remove((c1.getemail() + ".txt").c_str());
				rename((c1.getemail() + "temp.txt").c_str(), (c1.getemail() + ".txt").c_str());
				check = true;
				*/
			}
			cout << "Do you want to Update Other Information(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
				goto re_enter_again;
			else
				check = false;
		}
		else
		{
			cout << "Wrong Email Id" << endl;
			cout << "Enter Again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
				goto re_enter_select;
			check = false;
		}
	}
};

class staff :public person {
private:
	string staffid;
public:
	staff():staffid("")
	{}
};
class manager :public person {
private:
	cashier c;
	staff s1;
	string id;
public:
	manager() :id("")
	{}
};
class transaction {
private:
	string id;
	string time;
	customer c1;
public:
	transaction():id(""),time("")
	{}
	void withdaw()
	{
		bool find = false;
		char again;
		int i = 0,j=0;
		string findacc, line, accno, email, emailno,bal;
		int old_amount=0;
	re_enter_old_amount:
		i = 0;
		cout << "Enter Account No: "; cin >> findacc;
		ifstream account("Accounts.txt");
		while (getline(account, accno))
		{
			i++;
			if (accno==findacc)
			{
				j = i;
				find = true;
			}
		}
		if(find==false)
		{
			cout << "Account Not Found" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				goto re_enter_old_amount;
			}
		}
		account.close();
		i = 0;
		ifstream account1("Accounts.txt");
		while (getline(account1, emailno))
		{
			i++;
			if (i==j-1)
			{
				email = emailno;
			}
		}
		account1.close();
		i = 0;
		c1.setemail(email);
		ifstream file(c1.getemail() + ".txt");
		while (getline(file, line))
		{
			i++;
			if (i == 8)
			{
				cout << "Current Balance: " << line << endl;
				old_amount = stoi(line);
			}
		}
		int amount = 0;
		re_enter_amount:
		cout << "Enter Amount: "; cin >> amount;
		if (amount <= old_amount)
		{
			cout << "Confirm Withdrawal(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				cout << "Withdrawal Successful" << endl;
				old_amount -=amount;
			}
			cout << "Updated Balance: " << old_amount<<endl;
			check = true;
			bal = to_string(old_amount);
			updatefile(c1.getemail(), bal, 8);
			cout << c1.getemail() << endl;
			remove((c1.getemail() + ".txt").c_str());
			rename((c1.getemail() + "temp.txt").c_str(), (c1.getemail() + ".txt").c_str());
		}
		else
		{
			cout << "Insufficient Balance" << endl;
			cout << "Do you want to enter balance again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
				goto re_enter_amount;
		}
	}
};
class UserAcc {
private:
	string type;
public:
	transaction t1;
	customer c1;
	branch b1;
	UserAcc():type("")
	{}
	void settype(string a)
	{
		type = a;
	}
	string gettype()
	{
		return type;
	}
	void login()
	{
		int i = 0;
		char again;
		re_enter_again:
		cout << "Enter Email: "; c1.setemail();
		ifstream checkfile;
		checkfile.open(c1.getemail() + ".txt");
		if (checkfile)
		{
			string line;
		    re_enter_line:
			cout << "Enter Password: "; c1.setpass();
			while (getline(checkfile, line))
			{
				i++;
				if (i == 4)
				{
					if (line == c1.getpass())
					{
						cout << "Logged in Successfully" << endl;
						check = true;
					}
					else {
						cout << "Wrong Password!!!" << endl;
						cout << "Enter Again(Y/N): "; cin >> again;
						if (again == 'y' || again == 'Y')
						{
							goto re_enter_line;
							system("cls");
						}
						else {
							check = false;
						}
					}
				}
			}
		}
		else
		{
			cout << "No Account with this email found" << endl;
			cout << "Enter email again(Y/N): "; cin >> again;
			system("cls");
			if (again == 'y' || again == 'Y') {
				goto re_enter_again;
			}
			else {
				check = false;
			}
		}
		checkfile.close();
	}
	void forgotpass()
	{
		int rem=0;
		string checkpasss;
		char again=' ';
		re_enter_again:
		cout << "Enter Your Email: "; c1.setemail();
		ifstream checkfile;
		checkfile.open(c1.getemail() + ".txt");
		if (checkfile)
		{
			string line;
			int i = 0;
		    re_enter_i:
			i = 0;
			cout << "Enter Your Cnic: "; c1.setcnic();
			while (getline(checkfile, line))
			{
				i++;
				if (i == 9)
				{
					if (line == c1.getcnic())
					{
						
						re_enter_line:
						do {
							cout << "Enter Acc No: "; c1.setAccNo();
							i = 0;
							while (getline(checkfile, line))
							{
								i++;
								if (i == 3)
								{
									if (line == c1.getAccNo())
									{
										string checkpass;
									re_enter_checkpass:
										do {
											cout << "Enter New Password: "; c1.setpass();
											if (c1.getpass().length() < 8)
											{
												cout << "Password should be atleast 8 characters!!!" << endl;
											}
										} while (c1.getpass().length() < 8);
										cout << "Confirm Password: "; cin >> checkpass;
										if (checkpass != c1.getpass())
										{
											cout << "Password Does Not Match: " << endl;
											cout << "Do you want to enter again(Y/N): "; cin >> again;
											if (again == 'y' || again == 'Y')
											{
												goto re_enter_checkpass;
											}
											else
												check = false;
										}
										else
										{ 
											int j = 0;
											string src;
											ifstream file1(c1.getemail() + ".txt");
											ofstream write(c1.getemail() + "temp.txt");
											while (getline(file1, src))
											{
												j++;
												if (j == 4)
												{
													write << checkpass << endl;
												}
												else
												{
													write << src << endl;
												}
											}
											file1.close();
											write.close();
											checkfile.close();
											remove((c1.getemail() + ".txt").c_str());
											rename((c1.getemail() + "temp.txt").c_str(), (c1.getemail() + ".txt").c_str());
											check = true;
											cout << "Password Successfully Changed" << endl;
											system("pause");
											system("cls");
										}
									}
									else
									{
										cout << "Invalid Acc No!!" << endl;
										cout << "Do you want to enter again(Y/N): "; cin >> again;
									}
								}
							}
						} while (again=='y'||again=='Y');
					}
					else
					{
						cout << "Invalid Cnic!!" << endl;
						cout << "Do you want to enter again(Y/N): "; cin >> again;
						if (again == 'y' || again == 'Y')
							goto re_enter_i;
						else
							check = false;
					}
				}
			}
		}
		else
		{
			cout << "Invalid Email!!" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
				goto re_enter_again;
			else
				check = false;
		}
	}
	
};
class CashierAcc {
private:
	customer c1;
	cashier c;
	transaction t1;
	branch b1;
	UserAcc u1;
public:
	void createAcc()
	{
		system("cls");
		cout << "Enter the following" << endl;
		cout << "First Name: "; c1.setfname();
		cout << "Last Name: "; c1.setlname();
		char again = ' ';
	    re_enter_again:
	 	cout << "Email: "; c1.setemail();
		if (c1.getemail().find("@") != string::npos)
		{
			ifstream checkfile;
			checkfile.open(c1.getemail() + ".txt");
			if (checkfile)
			{
				cout << "An account with this eamil already exists" << endl;
				cout << "Do you want to enter another email(Y/N)"; cin >> again;
				if (again == 'y' || again == 'Y')
					goto re_enter_again;
			}
			else {
				do {
					cout << "Password: "; c1.setpass();
					if (c1.getpass().length() < 8)
					{
						cout << "Password should be atleast 8 characters!!!"<<endl;
					}
				} while (c1.getpass().length() < 8);
				cout << "Enter Age: "; c1.setage();
				cout << "Gender: "; c1.setgender();
				cout << "Cnic: "; c1.setcnic();
				cout << "Phone No.: "; c1.setphone();
				cout << "Adress: "; c1.setaddress();
				cout << "Salary: "; c1.setsalary();
				cout << "Branch Code(6 Digit): "; b1.setbranch();
				cout << "Acc No.(9 Digit): "; c1.setAccNo();
				cout << "Confirm Create Account(Y/N): "; cin >> again;
				if (again == 'y' || again == 'Y')
				{
					system("cls");
					ofstream file(c1.getemail() + ".txt");
					file << c1.getfname() << endl << c1.getlname() << endl << c1.getemail()
						<< endl << c1.getpass() << endl << c1.getphone() << endl << c1.getage()
						<< endl << c1.getgender() << endl << c1.getbalance() << endl << c1.getcnic()
						<< endl << c1.getsalary() << endl << c1.getaddress() << endl
						<< b1.getbranch() << c1.getAccNo() << endl;
					file.close();
					cout << "Account Successfully Created!!" << endl;
				}
				checkfile.close();
				ofstream file("Accounts.txt",ios::app);
				{
					file << c1.getemail() << endl
						<< b1.getbranch()<<c1.getAccNo() << endl;
						  
				}
			}
		}
		else
		{
			cout << "Invalid Email!!!" << endl;
			goto re_enter_again;
		}
	}
	
};
class ManagerAcc {
	manager m1;
};
class StaffAcc {
	staff s1;
};
class CODAcc:public UserAcc {
};
class MarketAcc:public UserAcc {
};
class SavingAcc:public UserAcc {
};
class CurrentAcc:public UserAcc {

public:
	void createcurrent()
	{
		//createAcc();
		settype("Current Account");
		ofstream file(c1.getemail() + ".txt",ios::app);
		file << gettype();
		file.close();
	}
};
class ATM {
private:
	transaction t1;
	UserAcc u1;
public:
	void verify()
	{
		cout << "Enter Your Email: "; u1.c1.setemail();
		ifstream checkfile;
		checkfile.open(u1.c1.getemail());
		if (checkfile)
		{
			cout << "Enter Pin: ";
		}
	}
	void withdraw()
	{

	}
};
class bank {
private:
	UserAcc u1;
	CashierAcc c1;
	ManagerAcc M1;
	StaffAcc s1;
	ATM a1;
	string branch;
	string name;
	string location;
	string code;
public:
	bank():branch(""),name(""),location(""),code("")
	{}
	void mainpage()
	{
		int select;
	re_enter_select:
		cout << "Press 1 if you are Customer" << endl;
		cout << "Press 2 if you are Cashier" << endl;
		cout << "Press 3 if you are Manager" << endl;
		cout << "Press 4 if you are Staff" << endl;
		cout << "Press 5 to Exit Program" << endl;
		cout << "Select: "; cin >> select;
		system("cls");
		switch (select)
		{
		case 1:
			u1.login();
			if (check == false)
			{
				goto re_enter_select;
				system("cls");
			}
			if (check = true)
			{
				system("cls");
				cout << "Press 1 to See Balance" << endl;
				cout << "Press 2 to Transfer Money" << endl;
				cout << "Press 3 to See Account Detail" << endl;
				cout << "Press 4 to Use ATM" << endl;
			}
			break;
		}
	}

};
int main()
{
	string email = "minhaledits@gmail.com";
	customer c1;
	CashierAcc u1;
	transaction t1;
	//u1.createAcc();s
	//c1.checkbalance("sarim@gmail.com");
	t1.withdaw();
	//remove((email + ".txt").c_str());
	//rename((email + "temp.txt").c_str(), (email + ".txt").c_str());
	return 0;
}

