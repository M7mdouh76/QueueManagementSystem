#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include<ctime>	
#include <iomanip>
#pragma warning (disable:4996)
using namespace std;
string GetSystemDateAndTime()
{
	time_t t = time(0);//time now
	tm* now = localtime(&t);
	int day = now->tm_mday;
	int month = (now->tm_mon) + 1;
	int year = (now->tm_year) + 1900;
	int hour = now->tm_hour;
	int sec = now->tm_sec;
	int min = now->tm_mon;
	return to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " - " + to_string(hour) + ":" + to_string(sec) + ":" + to_string(min);
}

class clsQueueLine
{
private:
	short _TotalTickets = 0;
	string _Prefix = "";
	short Avge_Served_Time;
	class clsTicket
	{
	private:
		short Num;
		short AveServedTime;
		short Tickets;
		string Prefix;
		short _waiting;
	public:
		clsTicket(short total_Tickets=0, string prefix="", short ave_served_time=0, short waiting=0)
		{
			Num = total_Tickets;
			Prefix = prefix;
			AveServedTime = ave_served_time;
			Tickets = total_Tickets;
			 _waiting= waiting;
		}
		string FullNumber()
		{
			return Prefix + to_string(Num);
		}
		short Exb_Served_Time()
		{
			return _waiting * AveServedTime;
		}
		void PrintTicket(clsTicket c)
		{
			cout << "\n\t\t\t\t_________________________\n";
			cout << "\t\t\t\t\t" << c.FullNumber() << endl;
			cout << "\t\t\t\t" << GetSystemDateAndTime() << endl;
			cout << "\t\t\t\t Waiting Clients = " << c._waiting << endl;
			cout << "\t\t\t\t  Serve time in\n";
			cout << "\t\t\t\t   " << c.Exb_Served_Time() << " Minutes" << endl;
			cout << "\t\t\t\t_________________________\n";

		}
	};
public:
	queue<clsTicket>queTicket;
	clsQueueLine(string pref, short min)
	{
		_Prefix = pref;
		Avge_Served_Time = min;
	}
	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket C(_TotalTickets, _Prefix, Avge_Served_Time, WaitingTickets());
		queTicket.push(C);
	}
	bool Servrd()
	{
		if (queTicket.empty())
		{
			return false;
		}
		queTicket.pop();
		return true;
	}
	short WaitingTickets()
	{
		return queTicket.size();
	}
	void PrintAllTickets()
	{
		clsTicket client;
		queue<clsTicket>temp = queTicket;
		while (!temp.empty())
		{
			client.PrintTicket(temp.front());
			temp.pop();
		}
	}
	void PrintTicketsLTR()
	{
		clsTicket client;
		queue<clsTicket>temp = queTicket;
		stack<clsTicket>stkTemp;
		cout << "\n" << setw(35) << "Tickets:";
		while (!temp.empty())
		{
			stkTemp.push(temp.front());
			temp.pop();
		}
		while (!stkTemp.empty())
		{
			cout << stkTemp.top().FullNumber() << " --> ";
			stkTemp.pop();
		}
	}
	void PrintTicketsRTL()
	{
		cout << "\n" << setw(35) << "Tickets:";
		clsTicket client;
		queue<clsTicket>temp = queTicket;
		while (!temp.empty())
		{
			cout << temp.front().FullNumber() << " <-- ";
			temp.pop();
		}
		cout << "\n";
	}
	void PrintQueueInfo()
	{
		cout << "\n\t\t\t\t_________________________\n";
		cout << "\n\t\t\t\t   Queue Info";
		cout << "\n\t\t\t\t_________________________\n\n";
		cout << "\t\t\t\t   Prefix         :" << _Prefix << endl;
		cout << "\t\t\t\t   Total Tickets  :" << _TotalTickets << endl;
		cout << "\t\t\t\t   Served Clients :" << ServedClients() << endl;
		cout << "\t\t\t\t   Waiting Clients:" << WaitingTickets() << endl;
		cout << "\t\t\t\t_________________________\n";

	}
	short ServedClients()
	{
		return _TotalTickets - WaitingTickets();
	}
};

