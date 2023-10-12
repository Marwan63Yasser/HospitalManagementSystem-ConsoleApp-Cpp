#include<iostream>
#include<windows.h>
#include <string>
#include <map>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //For Coloring the Text
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

template<class type>
class Node {
public:
	type data;
	Node* next{};
};

class Dr_List {
private:
	Node<Doctor>* head;

public:

	Dr_List(void)
	{
		head = NULL;
	}

	~Dr_List(void)
	{
		Node<Doctor>* currNode = head;
		Node<Doctor>* nextNode = NULL;
		while (currNode != NULL) {
			nextNode = currNode->next;
			delete currNode; // destroy the current node
			currNode = nextNode;
		}
	}

	bool IsEmpty()
	{
		return head == NULL;
	}

	void InsertDoc(Doctor a)
	{
		Node<Doctor>* newNode = new Node<Doctor>;
		Node<Doctor>* currNode = head;
		newNode->data.set_DrID(a.get_DrID());
		newNode->data.set_DrName(a.get_DrN());
		newNode->data.set_DrS(a.get_DrS());
		if (currNode == NULL)
		{
			newNode->next = head;
			head = newNode;
		}
		else {
			while (currNode->next != NULL)
				currNode = currNode->next;

			newNode->next = currNode->next;
			currNode->next = newNode;
		}
	}

	int FindDoc(string a)
	{
		Node<Doctor>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_DrID() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currIndex;
		return 0;
	}

	int DeleteDoc(string a)
	{
		Node<Doctor>* prevNode = NULL;
		Node<Doctor>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_DrID() != a) {
			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;
			}
			return currIndex;
		}
		return 0;
	}

	void DisplayList(void)
	{
		int num = 0;
		Node<Doctor>* currNode = head;
		while (currNode != NULL) {
			cout << "Doctor No." << (num + 1) << "\n";
			currNode->data.display_info();
			cout << "\n";
			currNode = currNode->next;
			num++;
		}
		cout << "Number of doctors in the system: " << num << endl;
	}

	string FindSDoc(string a)
	{
		Node<Doctor>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_DrS() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currNode->data.get_DrN();
		return "NULL";
	}

	Node<Doctor>* searchDocNode(string a)
	{
		Node<Doctor>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_DrID() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currNode;
		return NULL;
	}
};

class Pa_List {
private:
	Node<Patient>* head;

public:

	Pa_List(void)
	{
		head = NULL;
	}

	~Pa_List(void)
	{
		Node<Patient>* currNode = head;
		Node<Patient>* nextNode = NULL;
		while (currNode != NULL) {
			nextNode = currNode->next;
			delete currNode; // destroy the current node
			currNode = nextNode;
		}
	}

	bool IsEmpty()
	{
		return head == NULL;
	}

	void InsertPat(Patient a)
	{
		Node<Patient>* newNode = new Node<Patient>;
		Node<Patient>* currNode = head;
		newNode->data.set_PaID(a.get_PaID());
		newNode->data.set_PaName(a.get_PaName());
		newNode->data.set_PaType(a.get_PaType());
		newNode->data.set_PaPhone(a.get_PaPhone());
		newNode->data.set_PaAddress(a.get_PaAddress());
		newNode->data.set_PaDiagnose(a.get_PaDiagnose());
		for (int i = 0; i < 10; i++)
		{
			newNode->data.set_PaDisease(a.get_PaDisease(i), i);
		}
		if (currNode == NULL)
		{
			newNode->next = head;
			head = newNode;
		}
		else {
			while (currNode->next != NULL)
				currNode = currNode->next;

			newNode->next = currNode->next;
			currNode->next = newNode;
		}
	}

	int FindPat(string a)
	{
		Node<Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currIndex;
		return 0;
	}

	int DeletePat(string a)
	{
		Node<Patient>* prevNode = NULL;
		Node<Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;
			}
			return currIndex;
		}
		return 0;
	}

	void DisplayList(void)
	{
		int num = 0;
		Node<Patient>* currNode = head;
		while (currNode != NULL) {
			cout << "Patient No." << (num + 1) << "\n";
			currNode->data.display_info();
			cout << "\n";
			currNode = currNode->next;
			num++;
		}
		if (num == 0)
			cout << "Not Found noraml patients!!!\n";
		else
			cout << "Number of normal patients in the system: " << num << endl;
	}

	Node<Patient>* searchPatNode(string a)
	{
		Node<Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currNode;
		return NULL;
	}

};

class EmPa_List {
private:
	Node<Emergency_Patient>* head;

public:

	EmPa_List(void)
	{
		head = NULL;
	}

	~EmPa_List(void)
	{
		Node<Emergency_Patient>* currNode = head;
		Node<Emergency_Patient>* nextNode = NULL;
		while (currNode != NULL) {
			nextNode = currNode->next;
			delete currNode; // destroy the current node
			currNode = nextNode;
		}
	}

	bool IsEmpty()
	{
		return head == NULL;
	}

	void InsertEmPa(Emergency_Patient a)
	{
		Node<Emergency_Patient>* newNode = new Node<Emergency_Patient>;
		Node<Emergency_Patient>* currNode = head;
		newNode->data.set_PaID(a.get_PaID());
		newNode->data.set_PaName(a.get_PaName());
		newNode->data.set_PaType(a.get_PaType());
		newNode->data.set_PaPhone(a.get_PaPhone());
		newNode->data.set_PaAddress(a.get_PaAddress());
		newNode->data.set_PaDiagnose(a.get_PaDiagnose());
		for (int i = 0; i < 10; i++)
		{
			newNode->data.set_PaDisease(a.get_PaDisease(i), i);
		}
		newNode->data.set_GPdiagnose(a.get_GPdiagnose());
		if (currNode == NULL)
		{
			newNode->next = head;
			head = newNode;
		}
		else {
			while (currNode->next != NULL)
				currNode = currNode->next;

			newNode->next = currNode->next;
			currNode->next = newNode;
		}
	}

	int FindEmPa(string a)
	{
		Node<Emergency_Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currIndex;
		return 0;
	}

	int DeleteEmPa(string a)
	{
		Node<Emergency_Patient>* prevNode = NULL;
		Node<Emergency_Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;
			}
			return currIndex;
		}
		return 0;
	}

	void DisplayList(void)
	{
		int num = 0;
		Node<Emergency_Patient>* currNode = head;
		while (currNode != NULL) {
			cout << "Patient No." << (num + 1) << "\n";
			currNode->data.display_info();
			cout << "\n";
			currNode = currNode->next;
			num++;
		}
		if (num == 0)
			cout << "Not Found emergency cases!!!\n";
		else
			cout << "Number of Emergency cases in the system: " << num << endl;
	}

	Node<Emergency_Patient>* searchEmPaNode(string a)
	{
		Node<Emergency_Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currNode;
		return NULL;
	}

};

class ChPa_List {
private:
	Node<Chronic_Patient>* head;

public:

	ChPa_List(void)
	{
		head = NULL;
	}

	~ChPa_List(void)
	{
		Node<Chronic_Patient>* currNode = head;
		Node<Chronic_Patient>* nextNode = NULL;
		while (currNode != NULL) {
			nextNode = currNode->next;
			delete currNode; // destroy the current node
			currNode = nextNode;
		}
	}

	bool IsEmpty()
	{
		return head == NULL;
	}

	void InsertChPa(Chronic_Patient a)
	{
		Node<Chronic_Patient>* newNode = new Node<Chronic_Patient>;
		Node<Chronic_Patient>* currNode = head;
		newNode->data.set_PaID(a.get_PaID());
		newNode->data.set_PaName(a.get_PaName());
		newNode->data.set_PaType(a.get_PaType());
		newNode->data.set_PaPhone(a.get_PaPhone());
		newNode->data.set_PaAddress(a.get_PaAddress());
		newNode->data.set_PaDiagnose(a.get_PaDiagnose());
		for (int i = 0; i < 10; i++)
		{
			newNode->data.set_PaDisease(a.get_PaDisease(i), i);
		}
		newNode->data.set_monthMedicInquire(a.get_monthMedicInquire());
		if (currNode == NULL)
		{
			newNode->next = head;
			head = newNode;
		}
		else {
			while (currNode->next != NULL)
				currNode = currNode->next;

			newNode->next = currNode->next;
			currNode->next = newNode;
		}
	}

	int FindChPa(string a)
	{
		Node<Chronic_Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currIndex;
		return 0;
	}

	int DeleteChPa(string a)
	{
		Node<Chronic_Patient>* prevNode = NULL;
		Node<Chronic_Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;
			}
			return currIndex;
		}
		return 0;
	}

	void DisplayList(void)
	{
		int num = 0;
		Node<Chronic_Patient>* currNode = head;
		while (currNode != NULL) {
			cout << "Patient No." << (num + 1) << "\n";
			currNode->data.display_info();
			cout << "\n";
			currNode = currNode->next;
			num++;
		}
		if (num == 0)
			cout << "Not Found chronic patients!!!\n";
		else
			cout << "Number of Chronic patients in the system: " << num << endl;
	}

	Node<Chronic_Patient>* searchChPaNode(string a)
	{
		Node<Chronic_Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currNode;
		return NULL;
	}

};

class AcPa_List {
private:
	Node<Acute_Patient>* head;

public:

	AcPa_List(void)
	{
		head = NULL;
	}

	~AcPa_List(void)
	{
		Node<Acute_Patient>* currNode = head;
		Node<Acute_Patient>* nextNode = NULL;
		while (currNode != NULL) {
			nextNode = currNode->next;
			delete currNode; // destroy the current node
			currNode = nextNode;
		}
	}

	bool IsEmpty()
	{
		return head == NULL;
	}

	void InsertAcPa(Acute_Patient a)
	{
		Node<Acute_Patient>* newNode = new Node<Acute_Patient>;
		Node<Acute_Patient>* currNode = head;
		newNode->data.set_PaID(a.get_PaID());
		newNode->data.set_PaName(a.get_PaName());
		newNode->data.set_PaType(a.get_PaType());
		newNode->data.set_PaPhone(a.get_PaPhone());
		newNode->data.set_PaAddress(a.get_PaAddress());
		newNode->data.set_PaDiagnose(a.get_PaDiagnose());
		for (int i = 0; i < 10; i++)
		{
			newNode->data.set_PaDisease(a.get_PaDisease(i), i);
		}
		newNode->data.set_InterRate(a.get_InterRate());
		newNode->data.set_LoanDuar(a.get_LoanDuar());
		newNode->data.set_PrinAmount(a.get_PrinAmount());
		if (currNode == NULL)
		{
			newNode->next = head;
			head = newNode;
		}
		else {
			while (currNode->next != NULL)
				currNode = currNode->next;

			newNode->next = currNode->next;
			currNode->next = newNode;
		}
	}

	int FindAcPa(string a)
	{
		Node<Acute_Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currIndex;
		return 0;
	}

	int DeleteAcPa(string a)
	{
		Node<Acute_Patient>* prevNode = NULL;
		Node<Acute_Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;
			}
			return currIndex;
		}
		return 0;
	}

	void DisplayList(void)
	{
		int num = 0;
		Node<Acute_Patient>* currNode = head;
		while (currNode != NULL) {
			cout << "Patient No." << (num + 1) << "\n";
			currNode->data.display_info();
			cout << "\n";
			currNode = currNode->next;
			num++;
		}
		if (num == 0)
			cout << "Not Found acute patients!!!\n";
		else
			cout << "Number of Acute patients in the system: " << num << endl;
	}

	Node<Acute_Patient>* searchAcPaNode(string a)
	{
		Node<Acute_Patient>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data.get_PaID() != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currNode;
		return NULL;
	}

};

class scan_test
{
private:
	Node<string>* head;
public:
	scan_test(void)
	{
		head = NULL;
	}

	~scan_test(void)
	{
		Node<string>* currNode = head;
		Node<string>* nextNode = NULL;
		while (currNode != NULL) {
			nextNode = currNode->next;
			delete currNode; // destroy the current node
			currNode = nextNode;
		}
	}

	bool IsEmpty()
	{
		return head == NULL;
	}

	void InsertSacn(string a)
	{
		Node<string>* newNode = new Node<string>;
		Node<string>* currNode = head;
		newNode->data = a;
		if (currNode == NULL)
		{
			newNode->next = head;
			head = newNode;
		}
		else {
			while (currNode->next != NULL)
				currNode = currNode->next;

			newNode->next = currNode->next;
			currNode->next = newNode;
		}
	}

	int DeleteDoc(string a)
	{
		Node<string>* prevNode = NULL;
		Node<string>* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data != a) {
			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;
			}
			return currIndex;
		}
		return 0;
	}

	void DisplayList(void)
	{
		int num = 0;
		Node<string>* currNode = head;
		while (currNode != NULL) {
			cout << "scan No." << (num + 1) << "\n";
			cout << currNode->data;
			cout << "\n";
			currNode = currNode->next;
			num++;
		}
		cout << "Number of scans in the system: " << num << endl;
	}

	string FindDoc(int a)
	{
		Node<string>* currNode = head;
		int currIndex = 1;
		while (currNode && currIndex != a) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currNode->data;
		return "null";
	}

};

Dr_List doctors;
Pa_List patients;
EmPa_List Em_patient;
ChPa_List Ch_patient;
AcPa_List Ac_patient;

scan_test scans;


string reply;
int Pa_ChPa_AcPa = 0;

map<string, string>tests; 

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
	cout << "------------------------------------------------";
	SetConsoleTextAttribute(h, 5);
	cout << "  4- Edit a patient info\n";
	////////////////////////////////////////////////line 3//////////////////////////////////////////////////
	SetConsoleTextAttribute(h, 6);
	cout << "\t5- Deleting a doctor info   ";
	SetConsoleTextAttribute(h, 96);
	cout << "------------------------------------------------";
	SetConsoleTextAttribute(h, 6);
	cout << "  6- Deleting a Patient info\n";
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
	/////////////////////////////////////////////line 7///////////////////////////////////////////////////////
	SetConsoleTextAttribute(h, 3);
	cout << "\t\t\t\t\t 13- Show scans and tests for patients     ";

	SetConsoleTextAttribute(h, 1);
	cout << "\nEnter your choice : ";
	SetConsoleTextAttribute(h, 7);
	cin >> reply;

}

void next_step(string ID)
{
	string Mtest;
	int no_su = 0, no_te = 0, no_sc = 0, no_ph = 0; //the number of the operations or tests or........
	string ns;
	SetConsoleTextAttribute(h, 11);
	cout << "\nThe next step.......\n";
re_step1:
	SetConsoleTextAttribute(h, 7);
	cout << "1-Carrying out a surgery --- 2-Medical test or scan --- 3-Pharmacy --- 4-Nothing\n";
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
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the name of the test or sacn : ";
		SetConsoleTextAttribute(h, 6);
		getline(cin, Mtest);
		scans.InsertSacn(Mtest);
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nData has been sent to the tests lab !!!\n";
		no_te++;
	}
	else if (ns == "3")
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
	else if (ns == "4")
	{
	}
	else
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\nError\n\n";
		goto re_step1;
	}


	if (ns == "1" || ns == "2" || ns == "3" || ns == "4")
	{
		
			SetConsoleTextAttribute(h, 8);
			cout << "\n";
			for (int i = 0; i < no_su; i++)
			{
				cout << "Surgery no." << i + 1 << " has been successfully !! \n";
			}
			for (int i = 0; i < no_te; i++)
			{
				cout << "Test or scan no." << i + 1 << " has been successfully !! \n";
			}
			for (int i = 0; i < no_ph; i++)
			{
				cout << "Medication no." << i + 1 << " has been dispensed successfully !! \n";
			}
		
	}


	if (no_te == 0)
	{
		scans.InsertSacn("NULL");
		tests.insert({ID,"NULL"});
	}
	else
		tests.insert({ ID,Mtest });


}

Patient pa; Chronic_Patient Cpa; Acute_Patient Apa;

void spec_Dr(string ID)
{
	string sd, d;
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
		if (doctors.FindSDoc("Ophthalmologist") != "NULL")
		{
			SetConsoleTextAttribute(h, 10);
			cout << "\t\t\t\t\t   (----Ophthalmology Clinic----)\n";
			SetConsoleTextAttribute(h, 6);
			cout << "Dr." << doctors.FindSDoc("Ophthalmologist") << "\n";
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
		}
	}
	else if (sd == "2")
	{
	re_int:
		system("cls");
		if (doctors.FindSDoc("Internist") != "NULL")
		{
			SetConsoleTextAttribute(h, 10);
			cout << "\t\t\t\t\t   (----Internology Clinic----)\n";
			SetConsoleTextAttribute(h, 6);
			cout << "Dr." << doctors.FindSDoc("Internist") << "\n";
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
		}
	}
	else if (sd == "3")
	{
	re_neu:
		system("cls");
		if (doctors.FindSDoc("Neurologist") != "NULL")
		{
			SetConsoleTextAttribute(h, 10);
			cout << "\t\t\t\t\t   (----Neurology Clinic----)\n";
			SetConsoleTextAttribute(h, 6);
			cout << "Dr." << doctors.FindSDoc("Neurologist") << "\n";
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
		}
	}
	else if (sd == "4")
	{
	re_orth:
		system("cls");
		if (doctors.FindSDoc("Orthopedist") != "NULL")
		{
			SetConsoleTextAttribute(h, 10);
			cout << "\t\t\t\t\t   (----Orthopedogy Clinic----)\n";
			SetConsoleTextAttribute(h, 6);
			cout << "Dr." << doctors.FindSDoc("Orthopedist") << "\n";
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
		}
	}
	else if (sd == "5")
	{
		system("cls");
		if (doctors.FindSDoc("General Doctor") != "NULL")
		{
			SetConsoleTextAttribute(h, 10);
			cout << "\t\t\t\t\t\t  (---GP Clinic----)\n";
			SetConsoleTextAttribute(h, 6);
			cout << "Dr." << doctors.FindSDoc("General Doctor") << "\n";
			SetConsoleTextAttribute(h, 7);
			cout << "-------------------------------------------------------------------------------------------------------------------\n";
			testOfdoctor++;
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
			pa.set_PaDiagnose(d);
		}
		else if (Pa_ChPa_AcPa == 2)
		{
			Cpa.set_PaDiagnose(d);
		}
		else if (Pa_ChPa_AcPa == 3)
		{
			Apa.set_PaDiagnose(d);
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
				pa.set_PaDisease(dis, dis_count);
			}
			else if (Pa_ChPa_AcPa == 2)
			{
				Cpa.set_PaDisease(dis, dis_count);
			}
			else if (Pa_ChPa_AcPa == 3)
			{
				Apa.set_PaDisease(dis, dis_count);
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
			next_step(ID);
		}
		else
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nError\n";
			goto re_dis;
		}

		if (chos_dis == "1")
		{
			next_step(ID);
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
	string id, n, s;
	Doctor d;
	SetConsoleTextAttribute(h, 11);
	cout << "Enter the ID : ";
    reID_Dr:
	SetConsoleTextAttribute(h, 6);
	cin >> id;

	if (doctors.FindDoc(id) > 0)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\nThis ID is already exist!!\n";
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter another ID : ";
		goto reID_Dr;
	}
	d.set_DrID(id);
	cin.ignore();
	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Name : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, n);
	d.set_DrName(n);
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
		d.set_DrS("Ophthalmologist");
	}
	else if (spec == "2")
	{
		d.set_DrS("Internist");
	}
	else if (spec == "3")
	{
		d.set_DrS("Neurologist");
	}
	else if (spec == "4")
	{
		d.set_DrS("Orthopedist");
	}
	else if (spec == "5")
	{
		d.set_DrS("General Doctor");
	}
	else
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\nError\n\n";
		goto re_spec;
	}
	doctors.InsertDoc(d);
	SetConsoleTextAttribute(h, 4);
	cout << "\n\n--Data has been added !!!--\n";
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
	if (patients.FindPat(id) > 0)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\nThis ID is already exist!!\n";
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter another ID : ";
		goto reID_Pa;
	}
	pa.set_PaID(id);
	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Name : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, n);
	pa.set_PaName(n);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Address : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, a);
	pa.set_PaAddress(a);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Phone Number : ";
	SetConsoleTextAttribute(h, 6);
	cin >> p;
	pa.set_PaPhone(p);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Type : ";
	SetConsoleTextAttribute(h, 6);
	cin >> t;
	cin.ignore();
	pa.set_PaType(t);

	spec_Dr(id);
	patients.InsertPat(pa);
}

Emergency_Patient ep;
void add_EmPa()
{
	int testOfdoctor = 0;
	system("cls");
	if (doctors.FindSDoc("General Doctor") != "NULL")
	{
		SetConsoleTextAttribute(h, 10);
		cout << "\t\t\t\t\t\t  (---GP Clinic----)\n";
		SetConsoleTextAttribute(h, 6);
		cout << "Dr." << doctors.FindSDoc("General Doctor") << "\n";
		SetConsoleTextAttribute(h, 7);
		cout << "-------------------------------------------------------------------------------------------------------------------\n";
		testOfdoctor++;
	}

	if (testOfdoctor > 0)
	{
		string reply, initial_diagnose;
		cin.ignore();
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the Initial Diagnose :";
		SetConsoleTextAttribute(h, 6);
		getline(cin, initial_diagnose);
		ep.set_GPdiagnose(initial_diagnose);
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
		if (Em_patient.FindEmPa(id) > 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nThis ID is already exist!!\n";
			SetConsoleTextAttribute(h, 11);
			cout << "\nEnter another ID : ";
			goto reID_Pa;
		}
		ep.set_PaID(id);
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the Name : ";
		SetConsoleTextAttribute(h, 6);
		getline(cin, n);
		ep.set_PaName(n);

		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the Address : ";
		SetConsoleTextAttribute(h, 6);
		getline(cin, a);
		ep.set_PaAddress(a);

		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the Phone Number : ";
		SetConsoleTextAttribute(h, 6);
		cin >> p;
		ep.set_PaPhone(p);

		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter the Type : ";
		SetConsoleTextAttribute(h, 6);
		cin >> t;
		ep.set_PaType(t);

		int testOfdoctor2 = 0;
		if (reply == "1")
		{
			system("cls");

			if (doctors.FindSDoc("Ophthalmologist") != "NULL")
			{
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t\t   (----Ophthalmology Clinic----)\n";
				SetConsoleTextAttribute(h, 6);
				cout << "Dr." << doctors.FindSDoc("Ophthalmologist") << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";

				cout << "The GP diagnose : ";
				SetConsoleTextAttribute(h, 5);
				cout << ep.get_GPdiagnose() << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";

				testOfdoctor2++;
			}

		}
		else if (reply == "2")
		{
			system("cls");

			if (doctors.FindSDoc("Internist") != "NULL")
			{
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t\t   (----Internology Clinic----)\n";
				SetConsoleTextAttribute(h, 6);
				cout << "Dr." << doctors.FindSDoc("Internist") << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";

				cout << "The GP diagnose : ";
				SetConsoleTextAttribute(h, 5);
				cout << ep.get_GPdiagnose() << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";

				testOfdoctor2++;
			}
		}
		else if (reply == "3")
		{
			system("cls");
			if (doctors.FindSDoc("Neurologist") != "NULL")
			{
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t\t   (----Neurology Clinic----)\n";
				SetConsoleTextAttribute(h, 6);
				cout << "Dr." << doctors.FindSDoc("Neurologist") << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";

				cout << "The GP diagnose : ";
				SetConsoleTextAttribute(h, 5);
				cout << ep.get_GPdiagnose() << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";

				testOfdoctor2++;
			}
		}
		else if (reply == "4")
		{
			system("cls");
			if (doctors.FindSDoc("Orthopedist") != "NULL")
			{
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t\t   (----Orthopedogy Clinic----)\n";
				SetConsoleTextAttribute(h, 6);
				cout << "Dr." << doctors.FindSDoc("Orthopedist") << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";

				cout << "The GP diagnose : ";
				SetConsoleTextAttribute(h, 5);
				cout << ep.get_GPdiagnose() << "\n";
				SetConsoleTextAttribute(h, 7);
				cout << "-------------------------------------------------------------------------------------------------------------------\n";

				testOfdoctor2++;
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
			ep.set_PaDiagnose(d);

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
				ep.set_PaDisease(dis, dis_count);
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
				next_step(id);
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nError\n";
				goto re_dis;
			}

			if (chos_dis == "1")
			{
				next_step(id);
			}
		}
		Em_patient.InsertEmPa(ep);
	}

	else
	{
		SetConsoleTextAttribute(h, 4);
		cout << "There is no GP doctor recorded in the system !!\n\n";
	}

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
	if (Ch_patient.FindChPa(id) > 0)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\nThis ID is already exist!!\n";
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter another ID : ";
		goto reID_Pa;
	}
	Cpa.set_PaID(id);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Name : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, n);
	Cpa.set_PaName(n);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Address : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, a);
	Cpa.set_PaAddress(a);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Phone Number : ";
	SetConsoleTextAttribute(h, 6);
	cin >> p;
	Cpa.set_PaPhone(p);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Type : ";
	SetConsoleTextAttribute(h, 6);
	cin >> t;
	cin.ignore();
	Cpa.set_PaType(t);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Monthly Medication Inquire : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, mmi);
	Cpa.set_monthMedicInquire(mmi);

	spec_Dr(id);
	Ch_patient.InsertChPa(Cpa);
}

void add_AcPa()
{
	system("cls");
	Pa_ChPa_AcPa = 3;
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t    (-----Adding Acute Patients------)\n";
	string id, n, a, p, t, pa, ir, ld;
	SetConsoleTextAttribute(h, 11);
	cout << "Enter the ID : ";
reID_Pa:
	SetConsoleTextAttribute(h, 6);
	cin >> id;
	cin.ignore();
	if (Ac_patient.FindAcPa(id) > 0)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\nThis ID is already exist!!\n";
		SetConsoleTextAttribute(h, 11);
		cout << "\nEnter another ID : ";
		goto reID_Pa;
	}
	Apa.set_PaID(id);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Name : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, n);
	Apa.set_PaName(n);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Address : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, a);
	Apa.set_PaAddress(a);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Phone Number : ";
	SetConsoleTextAttribute(h, 6);
	cin >> p;
	Apa.set_PaPhone(p);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Type : ";
	SetConsoleTextAttribute(h, 6);
	cin >> t;
	cin.ignore();
	Apa.set_PaType(t);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Principal Amount : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, pa);
	Apa.set_PrinAmount(pa);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Interest Rate : ";
	SetConsoleTextAttribute(h, 6);
	getline(cin, ir);
	Apa.set_InterRate(ir);

	SetConsoleTextAttribute(h, 11);
	cout << "\nEnter the Loan Duration in mounths: ";
	SetConsoleTextAttribute(h, 6);
	cin >> ld;
	Apa.set_LoanDuar(ld);

	spec_Dr(id);
	Ac_patient.InsertAcPa(Apa);
}

void edit_Dr()
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t    (-----Editing Doctors Info-----)\n";
	if (doctors.IsEmpty() == true)
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
		if (doctors.searchDocNode(id) != NULL)
		{
			Node<Doctor>* edit = new Node<Doctor>;
			edit = doctors.searchDocNode(id);
			test++;
			string ans;
			cout << "\n";  edit->data.display_info();
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
				cin >> id; edit->data.set_DrID(id);
			}
			else if (ans == "2")
			{
				string n; cout << "Enter the new Name: ";
				SetConsoleTextAttribute(h, 6);
				getline(cin, n); edit->data.set_DrName(n);
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
					edit->data.set_DrS("Ophthalmologist");
				}
				else if (s == "2")
				{
					edit->data.set_DrS("Internist");
				}
				else if (s == "3")
				{
					edit->data.set_DrS("Neurologist");
				}
				else if (s == "3")
				{
					edit->data.set_DrS("Orthopedist");
				}
				else if (s == "5")
				{
					edit->data.set_DrS("General Doctor");
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
				edit->data.set_DrID(id); cout << "\n";
				SetConsoleTextAttribute(h, 11);
				cout << "Enter the new Name: ";
				SetConsoleTextAttribute(h, 6);
				getline(cin, n); edit->data.set_DrName(n); cout << "\n";
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
					edit->data.set_DrS("Ophthalmologist");
				}
				else if (s == "2")
				{
					edit->data.set_DrS("Internist");
				}
				else if (s == "3")
				{
					edit->data.set_DrS("Neurologist");
				}
				else if (s == "4")
				{
					edit->data.set_DrS("Orthopedist");
				}
				else if (s == "5")
				{
					edit->data.set_DrS("General Doctor");
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
	if (patients.IsEmpty() == true && Em_patient.IsEmpty() == true && Ch_patient.IsEmpty() == true && Ac_patient.IsEmpty() == true)
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
			int test = 0, test2 = 0;
			SetConsoleTextAttribute(h, 11);
			cout << "Enter the ID to search : ";
			SetConsoleTextAttribute(h, 6);
			cin >> id;
			if (patients.searchPatNode(id) != NULL)
			{
				test++;
				string ans;
				Node<Patient>* edit = new Node<Patient>;
				edit = patients.searchPatNode(id);
				cout << "\n"; edit->data.display_info();
				SetConsoleTextAttribute(h, 11);
				cout << "\n\t\t\t\t\t   What thing do you want to edit ?\n";
			re_chosData4:
				SetConsoleTextAttribute(h, 7);
				if (edit->data.get_PaDisease(0) == "000")
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
					cin >> id; edit->data.set_PaID(id);
				}
				else if (ans == "2")
				{
					string n; cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, n); edit->data.set_PaName(n);
				}
				else if (ans == "3")
				{
					cin.ignore();
					string a; cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, a); edit->data.set_PaAddress(a);
				}
				else if (ans == "4")
				{
					string p; cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; edit->data.set_PaPhone(p);
				}
				else if (ans == "5")
				{
					string t; cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; edit->data.set_PaType(t);
				}
				else if (ans == "6")
				{
					string d; cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, d); edit->data.set_PaDiagnose(d);
				}
				else if (ans == "7" && test2 == 2)
				{
					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (edit->data.get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							edit->data.set_PaDisease(dis, j);
							cout << "\n";
						}
					}
				}
				else if (ans == "8" || (ans == "7" && test2 == 1))
				{
					string id, n, a, p, t, d;
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; edit->data.set_PaID(id); cout << "\n";


					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, n); edit->data.set_PaName(n); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, a); edit->data.set_PaAddress(a); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; edit->data.set_PaPhone(p); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; edit->data.set_PaType(t); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, d); edit->data.set_PaDiagnose(d); cout << "\n";

					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (edit->data.get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							edit->data.set_PaDisease(dis, j);
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

			if (test == 0)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nThis ID is not found in the System !!!\n";
			}
		}
		else if (type_pa == "2")
		{
			string id;
			int test = 0, test2 = 0;
			SetConsoleTextAttribute(h, 11);
			cout << "Enter the ID to search : ";
			SetConsoleTextAttribute(h, 6);
			cin >> id;
			if (Ch_patient.searchChPaNode(id) != NULL)
			{
				test++;
				string ans;
				Node<Chronic_Patient>* edit = new Node<Chronic_Patient>;
				edit = Ch_patient.searchChPaNode(id);
				cout << "\n";
				edit->data.display_info();
				SetConsoleTextAttribute(h, 11);
				cout << "\n\t\t\t\t\t   What thing do you want to edit ?\n";
			re_chosData5:
				SetConsoleTextAttribute(h, 7);
				if (edit->data.get_PaDisease(0) == "000")
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
					cin >> id; edit->data.set_PaID(id);
				}
				else if (ans == "2")
				{
					string n; cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, n); edit->data.set_PaName(n);
				}
				else if (ans == "3")
				{
					string a; cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, a); edit->data.set_PaAddress(a);
				}
				else if (ans == "4")
				{
					string p; cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; edit->data.set_PaPhone(p);
				}
				else if (ans == "5")
				{
					string t; cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; edit->data.set_PaType(t);
				}
				else if (ans == "6")
				{
					string d; cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, d); edit->data.set_PaDiagnose(d);
				}
				else if (ans == "7" && test2 == 2)
				{
					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (edit->data.get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							edit->data.set_PaDisease(dis, j);
							cout << "\n";
						}
					}
				}
				else if (ans == "8" && test2 == 2 || ans == "7" && test == 1)
				{
					string mmi; cout << "Enter the new Monthly Medication Inquire: ";
					SetConsoleTextAttribute(h, 6);
					cin >> mmi; edit->data.set_monthMedicInquire(mmi);
				}
				else if (ans == "9" && test2 == 2 || ans == "8" && test2 == 1)
				{
					string id, n, a, p, t, d, mmi;
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; edit->data.set_PaID(id); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, n); edit->data.set_PaName(n); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, a); edit->data.set_PaAddress(a); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; edit->data.set_PaPhone(p); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; edit->data.set_PaType(t); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					cin >> d; edit->data.set_PaDiagnose(d); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new 8-Monthly Medication Inquire: ";
					SetConsoleTextAttribute(h, 6);
					cin >> mmi; edit->data.set_monthMedicInquire(mmi); cout << "\n";

					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (edit->data.get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							edit->data.set_PaDisease(dis, j);
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

			if (test == 0)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nThis ID is not found in the System !!!\n";
			}
		}
		else if (type_pa == "3")
		{
			string id;
			int test = 0, test2 = 0;
			SetConsoleTextAttribute(h, 11);
			cout << "Enter the ID to search : ";
			SetConsoleTextAttribute(h, 6);
			cin >> id;
			if (Ac_patient.searchAcPaNode(id) != NULL)
			{
				test++;
				string ans;
				Node<Acute_Patient>* edit = new Node<Acute_Patient>;
				edit = Ac_patient.searchAcPaNode(id);
				cout << "\n"; edit->data.display_info();
				SetConsoleTextAttribute(h, 11);
				cout << "\n\t\t\t\t\t   What thing do you want to edit ?\n";
			re_chosData6:
				SetConsoleTextAttribute(h, 7);
				if (edit->data.get_PaDisease(0) == "000")
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
					cin >> id; edit->data.set_PaID(id);
				}
				else if (ans == "2")
				{
					string n; cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, n); edit->data.set_PaName(n);
				}
				else if (ans == "3")
				{
					string a; cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, a); edit->data.set_PaAddress(a);
				}
				else if (ans == "4")
				{
					string p; cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; edit->data.set_PaPhone(p);
				}
				else if (ans == "5")
				{
					string t; cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; edit->data.set_PaType(t);
				}
				else if (ans == "6")
				{
					string d; cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, d); edit->data.set_PaDiagnose(d);
				}
				else if (ans == "7" && test2 == 2)
				{
					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (edit->data.get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							edit->data.set_PaDisease(dis, j);
							cout << "\n";
						}
					}

				}
				else if (ans == "7" && test2 == 1 || ans == "8" && test2 == 2)
				{
					string pa; cout << "Enter the new Principal Amount: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, pa); edit->data.set_PrinAmount(pa);
				}
				else if (ans == "8" && test2 == 1 || ans == "9" && test2 == 2)
				{
					string ir; cout << "Enter the new Interest Rate: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, ir); edit->data.set_InterRate(ir);
				}
				else if (ans == "9" && test2 == 1 || ans == "10" && test2 == 2)
				{
					string ld; cout << "Enter the new Loan Duration: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, ld); edit->data.set_LoanDuar(ld);
				}
				else if (ans == "10" && test2 == 1 || ans == "11" && test2 == 2)
				{
					string id, n, a, p, t, d, pa, ir, ld;
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; edit->data.set_PaID(id); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, n); edit->data.set_PaName(n); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, a); edit->data.set_PaAddress(a); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; edit->data.set_PaPhone(p); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; edit->data.set_PaType(t); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, d); edit->data.set_PaDiagnose(d); cout << "\n";

					cout << "Enter the new Principal Amount: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, pa); edit->data.set_PrinAmount(pa); cout << "\n";

					cout << "Enter the new Interest Rate: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, ir); edit->data.set_InterRate(ir); cout << "\n";

					cout << "Enter the new Loan Duration: "; cout << "\n";
					SetConsoleTextAttribute(h, 6);
					getline(cin, ld); edit->data.set_LoanDuar(ld);

					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (edit->data.get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							edit->data.set_PaDisease(dis, j);
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
	
			if (test == 0)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nThis ID is not found in the System !!!\n";
			}
		}
		else if (type_pa == "4")
		{
			string id;
			int test = 0, test2 = 0;
			SetConsoleTextAttribute(h, 11);
			cout << "Enter the ID to search : ";
			SetConsoleTextAttribute(h, 6);
			cin >> id;
			if (Em_patient.searchEmPaNode(id) != NULL)
			{
				test++;
				string ans;
				Node<Emergency_Patient>* edit = new Node<Emergency_Patient>;
				edit = Em_patient.searchEmPaNode(id);
				cout << "\n"; edit->data.display_info();
				SetConsoleTextAttribute(h, 11);
				cout << "\n\t\t\t\t\t   What thing do you want to edit ?\n";
			re_chosData7:
				SetConsoleTextAttribute(h, 7);
				if (edit->data.get_PaDisease(0) == "000")
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
					cin >> id; edit->data.set_PaID(id);
				}
				else if (ans == "2")
				{
					string n; cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, n); edit->data.set_PaName(n);
				}
				else if (ans == "3")
				{
					string a; cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, a); edit->data.set_PaAddress(a);
				}
				else if (ans == "4")
				{
					string p; cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; edit->data.set_PaPhone(p);
				}
				else if (ans == "5")
				{
					string t; cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; edit->data.set_PaType(t);
				}
				else if (ans == "6")
				{
					string gpd; cout << "Enter the new GP-Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, gpd); edit->data.set_GPdiagnose(gpd);
				}
				else if (ans == "7")
				{
					string d; cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, d); edit->data.set_PaDiagnose(d);
				}
				else if (ans == "8" && test2 == 2)
				{
					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (edit->data.get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							edit->data.set_PaDisease(dis, j);
							cout << "\n";
						}
					}
				}
				else if (ans == "8" && test2 == 1 || ans == "9" && test2 == 2)
				{
					string id, n, a, p, t, d, gpd;
					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new ID: ";
					SetConsoleTextAttribute(h, 6);
					cin >> id; edit->data.set_PaID(id); cout << "\n";


					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Name: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, n); edit->data.set_PaName(n); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Address: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, a); edit->data.set_PaAddress(a); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Phone Number: ";
					SetConsoleTextAttribute(h, 6);
					cin >> p; edit->data.set_PaPhone(p); cout << "\n";

					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Type: ";
					SetConsoleTextAttribute(h, 6);
					cin >> t; edit->data.set_PaType(t); cout << "\n";


					SetConsoleTextAttribute(h, 11);
					cout << "Enter the new Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					cin.ignore();
					getline(cin, d); edit->data.set_PaDiagnose(d); cout << "\n";

					cout << "Enter the new GP-Diagnose: ";
					SetConsoleTextAttribute(h, 6);
					getline(cin, gpd); edit->data.set_GPdiagnose(gpd); cout << "\n";

					string dis;

					for (int j = 0; j < 10; j++)
					{
						if (edit->data.get_PaDisease(j) != "000")
						{
							SetConsoleTextAttribute(h, 11);
							cout << "Enter the new Disease no." << j + 1 << " : ";
							SetConsoleTextAttribute(h, 6);
							cin.ignore();
							getline(cin, dis);
							edit->data.set_PaDisease(dis, j);
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
	if (doctors.IsEmpty() == true)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any doctor !!\n";
	}
	else {
		int test = 0, test2 = 0;
		string id;
		SetConsoleTextAttribute(h, 11);
		cout << "Enter the ID to search : ";
		SetConsoleTextAttribute(h, 6);
		cin >> id;
		if (doctors.searchDocNode(id) != NULL)
		{
			test++;
			Node<Doctor>* edit = new Node<Doctor>;
			edit = doctors.searchDocNode(id);
			cout << "\n"; edit->data.display_info();
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
				doctors.DeleteDoc(id);
			}
			else if (ans == "2")
			{
				test2++;
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nError\n\n";
				goto re_chosYesNo;
			}
		}

		SetConsoleTextAttribute(h, 4);
		if (test == 0)
			cout << "\nThis ID is not found in the System !!!\n";
		else if (test2 == 0)
			cout << "\n--Data has been deleted !!--";
	}
}

void delete_Pa()
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t   (-----Deleting Patients Info-----)\n";
	if (patients.IsEmpty() == true && Em_patient.IsEmpty() == true && Ch_patient.IsEmpty() == true && Ac_patient.IsEmpty() == true)
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
			if (patients.searchPatNode(id) != NULL)
			{
				test++;
				cout << "\n"; patients.searchPatNode(id)->data.display_info();
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
					patients.DeletePat(id);
				}
				else if (ans == "2")
				{
					test2++;
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosYesNo2;
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
			if (Ch_patient.searchChPaNode(id) != NULL)
			{
				test++;
				cout << "\n"; Ch_patient.searchChPaNode(id)->data.display_info();
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
					Ch_patient.DeleteChPa(id);
				}
				else if (ans == "2")
				{
					test2++;
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosYesNo3;
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
			if (Ac_patient.searchAcPaNode(id) != NULL)
			{
				test++;
				cout << "\n"; Ac_patient.searchAcPaNode(id)->data.display_info();
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
					Ac_patient.DeleteAcPa(id);
				}
				else if (ans == "2")
				{
					test2++;
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosYesNo4;
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
			if (Em_patient.searchEmPaNode(id) != NULL)
			{
				test++;
				cout << "\n"; Em_patient.searchEmPaNode(id)->data.display_info();
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
					Em_patient.DeleteEmPa(id);
				}
				else if (ans == "2")
				{
					test2++;
				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << "\nError\n\n";
					goto re_chosYesNo5;
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
	if (doctors.IsEmpty() == true)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any doctor !!\n";
	}
	else
	{
		doctors.DisplayList();
	}
}

void list_Pa()
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t   (-----The list of Patients-----)\n";

	if (patients.IsEmpty() == true && Ch_patient.IsEmpty() == true && Ac_patient.IsEmpty() == true)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any patient !!\n";
	}
	else
	{
		patients.DisplayList();

		if (Ch_patient.IsEmpty() == false)
		{
			SetConsoleTextAttribute(h, 12);
			cout << "The Chronic patients :\n";
		}
		Ch_patient.DisplayList();

		if (Ac_patient.IsEmpty() == false)
		{
			SetConsoleTextAttribute(h, 12);
			cout << "The Acute patients :\n";
		}
		Ac_patient.DisplayList();

	}
}

void list_EmPa()
{
	system("cls");
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t\t (-----The list of Emergency cases-----)\n";

	if (Em_patient.IsEmpty() == true)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n\nThere is no data recorded in the system for any emergency case !!\n";
	}
	else
	{
		Em_patient.DisplayList();
	}
}

void showScans()
{
	system("cls");
	for (auto tests : tests)
		cout << "ID: " << tests.first << " => " << "scan: " <<tests.second << "\n";
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

		else if (reply == "9") { Readd_EmPat:add_EmPa(); }
		else if (reply == "10") { list_EmPa(); }

		else if (reply == "11") { Readd_ChPat:add_ChPa(); }
		else if (reply == "12") { Readd_AcPat:add_AcPa(); }

		else if (reply == "13") { showScans(); }

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
		else if (reply == "13")
		{
			cout << "\t 1- Add another patient";
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
		else if (reply == "13" && rep == "1")
		{
			goto Readd_Pat;
		}

	} 	
	while (true);

}