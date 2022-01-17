#include <iostream>
#include<cstring>
#include<iomanip>
using namespace std;
void carmarketprice();
double firstPartInsurance ();
double noClaimsDiscount();
void additionalCov();
void finalPartInsurance();
double basicPremium,grosspremium,addCoverage,totalamountpayable;
double firstArray[8][2]={{273.8,120.6},{305.5,135.0},{339.1,151.2},{372.6,167.4},{404.3,181.8},{436,196.2},{469.6,212.4},{501.3,226.8}};
double secondArray[8][2]={{196.2,67.5},{220.0,75.6},{243.9,85.2},{266.5,93.6},{290.4,101.7},{313.0,110.1},{336.4,118.2},{359.5,126.6}};
int marketprice;

int main()
{
	char respond='y';
	
	do{
    cout <<"----------Welcome to Car Insurance calculator!----------"<< endl<<endl;
    
	 carmarketprice();
     basicPremium=firstPartInsurance ();
     grosspremium=noClaimsDiscount();
    
    cout << endl;
    cout << endl;
    bool addCoverage;
    
    do{
    cout << "Do you need additional coverage? true=1 false=0 " << endl;
    cin >> addCoverage;
    }while(addCoverage!=0 && addCoverage!=1);
    
    if (!addCoverage)
    {
    	cout << "Thank you!" << endl;
	}
   	else
	   additionalCov();
	   
	finalPartInsurance();
	
	cout<<"Do you want to continue? y=yes anykey=no ";
	cin>>respond;
	
	}while(respond=='y' || respond=='Y');
    
    cout<<endl;
    return 0;
}

void carmarketprice() // function accept market price from user
{
	do
    {	
        cout <<"\tPlease enter the market price of your car = RM ";
        cin>>marketprice;
    }
 	while (marketprice==0);
 //	return marketprice;
}


double firstPartInsurance () // function calculate about location,coverage and cc
{	
	int column,row,currentArray[8][2]={0},engineCapacity,market;
	char location, coverageType;
	float  firstthousand,nextthousand;
		cout << "Location west(W) OR east(E): ";
			cin >> location;
		while(location!='w'&&location!='W'&&location!='e'&&location!='E')
		{
			cout<<"Invalid! Please enter again: "<<endl;
			cout << "Location west(W) OR east(E): ";
			cin >> location;
		}
		
			cout << "COVERAGE TYPE: (C) COMPREHENSIVE OR (T) THIRD PARTY: ";
			cin >> coverageType;
		while(coverageType!='C' && coverageType!='T')
		{
			cout<<"Invalid! Please enter again: "<<endl;
			cout << "COVERAGE TYPE: (C) COMPREHENSIVE OR (T) THIRD PARTY: ";
			cin >> coverageType;
		}
	
			if (location == 'W' || location == 'w')
				{
					for(int i=0;i<8;i++)
					{
						for (int j=0;j<2;j++)
						{
							currentArray[i][j]=firstArray[i][j];
						}
					}
				
				nextthousand=26.0;
				}
			else 
				{
				for(int i=0;i<8;i++)
					{
						for (int j=0;j<2;j++)
						{
							currentArray[i][j]=secondArray[i][j];
						}
					}
					
				nextthousand=20.30;
				}

	cout << "Select engine capacity:(not esceeding) " << endl
		 << "(1) 1400 cc" << endl 
		 << "(2) 1650 cc" << endl
		 << "(3) 2200 cc" << endl
		 << "(4) 3050 cc" << endl
		 << "(5) 4100 cc" << endl
		 << "(6) 4250 cc" << endl
		 << "(7) 4400 cc" << endl
		 << "(8) over 4400 cc: ";	 
	cin >>engineCapacity;
	while(engineCapacity<0 || engineCapacity>8)
	{
		cout<<"Please enter a valid number: "<<endl;
		cout << "Select engine capacity:(not esceeding) " << endl
		 << "(1) 1400 cc" << endl 
		 << "(2) 1650 cc" << endl
		 << "(3) 2200 cc" << endl
		 << "(4) 3050 cc" << endl
		 << "(5) 4100 cc" << endl
		 << "(6) 4250 cc" << endl
		 << "(7) 4400 cc" << endl
		 << "(8) over 4400 cc" << endl
		 << "ANSWER:RM " ;	 
		cin >>engineCapacity;
	}
	
	
	switch (engineCapacity)
	{
		case 1: row=0;break;
		case 2: row=1;break;
		case 3: row=2;break;
		case 4: row=3;break;
		case 5: row=4;break;
		case 6: row=5;break;
		case 7: row=6;break;
		case 8: row=7;	break;
		
	}
	switch (coverageType)
	{
				case 'C': {
							column=0;
							firstthousand=currentArray[row][column];
							market=(marketprice/1000)-1;
							basicPremium=market*nextthousand + firstthousand;
							cout<<setprecision(2)<<fixed<<basicPremium;}break;
				case 'T': {
							column=1;
							firstthousand=currentArray[row][column];
							market=(marketprice/1000)-1;
							basicPremium=market*nextthousand + firstthousand;
							basicPremium=basicPremium*0.75;
							cout<<setprecision(2)<<fixed<<basicPremium;}break;		
	}	
		cout<<endl<<endl;
	return basicPremium;
}

double noClaimsDiscount()
{
	float NCD,a,b,c,d,e,f;
	double zeroyear,firstyear,secondyear,thirdyear,forthyear,fifthyear;
	double insurancePrice;
	do{
	cout << "Choose No Claim Discount below:  write (digit) only " << endl		 
		 << "(1) zero year - 0%" << endl
		 << "(2) first year - 25%" << endl
		 << "(3)second year - 30%" << endl
		 << "(4)third year - 38.33%" << endl
		 << "(5)forth year - 45%" << endl
		 << "(6)fifth year - 55%" << endl
		 << "Answer: ";
	cin >> NCD;
	}while(NCD<1 || NCD>6);

	insurancePrice=basicPremium;
	 if (NCD==1)
	{
		a=insurancePrice*0;
		zeroyear=insurancePrice-a;
		cout<<"UPDATED GROSS PREMIUM is :RM "<<zeroyear;
		grosspremium=zeroyear;
	}
	else if (NCD==2)
	{	
		b=insurancePrice*0.25;
		firstyear=insurancePrice-b;
		cout<<"UPDATED GROSS PREMIUM is :RM "<< firstyear;
			grosspremium=firstyear;
	}
	else if (NCD==3)
	{
		c=0.3*insurancePrice;
		secondyear=insurancePrice-c;
		cout<<"UPDATED GROSS PREMIUM is :RM "<<secondyear;
			grosspremium=secondyear;
	}
	else if (NCD==4)
	{
		d =0.3833*insurancePrice;
		thirdyear=insurancePrice-d;
		cout<<"UPDATED GROSS PREMIUM is :RM "<<thirdyear;
			grosspremium=thirdyear;
	}
	else if (NCD==5)
	{
		e=0.45*insurancePrice;
		forthyear=insurancePrice-e;
		cout<<"UPDATED GROSS PREMIUM is :RM "<<forthyear;
			grosspremium=forthyear;
	}
	else if (NCD==6)
	{
		f=0.3833*insurancePrice;
		fifthyear=insurancePrice-f;
		cout<<"UPDATED GROSS PREMIUM is :RM "<<fifthyear;
			grosspremium=fifthyear;
	}
	
	return grosspremium;
	// gross premium= basic premium - NCD
}

void additionalCov()
{
	double opCoverage;
	int optionalCov;
	cout << "Optional coverage: please choose in (digit):" << endl
		 << "(1) Natural disaster - 0.5% of sum insured" << endl
		 << "(2) Windscreen and Audio System - 15% of sum insured " << endl
		 << "(3) Strike,Riot and Civil Commotion - 0.3% of sum insured " << endl;
	cin >> optionalCov;
	
	if(optionalCov==1)
	{	
		opCoverage=0.005*(marketprice/100);
	}
	else if(optionalCov==2)
	{
		opCoverage=0.15*(marketprice/100);	
	}
	else if(optionalCov==3)
	{
		opCoverage=0.003*(marketprice/100);
	}
	cout<<endl;
	grosspremium=grosspremium+opCoverage;
	cout<< "TOTAL WITH OPTIONAL COVERAGE IS RM" << grosspremium<<endl;
	
}

void finalPartInsurance()
{
	double GSTgross;
	int stampduty=10;
	
	GSTgross=grosspremium*0.06;
	cout << "FINAL TOTAL (INCLUDING 6% GST AND STAMP DUTY) " << endl;
	totalamountpayable=grosspremium+GSTgross+stampduty;
	cout<< "RM" << totalamountpayable<<endl;
	
}



