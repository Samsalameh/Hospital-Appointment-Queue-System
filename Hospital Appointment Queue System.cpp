#include<iostream>
#include"clsHospitalQueue.h"
using namespace std;
int main()
{
	clsHospitalQueue Cardiology("Cardiology", 15);
	clsHospitalQueue Dental("Dental", 10);

	Cardiology.IssueAppointment("Ahmed");
	Cardiology.IssueAppointment("Ali");
	Cardiology.IssueAppointment("Sara","Emergency");

	Cardiology.QueueInfo();

	Cardiology.PrintAllAppointments();

	Cardiology.PrintQueueRTL();
	Cardiology.PrintQueueLTR();

	cout << "\n\n\n After Serving one Petient : \n";
	Cardiology.ServedPatient();
	Cardiology.QueueInfo();

	Dental.IssueAppointment("Mona");
	Dental.IssueAppointment("Khaled", "Emergency");
	Dental.QueueInfo();
	Dental.PrintAllAppointments();
	Dental.PrintQueueRTL();
	Dental.PrintQueueLTR();
	Dental.ServedPatient();
	Dental.QueueInfo();
	system("pause > 0");
	return 0;

}