/*
	Simulate Cyclic Redundancy Check (CRC) error detection algorithm for noisy channel.
*/
#include<iostream>
using namespace std;

int main()
{
	//MESSAGE and POLYNOMIAL
	int msg[20] = {1,0,1,0,1}, msgZ = 5;		//msgZ -> msg size
	cout << "Message size = ";
	cin >> msgZ;
	cout << "Message(0 or 1 only)\n";
	for(int i=0; i<msgZ; i++)
	{
		cout << "\t";
		cin >> msg[i];
		msg[i]%=2;
	}

	int pol[3] = {1,0,1}, polZ = 3;				//polZ -> generator polynomial size
	cout << "Generator Polynomial size = ";
	cin >> polZ;
	cout << "Polynomial =\n";
	for(int i=0; i<polZ; i++)
	{
		cout << "\t";
		cin >> pol[i];
		pol[i]%=2;
	}

//SENDER SIDE
	int sent[20];
	for(int i=0; i<msgZ; i++)
		sent[i] = msg[i];						//copying message into sent array

	cout << "\nSENDER SIDE : \n";
	cout << "\tMessage\t\t=\t";
	for(int i=0; i<msgZ; i++)
		cout << sent[i];

	cout << "\n\tPolynomial\t=\t";
	for(int i=0; i<polZ; i++)
		cout << pol[i];

	cout << "\n\tZeroes appended : " << polZ-1;
	for(int i=msgZ; i<msgZ+polZ-1; i++)
		sent[i] = 0;

	int temp[20];								//copying to temporary array
	for(int i=0; i<20; i++)
		temp[i]=sent[i];

	cout << "\n\tAppending 0\t=\t";
	for(int i=0; i<msgZ+polZ-1; i++)
		cout << temp[i];

	cout << "\n\tDividing...";
	int j,k;
	for(int i=0; i<msgZ; i++)					//Dividing and getting the remainder to temp array
	{
		j=0; k=i;
		if(temp[k]>=pol[j])
		{
			for(j=0,k=i; j<polZ; j++,k++)
			{
				if(temp[k]==pol[j])
					temp[k]=0;
				else
					temp[k]=1;
			}
		}
	}

	int crc[10];
	cout << "\n\tCRC bits\t=\t";				//Last polZ-1 bits of temp array are CRC bits
	for(int i=0,j=msgZ; i<polZ-1; i++,j++)
	{
		crc[i] = temp[j];
		cout << crc[i];
	}

	cout << "\n\tCRC appended\t=\t";
	for(int i=msgZ, j=0; i<msgZ+polZ-1; i++,j++)
		sent[i] = crc[j];
	for(int i=0; i<msgZ+polZ-1; i++)
		cout << sent[i];
	
	cout << "\n\tMESSAGE SENT...";

//RECEIVER SIDE
	int rec[20];
	for(int i=0; i<msgZ+polZ-1; i++)
		rec[i] = sent[i];						//copying message into 'rec' array

	cout << "\n\nRECEIVER SIDE : \n";
	cout << "\tReceived\t=\t";
	for(int i=0; i<msgZ+polZ-1; i++)
		cout << rec[i];

	cout << "\n\tPolynomial\t=\t";
	for(int i=0; i<polZ; i++)
		cout << pol[i];

	for(int i=0; i<msgZ+polZ-1; i++)
		temp[i]=rec[i];							//copying to temporary array


	cout << "\n\tDividing...";
	for(int i=0; i<msgZ; i++)					//Dividing and getting the remainder to temp array
	{
		j=0; k=i;
		if(temp[k]>=pol[j])
		{
			for(j=0,k=i; j<polZ; j++,k++)
			{
				if(temp[k]==pol[j])
					temp[k]=0;
				else
					temp[k]=1;
			}
		}
	}

	int rem[10];
	bool flag = true;
	cout << "\n\tRemainder bits\t=\t";			//Last polZ-1 bits of temp array are CRC bits
	for(int i=0,j=msgZ; i<polZ-1; i++,j++)
	{
		rem[i] = temp[j];
		cout << rem[i];
		if(rem[i]==1)
			flag = false;
	}

	if(flag)
	{
		cout << "\n\tHence, the message received was correct (all zeroes)";
		cout << "\n\tMessage\t\t=\t";
		for(int i=0; i<msgZ; i++)
		cout << rec[i];
	}
	else
	cout << "\n\tHence, the message received was incorrect (NOT all zeroes)";
	return 0;
}
