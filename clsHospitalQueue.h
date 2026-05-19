#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include"clsPatient.h"

using namespace std;
class clsHospitalQueue:public clsPatient
{
private:

	string _Prefix;
	string _DepName;
	string _PatientState;
	int _ServingTime = 0;
	int _TotalPatients = 0;
	int _ServedPatients = 0;
	int _WaitingPatients = 0;

	queue <clsPatient> PatientQueue;
public:
	clsHospitalQueue(string DepName, int ServingTime)
	{
		_DepName = DepName;
		_ServingTime = ServingTime;

	}
	string Prefix()
	{
		return _DepName[0] + to_string(0);
	}

	int WaitingTime()
	{
		return _ServingTime * _TotalPatients;
	}
	void IssueAppointment(string PatientName)
	{
		_WaitingPatients++;
		clsPatient Patient(Prefix(),_TotalPatients, PatientName, WaitingTime());
		PatientQueue.push(Patient);
		_TotalPatients++;

	}
	void IssueAppointment(string PatientName, string PatientState)
	{
		_WaitingPatients++;
		_PatientState = PatientState;
		clsPatient Patient(Prefix(),_TotalPatients, PatientName, WaitingTime(),true);
		PatientQueue.push(Patient);
		_TotalPatients++;

	}
	void ServedPatient()
	{
		if (!PatientQueue.empty())
		{
			PatientQueue.pop();
			_ServedPatients++;
			_WaitingPatients--;
		}
	}
	void QueueInfo()
	{
		clsPatient::clsScreen::_DrawScreenHeader(clsScreen::DepartmentInfo);
		cout << "\n\t\t\t\tDepartment Name	 = " << _DepName;
		cout << "\n\t\t\t\tPrefix		 = " << Prefix();
		cout << "\n\t\t\t\tTotal Patients	 : " << _TotalPatients;
		cout << "\n\t\t\t\tServed Patients	 : " << _ServedPatients;
		cout << "\n\t\t\t\tWaiting Patients : " << _WaitingPatients;
		cout << "\n\t\t\t\t------------------------------\n\n";
	}
	void PrintAllAppointments()
	{
		queue <clsPatient> TempQueue;
		TempQueue = PatientQueue;

		while (!TempQueue.empty())
		{
			TempQueue.front().PrintAppointment();
			TempQueue.pop();
		}
	}

	void PrintQueueRTL()
	{
		queue <clsPatient> TempQueue;
		TempQueue = PatientQueue;
		cout << "\n\n\n\t\t\t\tQueue RTL : ";
		while (!TempQueue.empty())
		{
			cout <<TempQueue.front().Name()<<" <--- ";
			TempQueue.pop();
		}
	}

	void PrintQueueLTR()
	{
		stack <clsPatient> TempStack;
		queue <clsPatient> TempQueue;
		TempQueue = PatientQueue;
		while (!TempQueue.empty())
		{
			TempStack.push( TempQueue.front());
			TempQueue.pop();
		}
		cout << "\n\n\n\t\t\t\tQueue RTL : ";
		while (!TempStack.empty())
		{
			cout << TempStack.top().Name()<<" ---> ";
			TempStack.pop();
		}
	}
};

