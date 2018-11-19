/*
	This simple program takes IP address (v4) as input and identifies the class to which the IP address belongs
*/
#include<iostream>
using namespace std;

int main()
{
	cout << "\nThis program tells you the class of IP address entered\n\n";
	cout << "Enter the bytes in decimal, one octet at a time\n\n";
	int ip[4];
	char ipClass = '-';
	for(int i=0; i<4; i++)
	{
		cout << "Enter octet #" << i+1 << " : ";
		cin >> ip[i];
		if(ip[i]<0 || ip[i]>255)
		{
			cout << "\n\n\t\t\tInvalid input\n\n";
			i--;
		}
	}

	//THE IP ADDRESS
	cout << "\nIP = ";
	for(int i=0; i<4; i++)
	{
		cout << ip[i];
		if(i!=3)
			cout << ".";
	}

	//1.0.0.0 - 126.255.255.255
	if(ip[0]>=1 && ip[0]<=126)
		ipClass = 'A';
	//127.0.0.0 - 127.255.255.255
	else if(ip[0]==127)
		ipClass = 'L';
	//128.0.0.0 - 191.255.255.255
	else if(ip[0]>=128 && ip[0]<=191)
		ipClass = 'B';
	//192.0.0.0 - 223.255.255.255
	else if(ip[0]>=192 && ip[0]<=223)
		ipClass = 'C';
	//224.0.0.0 - 239.255.255.255
	else if(ip[0]>=224 && ip[0]<=239)
		ipClass = 'D';
	//240.0.0.0 - 254.255.255.255
	else if(ip[0]>=240 && ip[0]<=254)
		ipClass = 'E';
	
	if(ipClass=='A')
		cout << "\n\nClass-A" << "   Subnet mask = 255.0.0.0";
	else if(ipClass=='B')
		cout << "\n\nClass-B";
	else if(ipClass=='C')
		cout << "\n\nClass-C";
	else if(ipClass=='D')
		cout << "\n\nClass-D" << "   Reserved for multicasting";
	else if(ipClass=='E')
		cout << "\n\nClass-E" << "   Experimental; for research use";
	else if(ipClass=='L')
		cout << "\n\nLocalhost or Loopback address";
	else
		cout << "\n\nNo class assigned";

	//Private IP addresses
	if(ip[0]==10)
		cout << "\tPrivate IP";

	if(ip[0]==172 && (ip[1]>=16 && ip[1]<=31))
		cout << "\tPrivate IP" << "   Subnet mask = 255.240.0.0";
	else
		cout << "   Subnet mask = 255.255.0.0";

	if(ip[0]==192 && ip[1]==168)
		cout << "\tPrivate IP" << "   Subnet mask = 255.255.0.0";
	else
		cout << "   Subnet mask = 255.255.255.0";

	//Google 216.58.216.164 172.217.11.174
	if((ip[0]==216 && ip[1]==58 && ip[2]==216 && ip[3]==164) ||(ip[0]==172 && ip[1]==217 && ip[2]==11 && ip[3]==174))
		cout << "\n\t(Google's IP address)";

	return 0;
}
