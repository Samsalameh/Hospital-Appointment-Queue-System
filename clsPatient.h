#pragma once
#include<iostream>
#include<string>
#include "clsScreen.h"
using namespace std;

class clsPatient: protected clsScreen
{
private:
	string _Prefix;
	string _PatientName;
	bool _EmergencyState = false;
	int _TotalPatients = 0;
	int _ServingTime = 0;
public:
	clsPatient()
	{

	}
	clsPatient(string Prefix, int TotalPatients, string PatientName, int ServingTime, bool EmergencyState = false)
	{
		 _Prefix = Prefix;
		 _TotalPatients = TotalPatients;
		 _PatientName = PatientName;
		 _ServingTime = ServingTime;
		 _EmergencyState = EmergencyState;
	}
	int PatientsCount()
	{
		return  _TotalPatients+1;
	}
	string Number()
	{
		if (_EmergencyState)
			return (_Prefix + to_string(PatientsCount()) + " (Emergency)");
		else
			return (_Prefix + to_string(PatientsCount()));
	}
	string Name()
	{
		return _PatientName;
	}
	int EstimatedWait()
	{
		return _ServingTime ;
	}
	void PrintAppointment()
	{
		clsScreen::_DrawScreenHeader(clsScreen::AppointmentInfo);
		cout << "\n\t\t\t\tNumber		= "<< Number();
		cout << "\n\t\t\t\tPatient		: "<< Name();
		cout << "\n\t\t\t\tEstimated Wait	: "<< EstimatedWait();
	}


};

