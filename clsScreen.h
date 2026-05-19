#pragma once
#include<iostream>
#include<string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;
class clsScreen
{
private:
		static string CurrentDateTime()
		{
			auto now = chrono::system_clock::now();

			time_t now_time =
				chrono::system_clock::to_time_t(now);

			tm localTime;

			localtime_s(&localTime, &now_time);

			stringstream ss;

			ss << put_time(&localTime,
				"%d/%m/%Y - %H:%M:%S");

			return ss.str();
		}
protected:
	enum enScreenType { DepartmentInfo = 0, AppointmentInfo = 1 };

	static void _DrawScreenHeader(enScreenType ScreenType)
	{
		switch (ScreenType)
		{
		case DepartmentInfo:
		{
			cout << "\n\n\n\n\t\t\t\t=============================\n";
			cout << "\n\n\t\t\t\t\tDepartment Info \n";
			cout << "\n\n\t\t\t\t=============================\n";
			cout << "\n\t\t\t\t    "<< CurrentDateTime()<<"\n";
			break;
		}
		case AppointmentInfo:
		{
			cout << "\n\n\n\n\t\t\t\t=============================\n";
			cout << "\n\n\t\t\t\t       Appointment Info \n";
			cout << "\n\n\t\t\t\t=============================\n";
			cout << "\n\t\t\t\t    " << CurrentDateTime() << "\n";

			break;
		}
		}
	}
};

