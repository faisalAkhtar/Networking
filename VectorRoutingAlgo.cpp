/*
	Simulate and implement distance vector routing algorithm
*/
#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	char vertex[10];
	int graph[10][10];
	while(true)
	{
		cout << "Enter number of vertices of the graph : ";
		cin >> num;
		if(num>10)
			cout << "\t\t(Less than 10)\n";
		else
			break;
	}

	cout << "\nVertices { ";
	for(int i=97,j=0; j<num; i++,j++)
	{
		vertex[j]=(char)i;
		cout << vertex[j] << " ";
	}
	cout << "}\n";

	cout << "\nNow enter the cost matrix. (A -ve value if vertices are not connected)\n";
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<num; j++)
		{
			if(j==i)
			{
				cout << "\t" << vertex[i] << "->" << vertex[j] << "   0\n";
				graph[i][i]=0;
				continue;
			}
			cout << "\t" << vertex[i] << "->" << vertex[j] << "   ";
			cin >> graph[i][j];
		}
		cout << endl;
	}

	for(int i=0; i<num; i++)
	{
		cout << "For router " << i+1 << " :\n";
		for(int j=0; j<num; j++)
		{
			cout << "\tnode " << j+1 << " via " << j+1 << "    Distance = " << graph[i][j] << endl;
		}
		cout << endl;
	}
	return 0;
}
