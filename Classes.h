#include<iostream>
#include<windows.h>
#include <string>

class Doctor
{
private:
	string Doctor_ID, Name, Specialty;
public:
	Doctor() : Doctor_ID("000"), Name("000"), Specialty("000")
	{}
	Doctor(string i, string n, string s)
	{
		Doctor_ID = i, Name = n, Specialty = s;
	}
	void set_DrID(string i) { Doctor_ID = i; }
	void set_DrName(string n) { Name = n; }
	void set_DrS(string s) { Specialty = s; }

	string get_DrID() { return Doctor_ID; }
	string get_DrN() { return Name; }
	string get_DrS() { return Specialty; }
	void display_info()
	{
		SetConsoleTextAttribute(h, 3);
		cout << "The Doctor's ID: ";
		SetConsoleTextAttribute(h, 1);
		cout << Doctor_ID << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "The Doctor's Name: ";
		SetConsoleTextAttribute(h, 1);
		cout << Name << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "The Doctor's Specialty: ";
		SetConsoleTextAttribute(h, 1);
		cout << Specialty << endl;
	}
};

class Patient
{
private:
	string Patient_ID, Name, Address, Phone, Type, Diagnose, disease[10];
public:
	Patient() : Patient_ID("000"), Name("000"), Address("000"), Phone("000"), Type("000"), Diagnose("000")
	{
		for (int i = 0; i < 10; i++)
		{
			disease[i] = "000";
		}
	}
	Patient(string i, string n, string a, string p, string t, string d)
	{
		Patient_ID = i, Name = n, Address = a, Phone = p, Type = t, Diagnose = d;
	}
	void set_PaID(string i) { Patient_ID = i; }
	void set_PaName(string n) { Name = n; }
	void set_PaAddress(string a) { Address = a; }
	void set_PaPhone(string p) { Phone = p; }
	void set_PaType(string t) { Type = t; }
	void set_PaDiagnose(string d) { Diagnose = d; }
	void set_PaDisease(string dis, int num) { disease[num] = dis; }

	string get_PaID() { return Patient_ID; }
	string get_PaName() { return Name; }
	string get_PaAddress() { return Address; }
	string get_PaPhone() { return Phone; }
	string get_PaType() { return Type; }
	string get_PaDiagnose() { return Diagnose; }
	string get_PaDisease(int num) { return disease[num]; }

	void display_info()
	{
		SetConsoleTextAttribute(h, 3);
		cout << "The Patient's ID: ";
		SetConsoleTextAttribute(h, 1);
		cout << Patient_ID << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "The Patient's Name: ";
		SetConsoleTextAttribute(h, 1);
		cout << Name << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "The Patient's Address: ";
		SetConsoleTextAttribute(h, 1);
		cout << Address << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "The Patient's Phone: ";
		SetConsoleTextAttribute(h, 1);
		cout << Phone << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "The Patient's Type: ";
		SetConsoleTextAttribute(h, 1);
		cout << Type << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "The Patient's diagnose: ";
		SetConsoleTextAttribute(h, 1);
		cout << Diagnose << endl;


		for (int i = 0; i < 10; i++)
		{
			if (disease[i] != "000")
			{
				SetConsoleTextAttribute(h, 3);
				cout << "The Patient's disease no." << i + 1 << " : ";
				SetConsoleTextAttribute(h, 1);
				cout << disease[i] << endl;
			}
		}
	}


};
class Emergency_Patient : public Patient
{
private:
	string gp_diagnose;
public:
	void set_GPdiagnose(string gpd)
	{
		gp_diagnose = gpd;
	}

	string get_GPdiagnose()
	{
		return gp_diagnose;
	}

	void display_info()
	{
		Patient::display_info();

		SetConsoleTextAttribute(h, 3);
		cout << "The Patient's GP diagnose: ";
		SetConsoleTextAttribute(h, 1);
		cout << gp_diagnose << endl;

	}

};
class Chronic_Patient : public Patient
{
private:
	string monthly_medication_inquires;
public:
	void set_monthMedicInquire(string mmi)
	{
		monthly_medication_inquires = mmi;
	}
	string get_monthMedicInquire()
	{
		return monthly_medication_inquires;
	}

	void display_info()
	{
		Patient::display_info();

		SetConsoleTextAttribute(h, 3);
		cout << "The Patient's Monthly Medication Inquires: ";
		SetConsoleTextAttribute(h, 1);
		cout << monthly_medication_inquires << endl;
	}
};
class Acute_Patient : public Patient
{
private:
	string principal_amount, interest_rate, loan_duration;
public:
	void set_PrinAmount(string pa)
	{
		principal_amount = pa;
	}
	void set_InterRate(string ir)
	{
		interest_rate = ir;
	}
	void set_LoanDuar(string ld)
	{
		loan_duration = ld;
	}

	string get_PrinAmount()
	{
		return principal_amount;
	}
	string get_InterRate()
	{
		return interest_rate;
	}
	string get_LoanDuar()
	{
		return loan_duration;
	}

	void display_info()
	{
		Patient::display_info();

		SetConsoleTextAttribute(h, 3);
		cout << "The Principal Amount: ";
		SetConsoleTextAttribute(h, 1);
		cout << principal_amount << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "The Patient's Interest Rate: ";
		SetConsoleTextAttribute(h, 1);
		cout << interest_rate << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "The Patient's Loan Duration in months: ";
		SetConsoleTextAttribute(h, 1);
		cout << loan_duration << endl;
	}
};