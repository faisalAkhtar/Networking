/*
	Simulate and implement selective repeat sliding window protocol
*/
#include<iostream>
#include<unistd.h>
using namespace std;

int main()
{
	char send[50], temp[20], rec[50];
	int win, frames=0;
	cout << "Enter window-size : ";
	cin >> win;
	cout << "Enter Message = ";
	fflush(stdin);
	gets(send);
	while(send[frames]!='\0')
		frames++;

	int i=0, j=0, n=1;
	while(true)
	{
		cout << " " << n << ".";

	// Send
		cout << "\n\t\tSender : \n";
		if(n!=1)
		{
			for(j=0; j<win; j++)
			{
				temp[j]=send[j+i];
				cout << "\t\t   Ack received" << endl;
				if(send[j+i+1]=='\0')
					break;
				usleep(500000);
			}
			for(j=0; j<win; j++)
			{
				cout << "\t\t     Send (" << temp[j] << ")" << endl;
				if(send[j+i+1]=='\0')
					break;
				usleep(500000);
			}
		}
		else
		for(j=0; j<win; j++)
		{
			temp[j]=send[j+i];
			cout << "\t\t     Send(" << temp[j] << ")" << endl;
			if(send[j+i+1]=='\0')
				break;
			usleep(500000);
		}
		temp[j+1]='\0';
		usleep(500000);

	// Receive
		cout << "\n\t\t\t\t\t\tReceiver : \n";
		for(j=0; j<win; j++)
		{
			cout << "\t\t\t\t\t\t   Received(" << temp[j] << ")" << endl;
			usleep(500000);
			if(send[j+i+1]=='\0')
				break;
		}
		for(j=0; j<win; j++)
		{
			cout << "\t\t\t\t\t\t       Ack sent" << endl;
			usleep(500000);
			if(send[j+i+1]=='\0')
				break;
		}
		for(j=0; j<win; j++)
		rec[j+i]=temp[j];
		usleep(500000);

		n++;
		i+=win;
		if(i>=frames)
		break;
	}
	cout << " " << n << ".";
	cout << "\n\t\tSender : ";
	for(int i=0; i<win; i++)
	{
		cout << "\n\t\t Ack received";
		if(send[j+i+1]=='\0')
			break;
		usleep(500000);
	}
	cout << "\n\nFinal Message = ";
	puts(rec);
	return 0;
}
