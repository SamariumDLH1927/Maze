#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>

using namespace std;

int ditu[10][10];
int walls[10][10][4];

int cdt[10][10];
int x, y, m, n, t;

void setup()
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			ditu[i][j] = 0;
			for(int k = 0; k < 4; k++)
			{
				walls[i][j][k] = 1;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		walls[0][i][2] = 0;
		walls[9][i][3] = 0;
		walls[i][0][0] = 0;
		walls[i][9][1] = 0;	
	}
}

void buildwall(int x1, int y1, int x2, int y2)
{
	if(x1==x2)
	{
		if(y1<y2)
		{
			walls[x1][y1][1] = 0;
			walls[x2][y2][0] = 0;
			return;
		}
		if(y2<y1)
		{
			walls[x2][y2][1] = 0;
			walls[x1][y1][0] = 0;
			return;
		}
	}
	if(y1==y2)
	{
		if(x1<x2)
		{
			walls[x1][y1][3] = 0;
			walls[x2][y2][2] = 0;
			return;
		}
		if(x2<x1)
		{
			walls[x2][y2][3] = 0;
			walls[x1][y1][2] = 0;
			return;
		}
	}
}

void print()
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

void chk(int a, int b)
{
	if(walls[a][b][0])
	{
		t = b-1;
		if(!cdt[a][t])
		{
			cdt[a][t] = 1;
			chk(a, t);
		}
	}
	if(walls[a][b][1])
	{
		t = b+1;
		if(!cdt[a][t])
		{
			cdt[a][t] = 1;
			chk(a, t);
		}
	}
	if(walls[a][b][2])
	{
		t = a-1;
		if(!cdt[t][b])
		{
			cdt[t][b] = 1;
			chk(t, b);
		}
	}
	if(walls[a][b][3])
	{
		t = a+1;
		if(!cdt[t][b])
		{
			cdt[t][b] = 1;
			chk(t, b);
		}
	}
}

int check()
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10 ; j++)
		{
			cdt[i][j] = 0;
		}
	}
	cdt[m][n] = 1;
	chk(m, n);
	if(cdt[x][y])
	{
		return 0;
	}
	return 1;
}

char change(int a, int b)
{
	t = walls[a][b][3] + walls[a][b][2]*2 + walls[a][b][1]*4 + walls[a][b][0]*8;
	t += 65;
	return char(t);
}

void printout()
{
	ofstream outFile;
	outFile.open("D://��ͼ����.txt");
	outFile << m << n << x << y;
	for(int i = m; i < 10; i++)
	{
		for(int j = n; j < 10 ; j++)
		{
			outFile << change(i, j);
		}
	}
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			outFile << change(i, j);
		}
	}
	for(int i = m; i < 10; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			outFile << change(i, j);
		}
	}
	for(int i = 0; i < m; i++)
	{
		for(int j = n; j < 10 ; j++)
		{
			outFile << change(i, j);
		}
	}
}

int checkerror(int a1, int b1, int a2, int b2)
{
	if((a1!=a2)&&(b1!=b2))
	{
		return 1;
	}
	if((a1==a2)&&(b1==b2))
	{
		return 1;
	}
	if((((a1+b1)-(a2+b2))!=1)&&((a1+b1)-(a2+b2))!=-1)
	{
		return 1;
	}
	return 0;
}

int repeaterror(int a1, int b1, int a2, int b2)
{
	if(a1==a2)
	{
		if(b1<b2)
		{
			if(walls[a1][b1][1] == 0)
			{
				return 1;
			}
		}
		if(b2<b1)
		{
			if(walls[a1][b1][0] == 0)
			{
				return 1;
			}
		}
	}
	if(b1==b2)
	{
		if(a1<a2)
		{
			if(walls[a1][b1][3] == 0)
			{
				return 1;
			}
		}
		if(a2<a1)
		{
			if(walls[a1][b1][2] == 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	cout << "����D�̴����ı��ĵ�����ͼ����.txt������Ҫ������D�̵��ļ�������ļ�Ŀ¼ӦΪD://��ͼ����.txt��"<< endl;
	cout << "���õ�ͼ�����������������㡢�յ㡢ǽ����Ϣ������յ������ʽ�������� �����꣨�м��ÿո��������ǽ���������1 ������1 ������2 ������2������ʱǽ����ʣ��������0 0��0 0֮�佨ǽ���ɽ�������ǽ���������Ϊ80���������ͼ��λ��S������㣬E�����յ㡣|�͡���+����ǽ��" << endl << "��ͼ����������Թ�����������ߣ�Samarium" << endl;
	int r = 1;
	while(r)
	{
		setup();
		print();
		cout << "��㣺";
		cin >> m >> n;
		ditu[m][n] = 1;
		cout << endl << "�յ㣺";
		cin >> x >> y;
		ditu[x][y] = 2;
		print();
		int num = 80;
		while(num)
		{
			int a1, b1, a2, b2;
			int crt = 1;
			while(crt)
			{
				cout << "����ǽ�����ͼ�������꣺";
				cin >> a1 >> b1 >> a2 >> b2;
				if((a1+a2+b1+b2) == 0)
				{
					crt = 0;
					num = 1;
				}
				else if(checkerror(a1, b1, a2, b2))
				{
					cout << "�������������룺" << endl;
				}
				else if(repeaterror(a1, b1, a2, b2))
				{
					
				}
				else
				{
					crt = 0;
					buildwall(a1, b1, a2, b2);
				}
			}
			print();
			num--;
		}
		if(check())
		{
			printf("��ͼ���������������\n");
		}
		else
		{
			r = 0;
		}
	}
	printout();	
	printf("��ͼ�����ѵ���\n");
	system("pause");
	return 0;
}
