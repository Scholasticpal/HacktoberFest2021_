#include<bits/stdc++.h>
using namespace std;
int main()
{
	char op;
	cout<<"Enter operator (+,-,*,/):"<<endl;
	cin>>op;
	double num1,num2;
	cout<<"Enter first number:";
	cin>>num1;
	cout<<"Enter second number:";
	cin>>num2;
	switch(op)
		{
			case'+':cout<<num1<<"+"<<num2<<"="<<(num1+num2)<<"\n";
				break;
			
			case'-':cout<<num1<<"-"<<num2<<"="<<(num1-num2)<<"\n";;
				break;
			
			case'*':cout<<num1<<"*"<<num2<<"="<<(num1*num2)<<"\n";;
				break;
			
			case'/':if(num2!=0.0)
				   cout<<num1<<"/"<<num2<<"="<<(num1/num2)<<"\n";;
				else
				   cout<<"divide by zero stiuation";
				break;
			
	        	default:cout<<"Invalid operator";
		}
		return 0;
}
