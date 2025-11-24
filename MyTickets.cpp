 

#include <iostream>
#include "clsQueueLine.h"
using namespace std;
int main()
{
	clsQueueLine PayBills("A0", 5);
	PayBills.IssueTicket();
	PayBills.IssueTicket();
	PayBills.IssueTicket();
	PayBills.IssueTicket();

	PayBills.IssueTicket();
	PayBills.IssueTicket();
	PayBills.IssueTicket();
	PayBills.IssueTicket();
	PayBills.PrintQueueInfo();
	PayBills.PrintQueueInfo();
	PayBills.PrintTicketsLTR();
	PayBills.PrintTicketsRTL();
	PayBills.PrintAllTickets();
}

