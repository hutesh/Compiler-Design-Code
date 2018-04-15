// CLR(1) PARSER

/*
bb
*/

#include<bits/stdc++.h>

using namespace std;

struct prod
{
	string lhs;
	string rhs;
};

int main()
{
	struct prod p[3];
	p[0].lhs="S";
	p[0].rhs="AA";
	p[1].rhs="aA";
	p[1].lhs="A";
	p[2].lhs="A";
	p[2].rhs="b";
	cout<<"The grammar for CLR(1) parser is\n"<<p[0].lhs<<" -> "<<p[0].rhs<<"\n"<<p[1].lhs<<" -> "<<p[1].rhs<<"\n"<<p[2].lhs<<" -> "<<p[2].rhs<<"\n";
	string tbl[7][5];
	int i,j;
	for(i=0;i<7;i++)
		for(j=0;j<5;j++)
			tbl[i][j]="";
	map<char,int> m1;
	map<int,char> m2;
	m1['a']=0;
	m1['b']=1;
	m1['$']=2;
	m1['A']=3;
	m1['S']=4;
	m2[0]='a';
	m2[1]='b';
	m2[2]='$';
	m2[3]='A';
	m2[4]='S';
	tbl[0][0]="S3";
	tbl[0][1]="S4";
	tbl[0][3]="G2";
	tbl[0][4]="G1";
	tbl[1][2]="A";
	tbl[2][0]="S3";
	tbl[2][1]="S4";
	tbl[2][3]="G5";
	tbl[3][0]="S3";
	tbl[3][1]="S4";
	tbl[3][3]="G6";
	tbl[4][0]="R3";
	tbl[4][1]="R3";
	tbl[4][2]="R3";
	tbl[5][0]="R1";
	tbl[5][1]="R1";
	tbl[5][2]="R1";
	tbl[6][0]="R2";
	tbl[6][1]="R2";
	tbl[6][2]="R2";
	cout<<"The parsing tbl for the above grammar is \n";
	cout<<setw(10)<<"State";
	for(i=0;i<5;i++)
		cout<<setw(10)<<m2[i];
	cout<<endl;
	for(i=0;i<7;i++)
	{
		cout<<setw(10)<<i;
		for(j=0;j<5;j++)
		{
			cout<<setw(10)<<tbl[i][j];
		}
		cout<<"\n\n\n";
	}
	while(1)
	{
		cout<<"\n\nEnter the string to check whether it belongs to the above grammar: ";
		string s;
		cin>>s;
		s=s+"$";
		stack<int> st;
		st.push(0);
		j=0;
		int flag=0;
		cout<<setw(20)<<"current state"<<setw(10)<<"input"<<setw(50)<<"Operations performed\n";
		while(1)
		{
			int curr_state=st.top();
			cout<<setw(20)<<curr_state<<setw(10)<<s[j];
			if(tbl[curr_state][m1[s[j]]].length()!=0)
			{
				
				if(tbl[curr_state][m1[s[j]]][0]=='S')
				{
					cout<<setw(50)<<"Shift right";
					st.push(s[j]);
					st.push(tbl[curr_state][m1[s[j]]][1]-'0');
					j++;
				}
				else if(tbl[curr_state][m1[s[j]]][0]=='R')
				{
					int l=tbl[curr_state][m1[s[j]]][1]-'1';
					int k,a,b;
					for(k=0;k<2*(p[l].rhs.length());k++)
					{
						st.pop();
					}
					a=st.top();
					//cout<<"The current top state is "<<a<<endl;
					st.push(p[l].lhs[0]);
					
					//cout<<"THe goto operation performed is "<<p[l].lhs[0]<<endl;
					if(tbl[a][m1[st.top()]].length()>1 && tbl[a][m1[st.top()]][0]=='G')
					{
						st.push(tbl[a][m1[st.top()]][1]-'0');
						cout<<setw(50)<<"Reduce with production "<<p[l].lhs<<" -> "<<p[l].rhs<<" and goto state "<<st.top();
					}
					else break;
				}
				else if(tbl[curr_state][m1[s[j]]][0]=='A')
				{
					flag=1;
					break;
				}
				cout<<endl;
			}
			else
			{
				break;
			}
		}
		if(flag==1)
			cout<<"\nString is accepted\n";
		else cout<<"\nString is not accepted\n";
		char ch;
		cout<<"Enter y to check another string else enter n"<<endl;
		cin>>ch;
		if(ch!='y')
			break;
	}
}
