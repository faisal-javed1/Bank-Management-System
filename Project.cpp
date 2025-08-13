#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<ctime>
using namespace std;
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
	person() :fname(""), lname(""), age(0), email(""), cnic(""), gender(""), salary(0), phone_no(""), address("")
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
	void setbranchcode(string b)
	{
		branchcode=b;
	}
	string getbranchcode()
	{
		return branchcode;
	}
};
class customer:public person {
private:
	string Cus_id;
	string Card_no;
	bool loan;
	int loanAmount;
	int AccBal;
	string AccNo;
	string pass;
	string ATMpin;
public:
	branch b1;
	customer():Cus_id(""),Card_no(""),loan("NULL"),loanAmount(0),AccBal(0), AccNo(""), pass("")
	{}
	void setAccNo(string s)
	{
		AccNo = s;
	}
	void setAccNo()
	{
		cin >> AccBal;
	}
	string getAccNo()
	{
		return AccNo;
	}
	void setbalance(int b)
	{
		AccBal = b;
	}
	void setATMpin()
	{
		cin >> ATMpin;
	}
	void setloan(bool s)
	{
		s = loan;
	}
	bool getloan()
	{
		return loan;
	}
	void setloanamount()
	{
		cin >> loanAmount;
	}
	int getloanamount()
	{
		return loanAmount;
	}
	string getATMpin()
	{
		return ATMpin;
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
				cout << endl << endl << "Balance: " << line << endl;
			}
		}
		file.close();
	}

	string GenerateCusAcc()
	{
		string line,Acctemp,First,Second;
		int i = 0, j = 0 ;
		ifstream file("Accounts.txt");
		while (getline(file, line))
		{
			i++;
		}
		file.close();
		j = i;
		i = 0;
		ifstream file1("Accounts.txt");
		while (getline(file1, line))
		{
			i++;
			if (j == i)
			{
				Acctemp = line;
			}
		}
		file1.close();
		for (int i = 7; i < 15; i++)
		{
			Second += Acctemp[i];
		}
		int src = stoi(Second);
		src += 1;
		Second = to_string(src);
		setAccNo(Second);
		return getAccNo();
	}

	string findfile(string Acctemp)
	{
		string line,temp;
		int i = 0,j=0;
		ifstream file( "Accounts.txt");
		while (getline(file, line))
		{
			i++;
			if (line==Acctemp)
			{
				j = i;
			}
		}
		file.close();
		i = 0;
		if (j == 0)
		{
			temp = "Error";
		}
		else
		{
			ifstream file1("Accounts.txt");
			while (getline(file1, line))
			{
				i++;
				if (i == j - 1)
				{
					temp = line;
				}
			}
			file1.close();
		}
		return temp;
	}
	string findfile(string emailid, int lineno)
	{
		int i = 0;
		string line,id;
		ifstream file(emailid + ".txt");
		while (getline(file, line))
		{
			i++;
			if (i == lineno)
			{
				id=line;
			}
		}
		file.close();
		return id;
	}
	void update(string email, string newdata, int lineno)
	{
		int i = 0,j=0;
		string line, edit, src;
		ifstream file(email + ".txt");
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
		remove((email + ".txt").c_str());
		rename((email + "temp.txt").c_str(), (email + ".txt").c_str());
	}
	void deleteuser()
	{
		string acctemp;
		int i = 0, j = 0;
		string line,line1,line2;
		char again;
	re_enter_again:
		i = 0;
		cout << "Enter Acc No: ";cin >> acctemp;
		ifstream file("Accounts.txt");
		while (getline(file, line))
		{
			i++;
			if (line == acctemp)
			{
				j = i;
			}
		}
		file.close();
		i = 0;
		if (j == 0)
		{
			cout << "Account Not Found!!!" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'Y' || again == 'y')
			{
				system("cls");
				goto re_enter_again;
			}
			else
				cout << "Delete Operation Failed!!!" << endl;
		}
		else
		{
			i = 0;
			ifstream get("Accounts.txt");
			while (getline(get, line1))
			{
				i++;
				if (i == j - 1)
				{
					line = line1;
				}
			}
			get.close();
			i = 0;
			ifstream read("Accounts.txt");
			ofstream write("Accountstemp.txt");
			while (getline(read, line2))
			{
				i++;
				if (i == j || i == (j - 1))
				{
				}
				else
				{
					write << line2 << endl;
				}
			}
			read.close();
			write.close();
			remove("Accounts.txt");
			remove((line + ".txt").c_str());
			rename("Accountstemp.txt", "Accounts.txt");
			cout << "Account Deleted Successfully" << endl;
		}
	}
	void DisplayCusFile(string emailtemp)
	{
		string line;
		int i = 0,j = 0;
		ifstream file(emailtemp+".txt");
		while (getline(file, line))
		{
			i++;
			if (i == 1)
			{
			cout << "Name: " << line << " ";
			}
			if (i == 2)
			{
			cout << line;
			}
			if (i == 3)
			{
			cout << endl << endl << "Email: " << line << endl;
			}
			if (i == 5)
			{
			cout << endl << "Phone No: " << line << endl;
			}
			if (i == 6)
			{
			cout << endl << "Age: " << line << endl;
			}
			if (i == 7)
			{
			cout << endl << "Gender: " << line << endl;
			}
			if (i == 8)
			{
			cout << endl << "Balance: " << line << endl;
			}
			if (i == 9)
			{
			cout << endl << "CNIC: " << line << endl;
			}
			if (i == 10)
			{
			cout << endl << "Salary: " << line << endl;
			}
			if (i == 11)
			{
			cout << endl << "Address: " << line << endl;
			}
			if (i == 12)
			{
			cout << endl << "Acc No: " << line << endl;
			}
			if (i == 13)
			{
			cout << endl << "Acc Type: " << line << endl;
			}
			if (i == 14)
			{
			cout << endl << "Loan Amount: " << line << endl;
			}
			if (i == 15)
			{
			cout << endl << "ATM Pin: " << line << endl;
			}
		}
						file.close();
	}

};

class cashier :public person {
private:
	string cid;
public:
	customer c1;
	branch b1;
	cashier():cid("")
	{}
	void setcid(string c)
	{
		cid = c;
	}
	string getcid()
	{
		return cid;
	}
	string findemp(string Acctemp)
	{
		string line, temp;
		int i = 0, j = 0;
		ifstream file("EmpAccounts.txt");
		while (getline(file, line))
		{
			i++;
			if (line == Acctemp)
			{
				j = i;
			}
		}
		file.close();
		i = 0;
		if (j == 0)
		{
			temp = "Error";
		}
		else
		{
			ifstream file1("EmpAccounts.txt");
			while (getline(file1, line))
			{
				i++;
				if (i == j - 1)
				{
					temp = line;
				}
			}
			file1.close();
		}
		return temp;
	}
	void DeleteCashier()
	{
		string acctemp;
		int i = 0, j = 0;
		string line, line1, line2;
		char again;
	re_enter_again:
		i = 0;
		cout << "Enter Acc No: "; cin >> acctemp;
		ifstream file("EmpAccounts.txt");
		while (getline(file, line))
		{
			i++;
			if (line == acctemp)
			{
				j = i;
			}
		}
		file.close();
		i = 0;
		if (j == 0)
		{
			cout << "Account Not Found!!!" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'Y' || again == 'y')
			{
				system("cls");
				goto re_enter_again;
			}
			else
				cout << "Delete Operation Failed!!!" << endl;
		}
		else
		{
			i = 0;
			ifstream get("EmpAccounts.txt");
			while (getline(get, line1))
			{
				i++;
				if (i == j - 1)
				{
					line = line1;
				}
			}
			get.close();
			i = 0;
			ifstream read("EmpAccounts.txt");
			ofstream write("EmpAccountstemp.txt");
			while (getline(read, line2))
			{
				i++;
				if (i == j || i == (j - 1))
				{
				}
				else
				{
					write << line2 << endl;
				}
			}
			read.close();
			write.close();
			remove("EmpAccounts.txt");
			remove((line + "Emp" + ".txt").c_str());
			rename("EmpAccountstemp.txt", "EmpAccounts.txt");
			cout << "Account Deleted Successfully" << endl;
		}
	}
	string GenerateEmpAcc()
	{
		string line, Acctemp, First, Second;
		int i = 0, j = 0;
		ifstream file("EmpAccounts.txt");
			while (getline(file, line))
			{
				i++;
			}
			file.close();
			j = i;
			i = 0;
			ifstream file1("EmpAccounts.txt");
			while (getline(file1, line))
			{
				i++;
				if (j == i)
				{
					Acctemp = line;
				}
			}
			file1.close();
			for (int i = 6; i < 10; i++)
			{
				Second += Acctemp[i];
			}
			int src = stoi(Second);
			src += 1;
			Second = to_string(src);
			setcid(Second);
		return getcid();
	}
};

class staff :public person {
private:
	string staffid;
public:
	staff():staffid("")
	{}
};
class transaction {
private:
	string id;
	string time;
public:
	customer c1;
	transaction():id(""),time("")
	{}
	void withdaw(string findacc)
	{
		bool find = false;
		char again;
		int i = 0,j=0;
		string  line, accno, email, emailno,bal;
		int old_amount=0;
	re_enter_old_amount:
		i = 0;
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
		account.close();
		if(find==false)
		{
			cout << "Account Not Found" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				system("cls");
				goto re_enter_old_amount;
			}
			else
			{
				cout << endl << "Transaction Unsuccessful" << endl;
			}
		}
		else
		{
			i = 0;
			ifstream account1("Accounts.txt");
			while (getline(account1, emailno))
			{
				i++;
				if (i == j - 1)
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
					cout<<endl << "Current Balance: " << line << endl;
					old_amount = stoi(line);
				}
			}
			file.close();
			int amount = 0;
		re_enter_amount:
			cout <<endl<< "Enter Amount: "; cin >> amount;
			if (amount <= old_amount)
			{
				cout << endl << "Confirm Withdrawal(Y/N): "; cin >> again;
				if (again == 'y' || again == 'Y')
				{
					old_amount -= amount;
					c1.setbalance(old_amount);
					cout <<endl<< "Withdrawal Successful" << endl;
					cout <<endl<< "Updated Balance: " << c1.getbalance() << endl;
					bal = to_string(c1.getbalance());
					c1.update(c1.getemail(), bal, 8);
					string src;
					ofstream write(c1.getemail() + ".txt", ios::app);
					write << amount << "rs has been withdrawed from your acc" << endl;
					write.close();
				}
				else
					cout << endl << "Transaction Unsuccessful" << endl;

			}
			else
			{
				cout << "Insufficient Balance" << endl;
				cout << "Do you want to enter balance again(Y/N): "; cin >> again;
				if (again == 'y' || again == 'Y')
				{
					system("cls");
					cout << endl << "Current Balance: " << line << endl<<endl;
					goto re_enter_amount;
				}
				else
					cout << endl << "Transaction Unsuccessful" << endl;
			}
		}
	}
	void deposit(string findacc)
	{
		bool find = false;
		char again;
		int i = 0, j = 0;
		string line, accno, email, emailno, bal;
		int old_amount = 0;
	re_enter_old_amount:
		i = 0;
		ifstream account("Accounts.txt");
		while (getline(account, accno))
		{
			i++;
			if (accno == findacc)
			{
				j = i;
				find = true;
			}
		}
		account.close();
		i = 0;
		if (find == false)
		{
			cout << "Account Not Found" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				goto re_enter_old_amount;
			}
			else
				cout << endl << "Transaction Unsuccessful" << endl;
		}
		else
		{
			i = 0;
			ifstream account1("Accounts.txt");
			while (getline(account1, emailno))
			{
				i++;
				if (i == j - 1)
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
				if (i == 1)
				{
					cout << "Account Holder Name: " << line<<endl;
				}
				if (i == 8)
				{
					cout << "Current Balance: " << line << endl;
					old_amount = stoi(line);
				}
			}
			file.close();
			int amount = 0;
			cout << "Enter Amount: "; cin >> amount;
			cout << "Confirm Deposit(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				cout << "Deposit Successful" << endl;
				old_amount += amount;
				c1.setbalance(old_amount);
				cout << "Updated Balance: " << c1.getbalance() << endl;
				bal = to_string(c1.getbalance());
				c1.update(c1.getemail(), bal, 8);
				ofstream write(c1.getemail() + ".txt", ios::app);
				write << amount << "rs has been Deposited to your acc" << endl;
				write.close();
			}
			else
				cout << endl << "Transaction Unsuccessful!!!" << endl;
		}
	}


	void transfer(string sen_email)
	{
		int i = 0, j = 0,k=0, rec_balance = 0, sen_balance = 0;
		char again;
		string rec, rec_email, line, line1, emailno, name,sen_Acc;
		bool find=false;
		string rec_bal, sen_bal;
	re_enter_find:


		cout << endl << "Enter Recipient Acc No: "; cin >> rec;
		cout << endl;
		ifstream sender1("Accounts.txt");
		while (getline(sender1, line))
		{
			i++;
			if (sen_email == line)
			{
				k = i;
			}
		}
		sender1.close();
		i = 0;
		ifstream receiver("Accounts.txt");
		while (getline(receiver, line))
		{
			i++;
			if (rec == line)
			{
				j = i;
				find = true;
			}
		}
		receiver.close();
		if (find == false)
		{
			cout << "Account Not Found" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				system("cls");
				goto re_enter_find;
			}
			else
			{
				cout <<endl<< "Transaction Unseccessful" << endl;
				system("pause");
			}
		}
		else
		{
			i = 0;
			ifstream account("Accounts.txt");
			while (getline(account, emailno))
			{
				i++;
				if (i == k + 1)
				{
					sen_Acc = emailno;
				}
				if (i == j - 1)
				{
					rec_email = emailno;
				}
			}
			account.close();
			c1.setemail(sen_email);
			i = 0;
			string line3;
			ifstream sender(c1.getemail() + ".txt");
			while (getline(sender, line3))
			{
				i++;
				if (i == 8)
				{
					cout << "Your Current Balance: " << line3 << endl << endl;
					sen_balance = stoi(line3);
					c1.setbalance(sen_balance);
				}
			}
			sender.close();
			i = 0;
			ifstream file(rec_email + ".txt");
			while (getline(file, line1))
			{
				i++;
				if (i == 1 || i == 2)
				{
					name += " " + line1;
				}
				if (i == 8)
				{
					rec_balance = stoi(line1);
				}
			}
			file.close();
			string bal;
			int amount = 0;
		re_enter_amount:
			cout << "Enter Amount: "; cin >> amount;
			if (sen_balance < amount)
			{
				cout << endl << "Insufficient Balance!!!" << endl;
				cout << "Do you want to enter again(Y/N): "; cin >> again;
				if (again == 'y' || again == 'Y')
				{
					system("cls");
					cout << "Enter Recipient Acc No: " << rec << endl << endl;
					cout << "Your Current Balance: " << c1.getbalance() << endl << endl;
					goto re_enter_amount;
				}
				else
				{
					cout << "Transaction Unsuccessful!!!" << endl;
					system("pause");
				}

			}
			else
			{
				cout << endl;
				cout << "Recipient Name: " << name << endl;
				cout << "Recipient Acc No: " << rec << endl;
				cout << endl;
				cout << "Confirm Deposit(Y/N): "; cin >> again;
				if (again == 'y' || again == 'Y')
				{

					sen_balance -= amount;
					rec_balance += amount;
					c1.setbalance(sen_balance);
					sen_bal = to_string(c1.getbalance());
					rec_bal = to_string(rec_balance);
					c1.update(rec_email, rec_bal, 8);
					c1.update(c1.getemail(), sen_bal, 8);
					ofstream write(c1.getemail() + ".txt", ios::app);
					write << amount << "rs has been tranferred to Acc No " << rec << endl;
					write.close();
					ofstream write1(rec_email + ".txt", ios::app);
					write1 << amount << "rs were debited to Acc from Acc No " << sen_Acc << endl;
					write1.close();
					cout << "Transaction Successful!!!" << endl;
					system("pause");
				}
				else
				{
					cout << endl << "Transaction Unsuccessful!!!" << endl;
					system("pause");
				}
			}
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
	UserAcc() :type("")
	{}
	void settype(string a)
	{
		type = a;
	}
	string gettype()
	{
		return type;
	}

	void LoginCusAcc()
	{
		int i = 0, select = 0, usermenu = 0;
		char again = ' ';
	re_enter_again:
		cout << endl << endl;
		cout << "Enter Email: "; c1.setemail();
		cout << endl;
		string line;
		ifstream checkfile;

		checkfile.open(c1.getemail() + ".txt");
		if (checkfile)
		{
			i = 0;
			cout << "Enter Password: "; c1.setpass();
			while (getline(checkfile, line))
			{
				i++;
				if (i == 4)
				{
					if (line == c1.getpass())
					{
						checkfile.close();
						cout << endl << "Logged In Successfully" << endl;
						system("pause");
					re_enter_usermenu:
						system("cls");
						cout << "\t\t\t\t\t\tSelect From Following" << endl << endl;
						cout << "1. Check Balance" << endl;
						cout << "2. Transfer Money" << endl;
						cout << "3. ATM Locator" << endl;
						cout << "4. Display Bank Statement" << endl;
						cout << "5. Setting" << endl;
						cout << "6. Log Out" << endl;
						cout << endl << "Select: "; cin >> select;
						system("cls");
						switch (select)
						{
						case 1:
							c1.checkbalance(c1.getemail());
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 2:
							t1.transfer(c1.getemail());
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 3:
							cout << "\t\t\t\t\t\tATM LOCATIONS" << endl << endl;
							cout << "Branch 1 : Awan Town,Lahore" << endl;
							cout << "Branch 2 : Bahria Town,Lahore" << endl;
							cout << "Branch 3 : Johar Town,Lahore" << endl;
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 4:
							bankstatemnt(c1.getemail());
							cout << endl << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 5:
							setting(c1.getemail());
							goto re_enter_usermenu;
							break;
						case 6:
							system("cls");
							cout << "Logged Out Successfully" << endl << endl;
							break;
						default:
							system("cls");
							cout << "Invalid Input!!!" << endl;
							goto re_enter_usermenu;
							break;
						}
					}
					else
					{
						cout << "Wrong Password!!!" << endl;
						cout << "Enter Again(Y/N): "; cin >> again;
						if (again == 'y' || again == 'Y')
						{
							system("cls");
							cout << "Incorrect Password" << endl;
							goto re_enter_again;

						}
						else
						{
							cout << "Login Failed!!!" << endl;
							system("pause");
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
				cout << endl << "Login Failed!!!" << endl;
				system("pause");
			}
		}
		checkfile.close();
	}
	void bankstatemnt(string user_email)
	{
		string line;
		int i = 0;
		ifstream file(user_email + ".txt");
		cout << "\t\t\t\t\t\t" << "Bank Statement" << endl << endl;

		while (getline(file, line))
		{
			i++;
			if (i > 15)
			{
				cout << line << endl;
			}
		}
	}

	void forgotpass()
	{
		int rem = 0;
		string checkpasss,Acctemp;
		int i = 0;
		char again = ' ';
	re_enter_again:
		cout << "Enter Your Email: "; c1.setemail();
		cout << endl;
		ifstream checkfile;
		checkfile.open(c1.getemail() + ".txt");
		if (checkfile)
		{
			checkfile.close();
			string line;
		re_enter_i:
			i = 0;
			cout << "Enter Your Cnic: "; c1.setcnic();
			cout << endl;
			string line3;
			ifstream checkcnic(c1.getemail() + ".txt");
			while(getline(checkcnic, line3))
			{

				i++;
				if (i == 9)
				{

					checkcnic.close();
					if (line3 == c1.getcnic())
					{

						checkcnic.close();
						int accc = 0;
						string line1;
					re_enter_accc:
						cout << "Enter Acc No: "; cin >> Acctemp;
						cout << endl;
						i = 0;
						ifstream checkfile1(c1.getemail() + ".txt");
						while (getline(checkfile1, line1))
						{
							i++;
							string checkpass;
							if (i == 12)
							{
								if (line1 == Acctemp)
								{
								re_enter_checkpass:
									do {
										cout << "Enter New Password: "; c1.setpass();
										if (c1.getpass().length() < 8)
										{
											cout << "Password should be atleast 8 characters!!!" << endl;
										}
									} while (c1.getpass().length() < 8);
									cout << endl << "Confirm Password: "; cin >> checkpass;
									if (checkpass != c1.getpass())
									{
										cout << "Password Does Not Match: " << endl;
										cout << "Do you want to enter again(Y/N): "; cin >> again;
										system("cls");
										cout << "Enter Your Email: " << c1.getemail();
										cout << endl<<endl;
										cout << "Enter Your Cnic: " << c1.getcnic();
										cout << endl<<endl;
										cout << "Enter Acc No: " << Acctemp;
										cout << endl<<endl;
										goto re_enter_checkpass;
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
										checkfile1.close();
										remove((c1.getemail() + ".txt").c_str());
										rename((c1.getemail() + "temp.txt").c_str(), (c1.getemail() + ".txt").c_str());
										cout <<endl<<  "Password Successfully Changed" << endl<<endl;
									}
								}
								else
								{
									cout << "Invalid Acc No!!" << endl;
									cout << "Do you want to enter again(Y/N): "; cin >> again;
									if (again == 'y' || again == 'Y')
									{
										system("cls");
										cout << "Enter Your Email: " << c1.getemail();
										cout << endl << endl;
										cout << "Enter Your Cnic: " << c1.getcnic();
										cout << endl << endl;
										goto re_enter_accc;
									}
									else
										cout << endl << "Password Change Failed!!!" << endl;
								}
							}
						}
					}
					else
					{
						cout << "Invalid Cnic!!" << endl;
						cout << "Do you want to enter again(Y/N): "; cin >> again;
						if (again == 'y' || again == 'Y')
						{
							system("cls");
							cout << "Enter Your Email: " << c1.getemail();
							cout << endl << endl;
							goto re_enter_i;
						}
						else
							cout << endl << "Password Change Failed!!!" << endl;
					}
				}
			}
		}
		else
		{
			cout << "Invalid Email!!" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				system("cls");
				goto re_enter_again;
			}
			else
				cout << endl << "Password Change Failed!!!" << endl;
		}
	}

	void setting(string emailtemp)
	{
		string line;
		int select = 0,i=0;
		re_enter_select:
		cout << "\t\t\t\t\t\tSelect From Following" << endl << endl;
		cout << "1. Account Info" << endl;
		cout << "2. Bank Statement" << endl;
		cout << "3. Update Password" << endl;
		cout << "4. Change ATM Pin" << endl;
		cout << "5. Go Back" << endl;
		cout << endl << "Select: "; cin >> select;
		system("cls");
		cout << endl;
		switch (select)
		{
		case 1:
			c1.DisplayCusFile(emailtemp);
			cout << endl;
			system("pause");
			system("cls");
			goto re_enter_select;
			break;
		case 2:
			bankstatemnt(emailtemp);
			system("pause");
			system("cls");
			goto re_enter_select;
			break;
		case 3:
			if (select == 3)
			{
				string pass;
				do {
					cout << "Old Password: " << c1.findfile(emailtemp, 4) << endl << endl;
					cout << "Enter New Password: "; cin >> pass;
					if (pass.length() < 8)
					{
						cout << "Password shoud contain atleast 8 characters!!!" << endl;
					}

				} while (pass.length() < 8);
				c1.update(emailtemp, pass, 4);

			}
			system("pause");
			system("cls");
			goto re_enter_select;
			break;
		case 4:
			if (select == 4)
			{
				string pin;
				cout << "Old ATM Pin: " << c1.findfile(emailtemp, 15) << endl << endl;
				cout << "Enter New Pin"; cin >> pin;
				c1.update(emailtemp, pin, 15);
			}
			system("pause");
			system("cls");
			goto re_enter_select;
			break;
		case 5:
			system("cls");
			break;
		default:
			system("cls");
			cout << "Invalid Input!!!" << endl;
			goto re_enter_select;
			break;
		}
	}
	
};
class CashierAcc {
private:
	string pass;
public:
	customer c1;
	cashier c;
	transaction t1;
	UserAcc u1;
	branch b1,b2,b3;
	CashierAcc():pass(""){}
	void setpass()
	{
		cin >> pass;
	}
	string getpass()
	{
		return pass;
	}
	void CreateCusAcc()
	{
		int select=0;
		system("cls");
		cout << "\t\t\t\t\t\tEnter the following" << endl;
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
				else
					cout << endl <<"Account Creation Failed!!!" << endl;
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
				b1.setbranchcode("028401"); b2.setbranchcode("028505"); b3.setbranchcode("028204");

				do {
					cout << "Branches: " << "\t1. " << b1.getbranchcode() << "\t2. " << b2.getbranchcode() << "\t3. " << b3.getbranchcode() << endl;
					cout << "Select Branch Code: "; cin >> select;
					if (select == 1)
					{
						c1.b1.setbranchcode(b1.getbranchcode());
					}
					else if (select == 2)
					{
						c1.b1.setbranchcode(b2.getbranchcode());
					}
					else if (select == 3)
					{
						c1.b1.setbranchcode(b3.getbranchcode());
					}
					else
						cout << "Invalid Input!!!" << endl;
				} while (select < 1 || select > 3);
				cout << "Acc No: " << c1.b1.getbranchcode() << c1.GenerateCusAcc() << endl;

				do {
					cout << "Acc Type: " << "\t1. " << "Current" << "\t2. " << "Saving" << "\t3. " << "MoneyMarket" << "\t4. COD"<<endl;
					cout << "Select Acc Type: "; cin >> select;
					if (select == 1)
						u1.settype("Current");
					else if (select == 2)
						u1.settype("Saving");
					else if (select == 3)
						u1.settype("MoneyMarket");
					else if(select==4)
						u1.settype("COD");
					else
						cout << "Invalid Input!!!" << endl;
				} while (select < 1 || select > 4);
				do {
					cout << "Set ATM Pin(4 Digits): "; c1.setATMpin();
					if (c1.getATMpin().length() != 4)
						cout << "ATM Pin should contain 4 Digits!!!" << endl;
				} while (c1.getATMpin().length() != 4);
				cout << "Confirm Create Account(Y/N): "; cin >> again;

				if (again == 'y' || again == 'Y')
				{
					

					system("cls");
					ofstream file(c1.getemail() + ".txt");
					file << c1.getfname() << endl << c1.getlname() << endl << c1.getemail()
						<< endl << c1.getpass() << endl << c1.getphone() << endl << c1.getage()
						<< endl << c1.getgender() << endl << c1.getbalance() << endl << c1.getcnic()
						<< endl << c1.getsalary() << endl << c1.getaddress() << endl
						<< c1.b1.getbranchcode() << c1.getAccNo() << endl
						<< u1.gettype() << endl << "NULL" << endl<<c1.getATMpin()<<endl;
					file.close();
					cout <<endl<< "Account Successfully Created!!" << endl;
				}
				checkfile.close();
				ofstream file("Accounts.txt",ios::app);
				{
					file << c1.getemail() << endl
						<< c1.b1.getbranchcode()<<c1.getAccNo() << endl;
						  
				}
				file.close();
			}
		}
		else
		{
			cout << "Invalid Email!!!" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
				goto re_enter_again;
			else
				cout << endl << "Account Creation Failed!!!" << endl;
		}
	}
	void forgotpass()
	{
		int rem = 0;
		string checkpasss, Acctemp;
		int i = 0;
		char again = ' ';
	re_enter_again:
		cout << "Enter Your Email: "; c.setemail();
		cout << endl;
		ifstream checkfile;
		checkfile.open(c.getemail()+ "Emp" + ".txt");
		if (checkfile)
		{
			checkfile.close();
			string line;
		re_enter_i:
			i = 0;
			cout << "Enter Your Cnic: "; c.setcnic();
			cout << endl;
			string line3;
			ifstream checkcnic(c.getemail()+"Emp" + ".txt");
			while (getline(checkcnic, line3))
			{

				i++;
				if (i == 8)
				{
					checkcnic.close();
					if (line3 == c.getcnic())
					{
						int accc = 0;
						string line1;
					re_enter_accc:
						cout << "Enter Acc No: "; cin >> Acctemp;
						cout << endl;
						i = 0;
						ifstream checkfile1(c.getemail()+"Emp" + ".txt");
						while (getline(checkfile1, line1))
						{
							i++;
							string checkpass;
							if (i == 11)
							{
								checkfile1.close();
								if (line1 == Acctemp)
								{
								re_enter_checkpass:
									do {
										cout << "Enter New Password: "; setpass();
										if (getpass().length() < 8)
										{
											cout << "Password should be atleast 8 characters!!!" << endl;
										}
									} while (getpass().length() < 8);
									cout << endl << "Confirm Password: "; cin >> checkpass;
									if (checkpass != getpass())
									{
										cout << "Password Does Not Match: " << endl;
										cout << "Do you want to enter again(Y/N): "; cin >> again;
										system("cls");
										cout << "Enter Your Email: " << c.getemail();
										cout << endl << endl;
										cout << "Enter Your Cnic: " << c.getcnic();
										cout << endl << endl;
										cout << "Enter Acc No: " << Acctemp;
										cout << endl << endl;
										goto re_enter_checkpass;
									}
									else
									{
										int j = 0;
										string src;
										ifstream file1(c.getemail() +"Emp" +".txt");
										ofstream write(c.getemail() +"Emp"+ "temp.txt");
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
										checkcnic.close();
										checkfile1.close();
										remove((c.getemail() +"Emp" +".txt").c_str());
										rename((c.getemail() +"Emp"+ "temp.txt").c_str(), (c.getemail()+"Emp" + ".txt").c_str());
										cout << endl << "Password Successfully Changed" << endl << endl;
									}
								}
								else
								{
									cout << "Invalid Acc No!!" << endl;
									cout << "Do you want to enter again(Y/N): "; cin >> again;
									if (again == 'y' || again == 'Y')
									{
										system("cls");
										cout << "Enter Your Email: " << c.getemail();
										cout << endl << endl;
										cout << "Enter Your Cnic: " << c.getcnic();
										cout << endl << endl;
										goto re_enter_accc;
									}
									else
										cout << endl << "Password Change Failed!!!" << endl;
								}
							}
						}
					}
					else
					{
						cout << "Invalid Cnic!!" << endl;
						cout << "Do you want to enter again(Y/N): "; cin >> again;
						if (again == 'y' || again == 'Y')
						{
							system("cls");
							cout << "Enter Your Email: " << c.getemail();
							cout << endl << endl;
							goto re_enter_i;
						}
						else
							cout << endl << "Password Change Failed!!!" << endl;
					}
				}
			}
		}
		else
		{
			cout << "Invalid Email!!" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				system("cls");
				goto re_enter_again;
			}
			else
				cout << endl << "Password Change Failed!!!" << endl;
		}
	}
	void LoginEmpAcc()
	{
		int i = 0, select = 0, usermenu = 0;
		char again = ' ';
	re_enter_again:
		cout << endl << endl;
		cout << "Enter Email: "; c.setemail();
		cout << endl;
		string line;
		ifstream checkfile;

		checkfile.open(c.getemail() + "Emp" ".txt");
		if (checkfile)
		{
			i = 0;
			cout << "Enter Password: "; setpass();
			while (getline(checkfile, line))
			{
				i++;
				if (i == 4)
				{
					if (line == getpass())
					{
						checkfile.close();
						cout << endl << "Logged In Successfully" << endl;
						system("pause");
					re_enter_usermenu:
						system("cls");
						string acctemp,line,emailtemp;
						int i = 0, j = 0;
						ifstream file("Accounts.txt");
						ifstream file1("Accounts.txt");
						cout << "\t\t\t\t\t\tSelect From Following" << endl << endl;
						cout << "1. Display Customer Info" << endl;
						cout << "2. Update Cusotmer Info" << endl;
						cout << "3. Perform Transaction" << endl;
						cout << "4. Customer Accounts List" << endl;
						cout << "5. Delete Customer Account" << endl;
						cout << "6. Add New Customer" << endl;
						cout << "7. View Your Profile" << endl;
						cout << "8. Log Out" << endl;
						cout << endl << "Select: "; cin >> select;
						system("cls");
						cout << endl;
						switch (select)
						{
						case 1:
							cout << "Acc No: "; cin >> acctemp;
							while (getline(file, line))
							{
								i++;
								if (line.find(acctemp) != string::npos)
								{
									j = i;
								}
							}
							file.close();
							i = 0;
							if (j == 0)
							{
								cout << "Acc Not Found!!!" << endl;
							}
							else
							{
								while (getline(file1, line))
								{
									i++;
									if (i == j - 1)
									{
										emailtemp = line;
									}
								}
								file1.close();
								c1.DisplayCusFile(emailtemp);
							}
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 2:
							file.close();
							file1.close();
							UpdateCusinfo();
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 3:
							file.close();
							file1.close();
							cout << "\t\t\t\t\t\tSelect From Following" << endl<<endl;
							cout << "1 .Transfer Money" << endl;
							cout << "2. Deposit Money" << endl;
							cout << "3. Withdraw Money" << endl;
							cout << endl << "Select: "; cin >> select;
							system("cls");
							cout << endl;
							cout << "Enter Acc No: "; cin >> acctemp;
							if (c1.findfile(acctemp) == "Error")
							{
								cout << "Account Not Found!!!" << endl;
							}
							else
							{
								emailtemp = c1.findfile(acctemp);
								switch (select)
								{
								case 1:
									u1.t1.transfer(emailtemp);
									break;
								case 2:
									u1.t1.deposit(acctemp);
									break;
								case 3:
									u1.t1.withdaw(acctemp);
									break;
								default:
									cout << "Invalid Input!!!" << endl;
									goto re_enter_usermenu;
									break;
								}
							}
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 4:
							if (select == 4)
							{
								cout << "\t\t\t\t\t\tAccounts List" << endl;
								i = 0;
								j = 0;
								ifstream info("Accounts.txt");
								while (getline(info, line))
								{
									i++;
									if (i % 2 == 1)
									{
										cout << "Email: " << line << endl;
									}
									if (i % 2 == 0)
									{
										cout << "Acc No: " << line << endl;
										cout << endl;
									}
								}
								info.close();
							}
							file.close();
							file1.close();
							cout << endl;
							
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 5:
							file.close();
							file1.close();
							u1.c1.deleteuser();
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 6:
							CreateCusAcc();
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 7:
							file.close();
							file1.close();
							cout << "Name: " << c1.findfile(c.getemail()+"Emp", 1) << c1.findfile(c.getemail() + "Emp", 2) << endl << endl;
							cout << "Email: " << c1.findfile(c.getemail() + "Emp", 3) << endl<<endl;
							cout<<"Password: "<< c1.findfile(c.getemail() + "Emp", 4) << endl << endl;
							cout<<"Phone NO: "<< c1.findfile(c.getemail() + "Emp", 5) << endl << endl;
							cout<<"Age: "<< c1.findfile(c.getemail() + "Emp", 6) << endl << endl;
							cout<<"Gender: "<< c1.findfile(c.getemail() + "Emp", 7) << endl << endl;
							cout<<"CNIC: "<< c1.findfile(c.getemail() + "Emp", 8) << endl << endl;
							cout<<"Salary: "<< c1.findfile(c.getemail() + "Emp", 9) << endl << endl;
							cout<<"Address: "<< c1.findfile(c.getemail() + "Emp", 10) << endl << endl;
							cout<<"Cashier ID: "<< c1.findfile(c.getemail() + "Emp", 11) << endl << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 8:
							break;
						default:
							cout << "Invalid Input!!!" << endl;
							goto re_enter_usermenu;
							break;
						}
					}
					else
					{
						cout << "Wrong Password!!!" << endl;
						cout << "Enter Again(Y/N): "; cin >> again;
						if (again == 'y' || again == 'Y')
						{
							system("cls");
							cout << "Incorrect Password" << endl;
							goto re_enter_again;

						}
						else
						{
							cout << "Login Failed!!!" << endl;
							system("pause");
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
				cout << endl << "Login Failed!!!" << endl;
				system("pause");
			}
		}
		checkfile.close();
	}
	void UpdateCusinfo()
	{
		int select = 0, i = 0, j = 0;
		string findacc, accno;
		char again;
	re_enter_again:
		cout << "Enter Account No: "; cin >> findacc;
		i = 0;
		j = 0;
		ifstream account("Accounts.txt");
		while (getline(account, accno))
		{
			i++;
			if (accno == findacc)
			{
				j = i;
			}
		}
		account.close();
		if (j == 0)
		{
			cout << "Account Not Found!!!" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				system("cls");
				goto re_enter_again;
			}
			else
				cout << "Update Operation Failed!!!" << endl;
		}
		else
		{
			system("cls");
			i = 0;
			string emailno;
			ifstream account1("Accounts.txt");
			while (getline(account1, emailno))
			{
				i++;
				if (i == j - 1)
				{
					c1.setemail(emailno);
				}
			}
			account1.close();
			int src = 0;
			string newdata;
			re_enter_newdata:
			cout << "Name: " << c1.findfile(c1.getemail(), 1) << " " << c1.findfile(c1.getemail(), 2) << endl;
			cout << "1. Update Email Adress" << endl;
			cout << "2. Update Pasword" << endl;
			cout << "3. Update Phone No." << endl;
			cout << "4. Update Acc Type" << endl;
			cout << "5. Update Salary" << endl;
			cout << "6. Update Address" << endl;
			cout << "7. Update ATM Pin" << endl;
			cout << "8. Goto Main Menu" << endl;
			cout << endl;
			cout << "Select: "; cin >> select;
			system("cls");
			cout << endl;
			switch (select)
			{
			case 1:
				re_enter_select:
				cout << "Old Email Adress: " << c1.findfile(c1.getemail(), 3) << endl << endl;
				cout << "Enter New Email: "; cin >> newdata;
				if (newdata.find("@") != string::npos)
				{
					cout << "J=" << j;
					c1.update("Accounts", newdata, j - 1);
					c1.update(c1.getemail(), newdata, 3);
					rename((c1.getemail() + ".txt").c_str(), (newdata + ".txt").c_str());
					cout << endl << "Updated Successfully" << endl << endl;
					c1.setemail(newdata);
					system("pause");
					system("cls");
					goto re_enter_newdata;
				}
				else
				{
					system("cls");
					cout << "Invalid Email!!!" << endl<<endl;
					cout << "Old Email Adress: " << c1.findfile(c1.getemail(), 3) << endl << endl;
					goto re_enter_select;
				}
				break;
			case 2:
				do {
					cout << "Old Password: " << c1.findfile(c1.getemail(), 4) << endl<<endl;
					cout << "Enter New Password: "; cin >> newdata;
					if (newdata.length() < 8)
					{
						system("cls");
						cout << "Password should be atleast 8 characters" << endl;
					}
				} while (newdata.length() < 8);
				c1.update(c1.getemail(), newdata, 4);
				cout << endl << "Updated Successfully" << endl << endl;
				system("pause");
				system("cls");
				goto re_enter_newdata;
				break;
			case 3:
				cout << "Old Phone No: " << c1.findfile(c1.getemail(), 5) << endl << endl;
				cout << "Enter New Phone No.: "; cin >> newdata;
				c1.update(c1.getemail(), newdata, 5);
				cout << endl << "Updated Successfully" << endl << endl;
				system("pause");
				system("cls");
				goto re_enter_newdata;
				break;
			case 4:
				cout << "Old Account Type: " << c1.findfile(c1.getemail(), 13) << endl<<endl;
				do {
					cout << "Acc Type: " << "\t1. " << "Current" << "\t2. " << "Saving" << "\t3. " << "MoneyMarket" << "\t4. COD" << endl;
					cout << "Select Acc Type: "; cin >> src;
					if (src == 1)
						u1.settype("Current");
					else if (src == 2)
						u1.settype("Saving");
					else if (src == 3)
						u1.settype("MoneyMarket");
					else if (src == 4)
						u1.settype("COD");
					else
						cout << "Invalid Input!!!" << endl;
				} while (src < 1 || src > 4);
				c1.update(c1.getemail(), u1.gettype(), 13);
				cout << endl << "Updated Successfully" << endl << endl;
				system("pause");
				system("cls");
				goto re_enter_newdata;
				break;
			case 5:
				cout << "Old Salary: " << c1.findfile(c1.getemail(), 10) << endl;
				cout << "Enter New Salary: "; cin >> newdata;
				c1.update(c1.getemail(), newdata, 10);
				cout << endl << "Updated Successfully" << endl << endl;
				system("pause");
				system("cls");
				goto re_enter_newdata;
				break;
			case 6:
				cout << "Old Address: " << c1.findfile(c1.getemail(), 11) << endl;
				cout << "Enter New Address: "; cin >> newdata;
				c1.update(c1.getemail(), newdata, 11);
				cout << endl << "Updated Successfully" << endl<< endl;
				system("pause");
				system("cls");
				goto re_enter_newdata;
				break;
			case 7:
				cout << "Old ATM Pin: " << c1.findfile(c1.getemail(), 15) << endl;
				cout << "Enter ATM Pin: "; cin >> newdata;
				c1.update(c1.getemail(), newdata, 15);
				cout << endl << "Updated Successfully" << endl << endl;
				system("pause");
				system("cls");
				goto re_enter_newdata;
				break;
			case 8:
				break;
			default:
				cout << "Wrong Input" << endl;
				goto re_enter_newdata;
				break;
			}
		}
	}
	
};
class manager :public person {
private:
	string id;
public:
	CashierAcc c1;
	UserAcc u1;
	staff s1;
	manager() :id("")
	{}


};
class ManagerAcc {
public:
	string pass;
	manager m1;
	CashierAcc c1;
	UserAcc u1;
	branch b1, b2, b3;
	void CreateCashierAcc()
	{
		int select = 0;
		system("cls");
		cout << "\t\t\t\t\t\tEnter the following" << endl;
		cout << "First Name: "; c1.c.setfname();
		cout << "Last Name: "; c1.c.setlname();
		char again = ' ';
	re_enter_again:
		cout << "Email: "; c1.c.setemail();

		if (c1.c.getemail().find("@") != string::npos)
		{
			ifstream checkfile;

			checkfile.open(c1.c.getemail() +"Emp"+".txt");
			if (checkfile)
			{
				cout << "An account with this eamil already exists" << endl;
				cout << "Do you want to enter another email(Y/N)"; cin >> again;
				if (again == 'y' || again == 'Y')
					goto re_enter_again;
				else
					cout << endl << "Account Creation Failed!!!" << endl;
			}

			else {

				do {
					cout << "Password: "; c1.setpass();
					if (c1.getpass().length() < 8)
					{
						cout << "Password should be atleast 8 characters!!!" << endl;
					}
				} while (c1.getpass().length() < 8);

				cout << "Enter Age: "; c1.c.setage();
				cout << "Gender: "; c1.c.setgender();
				cout << "Cnic: "; c1.c.setcnic();
				cout << "Phone No.: "; c1.c.setphone();
				cout << "Adress: "; c1.c.setaddress();
				cout << "Salary: "; c1.c.setsalary();
				b1.setbranchcode("028401"); b2.setbranchcode("028505"); b3.setbranchcode("028204");

				do {
					cout << "Branches: " << "\t1. " << b1.getbranchcode() << "\t2. " << b2.getbranchcode() << "\t3. " << b3.getbranchcode() << endl;
					cout << "Select Branch Code: "; cin >> select;
					if (select == 1)
					{
						c1.b1.setbranchcode(b1.getbranchcode());
					}
					else if (select == 2)
					{
						c1.b1.setbranchcode(b2.getbranchcode());
					}
					else if (select == 3)
					{
						c1.b1.setbranchcode(b3.getbranchcode());
					}
					else
						cout << "Invalid Input!!!" << endl;
				} while (select < 1 || select > 3);
				cout << "Cashier ID: " << c1.b1.getbranchcode() << c1.c.GenerateEmpAcc() << endl;
				cout << "Confirm Create Account(Y/N): "; cin >> again;
				if (again == 'y' || again == 'Y')
				{
					system("cls");
					ofstream file(c1.c.getemail() + "Emp"+".txt");
					file << c1.c.getfname() << endl << c1.c.getlname() << endl << c1.c.getemail()
						<< endl << c1.getpass() << endl << c1.c.getphone() << endl << c1.c.getage()
						<< endl << c1.c.getgender() << endl << c1.c.getcnic()
						<< endl << c1.c.getsalary() << endl << c1.c.getaddress() << endl
						<< c1.b1.getbranchcode() << c1.c.GenerateEmpAcc() << endl;
					file.close();
					cout << endl << "Account Successfully Created!!" << endl;
				}
				checkfile.close();
				ofstream file("EmpAccounts.txt", ios::app);
				{
					file << c1.c.getemail() << endl
						<< c1.b1.getbranchcode() << c1.c.GenerateEmpAcc() << endl;

				}
				file.close();

			}
		}
		else
		{
			cout << "Invalid Email!!!" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
				goto re_enter_again;
			else
				cout << endl << "Account Creation Failed!!!" << endl;
		}
	}
	void forgotpass()
	{
		int rem = 0;
		string checkpasss, Acctemp;
		int i = 0;
		char again = ' ';
	re_enter_again:
		cout << "Enter Your Email: "; m1.setemail();
		cout << endl;
		ifstream checkfile;
		checkfile.open(m1.getemail() + "Man" + ".txt");
		if (checkfile)
		{
			checkfile.close();
			string line;
		re_enter_i:
			i = 0;
			cout << "Enter Your Cnic: "; m1.setcnic();
			cout << endl;
			string line3;
			ifstream checkcnic(m1.getemail() + "Man" + ".txt");
			while (getline(checkcnic, line3))
			{

				i++;
				if (i == 8)
				{
					checkcnic.close();
					if (line3 == m1.getcnic())
					{
						int accc = 0;
						string line1;
					re_enter_accc:
						cout << "Enter Acc No: "; cin >> Acctemp;
						cout << endl;
						i = 0;
						ifstream checkfile1(m1.getemail() + "Man" + ".txt");
						while (getline(checkfile1, line1))
						{
							i++;
							string checkpass;
							if (i == 11)
							{
								checkfile1.close();
								if (line1 == Acctemp)
								{
								re_enter_checkpass:
									do {
										cout << "Enter New Password: "; pass;
										if (pass.length() < 8)
										{
											cout << "Password should be atleast 8 characters!!!" << endl;
										}
									} while (pass.length() < 8);
									cout << endl << "Confirm Password: "; cin >> checkpass;
									if (checkpass != pass)
									{
										cout << "Password Does Not Match: " << endl;
										cout << "Do you want to enter again(Y/N): "; cin >> again;
										system("cls");
										cout << "Enter Your Email: " << m1.getemail();
										cout << endl << endl;
										cout << "Enter Your Cnic: " << m1.getcnic();
										cout << endl << endl;
										cout << "Enter Acc No: " << Acctemp;
										cout << endl << endl;
										goto re_enter_checkpass;
									}
									else
									{
										int j = 0;
										string src;
										ifstream file1(m1.getemail() + "Man" + ".txt");
										ofstream write(m1.getemail() + "Man" + "temp.txt");
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
										checkcnic.close();
										checkfile1.close();
										remove((m1.getemail() + "Man" + ".txt").c_str());
										rename((m1.getemail() + "Man" + "temp.txt").c_str(), (m1.getemail() + "Man" + ".txt").c_str());
										cout << endl << "Password Successfully Changed" << endl << endl;
									}
								}
								else
								{
									cout << "Invalid Acc No!!" << endl;
									cout << "Do you want to enter again(Y/N): "; cin >> again;
									if (again == 'y' || again == 'Y')
									{
										system("cls");
										cout << "Enter Your Email: " << m1.getemail();
										cout << endl << endl;
										cout << "Enter Your Cnic: " << m1.getcnic();
										cout << endl << endl;
										goto re_enter_accc;
									}
									else
										cout << endl << "Password Change Failed!!!" << endl;
								}
							}
						}
					}
					else
					{
						cout << "Invalid Cnic!!" << endl;
						cout << "Do you want to enter again(Y/N): "; cin >> again;
						if (again == 'y' || again == 'Y')
						{
							system("cls");
							cout << "Enter Your Email: " << m1.getemail();
							cout << endl << endl;
							goto re_enter_i;
						}
						else
							cout << endl << "Password Change Failed!!!" << endl;
					}
				}
			}
		}
		else
		{
			cout << "Invalid Email!!" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				system("cls");
				goto re_enter_again;
			}
			else
				cout << endl << "Password Change Failed!!!" << endl;
		}
	}
	void LoginManAcc()
	{
		int i = 0, select = 0, usermenu = 0;
		char again = ' ';
	re_enter_again:
		cout << endl << endl;
		cout << "Enter Email: "; m1.setemail();
		cout << endl;
		string line;
		ifstream checkfile;
		checkfile.open(m1.getemail() + "Man" ".txt");
		if (checkfile)
		{
			i = 0;
			cout << "Enter Password: ";cin >> pass;
			while (getline(checkfile, line))
			{
				i++;
				if (i == 4)
				{
					if (line == pass)
					{
						checkfile.close();
						cout << endl << "Logged In Successfully" << endl;
						system("pause");
					re_enter_usermenu:
						system("cls");
						string acctemp, line, emailtemp;
						int i = 0, j = 0;
						cout << "\t\t\t\t\t\tSelect From Following" << endl << endl;
						cout << "1. Add New Employee" << endl;
						cout << "2. Display Cashier Info" << endl;
						cout << "3. Update Cashier Info" << endl;
						cout << "4. Display Customer Info" << endl;
						cout << "5. Customer Accounts List" << endl;
						cout << "6. Employee Accounts List" << endl;
						cout << "7. Delete Cashier Account" << endl;
						cout << "8. Assign Staff Duty" << endl;
						cout << "9. Display Staff Duty List" << endl;
						cout << "10.View Your Profile" << endl;
						cout << "11.Log Out" << endl;
						cout << endl << "Select: "; cin >> select;
						system("cls");
						cout << endl;
						switch (select)
						{
						case 1:
							CreateCashierAcc();
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 2:
							cout << "Enter Acc No: "; cin >> acctemp;
							if (c1.c.findemp(acctemp) == "Error")
							{
								cout << endl;
								cout << "Account Not Found!!!" << endl;
							}
							else
							{
								cout << "Name: " << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 1) << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 2) << endl << endl;
								cout << "Email: " << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 3) << endl << endl;
								cout << "Password: " << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 4) << endl << endl;
								cout << "Phone NO: " << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 5) << endl << endl;
								cout << "Age: " << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 6) << endl << endl;
								cout << "Gender: " << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 7) << endl << endl;
								cout << "CNIC: " << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 8) << endl << endl;
								cout << "Salary: " << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 9) << endl << endl;
								cout << "Address: " << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 10) << endl << endl;
								cout << "Cashier ID: " << c1.c1.findfile(c1.c.findemp(acctemp) + "Emp", 11) << endl << endl;
							}
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 3:
							UpdateEmpinfo();
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 4:
							cout << "Enter Acc No: "; cin >> acctemp;
							if (c1.c.findemp(acctemp) == "Error")
							{
								cout << endl;
								cout << "Account Not Found!!!" << endl;
							}
							else
							{
								c1.c1.DisplayCusFile(c1.c.findemp(acctemp));
							}
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 5:
							if (select == 5)
							{
								string line;
								int i = 0;
								cout << "\t\t\t\t\t\tAccounts List" << endl;
								i = 0;
								j = 0;
								ifstream info("Accounts.txt");
								while (getline(info, line))
								{
									i++;
									if (i % 2 == 1)
									{
										cout << "Email: " << line << endl;
									}
									if (i % 2 == 0)
									{
										cout << "Acc No: " << line << endl;
										cout << endl;
									}
								}
								info.close();
							}
							cout << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 6:
							if (select == 6)
							{
								string line;
								int i = 0;
								cout << "\t\t\t\t\t\tAccounts List" << endl;
								i = 0;
								j = 0;
								ifstream info("EmpAccounts.txt");
								while (getline(info, line))
								{
									i++;
									if (i % 2 == 1)
									{
										cout << "Email: " << line << endl;
									}
									if (i % 2 == 0)
									{
										cout << "Acc No: " << line << endl;
										cout << endl;
									}
								}
								info.close();
							}
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 7:
							c1.c.DeleteCashier();
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 8:
							if (select == 8)
							{
								char again1;
								string staffname,staffduty;
								re_enter_again1:
								cout << "Enter Staff Name: "; cin >> staffname;
								cout << endl;
								cout << "Enter Staff Duty: "; cin >> staffduty;
								cout << endl;
								cout << "Duty Assigned Successfully" << endl;
								ofstream assign("StaffDuty.txt",ios::app);
								assign << staffname << endl << staffduty << endl;
								assign.close();
								cout << "Do you want to Assign Another Task(Y/N): "; cin >> again1;
								if (again == 'y' || again == 'Y')
									goto re_enter_again1;
							}
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 9:
							if (select == 9)
							{
								int i = 0;
								string line;
								ifstream file("StaffDuty.txt");
								while (getline(file, line))
								{
									i++;
									if (i % 2 == 1)
									{
										cout << "Name: " << line << endl;
									}
									if (i % 2 == 0)
									{
										cout << "Duty: " << line << endl;
										cout << endl;
									}
								}
								file.close();
								system("pause");
								system("cls");
								goto re_enter_usermenu;
							}
							break;
						case 10:
							cout << "Name: " << c1.c1.findfile(m1.getemail() + "Man", 1) << c1.c1.findfile(m1.getemail() + "Man", 2) << endl << endl;
							cout << "Email: " << c1.c1.findfile(m1.getemail() + "Man", 3) << endl << endl;
							cout << "Password: " << c1.c1.findfile(m1.getemail() + "Man", 4) << endl << endl;
							cout << "Phone NO: " << c1.c1.findfile(m1.getemail() + "Man", 5) << endl << endl;
							cout << "Age: " << c1.c1.findfile(m1.getemail() + "Man", 6) << endl << endl;
							cout << "Gender: " << c1.c1.findfile(m1.getemail() + "Man", 7) << endl << endl;
							cout << "CNIC: " << c1.c1.findfile(m1.getemail() + "Man", 8) << endl << endl;
							cout << "Salary: " << c1.c1.findfile(m1.getemail() + "Man", 9) << endl << endl;
							cout << "Address: " << c1.c1.findfile(m1.getemail() + "Man", 10) << endl << endl;
							cout << "Manager ID: " << c1.c1.findfile(m1.getemail() + "Man", 11) << endl << endl;
							system("pause");
							system("cls");
							goto re_enter_usermenu;
							break;
						case 11:
							break;
						default:
							cout << "Invalid Input!!!" << endl;
							goto re_enter_usermenu;
							break;
						}
					}
					else
					{
						cout << "Wrong Password!!!" << endl;
						cout << "Enter Again(Y/N): "; cin >> again;
						if (again == 'y' || again == 'Y')
						{
							system("cls");
							cout << "Incorrect Password" << endl;
							goto re_enter_again;

						}
						else
						{
							cout << "Login Failed!!!" << endl;
							system("pause");
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
				cout << endl << "Login Failed!!!" << endl;
				system("pause");
			}
		}
		checkfile.close();
	}

	void UpdateEmpinfo()
	{
		int select = 0, i = 0, j = 0;
		string findacc, accno;
		char again;
	re_enter_again:
		cout << "Enter Account No: "; cin >> findacc;
		i = 0;
		j = 0;
		ifstream account("EmpAccounts.txt");
		while (getline(account, accno))
		{
			i++;
			if (accno == findacc)
			{
				j = i;
			}
		}
		account.close();
		if (j == 0)
		{
			cout << "Account Not Found!!!" << endl;
			cout << "Do you want to enter again(Y/N): "; cin >> again;
			if (again == 'y' || again == 'Y')
			{
				system("cls");
				goto re_enter_again;
			}
			else
				cout << "Update Operation Failed!!!" << endl;
		}
		else
		{
			system("cls");
			i = 0;
			string emailno;
			ifstream account1("EmpAccounts.txt");
			while (getline(account1, emailno))
			{
				i++;
				if (i == j - 1)
				{
					c1.c1.setemail(emailno);
				}
			}
			account1.close();
			int src = 0;
			string newdata;
		re_enter_newdata:
			cout << "Name: " << c1.c1.findfile(c1.c1.getemail()+"Emp", 1) << " " << c1.c1.findfile(c1.c1.getemail()+"Emp", 2) << endl << endl;
			cout << "1. Update Email Adress" << endl;
			cout << "2. Update Pasword" << endl;
			cout << "3. Update Phone No." << endl;
			cout << "4. Update Salary" << endl;
			cout << "5. Update Address" << endl;
			cout << "6. Goto Main Menu" << endl;
			cout << endl;
			cout << "Select: "; cin >> select;
			system("cls");
			cout << endl;
			switch (select)
			{
			case 1:
			re_enter_select:
				cout << "Old Email Adress: " << c1.c1.findfile(c1.c1.getemail()+"Emp", 3) << endl << endl;
				cout << "Enter New Email: "; cin >> newdata;
				if (newdata.find("@") != string::npos)
				{
					c1.c1.update("EmpAccounts", newdata, j - 1);
					c1.c1.update(c1.c1.getemail()+"Emp", newdata, 3);
					rename((c1.c1.getemail()+"Emp" + ".txt").c_str(), (newdata+"Emp" + ".txt").c_str());
					cout << endl << "Updated Successfully" << endl << endl;
					c1.c1.setemail(newdata);
					system("pause");
					system("cls");
					goto re_enter_newdata;
				}
				else
				{
					system("cls");
					cout << "Invalid Email!!!" << endl << endl;
					cout << "Old Email Adress: " << c1.c1.findfile(c1.c1.getemail()+"Emp", 3) << endl << endl;
					goto re_enter_select;
				}
				break;
			case 2:
				do {
					cout << "Old Passwords: " << c1.c1.findfile(c1.c1.getemail()+"Emp", 4) << endl << endl;
					cout << "Enter New Password: "; cin >> newdata;
					if (newdata.length() < 8)
					{
						system("cls");
						cout << "Password should be atleast 8 characters" << endl;
					}
				} while (newdata.length() < 8);
				c1.c1.update(c1.c1.getemail()+"Emp", newdata, 4);
				cout << endl << "Updated Successfully" << endl << endl;
				system("pause");
				system("cls");
				goto re_enter_newdata;
				break;
			case 3:
				cout << "Old Phone No: " << c1.c1.findfile(c1.c1.getemail()+"Emp", 5) << endl << endl;
				cout << "Enter New Phone No.: "; cin >> newdata;
				c1.c1.update(c1.c1.getemail()+"Emp", newdata, 5);
				cout << endl << "Updated Successfully" << endl << endl;
				system("pause");
				system("cls");
				goto re_enter_newdata;
				break;
			case 4:
				cout << "Old Salary: " << c1.c1.findfile(c1.c1.getemail()+"Emp", 10) << endl;
				cout << "Enter New Salary: "; cin >> newdata;
				c1.c1.update(c1.c1.getemail()+"Emp", newdata, 10);
				cout << endl << "Updated Successfully" << endl << endl;
				system("pause");
				system("cls");
				goto re_enter_newdata;
				break;
			case 5:
				cout << "Old Address: " << c1.c1.findfile(c1.c1.getemail()+"Emp", 11) << endl;
				cout << "Enter New Address: "; cin >> newdata;
				c1.c1.update(c1.c1.getemail()+"Emp", newdata, 11);
				cout << endl << "Updated Successfully" << endl << endl;
				system("pause");
				system("cls");
				goto re_enter_newdata;
				break;
			case 6:
				break;
			default:
				cout << "Wrong Input" << endl;
				goto re_enter_newdata;
				break;
			}
		}
	}
};
class StaffAcc {
	staff s1;
};
class ATM {
private:
	transaction t1;
	UserAcc u1;
	customer c1;
public:
	void login()
	{
		bool check = false;
		string line,Acctemp,emailtemp;
		int i = 0,j=0;
		cout << "\t\t\t\t\t\t" << "Enter The Followings" << endl << endl;
		cout << "Enter Acc No: "; cin >> Acctemp;
		cout << endl;
		ifstream file("Accounts.txt");
		while (getline(file, line))
		{
			i++;
				if (line==Acctemp)
				{
					check = true;
					file.close();
					j = i;
					i = 0;
					ifstream file1("Accounts.txt");
					while (getline(file1, line))
					{
						i++;
						if (i == j - 1)
						{ 
							emailtemp = line;
							file1.close();
							i = 0;
							ifstream file2(line + ".txt");
							while (getline(file2, line))
							{
								i++;
								if (i == 15)
								{
									file2.close();
									i = 0;
									j = 0;
									string pin;
									re_enter_pin:
									cout << "Enter Pin: "; cin >> pin;
									if (line == pin)
									{

										cout<<endl << "Login Successful" << endl;
										system("pause");
										system("cls");
										int select = 0;
										char again = ' ';
										re_enter_again:
										cout << "\t\t\t\t\t\t" << "Select From Followings" << endl << endl;
										cout << "1. Check Balance" << endl;
										cout << "2. Withdrawal" << endl;
										cout << "3. Transfer Money" << endl;
										cout << "4. Change Pin" << endl;
										cout << "5. Logout" << endl;
										cout << endl;
										cout << "Select: "; cin >> select;
										system("cls");
										switch (select)
										{
										case 1:
											c1.checkbalance(emailtemp);
											cout << endl;
											system("pause");
											system("cls");
											goto re_enter_again;
											break;
										case 2:
											t1.withdaw(Acctemp);
											cout << endl;
											system("pause");
											system("cls");
											goto re_enter_again;
											break;
										case 3:
											t1.transfer(emailtemp);
											system("pause");
											system("cls");
											goto re_enter_again;
											break;
										case 4:
											cout << endl << "Enter New Pin: "; cin >> pin;
											c1.update(emailtemp, pin, 15);
											cout << endl << "Pin Successfully Changed!!!" << endl;
											system("pause");
											system("cls");
											goto re_enter_again;
											break;
										case 5:
											break;
										default:
											system("cls");
											cout << "Invalid Input" << endl;
											goto re_enter_again;
											break;
										}
									}
									else
									{
										j++;
										cout << "Invalid Pin" << endl;
										system("pause");
										system("cls");
										if (j == 4)
										{
											check = false;
										}
										else
										{
											cout << "\t\t\t\t\t\t" << "Enter The Followings" << endl << endl;
											cout << "Enter Acc No: " << Acctemp << endl;
											cout << endl;
											goto re_enter_pin;
										}
									}
								}
							}
						}
					}
				}
		}
		file.close();
		if (check == false)
		{
			cout <<endl<< "Account Not Found"<<endl<<endl;
			system("pause");

		}
	}
};
class bank {
private:
	string name;
	string location;

public:
	UserAcc u1;
	CashierAcc c1;
	ManagerAcc M1;
	StaffAcc s1;
	ATM a1;
	branch b1, b2, b3;
	bank() :name(""), location("")
	{}
	void setname(string n)
	{
		name = n;
	}
	string getname()
	{
		return name;
	}
	void setlocation(string l)
	{
		location = l;
	}
	string getlocation()
	{
		return location;
	}
};

int main()
{
	CashierAcc cc1;
	customer c1;
	UserAcc u1;
	ManagerAcc m1;
	ATM a1;
	string alpha;
	int select = 0, usermenu = 0, usermenu1 = 0;
	string src;
	re_enter_select:
	cout << "Select from Following" << endl << endl;
	cout << "1. Customer" << endl;
	cout << "2. Cashier" << endl;
	cout << "3. Manager" << endl;
	cout << "4. Exit" << endl;
	cout << endl << "Select: "; cin >> select;
	system("cls");

	switch (select)
	{
	case 1:
	re_enter_usermenu:
		cout << "Select From Following" << endl << endl;
		cout << "1. Login" << endl;
		cout << "2. Forgot Password" << endl;
		cout << "3. ATM" << endl;
		cout << "4. Exit" << endl;
		cout << endl << "Select: "; cin >> select;
		system("cls");

		switch (select)
		{
		case 1:
			u1.LoginCusAcc();
			system("pause");
			system("cls");
			goto re_enter_usermenu;
			break;
		case 2:
			u1.forgotpass();
			system("pause");
			system("cls");
			goto re_enter_usermenu;
			break;
		case 3:
			a1.login();
			cout << endl;
			system("cls");
			goto re_enter_usermenu;
			break;
		case 4:
			goto re_enter_select;
			break;
		default:
			cout << "Invalid Input!!!" << endl;
			goto re_enter_usermenu;
			break;
		}

		break;

	case 2:
		re_enter_src:
		cout << "Select From Following" << endl << endl;
		cout << "1. Login" << endl;
		cout << "2. Forgot Password" << endl;
		cout << "3. Main Menu" << endl;
		cout << endl << "Select: "; cin >> select;
		system("cls");

		switch (select)
		{
		case 1:
			cc1.LoginEmpAcc();
			goto re_enter_src;
			break;
		case 2:
			cc1.forgotpass();
			cout << endl;
			system("pause");
			system("cls");
			goto re_enter_src;
			break;
		case 3:
			system("cls");
			goto re_enter_select;
			break;
		default:
			system("cls");
			goto re_enter_src;
			break;
		}
		break;

	case 3:
		re_enter_alpha:
		cout << "Select From Following" << endl << endl;
		cout << "1. Login" << endl;
		cout << "2. Forgot Password" << endl;
		cout << "3. Main Menu" << endl;
		cout << endl << "Select: "; cin >> select;
		system("cls");

		switch (select)
		{
		case 1:
			m1.LoginManAcc();
			cout << endl;
			system("cls");
			goto re_enter_src;
			break;
		case 2:
			m1.forgotpass();
			system("pause");
			system("cls");
			goto re_enter_src;
			break;
		case 3:
			return 0;
			break;
		default:
			cout << "Invalid Input" << endl;
			goto re_enter_alpha;
			break;
		}
	case 4:
		return 0;
		break;
	default:
		cout << "Invalid Input" << endl;
		goto re_enter_select;
	}

return 0;
}