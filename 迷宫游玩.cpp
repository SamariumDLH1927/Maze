#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <time.h>

using namespace std;

int ditu[10][10];
int walls[10][10][4];
int known[10][10][4];
char seed[104];
int sdt[10][10];
int a1, b1, a2, b2, a0, b0;
int crt;


int chartoint(char x)
{
	int t = int(x);
	t -= 48;
	return t;
}

void setup()
{
	crt = 4;
	for(int i = a1; i < 10; i++)
	{
		for(int j = b1; j < 10 ; j++)
		{
			sdt[i][j] = int(seed[crt]) - 65;
			crt++;
		}
	}
	for(int i = 0; i < a1; i++)
	{
		for(int j = 0; j < b1 ; j++)
		{
			sdt[i][j] = int(seed[crt]) - 65;
			crt++;
		}
	}
	for(int i = a1; i < 10; i++)
	{
		for(int j = 0; j < b1 ; j++)
		{
			sdt[i][j] = int(seed[crt]) - 65;
			crt++;
		}
	}
	for(int i = 0; i < a1; i++)
	{
		for(int j = b1; j < 10 ; j++)
		{
			sdt[i][j] = int(seed[crt]) - 65;
			crt++;
		}
	}
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			walls[i][j][0] = sdt[i][j] / 8;
			sdt[i][j] %= 8;
			walls[i][j][1] = sdt[i][j] / 4;
			sdt[i][j] %= 4;
			walls[i][j][2] = sdt[i][j] / 2;
			sdt[i][j] %= 2;
			walls[i][j][3] = sdt[i][j];
			for(int k = 0; k < 4; k++)
			{
				known[i][j][k] = 1;
			}
			ditu[i][j] = 0;
		}
	}
	ditu[a1][b1] = 1;
	ditu[a2][b2] = 2;
}

void print()
{
	printf("   0   1   2   3   4   5   6   7   8   9\n\n");
	for(int i = 0; i < 10; i++)
	{
		cout << i << "  ";
		if((a0==0)&&(i==b0))
		{
			cout << 'O';
		}
		else
		{
			cout << "��";
		}
		//cout << i << "  " << ditu[0][i];
		for(int j = 1; j <= 9; j++)
		{
			if(known[j][i][2])
			{
				printf("   ");
			}
			else
			{
				printf(" | ");
			}
			if((j==a0)&&(i==b0))
			{
				cout << "O";
			}		
			else if(ditu[i][j] == 0)
			{
				cout << "��";
			}				
			else if(ditu[i][j] == 1)
			{
				cout << "S";
			}
			else if(ditu[i][j] == 2)
			{
				cout << "E";
			}
			//cout << ditu[j][i];
		}
		cout << endl << "  ";
		for(int j = 0; j < 10; j++)
		{
			if(i == 9) 
			{
				break;
			}
			
			if(j == 9)
			{
				if(known[j][i][1])
				{
					printf("  ");
				}
				else
				{
					printf("--");
				}
			}
			else
			{
				if(known[j][i][1])
				{
					printf("   +");
				}
				else
				{
					printf("---+");
				}
			}
		}
		cout << endl;
		
	}
}

void printend()
{
	printf("   0   1   2   3   4   5   6   7   8   9\n\n");
	for(int i = 0; i < 10; i++)
	{
		cout << i << "  " << "��";
		//cout << i << "  " << ditu[0][i];
		for(int j = 1; j <= 9; j++)
		{
			if(walls[j][i][2])
			{
				printf("   ");
			}
			else
			{
				printf(" | ");
			}
			if(ditu[i][j] == 0)
			{
				cout << "��";
			}
			else if(ditu[i][j] == 1)
			{
				cout << "S";
			}
			else if(ditu[i][j] == 2)
			{
				cout << "E";
			}
			//cout << ditu[j][i];
		}
		cout << endl << "  ";
		for(int j = 0; j < 10; j++)
		{
			if(i == 9) 
			{
				break;
			}
			
			if(j == 9)
			{
				if(walls[j][i][1])
				{
					printf("  ");
				}
				else
				{
					printf("--");
				}
			}
			else
			{
				if(walls[j][i][1])
				{
					printf("   +");
				}
				else
				{
					printf("---+");
				}
			}
		}
		cout << endl;
	}
}

void mov(int dir)
{
	if(walls[a0][b0][dir])
	{
		if(dir == 0) b0--;
		if(dir == 1) b0++;
		if(dir == 2) a0--;
		if(dir == 3) a0++;
	}
	else
	{
		known[a0][b0][dir] = 0;
		if(dir == 0)
		{
			b0--;
			dir++;
			known[a0][b0][dir] = 0;
			b0++;
			dir--;
		} 
		if(dir == 1)
		{
			b0++;
			dir--;
			known[a0][b0][dir] = 0;
			b0--;
			dir++;
		}
		if(dir == 2)
		{
			a0--;
			dir++;
			known[a0][b0][dir] = 0;
			a0++;
			dir--;
		}
		if(dir == 3)
		{
			a0++;
			dir--;
			known[a0][b0][dir] = 0;
			a0--;
			dir++;
		}
	}
}

int main()
{
	cout << "ǽ���������Ϊ80���������ͼ��λ��S������㣬E�����յ㡣|�͡���+����ǽ��O����ǰλ�á������ƶ�ʱ����������������ָ���Enterʱ����������ƶ�" << endl << "��ͼ����������Թ�����������ߣ�Samarium" << endl;
	cout << "�����ͼ�����Կ�ʼ��Ϸ��" << endl;
	scanf("%s", seed);
	a1 = chartoint(seed[0]);
	b1 = chartoint(seed[1]);
	a2 = chartoint(seed[2]);
	b2 = chartoint(seed[3]);
	a0 = a1;
	b0 = b1;
	setup();
	a1 = chartoint(seed[1]);
	b1 = chartoint(seed[0]);
	a2 = chartoint(seed[3]);
	b2 = chartoint(seed[2]);
	a0 = a1;
	b0 = b1;
	int win = 0;
	crt = 0;
	while(!win)
	{
		cout << "��ǰ���ò���Ϊ" << crt << "��" << endl;
		print();
		int tmp = 1;
		while(tmp)
		{
			cout << "����wasd+Enter�������������ƶ���";
			char mv;
			cin >> mv;
			if(mv == 'w')
			{
				tmp = 0;
				mov(0);
			}
			else if(mv == 's')
			{
				tmp = 0;
				mov(1);
			}
			else if(mv == 'a')
			{
				tmp = 0;
				mov(2);
			}
			else if(mv == 'd')
			{
				tmp = 0;
				mov(3);
			}
			else{
				cout << "�������������롣" << endl;
			}
		}
		crt++;
		if((a0==a2)&&(b0==b2))
		{
			win = 1;
		}
	}
	printend();
	cout << "������Ϸ��ͼ����" << endl << "������" << crt << "���ִ��յ�" << endl;
	system("pause");
	return 0;
}
