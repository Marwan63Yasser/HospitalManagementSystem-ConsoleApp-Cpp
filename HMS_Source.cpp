#include<iostream>
#include<windows.h>
#include <string>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //For Coloring the Text

class Doctor
{
private:
	string Doctor_ID, Name, Specialty;
public:
	Doctor() : Doctor_ID("000"),Name("000"),Specialty("000")
    {}
	Doctor(string i, string n, string s )
	{
		Doctor_ID = i, Name = n, Specialty = s ;
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
		cout  << Name << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "The Doctor's Specialty: ";
		SetConsoleTextAttribute(h, 1);
		cout<< Specialty << endl;
	}
};
class Patient
{
private:
	string Patient_ID, Name, Address, Phone, Type, Diagnose , disease[10];
public:
	Patient(): Patient_ID("000"),Name("000"),Address("000"),Phone("000"),Type("000"),Diagnose("000")
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
		cout<< Phone << endl;

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

//////////////////////////////////////////////////////////////Hospital Capacity/////////////////////////////////////////////////////////////
Doctor doctors[50];
Patient patients[200];
Emergency_Patient Em_patients[30];
Chronic_Patient Ch_patients[20];
Acute_Patient Ac_patients[20];

//////////////////////////////////////////////////////////////Counters//////////////////////////////////////////////////////////////////////
int DrCount = 0;
int PaCount = 0;
int EmPaCount = 0;
int ChPaCount = 0;
int AcPaCount = 0;
string reply;
int Pa_ChPa_AcPa = 0;

void home_page()
{
	system("cls");
	SetConsoleTextAttribute(h, 5);//color
	cout << "\t\t\t\t\t (----Hospital Management System----)\n\n";
	SetConsoleTextAttribute(h, 3);
	cout << "\t\t\t\t\t\t(-----Home Page-----)\n\n";

	//////////////////////////////////////////////////line 1/////////////////////////////////////////////////
	SetConsoleTextAttribute(h, 4);
	cout << "\t1- Add a new doctor         ";
	SetConsoleTextAttribute(h, 64);
	cout << "------------------------------------------------";
	SetConsoleTextAttribute(h, 4);
	cout << "  2- Add a new patient\n";
	/////////////////////////////////////////////////line 2/////////////////////////////////////////////////
	SetConsoleTextAttribute(h, 5);
	cout << "\t3- Edit a doctor info       ";
	SetConsoleTextAttribute(h, 80);
	cout<< "------------------------------------------------";
	SetConsoleTextAttribute(h, 5);
	cout <<"  4- Edit a patient info\n";
	////////////////////////////////////////////////line 3//////////////////////////////////////////////////
	SetConsoleTextAttribute(h, 6);
	cout << "\t5- Deleting a doctor info   ";
	SetConsoleTextAttribute(h, 96);
	cout <<"------------------------------------------------";
	SetConsoleTextAttribute(h, 6);
	cout <<"  6- Deleting a Patient info\n";
	//////////////////////////////////////////////line 4/////////////////////////////////////////////////////
	SetConsoleTextAttribute(h, 8);
	cout << "\t7- Show the list of Doctors ";
	SetConsoleTextAttribute(h, 128);
	cout << "------------------------------------------------";
	SetConsoleTextAttribute(h, 8);
	cout << "  8- Show the list of Patients\n";
	/////////////////////////////////////////////line 5///////////////////////////////////////////////////////
	SetConsoleTextAttribute(h, 2);
	cout << "\t9- Add Emergency case       ";
	SetConsoleTextAttribute(h, 32);
	cout << "------------------------------------------------";
	SetConsoleTextAttribute(h, 2);
	cout << "  10- Show list of Emergency cases\n";
	/////////////////////////////////////////////line 6///////////////////////////////////////////////////////
	SetConsoleTextAttribute(h, 14);
	cout << "\t11- Add a Chronic patients  ";
	SetConsoleTextAttribute(h, 224);
	cout << "------------------------------------------------";
	SetConsoleTextAttribute(h, 14);
	cout << "  12- Add an Acute patients\n";

	SetConsoleTextAttribute(h,1);
	cout << "\nEnter your choice : ";
	SetConsoleTextAttribute(h, 7);
	cin >> reply;

}

void next_step()
{
	int no_su = 0, no_te = 0, no_sc = 0, no_ph = 0; //the number of the operations or tests or........
	string ns;
	SetConsoleTextAttribute(h, 11);
	cout << "\nThe next step.......\n";
re_step1:
	SetConsoleTextAttribute(h, 7);
	cout << "1-Carrying out a surgery --- 2-Medical test --- 3-Mediacl scan --- 4-Pharmacy --- 5-Nothing\n";
	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter your choice : ";
	SetConsoleTextAttribute(h, 6);
	cin >> ns;
	cin.ignore();
	if (ns == "1")
	{
	re_surgery:
		string surgery;
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the type of the surgery : ";
		SetConsoleTextAttribute(h, 6);
		getline(cin, surgery);
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nData has been sent to the operating room !!!\n";
		no_su++;
	}
	else if (ns == "2")
	{
	re_test:
		string Mtest;
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the name of the test : ";
		SetConsoleTextAttribute(h, 6);
		getline(cin, Mtest);
		SetConsoleTextAttribute(h,4);
		cout << "\n\nData has been sent to the tests lab !!!\n";
		no_te++;
	}
	else if (ns == "3")
	{
	re_scan:
		string Mscan;
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the name of the scan : ";
		SetConsoleTextAttribute(h, 6);
		getline(cin, Mscan);
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nData has been sent to the scans lab !!!\n";
		no_sc++;
	}
	else if (ns == "4")
	{
	re_remedy:
		string remedy;
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the name of the remedy : ";
		SetConsoleTextAttribute(h, 6);
		getline(cin, remedy);
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nData has been sent to the pharmacy !!!\n";
		no_ph++;
	}
	else if (ns == "5")
	{}
	else
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\nError\n\n";
		goto re_step1;
	}


	if (ns == "1" || ns == "2" || ns == "3" || ns == "4" )
	{
		string ns2;
		SetConsoleTextAttribute(h, 11);
		cout << "\nAnother thing ?.......\n";
		SetConsoleTextAttribute(h, 7);
		cout << "1-Carrying out a surgery --- 2-Medical test --- 3-Mediacl scan --- 4-Pharmacy --- 5-Nothing\n";
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter your choice : ";
		SetConsoleTextAttribute(h, 6);
		cin >> ns2;
		cin.ignore();
		if (ns2 == "1")
		{
			goto re_surgery;
		}
		else if (ns2 == "2")
		{
			goto re_test;
		}
		else if (ns2 == "3")
		{
			goto re_scan;
		}
		else if (ns2 == "4")
		{
			goto re_remedy;
		}
		else
		{
			SetConsoleTextAttribute(h, 8);
			cout << "\n";
			for (int i = 0; i < no_su; i++)
			{
				cout << "Surgery no." << i + 1 << " has been successfully !! \n";
			}
			for (int i = 0; i < no_te; i++)
			{
				cout << "Test no." << i + 1 << " has been successfully !! \n";
			}
			for (int i = 0; i < no_sc; i++)
			{
				cout << "Scan no." << i + 1 << " has been successfully !! \n";
			}
			for (int i = 0; i < no_ph; i++)
			{
				cout << "Medication no." << i + 1 << " has been dispensed successfully !! \n";
			}
		}
	}

} 
void spec_Dr()
{
	string sd , d;
re_Specialist:
	SetConsoleTextAttribute(h, 11);
	cout << "\nThe Specialist doctor: \n";
	SetConsoleTextAttribute(h, 7);
	cout << "1- Ophthalmologist --- 2- Internist --- 3- Neurologist --- 4-Orthopedist --- 5- Other\n";
	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter your choice : ";
	SetConsoleTextAttribute(h, 6);
	cin >> sd;
	cin.ignore();

	string initial_diagnose;
	int cin_error = 0;
	int testOfdoctor = 0;

	if (sd == "1")
	{
	re_oth:
		system("cls");

		for (int i = 0; i < DrCount; i++)
		{
			if (doctors[i].get_DrS() == "Ophthalmologist")
			{
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t\t   (----Ophthalmology Clinic----)\n";
				SetConsoleTextAttribute(h, 6);
				cout << "Dr." << doctors[i].get_DrN() << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";
				if (sd == "5")
				{
					cout << "The GP diagnose : ";
					SetConsoleTextAttribute(h, 5);
					cout << initial_diagnose << "\n";
					SetConsoleTextAttribute(h, 7);
					cout << "-------------------------------------------------------------------------------------------------------------------\n";
					cin_error++;
				}
				sd = "1";
				testOfdoctor++;
				break;
			}
		}

	}
	else if (sd == "2")
	{
	re_int:
		system("cls");
		for (int i = 0; i < DrCount; i++)
		{
			if (doctors[i].get_DrS() == "Internist")
			{
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t\t   (----Internology Clinic----)\n";
				SetConsoleTextAttribute(h, 6);
				cout << "Dr." << doctors[i].get_DrN() << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";
				if (sd == "5")
				{
					cout << "The GP diagnose : ";
					SetConsoleTextAttribute(h, 5);
					cout << initial_diagnose << "\n";
					SetConsoleTextAttribute(h, 7);
					cout << "-------------------------------------------------------------------------------------------------------------------\n";
					cin_error++;
				}
				sd = "2";
				testOfdoctor++;
				break;
			}
		}
	}
	else if (sd == "3")
	{
	re_neu:
		system("cls");
		for (int i = 0; i < DrCount; i++)
		{
			if (doctors[i].get_DrS() == "Neurologist")
			{
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t\t   (----Neurology Clinic----)\n";
				SetConsoleTextAttribute(h, 6);
				cout << "Dr." << doctors[i].get_DrN() << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";
				if (sd == "5")
				{
					cout << "The GP diagnose : ";
					SetConsoleTextAttribute(h, 5);
					cout << initial_diagnose << "\n";
					SetConsoleTextAttribute(h, 7);
					cout << "-------------------------------------------------------------------------------------------------------------------\n";
					cin_error++;
				}
				sd = "3";
				testOfdoctor++;
				break;

			}
		}
	}
	else if (sd == "4")
	{
	re_orth:
		system("cls");
		for (int i = 0; i < DrCount; i++)
		{
			if (doctors[i].get_DrS() == "Orthopedist")
			{
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t\t   (----Orthopedogy Clinic----)\n";
				SetConsoleTextAttribute(h, 6);
				cout << "Dr." << doctors[i].get_DrN() << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";
				if (sd == "5")
				{
					cout << "The GP diagnose : ";
					SetConsoleTextAttribute(h, 5);
					cout << initial_diagnose << "\n";
					SetConsoleTextAttribute(h, 7);
					cout << "-------------------------------------------------------------------------------------------------------------------\n";
					cin_error++;
				}
				sd = "4";
				testOfdoctor++;
				break;

			}
		}
	}
	else if (sd == "5")
	{
		system("cls");
		for (int i = 0; i < DrCount; i++)
		{
			if (doctors[i].get_DrS() == "General Doctor")
			{
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t\t\t  (---GP Clinic----)\n";
				SetConsoleTextAttribute(h, 6);
				cout << "Dr." << doctors[i].get_DrN() << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";
				testOfdoctor++;
				break;
			}
		}
	}
	else
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\nError\n";
		goto re_Specialist;
	}


	if (sd == "5" && testOfdoctor > 0)
	{
		string reply;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the Initial Diagnose :";
		SetConsoleTextAttribute(h, 6);
		getline(cin, initial_diagnose);
	re_specDr:
		SetConsoleTextAttribute(h, 11);
		cout << "\nWhat doctor is appropriate for this situation ?\n";
		SetConsoleTextAttribute(h, 7);
		cout << "1- Ophthalmologist --- 2- Internist --- 3- Neurologist --- 4-Orthopedist \n";
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter your choice : ";
		SetConsoleTextAttribute(h, 6);
		cin >> reply;

		if (reply == "1")
		{
			goto re_oth;
		}
		else if (reply == "2")
		{
			goto re_int;
		}
		else if (reply == "3")
		{
			goto re_neu;
		}
		else if (reply == "4")
		{
			goto re_orth;
		}
		else 
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nError\n";
			goto re_specDr;
		}
	}
	else if (testOfdoctor > 0)
	{
		if (cin_error > 0)
		{
			cin.ignore();
		}
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the Diagnose :";
		SetConsoleTextAttribute(h, 6);
		getline(cin, d);
		if (Pa_ChPa_AcPa == 1)
		{
			patients[PaCount].set_PaDiagnose(d);
		}
		else if (Pa_ChPa_AcPa == 2)
		{
			Ch_patients[ChPaCount].set_PaDiagnose(d);
		}
		else if (Pa_ChPa_AcPa == 3)
		{
			Ac_patients[AcPaCount].set_PaDiagnose(d);
		}

	re_dis:

		string chos_dis, chos_dis2, dis;
		int dis_count = 0;
		SetConsoleTextAttribute(h, 11);
		cout << "\nIs there a disease ? \n";
		SetConsoleTextAttribute(h, 7);
		cout << "1- Yes ----- 2- No\n";
		SetConsoleTextAttribute(h, 11);
		cout << "Enter your choice : ";
		SetConsoleTextAttribute(h, 6);
		cin >> chos_dis;

		if (chos_dis == "1")
		{
		re_dis2:
			SetConsoleTextAttribute(h, 11);
			cout << "\nEnter the disease : ";
			SetConsoleTextAttribute(h, 6);
			cin.ignore();
			getline(cin, dis);
			if (Pa_ChPa_AcPa == 1)
			{
				patients[PaCount].set_PaDisease(dis, dis_count);
			}
			else if(Pa_ChPa_AcPa == 2)
			{
				Ch_patients[ChPaCount].set_PaDisease(dis, dis_count);
			}
			else if (Pa_ChPa_AcPa == 3)
			{
				Ac_patients[AcPaCount].set_PaDisease(dis, dis_count);
			}
			dis_count++;

			SetConsoleTextAttribute(h, 11);
			cout << "\nAnother disease ?";
			SetConsoleTextAttribute(h, 7);
			cout << "\n1- Yes ----- 2- No\n";
			SetConsoleTextAttribute(h, 11);
			cout << "Enter your choice : ";
			SetConsoleTextAttribute(h, 6);
			cin >> chos_dis2;
			if (chos_dis2 == "1")
			{
				goto re_dis2;
			}

		}
		else if (chos_dis == "2")
		{
			next_step();
		}
		else
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nError\n";
			goto re_dis;
		}

		if (chos_dis == "1")
		{
			next_step();
		}

	}
	else
	{

		if (sd == "5")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "There is no GP doctor recorded in the system !!\n\n";
		}
		else
		{
			SetConsoleTextAttribute(h, 4);
			cout << "There is no doctor recorded in the system with this specialty !!\n\n";
		}

	}

}

void add_Dr()
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t\t(-----Adding Doctors-----)\n";
	SetConsoleTextAttribute(h, 4);
	string id, n, s ;
	SetConsoleTextAttribute(h, 11);
	cout << "Enter the ID : ";
reID_Dr:
	SetConsoleTextAttribute(h, 6);
	cin >> id;
	if (DrCount > 0)
	{
		for (int i = 0; i < DrCount; i++)
		{
			if (doctors[i].get_DrID() == id)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nThis ID is already exist!!\n";
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter another ID : ";
				goto reID_Dr;
			}
		}
	}
	doctors[DrCount].set_DrID(id);
	cin.ignore();
	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Name : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, n);
	doctors[DrCount].set_DrName(n);
	string spec;
	re_spec:
	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Specialty : ....... \n";
	SetConsoleTextAttribute(h, 7);
	cout << "1- Ophthalmologist --- 2- Internist --- 3- Neurologist --- 4-Orthopedist --- 5- General Doctor\n";
	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter your choice : ";
	SetConsoleTextAttribute(h, 6);
	cin >> spec;
	if (spec == "1")
	{
		doctors[DrCount].set_DrS("Ophthalmologist");
	}
	else if (spec == "2")
	{
		doctors[DrCount].set_DrS("Internist");
	}                                                       
	else if (spec == "3")
	{
		doctors[DrCount].set_DrS("Neurologist");
	}
	else if (spec == "4")
	{
		doctors[DrCount].set_DrS("Orthopedist");
	}
	else if (spec == "5")
	{
		doctors[DrCount].set_DrS("General Doctor");
	}
	else
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\nError\n\n";
		goto re_spec;
	}
	SetConsoleTextAttribute(h, 4);
	cout << "\n\n--Data has been added !!!--\n";
	DrCount++;
}
void add_Pa()
{
	system("cls");
	Pa_ChPa_AcPa = 1;
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t      (-----Adding Patients------)\n";
	string id, n, a, p, t;
	SetConsoleTextAttribute(h, 11);
	cout << "Enter the ID : ";
reID_Pa:
	SetConsoleTextAttribute(h, 6);
	cin >> id;
	cin.ignore();
	if (PaCount > 0)
	{
		for (int i = 0; i < PaCount; i++)
		{
			if (patients[i].get_PaID() == id)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nThis ID is already exist!!\n";
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter another ID : ";
				goto reID_Pa;
			}
		}
	}
	patients[PaCount].set_PaID(id);
	
	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Name : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, n);
	patients[PaCount].set_PaName(n);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Address : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, a);
    patients[PaCount].set_PaAddress(a);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Phone Number : ";
	SetConsoleTextAttribute(h, 6);
	cin >> p;
	patients[PaCount].set_PaPhone(p);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Type : ";
	SetConsoleTextAttribute(h, 6);
	cin >> t;
	cin.ignore();
	patients[PaCount].set_PaType(t);

	spec_Dr();

	PaCount++;
} 

void add_EmPa()
{
	int testOfdoctor = 0;
	system("cls");
	for (int i = 0; i < DrCount; i++)
	{
		if (doctors[i].get_DrS() == "General Doctor")
		{
			SetConsoleTextAttribute(h, 10);
			cout << "\t\t\t\t\t\t  (---GP Clinic----)\n";
			SetConsoleTextAttribute(h, 6);
			cout << "Dr." << doctors[i].get_DrN() << "\n";
			SetConsoleTextAttribute(h, 7);
			cout << "-------------------------------------------------------------------------------------------------------------------\n";
			testOfdoctor++;
			break;
		}
	}

	if (testOfdoctor > 0)
	{

		string reply , initial_diagnose;
		cin.ignore();
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the Initial Diagnose :";
		SetConsoleTextAttribute(h, 6);
		getline(cin, initial_diagnose);
		Em_patients[EmPaCount].set_GPdiagnose(initial_diagnose);
	re_specDr:
		SetConsoleTextAttribute(h, 11);
		cout << "\nWhat doctor is appropriate for this situation ?\n";
		SetConsoleTextAttribute(h, 7);
		cout << "1- Ophthalmologist --- 2- Internist --- 3- Neurologist --- 4- Orthopedist\n";
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter your choice : ";
		SetConsoleTextAttribute(h, 6);
		cin >> reply;

		system("cls");
		SetConsoleTextAttribute(h, 10);
		cout << "\t\t\t\t\t   (-----Adding Emergency Patients------)\n";
		string id, n, a, p, t, d;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the ID : ";
	reID_Pa:
		SetConsoleTextAttribute(h, 6);
		cin >> id;
		cin.ignore();
		if (EmPaCount > 0)
		{
			for (int i = 0; i < EmPaCount; i++)
			{
				if (Em_patients[i].get_PaID() == id)
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nThis ID is already exist!!\n";
					SetConsoleTextAttribute(h, 11);
					cout << "\nEnter another ID : ";
					goto reID_Pa;
				}
			}
		}
		Em_patients[EmPaCount].set_PaID(id);

		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the Name : ";
		SetConsoleTextAttribute(h, 6);
		getline(cin, n);
		Em_patients[EmPaCount].set_PaName(n);

		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the Address : ";
		SetConsoleTextAttribute(h, 6);
		getline(cin, a);
		Em_patients[EmPaCount].set_PaAddress(a);

		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the Phone Number : ";
		SetConsoleTextAttribute(h, 6);
		cin >> p;
		Em_patients[EmPaCount].set_PaPhone(p);

		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the Type : ";
		SetConsoleTextAttribute(h, 6);
		cin >> t;
		Em_patients[EmPaCount].set_PaType(t);

		int testOfdoctor2 = 0;
		if (reply == "1")
		{
			system("cls");

			for (int i = 0; i < DrCount; i++)
			{
				if (doctors[i].get_DrS() == "Ophthalmologist")
				{
					SetConsoleTextAttribute(h, 10);
					cout << "\t\t\t\t\t   (----Ophthalmology Clinic----)\n";
					SetConsoleTextAttribute(h, 6);
					cout << "Dr." << doctors[i].get_DrN() << "\n";
					SetConsoleTextAttribute(h, 7);
					cout << "-------------------------------------------------------------------------------------------------------------------\n";
					
						cout << "The GP diagnose : ";
						SetConsoleTextAttribute(h, 5);
						cout << Em_patients[EmPaCount].get_GPdiagnose() << "\n";
						SetConsoleTextAttribute(h, 7);
						cout << "-------------------------------------------------------------------------------------------------------------------\n";
						//cin_error++;
					testOfdoctor2++;
					break;
				}
			}
		}
		else if (reply == "2")
		{
			system("cls");
			for (int i = 0; i < DrCount; i++)
			{
				if (doctors[i].get_DrS() == "Internist")
				{
					SetConsoleTextAttribute(h, 10);
					cout << "\t\t\t\t\t   (----Internology Clinic----)\n";
					SetConsoleTextAttribute(h, 6);
					cout << "Dr." << doctors[i].get_DrN() << "\n";
					SetConsoleTextAttribute(h, 7);
					cout << "-------------------------------------------------------------------------------------------------------------------\n";
					
						cout << "The GP diagnose : ";
						SetConsoleTextAttribute(h, 5);
						cout << Em_patients[EmPaCount].get_GPdiagnose() << "\n";
						SetConsoleTextAttribute(h, 7);
						cout << "-------------------------------------------------------------------------------------------------------------------\n";
					
					testOfdoctor2++;
					break;
				}
			}
		}
		else if (reply == "3")
		{
			system("cls");
			for (int i = 0; i < DrCount; i++)
			{
				if (doctors[i].get_DrS() == "Internist")
				{
					SetConsoleTextAttribute(h, 10);
					cout << "\t\t\t\t\t   (----Internology Clinic----)\n";
					SetConsoleTextAttribute(h, 6);
					cout << "Dr." << doctors[i].get_DrN() << "\n";
					SetConsoleTextAttribute(h, 7);
					cout << "-------------------------------------------------------------------------------------------------------------------\n";
					
						cout << "The GP diagnose : ";
						SetConsoleTextAttribute(h, 5);
						cout << Em_patients[EmPaCount].get_GPdiagnose() << "\n";
						SetConsoleTextAttribute(h, 7);
						cout << "-------------------------------------------------------------------------------------------------------------------\n";
					
					testOfdoctor2++;
					break;
				}
			}
		}
		else if (reply == "4")
		{
			system("cls");
			for (int i = 0; i < DrCount; i++)
			{
				if (doctors[i].get_DrS() == "Orthopedist")
				{
					SetConsoleTextAttribute(h, 10);
					cout << "\t\t\t\t\t   (----Orthopedogy Clinic----)\n";
					SetConsoleTextAttribute(h, 6);
					cout << "Dr." << doctors[i].get_DrN() << "\n";
					SetConsoleTextAttribute(h, 7);
					cout << "-------------------------------------------------------------------------------------------------------------------\n";

					cout << "The GP diagnose : ";
					SetConsoleTextAttribute(h, 5);
					cout << Em_patients[EmPaCount].get_GPdiagnose() << "\n";
					SetConsoleTextAttribute(h, 7);
					cout << "-------------------------------------------------------------------------------------------------------------------\n";

					testOfdoctor2++;
					break;
				}
			}
		}
		else 
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nError\n";
			goto re_specDr;
		}

		if (testOfdoctor2 == 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "There is no doctor recorded in the system with this specialty !!\n\n";
		}
		else
		{
			cin.ignore();
			SetConsoleTextAttribute(h, 11);
			cout << "Enter the Diagnose :";
			SetConsoleTextAttribute(h, 6);
			getline(cin, d);
			Em_patients[EmPaCount].set_PaDiagnose(d);

		re_dis:

			string chos_dis, chos_dis2, dis;
			int dis_count = 0;
			SetConsoleTextAttribute(h, 11);
			cout << "\n\nIs there a disease ? \n";
			SetConsoleTextAttribute(h, 7);
			cout << "1- Yes ----- 2- No\n";
			SetConsoleTextAttribute(h, 11);
			cout << "Enter your choice : ";
			SetConsoleTextAttribute(h, 6);
			cin >> chos_dis;

			if (chos_dis == "1")
			{
			re_dis2:
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter the disease : ";
				SetConsoleTextAttribute(h, 6);
				cin.ignore();
				getline(cin, dis);
				Em_patients[EmPaCount].set_PaDisease(dis, dis_count);
				dis_count++;

				SetConsoleTextAttribute(h, 11);
				cout << "\nAnother disease ?";
				SetConsoleTextAttribute(h, 7);
				cout << "\n1- Yes ----- 2- No\n";
				SetConsoleTextAttribute(h, 11);
				cout << "Enter your choice : ";
				SetConsoleTextAttribute(h, 6);
				cin >> chos_dis2;
				if (chos_dis2 == "1")
				{
					goto re_dis2;
				}

			}
			else if (chos_dis == "2")
			{
				next_step();
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nError\n";
				goto re_dis;
			}

			if (chos_dis == "1")
			{
				next_step();
			}
		}
	}

	else
	{
			SetConsoleTextAttribute(h, 4);
			cout << "There is no GP doctor recorded in the system !!\n\n";
	}

	EmPaCount++;
}

void add_ChPa()
{
	system("cls");
	Pa_ChPa_AcPa = 2;
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t    (-----Adding Chronic Patients------)\n";
	string id, n, a, p, t, mmi;
	SetConsoleTextAttribute(h, 11);
	cout << "Enter the ID : ";
reID_Pa:
	SetConsoleTextAttribute(h, 6);
	cin >> id;
	cin.ignore();
	if (ChPaCount > 0)
	{
		for (int i = 0; i < ChPaCount; i++)
		{
			if (Ch_patients[i].get_PaID() == id)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nThis ID is already exist!!\n";
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter another ID : ";
				goto reID_Pa;
			}
		}
	}
	Ch_patients[ChPaCount].set_PaID(id);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Name : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, n);
	Ch_patients[ChPaCount].set_PaName(n);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Address : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, a);
	Ch_patients[ChPaCount].set_PaAddress(a);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Phone Number : ";
	SetConsoleTextAttribute(h, 6);
	cin >> p;
	Ch_patients[ChPaCount].set_PaPhone(p);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Type : ";
	SetConsoleTextAttribute(h, 6);
	cin >> t;
	cin.ignore();
	Ch_patients[ChPaCount].set_PaType(t);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Monthly Medication Inquire : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, mmi);
	Ch_patients[ChPaCount].set_monthMedicInquire(mmi);

	spec_Dr();

	ChPaCount++;
}
void add_AcPa()
{
	system("cls");
	Pa_ChPa_AcPa = 3;
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t    (-----Adding Acute Patients------)\n";
	string id, n, a, p, t , pa ,ir ,ld;
	SetConsoleTextAttribute(h, 11);
	cout << "Enter the ID : ";
reID_Pa:
	SetConsoleTextAttribute(h, 6);
	cin >> id;
	cin.ignore();
	if (AcPaCount > 0)
	{
		for (int i = 0; i < AcPaCount; i++)
		{
			if (Ac_patients[i].get_PaID() == id)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nThis ID is already exist!!\n";
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter another ID : ";
				goto reID_Pa;
			}
		}
	}
	Ac_patients[AcPaCount].set_PaID(id);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Name : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, n);
	Ac_patients[AcPaCount].set_PaName(n);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Address : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, a);
	Ac_patients[AcPaCount].set_PaAddress(a);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Phone Number : ";
	SetConsoleTextAttribute(h, 6);
	cin >> p;
	Ac_patients[AcPaCount].set_PaPhone(p);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Type : ";
	SetConsoleTextAttribute(h, 6);
	cin >> t;
	cin.ignore();
	Ac_patients[AcPaCount].set_PaType(t);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Principal Amount : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, pa);
	Ac_patients[AcPaCount].set_PrinAmount(pa);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Interest Rate : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, ir);
	Ac_patients[AcPaCount].set_InterRate(ir);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Loan Duration in mounths: ";
	SetConsoleTextAttribute(h, 6);
	cin >> ld;
	Ac_patients[AcPaCount].set_LoanDuar(ld);

	spec_Dr();

	AcPaCount++;
}

void edit_Dr()
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t    (-----Editing Doctors Info-----)\n";
	if (doctors[0].get_DrID() == "000")
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any doctor !!\n";
	}
	else
	{
		string id;
		int test = 0;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the ID to search : "; 
		SetConsoleTextAttribute(h, 6);
		cin >> id;
		for (int i = 0; i < DrCount; i++)
		{
			if (doctors[i].get_DrID() == id)
			{
				test++;
				string ans;
				cout << "\n";  doctors[i].display_info();
				SetConsoleTextAttribute(h, 11);
				cout << "\n\t\t\t\t\t   What thing do you want to edit ?\n";
				re_chosData1:
				SetConsoleTextAttribute(h, 7);
				cout << "\t\t\t    1-ID ----------- 2-Name -------- 3-Specialty ----------- 4-All\n";
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter your choice : ";
				SetConsoleTextAttribute(h, 6);
				cin >> ans; 
				cin.ignore();
				SetConsoleTextAttribute(h, 11);
				if (ans == "1")
				{
					string id; cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; doctors[i].set_DrID(id);
				}
				else if (ans == "2")
				{
					string n; cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin,n); doctors[i].set_DrName(n);
				}
				else if (ans == "3")
				{
					string s; cout << "Enter the new Specialty: ";
					re_chosData2:
					SetConsoleTextAttribute(h, 7);
					cout << "1- Ophthalmologist --- 2- Internist --- 3- Neurologist --- 4- Orthopedist --- 5- General Doctor\n";
					SetConsoleTextAttribute(h, 11);
					cout << "\nEnter your choice : ";
					SetConsoleTextAttribute(h, 6);
					cin >> s;
					if (s == "1")
					{
						doctors[i].set_DrS("Ophthalmologist");
					}
					else if (s == "2")
					{
						doctors[i].set_DrS("Internist");
					}
					else if (s == "3")
					{
						doctors[i].set_DrS("Neurologist");
					}
					else if (s == "3")
					{
						doctors[i].set_DrS("Orthopedist");
					}
					else if (s == "5")
					{
						doctors[i].set_DrS("General Doctor");
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "\nError\n\n";
						goto re_chosData2;
					}
					
				}
				else if (ans == "4")
				{
					SetConsoleTextAttribute(h, 11);
					string id, n, s; cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6); 
					cin >> id; 
					cin.ignore(); 
					doctors[i].set_DrID(id); cout << "\n";
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, n); doctors[i].set_DrName(n); cout << "\n";
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Specialty: "; 
					re_chosData3:
					SetConsoleTextAttribute(h, 7);
					cout << "1- Ophthalmologist --- 2- Internist --- 3- Neurologist --- 4- Orthopedist --- 5- General Doctor\n";
					SetConsoleTextAttribute(h, 11);
					cout << "\nEnter your choice : ";
					SetConsoleTextAttribute(h, 6);
					cin >> s;
					if (s == "1")
					{
						doctors[i].set_DrS("Ophthalmologist");
					}
					else if (s == "2")
					{
						doctors[i].set_DrS("Internist");
					}
					else if (s == "3")
					{
						doctors[i].set_DrS("Neurologist");
					}
					else if (s == "4")
					{
						doctors[i].set_DrS("Orthopedist");
					}
					else if (s == "5")
					{
						doctors[i].set_DrS("General Doctor");
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "\nError\n\n";
						goto re_chosData3;
					}
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosData1;
				}
			}
		}
		if (test == 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nThis ID is not found in the System !!!\n";
		}

	}
}
void edit_Pa() 
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t   (-----Editing Patients Info-----)\n";
	if (patients[0].get_PaID() == "000" && Ch_patients[0].get_PaID() == "000" && Ac_patients[0].get_PaID() == "000" && Em_patients[0].get_PaID() == "000")
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any patient !!\n";
	}
	else 
	{
		string type_pa;
		SetConsoleTextAttribute(h, 11);
		cout << "What the type of patient ?\n";
		re_edit:
		SetConsoleTextAttribute(h, 7);
		cout << "1- Normal patient --- 2- Chronic patient --- 3- Acute patient --- 4- Emergency case\n";
		SetConsoleTextAttribute(h, 11);
		cout << "Enter your Choice: ";
		SetConsoleTextAttribute(h, 6);
		cin >> type_pa;

		if (type_pa == "1")
		{
		string id;
		int test = 0 , test2 = 0;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the ID to search : ";
		SetConsoleTextAttribute(h, 6);
		cin >> id;
		for (int i = 0; i < PaCount; i++)
		{
			if (patients[i].get_PaID() == id)
			{
				test++ ;
				string ans;
				cout << "\n"; patients[i].display_info();
				SetConsoleTextAttribute(h, 11);
				cout << "\n\t\t\t\t\t   What thing do you want to edit ?\n";
			re_chosData4:
				SetConsoleTextAttribute(h, 7);
				if (patients[i].get_PaDisease(0) == "000")
				{
					test2 = 1;
					cout << "\t      1-ID ---- 2-Name ---- 3-Address ---- 4-Phone Number ---- 5-Type ---- 6-Diagnose ---- 7-All";
				}
				else
				{
					test2 = 2;
					cout << "\t 1-ID ---- 2-Name ---- 3-Address ---- 4-Phone Number ---- 5-Type ---- 6-Diagnose ---- 7-Disease ---- 8-All";
				}
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter your choice : ";
				SetConsoleTextAttribute(h, 6);
				cin >> ans;
				SetConsoleTextAttribute(h, 11);
				if (ans == "1")
				{
					string id; cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; patients[i].set_PaID(id);
				}
				else if (ans == "2")
				{
					string n; cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , n); patients[i].set_PaName(n);
				}
				else if (ans == "3")
				{
					cin.ignore();
					string a; cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , a); patients[i].set_PaAddress(a);
				}
				else if (ans == "4")
				{
					string p; cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; patients[i].set_PaPhone(p);
				}
				else if (ans == "5")
				{
					string t; cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; patients[i].set_PaType(t);
				}
				else if (ans == "6")
				{
					string d; cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , d); patients[i].set_PaDiagnose(d);
				}
				else if (ans == "7" && test2 == 2)
				{
					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (patients[i].get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							patients[i].set_PaDisease(dis, j);
							cout << "\n";
						}
					}
				}
				else if (ans == "8" || (ans=="7" && test2 == 1))
				{
					string id, n, a, p, t, d;
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; patients[i].set_PaID(id); cout << "\n";

					
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , n); patients[i].set_PaName(n); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin , a); patients[i].set_PaAddress(a); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; patients[i].set_PaPhone(p); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; patients[i].set_PaType(t); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , d); patients[i].set_PaDiagnose(d); cout << "\n";

					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (patients[i].get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							patients[i].set_PaDisease(dis, j);
							cout << "\n";
						}
					}

				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosData4;
				}
			}
		}
		if (test == 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nThis ID is not found in the System !!!\n";
		}
     	}
		else if (type_pa == "2")
		{
		string id;
		int test = 0 , test2=0;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the ID to search : ";
		SetConsoleTextAttribute(h, 6);
		cin >> id;
		for (int i = 0; i < ChPaCount; i++)
		{
			if (Ch_patients[i].get_PaID() == id)
			{
				test++;
				string ans;
				cout << "\n"; 
				Ch_patients[i].display_info();
				SetConsoleTextAttribute(h, 11);
				cout << "\n\t\t\t\t\t   What thing do you want to edit ?\n";
			re_chosData5:
				SetConsoleTextAttribute(h, 7);
				if (Ch_patients[i].get_PaDisease(0) == "000")
				{
					test2 = 1;
					cout << "1-ID ---- 2-Name ---- 3-Address ---- 4-Phone Number ---- 5-Type ---- 6-Diagnose ---- 7-Monthly Medication Inquire ---- 8-All";
				}
				else
				{
					test2 = 2;
					cout << "1-ID --- 2-Name --- 3-Address --- 4-Phone Number --- 5-Type --- 6-Diagnose --- 7-Disease --- 8-Monthly Medication Inquire --- 9-All";
				}
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter your choice : ";
				SetConsoleTextAttribute(h, 6);
				cin >> ans;
				SetConsoleTextAttribute(h, 11);
				if (ans == "1")
				{
					string id; cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; Ch_patients[i].set_PaID(id);
				}
				else if (ans == "2")
				{
					string n; cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , n); Ch_patients[i].set_PaName(n);
				}
				else if (ans == "3")
				{
					string a; cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , a); Ch_patients[i].set_PaAddress(a);
				}
				else if (ans == "4")
				{
					string p; cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; Ch_patients[i].set_PaPhone(p);
				}
				else if (ans == "5")
				{
					string t; cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; Ch_patients[i].set_PaType(t);
				}
				else if (ans == "6")
				{
					string d; cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , d); Ch_patients[i].set_PaDiagnose(d);
				}
				else if (ans == "7" && test2 == 2 )
				{
					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (Ch_patients[i].get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							Ch_patients[i].set_PaDisease(dis, j);
							cout << "\n";
						}
					}
				}
				else if (ans == "8" && test2 == 2 || ans == "7" && test == 1)
				{
					string mmi; cout << "Enter the new Monthly Medication Inquire: ";
					SetConsoleTextAttribute(h, 6);
					cin >> mmi; Ch_patients[i].set_monthMedicInquire(mmi);
				}
				else if (ans == "9" && test2 == 2 || ans=="8" && test2 == 1 )
				{
					string id, n, a, p, t, d , mmi;
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; Ch_patients[i].set_PaID(id); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , n); Ch_patients[i].set_PaName(n); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin , a); Ch_patients[i].set_PaAddress(a); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; Ch_patients[i].set_PaPhone(p); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; Ch_patients[i].set_PaType(t); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					cin >> d; Ch_patients[i].set_PaDiagnose(d); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new 8-Monthly Medication Inquire: ";
					SetConsoleTextAttribute(h, 6);
					cin >> mmi; Ch_patients[i].set_monthMedicInquire(mmi); cout << "\n";

					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (Ch_patients[i].get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							Ch_patients[i].set_PaDisease(dis, j);
							cout << "\n";
						}
					}
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosData5;
				}
			}
		}
		if (test == 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nThis ID is not found in the System !!!\n";
		}
		}
		else if (type_pa == "3")
		{
		string id;
		int test = 0 , test2 = 0;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the ID to search : ";
		SetConsoleTextAttribute(h, 6);
		cin >> id;
		for (int i = 0; i < AcPaCount; i++)
		{
			if (Ac_patients[i].get_PaID() == id)
			{
				test++;
				string ans;
				cout << "\n"; Ac_patients[i].display_info();
				SetConsoleTextAttribute(h, 11);
				cout << "\n\t\t\t\t\t   What thing do you want to edit ?\n";
			re_chosData6:
				SetConsoleTextAttribute(h, 7);
				if (Ac_patients[i].get_PaDisease(0) == "000")
				{
					test2 = 1;
					cout << "1-ID --- 2-Name --- 3-Address --- 4-Phone Number --- 5-Type --- 6-Diagnose --- 7-Principal Amount --- 8-Interest Rate --- 9-Loan Duration --- 10-All";
				}
				else
				{
					test2 = 2;
					cout << "1-ID --- 2-Name --- 3-Address --- 4-Phone Number --- 5-Type --- 6-Diagnose --- 7-Disease --- 8-Principal Amount --- 9-Interest Rate --- 10-Loan Duration --- 11-All";
				}
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter your choice : ";
				SetConsoleTextAttribute(h, 6);
				cin >> ans;
				SetConsoleTextAttribute(h, 11);
				if (ans == "1")
				{
					string id; cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; Ac_patients[i].set_PaID(id);
				}
				else if (ans == "2")
				{
					string n; cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin,n); Ac_patients[i].set_PaName(n);
				}
				else if (ans == "3")
				{
					string a; cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin,a); Ac_patients[i].set_PaAddress(a);
				}
				else if (ans == "4")
				{
					string p; cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; Ac_patients[i].set_PaPhone(p);
				}
				else if (ans == "5")
				{
					string t; cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; Ac_patients[i].set_PaType(t);
				}
				else if (ans == "6")
				{
					string d; cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , d); Ac_patients[i].set_PaDiagnose(d);
				}
				else if (ans == "7" && test2 == 2)
				{
					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (Ac_patients[i].get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							Ac_patients[i].set_PaDisease(dis, j);
							cout << "\n";
						}
					}

				}
				else if (ans == "7" && test2 == 1 || ans == "8" && test2 == 2)
				{
					string pa; cout << "Enter the new Principal Amount: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, pa); Ac_patients[i].set_PrinAmount(pa);
				}
				else if (ans == "8" && test2 == 1 || ans == "9" && test2 == 2)
				{
					string ir; cout << "Enter the new Interest Rate: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, ir); Ac_patients[i].set_InterRate(ir);
				}
				else if (ans == "9" && test2 == 1 || ans == "10" && test2 == 2)
				{
					string ld; cout << "Enter the new Loan Duration: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, ld); Ac_patients[i].set_LoanDuar(ld);
				}
				else if ( ans == "10" && test2 == 1 || ans == "11" && test2 == 2)
				{
					string id, n, a, p, t, d , pa , ir ,ld;
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; Ac_patients[i].set_PaID(id); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin,n); Ac_patients[i].set_PaName(n); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin ,a); Ac_patients[i].set_PaAddress(a); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; Ac_patients[i].set_PaPhone(p); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; Ac_patients[i].set_PaType(t); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin , d); Ac_patients[i].set_PaDiagnose(d); cout << "\n";

					cout << "Enter the new Principal Amount: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, pa); Ac_patients[i].set_PrinAmount(pa); cout << "\n";

					cout << "Enter the new Interest Rate: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, ir); Ac_patients[i].set_InterRate(ir); cout << "\n";

				    cout << "Enter the new Loan Duration: "; cout << "\n";
					SetConsoleTextAttribute(h, 6);
					getline(cin, ld); Ac_patients[i].set_LoanDuar(ld);

					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (Ac_patients[i].get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							Ac_patients[i].set_PaDisease(dis, j);
							cout << "\n";
						}
					}
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosData6;
				}
			}
		}
		if (test == 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nThis ID is not found in the System !!!\n";
		}
		}
		else if (type_pa == "4")
		{
		string id;
		int test = 0 , test2=0;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the ID to search : ";
		SetConsoleTextAttribute(h, 6);
		cin >> id;
		for (int i = 0; i < EmPaCount; i++)
		{
			if (Em_patients[i].get_PaID() == id)
			{
				test++;
				string ans;
				cout << "\n"; Em_patients[i].display_info();
				SetConsoleTextAttribute(h, 11);
				cout << "\n\t\t\t\t\t   What thing do you want to edit ?\n";
			re_chosData7:
				SetConsoleTextAttribute(h, 7);
				if (Em_patients[i].get_PaDisease(0) == "000")
				{
					test2 = 1;
					cout << "\t 1-ID ---- 2-Name ---- 3-Address ---- 4-Phone Number ---- 5-Type ---- 6-GP-Diagnose ---- 7-Diagnose ---- 8-All ";
				}
				else
				{
					test2 = 2;
					cout << "\t 1-ID ---- 2-Name ---- 3-Address ---- 4-Phone Number ---- 5-Type ---- 6-GP-Diagnose ---- 7-Diagnose ---- 8-Disease ---- 9-All";
				}
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter your choice : ";
				SetConsoleTextAttribute(h, 6);
				cin >> ans;
				SetConsoleTextAttribute(h, 11);
				if (ans == "1")
				{
					string id; cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; Em_patients[i].set_PaID(id);
				}
				else if (ans == "2")
				{
					string n; cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, n); Em_patients[i].set_PaName(n);
				}
				else if (ans == "3")
				{
					string a; cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, a); Em_patients[i].set_PaAddress(a);
				}
				else if (ans == "4")
				{
					string p; cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; Em_patients[i].set_PaPhone(p);
				}
				else if (ans == "5")
				{
					string t; cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; Em_patients[i].set_PaType(t);
				}
				else if (ans == "6")
				{
					string gpd; cout << "Enter the new GP-Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, gpd); Em_patients[i].set_GPdiagnose(gpd);
				}
				else if (ans == "7")
				{
					string d; cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, d); Em_patients[i].set_PaDiagnose(d);
				}
				else if (ans == "8" && test2 == 2)
				{
					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (patients[i].get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							Em_patients[i].set_PaDisease(dis, j);
							cout << "\n";
						}
					}
				}
				else if (ans == "8" && test2 == 1 || ans == "9" && test2 == 2)
				{
					string id, n, a, p, t, d , gpd;
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; Em_patients[i].set_PaID(id); cout << "\n";


					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, n); Em_patients[i].set_PaName(n); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, a); Em_patients[i].set_PaAddress(a); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; Em_patients[i].set_PaPhone(p); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; Em_patients[i].set_PaType(t); cout << "\n";


					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, d); Em_patients[i].set_PaDiagnose(d); cout << "\n";

					cout << "Enter the new GP-Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, gpd); Em_patients[i].set_GPdiagnose(gpd); cout << "\n";

					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (patients[i].get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							Em_patients[i].set_PaDisease(dis, j);
							cout << "\n";
						}
					}
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosData7;
				}
			}
		}
		if (test == 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nThis ID is not found in the System !!!\n";
		}
        }
		else
		{
		SetConsoleTextAttribute(h, 4);
		cout << "\nError\n\n";
		goto re_edit;
        }
	}
}

void delete_Dr()
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t   (-----Deleting Doctors Info-----)\n";
	if (doctors[0].get_DrID() == "000")
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any doctor !!\n";
	}
	else {
		int test = 0 , test2=0;
		string id;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the ID to search : "; 
		SetConsoleTextAttribute(h, 6);
		cin >> id;
		for (int i = 0; i < DrCount; i++)
		{
			if (doctors[i].get_DrID() == id)
			{
				test++;
				cout << "\n"; doctors[i].display_info();
				string ans;
				SetConsoleTextAttribute(h, 11);
				cout << "\nDo you want delete it ? \n"; 
				re_chosYesNo:
				SetConsoleTextAttribute(h, 7);
				cout << "1- Yes ----- 2- No\n";
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter your choice : "; 
				SetConsoleTextAttribute(h, 6);
				cin >> ans;
				if (ans == "1")
				{
					if (i == (DrCount - 1))
					{
						doctors[i].set_DrID("000"); doctors[i].set_DrName("000"); doctors[i].set_DrS("000");
						DrCount--;
					}
					else if (i < (DrCount - 1))
					{
						for (int j = 0, k = 1; j < (DrCount - 1); j++, k++)
						{
							doctors[i + j] = doctors[i + k];
						}
						doctors[(DrCount - 1)].set_DrID("000"); doctors[(DrCount - 1)].set_DrName("000"); doctors[(DrCount - 1)].set_DrS("000");
						DrCount--;
					}
				}
				else if (ans == "2")
				{
					test2++;
					break;
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosYesNo;
				}
					
			}
		}

		SetConsoleTextAttribute(h, 4);
		if (test == 0)
			cout << "\nThis ID is not found in the System !!!\n";
		else if(test2 == 0)
			cout << "\n--Data has been deleted !!--";
	}
} 
void delete_Pa() 
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t   (-----Deleting Patients Info-----)\n";
	if (patients[0].get_PaID() == "000" && Ch_patients[0].get_PaID() == "000" && Ac_patients[0].get_PaID() == "000" && Em_patients[0].get_PaID() == "000")
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any patient !!\n";
	}
	else
	{
		string type_pa;
		SetConsoleTextAttribute(h, 11);
		cout << "What the type of patient ?\n";
	re_delete:
		SetConsoleTextAttribute(h, 7);
		cout << "1- Normal patient --- 2- Chronic patient --- 3- Acute patient --- 4- Emergency case\n";
		SetConsoleTextAttribute(h, 11);
		cout << "Enter your Choice: ";
		SetConsoleTextAttribute(h, 6);
		cin >> type_pa;

		if (type_pa == "1") 
		{
			int test = 0, test2 = 0;
			string id;
			SetConsoleTextAttribute(h, 11);
			cout << "Enter the ID to search : ";
			SetConsoleTextAttribute(h, 6);
			cin >> id;
			for (int i = 0; i < PaCount; i++)
			{
				if (patients[i].get_PaID() == id)
				{
					test++;
					cout << "\n"; patients[i].display_info();
					string ans;
					SetConsoleTextAttribute(h, 11);
					cout << "\nDo you want delete it ? \n";
				re_chosYesNo2:
					SetConsoleTextAttribute(h, 7);
					cout << "1- Yes ----- 2- No\n";
					SetConsoleTextAttribute(h, 11);
					cout << "\nEnter your choice : ";
					SetConsoleTextAttribute(h, 6);
					cin >> ans;
					if (ans == "1")
					{
						if (i == (PaCount - 1))
						{
							patients[i].set_PaID("000"); patients[i].set_PaName("000"); patients[i].set_PaAddress("000"); patients[i].set_PaPhone("000"); patients[i].set_PaType("000"); patients[i].set_PaDiagnose("000");
							for (int j = 0; j < 10; j++)
							{
								patients[i].set_PaDisease("000", j);
							}
							PaCount--;
						}
						else if (i < (PaCount - 1))
						{
							for (int j = 0, k = 1; j < (PaCount - 1); j++, k++)
							{
								patients[i + j] = patients[i + k];
							}
							patients[(PaCount - 1)].set_PaID("000"); patients[(PaCount - 1)].set_PaName("000");
							patients[(PaCount - 1)].set_PaAddress("000"); patients[(PaCount - 1)].set_PaPhone("000");
							patients[(PaCount - 1)].set_PaType("000"); patients[(PaCount - 1)].set_PaDiagnose("000");
							for (int j = 0; j < 10; j++)
							{
								patients[(PaCount - 1)].set_PaDisease("000", j);
							}
							PaCount--;
						}
					}
					else if (ans == "2")
					{
						test2++;
						break;
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "\nError\n\n";
						goto re_chosYesNo2;
					}
				}
			}

			SetConsoleTextAttribute(h, 4);
			if (test == 0)
				cout << "\nThis ID is not found in the System !!!\n";
			else if (test2 == 0)
				cout << "\n--Data has been deleted !!--";
		}
		else if (type_pa == "2")
		{
			int test = 0, test2 = 0;
			string id;
			SetConsoleTextAttribute(h, 11);
			cout << "Enter the ID to search : ";
			SetConsoleTextAttribute(h, 6);
			cin >> id;
			for (int i = 0; i < ChPaCount; i++)
			{
				if (Ch_patients[i].get_PaID() == id)
				{
					test++;
					cout << "\n"; Ch_patients[i].display_info();
					string ans;
					SetConsoleTextAttribute(h, 11);
					cout << "\nDo you want delete it ? \n";
				re_chosYesNo3:
					SetConsoleTextAttribute(h, 7);
					cout << "1- Yes ----- 2- No\n";
					SetConsoleTextAttribute(h, 11);
					cout << "\nEnter your choice : ";
					SetConsoleTextAttribute(h, 6);
					cin >> ans;
					if (ans == "1")
					{
						if (i == (ChPaCount - 1))
						{
							Ch_patients[i].set_PaID("000"); Ch_patients[i].set_PaName("000"); Ch_patients[i].set_PaAddress("000"); Ch_patients[i].set_PaPhone("000"); Ch_patients[i].set_PaType("000"); Ch_patients[i].set_PaDiagnose("000"); Ch_patients[i].set_monthMedicInquire("000");
							for (int j = 0; j < 10; j++)
							{
								Ch_patients[i].set_PaDisease("000", j);
							}
							ChPaCount--;
						}
						else if (i < (ChPaCount - 1))
						{
							for (int j = 0, k = 1; j < (ChPaCount - 1); j++, k++)
							{
								Ch_patients[i + j] = Ch_patients[i + k];
							}
							Ch_patients[(ChPaCount - 1)].set_PaID("000"); Ch_patients[(ChPaCount - 1)].set_PaName("000");
							Ch_patients[(ChPaCount - 1)].set_PaAddress("000"); Ch_patients[(ChPaCount - 1)].set_PaPhone("000");
							Ch_patients[(ChPaCount - 1)].set_PaType("000"); Ch_patients[(ChPaCount - 1)].set_PaDiagnose("000");
							Ch_patients[(ChPaCount - 1)].set_monthMedicInquire("000");
							for (int j = 0; j < 10; j++)
							{
								Ch_patients[(ChPaCount - 1)].set_PaDisease("000", j);
							}
							ChPaCount--;
						}
					}
					else if (ans == "2")
					{
						test2++;
						break;
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "\nError\n\n";
						goto re_chosYesNo3;
					}
				}
			}

			SetConsoleTextAttribute(h, 4);
			if (test == 0)
				cout << "\nThis ID is not found in the System !!!\n";
			else if (test2 == 0)
				cout << "\n--Data has been deleted !!--";
		}
		else if (type_pa == "3")
		{
		int test = 0, test2 = 0;
		string id;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the ID to search : ";
		SetConsoleTextAttribute(h, 6);
		cin >> id;
		for (int i = 0; i < AcPaCount; i++)
		{
			if (Ac_patients[i].get_PaID() == id)
			{
				test++;
				cout << "\n"; Ac_patients[i].display_info();
				string ans;
				SetConsoleTextAttribute(h, 11);
				cout << "\nDo you want delete it ? \n";
			re_chosYesNo4:
				SetConsoleTextAttribute(h, 7);
				cout << "1- Yes ----- 2- No\n";
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter your choice : ";
				SetConsoleTextAttribute(h, 6);
				cin >> ans;
				if (ans == "1")
				{
					if (i == (AcPaCount - 1))
					{
						Ac_patients[i].set_PaID("000"); Ac_patients[i].set_PaName("000"); Ac_patients[i].set_PaAddress("000"); Ac_patients[i].set_PaPhone("000"); Ac_patients[i].set_PaType("000"); Ac_patients[i].set_PaDiagnose("000");
						Ac_patients[i].set_PrinAmount("000"); Ac_patients[i].set_InterRate("000"); Ac_patients[i].set_InterRate("000");
						for (int j = 0; j < 10; j++)
						{
							Ac_patients[i].set_PaDisease("000", j);
						}
						AcPaCount--;
					}
					else if (i < (AcPaCount - 1))
					{
						for (int j = 0, k = 1; j < (AcPaCount - 1); j++, k++)
						{
							Ac_patients[i + j] = Ac_patients[i + k];
						}
						Ac_patients[(AcPaCount - 1)].set_PaID("000"); Ac_patients[(AcPaCount - 1)].set_PaName("000");
						Ac_patients[(AcPaCount - 1)].set_PaAddress("000"); Ac_patients[(AcPaCount - 1)].set_PaPhone("000");
						Ac_patients[(AcPaCount - 1)].set_PaType("000"); Ac_patients[(AcPaCount - 1)].set_PaDiagnose("000");
						Ac_patients[(AcPaCount - 1)].set_PrinAmount("000"); Ac_patients[(AcPaCount - 1)].set_InterRate("000"); Ac_patients[(AcPaCount - 1)].set_InterRate("000");
						for (int j = 0; j < 10; j++)
						{
							Ac_patients[(AcPaCount - 1)].set_PaDisease("000", j);
						}
						AcPaCount--;
					}
				}
				else if (ans == "2")
				{
					test2++;
					break;
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosYesNo4;
				}
			}
		}

		SetConsoleTextAttribute(h, 4);
		if (test == 0)
			cout << "\nThis ID is not found in the System !!!\n";
		else if (test2 == 0)
			cout << "\n--Data has been deleted !!--";
        }
		else if (type_pa == "4")
		{
		int test = 0, test2 = 0;
		string id;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the ID to search : ";
		SetConsoleTextAttribute(h, 6);
		cin >> id;
		for (int i = 0; i < EmPaCount; i++)
		{
			if (Em_patients[i].get_PaID() == id)
			{
				test++;
				cout << "\n"; Em_patients[i].display_info();
				string ans;
				SetConsoleTextAttribute(h, 11);
				cout << "\nDo you want delete it ? \n";
			re_chosYesNo5:
				SetConsoleTextAttribute(h, 7);
				cout << "1- Yes ----- 2- No\n";
				SetConsoleTextAttribute(h, 11);
				cout << "\nEnter your choice : ";
				SetConsoleTextAttribute(h, 6);
				cin >> ans;
				if (ans == "1")
				{
					if (i == (EmPaCount - 1))
					{
						Em_patients[i].set_PaID("000"); Em_patients[i].set_PaName("000"); Em_patients[i].set_PaAddress("000"); Em_patients[i].set_PaPhone("000"); Em_patients[i].set_PaType("000"); Em_patients[i].set_PaDiagnose("000");
						Em_patients[i].set_GPdiagnose("000");
						for (int j = 0; j < 10; j++)
						{
							Em_patients[i].set_PaDisease("000", j);
						}
						EmPaCount--;
					}
					else if (i < (EmPaCount - 1))
					{
						for (int j = 0, k = 1; j < (EmPaCount - 1); j++, k++)
						{
							Em_patients[i + j] = Em_patients[i + k];
						}
						Em_patients[(EmPaCount - 1)].set_PaID("000"); Em_patients[(EmPaCount - 1)].set_PaName("000");
						Em_patients[(EmPaCount - 1)].set_PaAddress("000"); Em_patients[(EmPaCount - 1)].set_PaPhone("000");
						Em_patients[(EmPaCount - 1)].set_PaType("000"); Em_patients[(EmPaCount - 1)].set_PaDiagnose("000");
						Em_patients[(EmPaCount - 1)].set_GPdiagnose("000");
						for (int j = 0; j < 10; j++)
						{
							Em_patients[(EmPaCount - 1)].set_PaDisease("000", j);
						}
						EmPaCount--;
					}
				}
				else if (ans == "2")
				{
					test2++;
					break;
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosYesNo5;
				}
			}
		}

		SetConsoleTextAttribute(h, 4);
		if (test == 0)
			cout << "\nThis ID is not found in the System !!!\n";
		else if (test2 == 0)
			cout << "\n--Data has been deleted !!--";
        }
		else
		{
		SetConsoleTextAttribute(h, 4);
		cout << "\nError\n\n";
		goto re_delete;
        }
	}
}

void list_Dr()
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t   (-----The list of Doctors-----)\n";
	if (doctors[0].get_DrID() == "000")
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any doctor !!\n";
	}
	else
	{
		for (int i = 0; i < DrCount; i++)
		{
			SetConsoleTextAttribute(h, 11);
			cout << "Doctor No." << (i + 1) << "\n";
			SetConsoleTextAttribute(h, 6);
			doctors[i].display_info(); cout << "\n";
		}
	}
}
void list_Pa()
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t   (-----The list of Patients-----)\n";

	if (patients[0].get_PaID() == "000" && Ch_patients[0].get_PaID() == "000" && Ac_patients[0].get_PaID() == "000")
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any patient !!\n";
	}
	else
	{
		for (int i = 0; i < PaCount; i++)
		{
			SetConsoleTextAttribute(h, 11);
			cout << "Patient No." << (i + 1) << "\n";
			patients[i].display_info(); cout << "\n";
		}

		if (Ch_patients[0].get_PaID() != "000")
		{
			SetConsoleTextAttribute(h, 12);
			cout << "The Chronic patients :\n";
		}
		for (int i = 0; i < ChPaCount; i++)
		{
			SetConsoleTextAttribute(h, 11);
			cout << "Patient No." << (i + 1) << "\n";
			Ch_patients[i].display_info(); cout << "\n";
		}

		if (Ch_patients[0].get_PaID() != "000")
		{
			SetConsoleTextAttribute(h, 12);
			cout << "The Acute patients :\n";
		}
		for (int i = 0; i < AcPaCount; i++)
		{
			SetConsoleTextAttribute(h, 11);
			cout << "Patient No." << (i + 1) << "\n";
			Ac_patients[i].display_info(); cout << "\n";
		}
	}
}

void list_EmPa()
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t (-----The list of Emergency cases-----)\n";

	if (Em_patients[0].get_PaID() == "000" )
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any emergency case !!\n";
	}
	else
	{
		for (int i = 0; i < EmPaCount; i++)
		{
			SetConsoleTextAttribute(h, 11);
			cout << "Patient No." << (i + 1) << "\n";
			Em_patients[i].display_info(); cout << "\n";
		}

	}
}

int main()
{
	do
	{
		start:
			home_page();

			if (reply == "1") { Readd_Doc:add_Dr(); }
			else if (reply == "2") { Readd_Pat:add_Pa(); }

			else if (reply == "3") { Reedit_Doc:edit_Dr(); }
			else if (reply == "4") { Reedit_Pat:edit_Pa(); }

			else if (reply == "5") { Redelete_Doc:delete_Dr(); }
			else if (reply == "6") { Redelete_Pat:delete_Pa(); }

			else if (reply == "7") { show_Doc:list_Dr(); }
			else if (reply == "8") { show_Pat:list_Pa(); }

			else if(reply == "9")  {Readd_EmPat:add_EmPa();}
			else if(reply == "10") {list_EmPa();}
			
			else if (reply == "11") {Readd_ChPat:add_ChPa();}
			else if (reply == "12"){Readd_AcPat:add_AcPa();}

			else
				goto start;

		
				string rep;
				int temp = 0;
				SetConsoleTextAttribute(h, 10);
				cout << "\n\n\t\t\t\t\t      You Can.........(Choose)\n";
				SetConsoleTextAttribute(h, 11);
				if (reply == "1")
				{
					cout << "\t 1- Add another doctor";
				}
				else if (reply == "2")
				{
					cout << "\t 1- Add another patient";
				}
				else if (reply == "3")
				{
					cout << "\t 1- Edit another doctor";
				}
				else if (reply == "4")
				{
					cout << "\t 1- Edit another patient";
				}
				else if (reply == "5")
				{
					cout << "\t 1- Delete another doctor";
				}
				else if (reply == "6")
				{
					cout << "\t 1- Delete another patient";
				}
				else if (reply == "7")
				{
					cout << "\t 1- Show the list of patients";
				}
				else if (reply == "8")
				{
					cout << "\t 1- Show the list of doctors";
				}
				else if (reply == "9")
				{
					cout << "\t 1- Add another Emergency case";
				}
				else if (reply == "10")
				{
					cout << "\t 1- Add an Emergency case";
				}
				else if (reply == "11")
				{
					cout << "\t 1- Add another chronic patient";
				}
				else if (reply == "12")
				{
					cout << "\t 1- Add another acute patient";
				}

				SetConsoleTextAttribute(h, 2);
				cout << " -------------------------------------------------- ";
				SetConsoleTextAttribute(h, 11);
				cout << "2 - Return to Home Page\n";
				SetConsoleTextAttribute(h, 6);
				cin >> rep;

				if (reply == "1" && rep == "1")
				{
					goto Readd_Doc;
				}
				else if (reply == "2" && rep == "1")
				{
					goto Readd_Pat;
				}
				else if (reply == "3" && rep == "1")
				{
					goto Reedit_Doc;
				}
				else if (reply == "4" && rep == "1")
				{
					goto Reedit_Pat;
				}
				else if (reply == "5" && rep == "1")
				{
					goto Redelete_Doc;
				}
				else if (reply == "6" && rep == "1")
				{
					goto Redelete_Pat;
				}
				else if (reply == "7" && rep == "1")
				{
					reply = "8";
					goto show_Pat;
				}
				else if (reply == "8" && rep == "1")
				{
					reply = "7";
					goto show_Doc;
				}
				else if (reply == "9" && rep == "1")
				{
					goto Readd_EmPat;
				}
				else if (reply == "10" && rep == "1")
				{
					reply = 9;
					goto Readd_EmPat;
				}
				else if (reply == "11" && rep == "1")
				{
					goto Readd_ChPat;
				}
				else if (reply == "12" && rep == "1")
				{
					goto Readd_AcPat;
				}
			
	}
	while (true);

}

