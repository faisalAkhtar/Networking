/*
	Simulate and implement go back n sliding window protocol
*/
#include<iostream>
#include<stdio.h>
#include<unistd.h>
using namespace std;

int main()
{
	char send[50], temp[20];
	int win, frames=0;
	cout << "Enter window-size : ";
	cin >> win;
	cout << "Enter string : ";
	fflush(stdin);
	gets(send);
	while(send[frames]!='\0')
		frames++;

	int i=0, j=0, n=1;
	while(true)
	{
		cout << " " << n << ".";

		//send
		cout << "\n\t\tSender : \n";
		if(n!=1)
			cout << "\t\t   Ack received" << endl;
		cout << "\t\t   Message sent = ";
		for(j=0; j<win; j++)
		temp[j]=send[j+i];
		temp[j+1] = '\0';
		puts(temp);
		usleep(500000);

		//receive
		cout << "\n\t\t\t\t\t\tReceiver : \n";
		cout << "\t\t\t\t\t\t   Message received = ";
		for(j=0; j<win; j++)
		rec[j+i]=temp[j];
		puts(temp);
		cout << "\t\t\t\t\t\t   Ack sent\n";
		usleep(500000);

		n++;
		i+=win;
		if(i>=frames)
		break;
	}
	cout << " " << n << ".";
	cout << "\n\t\tSender : \n";
	cout << "\t\t   Ack received" << endl;
	return 0;
}
