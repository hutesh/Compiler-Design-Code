#include<bits/stdc++.h>
using namespace std;
string s1="a";
string s2="e";
string s3="";
string s4="";
string s;
string Arr[]={"Aa","b"};
string Brr[]={"c"};
int checkParser(string s1,string s2,string s3,string s4,string input,int l,int p)
{
   s=s1+s3+s4+s2;
   if(s.length()>l)
       return 0;
   else if(s==input&&p==1)
       return 1;
   else if((s!=input)&&(s.length()==l))
       return 0;
   else if((s!=input)&&(s.length()<l&&p==1))
       return 0;
   else
      {
        for(int i=0;i<2;i++)
         {
               string s33=s3;
               s33.erase(0,1);
               s33=Arr[i]+s33;
               for(int j=0;j<1;j++)
               {
                      string s44=s4;
                      s44=s44.erase(0,1);
                      s44=Brr[j]+s44;
                     //cout<<s1+s33+s44+s2<<"\n";
               	       if(checkParser(s1,s2,s33,s44,input,l,i))
		                  return 1;
		       }    }
      }
 return 0;
}
int main()
{
    cout<<"Enter no of test cases\n";
    int t;
    cin>>t;
    while(t--)
    {
   string input;
   cout<<"Enter string to check that it can be generatd by grammer or not\n";
   cin>>input;
   int p=0;
   int l=input.length();
   if(checkParser(s1,s2,s3,s4,input,l,p))
        cout<<"Can Generate This String"<<"\n";
    else
        cout<<"Can not Generate This String"<<"\n";
    }
  return 0;
}

