/*
	Simulate and implement stop and wait protocol for noisy channel
*/
#include<iostream>
#include<unistd.h>
using namespace std;

int sender(int ack)
{
	cout << "\n\t\tSender : \n";
	if(ack!=0)
		cout << "\t\t   Ack" << ack%2 << " received" << endl;
	cout << "\t\t   Packet ID (";
	ack++;
	if(ack%2)
		cout << "0)" << endl;
	else
		cout << "1)" << endl;
	cout << "\t\t   Packet sent" << endl;
	int data = ack;
	return data;
}

int receiver(int data)
{
	cout << "\n\t\t\t\t\t\tReceiver : \n";
	cout << "\t\t\t\t\t\t   Packet received";
	cout << "\n\t\t\t\t\t\t   Acknowledgement (Ack";
	if(data%2)
		cout << "1";
	else
		cout << "0";
	cout << " sent)\n";
	int ack = data;
	return ack;
}

int main()
{
	int response[2];
	cout << "Sending 4 packets\n";
	cout << "Do you want following noises in your channel? Answer as 1(yes) or 0(no).\n";
	cout << "   Lost or delayed packet\t:\t";
		cin >> response[0];
		response[0]%=2;
	cout << "   Lost or delayed ack\t\t:\t";
		cin >> response[1];
		response[1]%=2;

	int data = 0, ack=-1, i=1;
	cout << " " << i << ".";
	data = sender(data);
	usleep(500000);
	ack = receiver(data);
	usleep(500000);

	i++;
	if(response[0])
	{
		cout << " " << i << ".";
		data = sender(ack);
		sleep(1);
		usleep(500000);
		cout << "\n\t\t\t\t\t\tReceiver : \n";
		cout << "\t\t\t\t\t\t   Packet not received - DATA LOST (Send ack again)\n";
		usleep(500000);
	}
	else
		cout << " " << i << ".";
	data = sender(ack);
	usleep(500000);
	ack = receiver(data);
	usleep(500000);

	i++;
	if(response[1])
	{
		cout << " " << i << ".";
		data = sender(ack);
		usleep(500000);
		receiver(data);
		sleep(1);
		cout << "\n\t\tSender : \n";
		cout << "\t\t   Ack not received - ACK LOST (Sending packet again)\n";
		usleep(500000);
	}
	else
		cout << " " << i << ".";
	data = sender(ack);
	usleep(500000);
	ack = receiver(data);
	usleep(500000);

	i++;

	cout << " " << i << ".";
	data = sender(ack);
	usleep(500000);
	ack = receiver(data);
	usleep(500000);

	i++;

	cout << " " << i << ".";
	cout << "\n\t\tSender : \n";
	cout << "\t\t   Ack received" << endl;
	return 0;
}
