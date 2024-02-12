// Ali Bayani. AD. cpp.cpp : Defines the entry point for the console application.
//

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

void MainFunction ( int );

int main()
{
	cout << " --------------------------------------------------------------------" << endl;
	cout << "| ******** This program has been created for only 2^n teams ******** |" << endl;
	cout << " --------------------------------------------------------------------" << endl << endl;

	cout << " Enter the number of teams : ";

	int input;
	cin >> input;
	bool ans =  false;

	switch ( input ) {
		
	case 0:
		cout << " Invalid Input ! ";
		break;
	default:
		{
	        for ( int i = 1 ; i <= input ; i++ )
	        {
	      	    if ( (int)(pow(2,i)) == input ) 
		        {
			        ans = true;
			        MainFunction ( input );
		        }
	        }
		}
	}

	if ( ans == false )
		cout << " Invalid Input ! ";


	_getch();
	return 0;
}

void MainFunction ( int input )
{
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	string *TeamArray = new string [input];

	for ( int i = 0 ; i < input ; i++ )
	{
		cout << " Enter the name of team " << (i+1) << " : ";
		cin.get();
		getline ( cin , TeamArray [ i ] );
	}

//-----------------------------------------------------------------------------------------------------------
	
	int NumOfArr = input / 2;
	string **NewArr = new string*[NumOfArr];     //Creat input/2 arrys with 2 home,,  Part 1

	for ( int i = 0 ; i < NumOfArr ; i++ )
	{
		NewArr [ i ] = new string [ 2 ];
	}

	for ( int i = 0 ; i < NumOfArr ; i++ )
	{
		NewArr [ i ] [ 0 ] = TeamArray [ i * 2 ];
		NewArr [ i ] [ 1 ] = TeamArray [ ( i * 2 ) + 1 ];    
	}

//----------------------------------------------------------------------------------------------------------
	
	string **ReveseOfNewArr = new string*[NumOfArr];     //Creat Reverse of input/2 arrys with 2 home,,  Part 2 

	for ( int i = 0 ; i < NumOfArr ; i++ )
	{
		ReveseOfNewArr [ i ] = new string [ 2 ];
	}

	for ( int i = 0 ; i < NumOfArr ; i++ )
	{
		for ( int j = 0 ; j < 2 ; j++ )
		{
			ReveseOfNewArr [ i ] [ j ] = NewArr [ i ] [ 2 - j - 1 ];
		}
	}

//----------------------------------------------------------------------------------------------------------

	string **RNArr = new string*[input];     // ( New Aarray + Reverse ) InputSize arrys with 2 home,,  Part 3 

	for ( int i = 0 ; i < input ; i++ )
	{
		RNArr [ i ] = new string [ 2 ];
	}

	for ( int i = 0 ; i < NumOfArr ; i++ )
	{
		for ( int j = 0 ; j < 2 ; j++ )
		{
			RNArr [ i * 2 ]         [ j ] =  NewArr         [ i ] [ j ];
			RNArr [ ( i * 2 ) + 1 ] [ j ] =  ReveseOfNewArr [ i ] [ j ];
		}
	}

//****************************************************************************************************************************************************************************************************************
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
//****************************************************************************************************************************************************************************************************************

	cout << endl << endl << "*************** Tornoment Table ***************" << endl;

	switch ( input ) 
	{

	    case 2:

		    cout << "Weeks" << "\t" << " 1 " << "\t" << " 2 " << endl;
			cout <<"-----------------------------------" << endl;

		    for ( int i = 0 ; i < input ; i++ )
    	    {
				cout << "\t";

			    for ( int j = 0 ; j < input ; j++ )
		        {
					cout << RNArr [ i ] [ j ] << "\t";
		        }

				cout << endl;
	        }
        break;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
	    
		case 4:

			string **FourWeek = new string*[input];    
	        for ( int i = 0 ; i < input ; i++ )
	        {
	    	     FourWeek [ i ] = new string [ input ];
        	}

	        for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 4 ; j++ )
		         {
			          FourWeek [ i ] [ j ] =  RNArr [ i ] [ j ];

					  if      ( i < NumOfArr )
					  {
			              FourWeek [ i + NumOfArr ] [ j + NumOfArr ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < input )
					  {
						  FourWeek [ i - NumOfArr ] [ j + NumOfArr ] =  RNArr [ i ] [ j ];
					  }
		         }
	        }

			cout << "Weeks" << "\t" << " 1 " << "\t" << " 2 " << "\t" << " 3 " << "\t" << " 4 " << endl;
			cout <<"--------------------------------------------------------------------------" << endl;

		    for ( int i = 0 ; i < input ; i++ )
    	    {
				cout << "\t";

			    for ( int j = 0 ; j < 4 ; j++ )
		        {
					cout << FourWeek [ i ] [ j ] << "\t";
		        }

				cout << endl;
	        }

			delete [] FourWeek;

        break;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
		
        case 8:

		    string **EightWeek = new string*[input];    
	        for ( int i = 0 ; i < input ; i++ )
	        {
	    	     EightWeek [ i ] = new string [ input ];
        	}

	        for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 4 ; j++ )                                         // Till week 4
		         {
			          EightWeek [ i ] [ j ] =  RNArr [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              EightWeek [ i + 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  EightWeek [ i - 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  EightWeek [ i + 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  EightWeek [ i - 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
		         }
	        }

			string **EightWeek2 = new string*[input];   
	        for ( int i = 0 ; i < input ; i++ )
	        {
	    	     EightWeek2 [ i ] = new string [ input ];
        	}

			for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 6 ; j++ )                                           // Till week 6
		         {
			          EightWeek2 [ i ] [ j ] =  EightWeek [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              EightWeek2 [ i + 4 ] [ j + 4 ] =  EightWeek [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  EightWeek2 [ i + 4 ] [ j + 4 ] =  EightWeek [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  EightWeek2 [ i - 4 ] [ j + 4 ] =  EightWeek [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  EightWeek2 [ i - 4 ] [ j + 4 ] =  EightWeek [ i ] [ j ];
					  }
		         }
	        }

			string **EightWeek3 = new string*[input];    
	        for ( int i = 0 ; i < input ; i++ )
	        {
	    	     EightWeek3 [ i ] = new string [ input ];
        	}

			for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 8 ; j++ )                                        // Till week 8
		         {
			          EightWeek3 [ i ] [ j ] =  EightWeek2 [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              EightWeek3 [ i + 6 ] [ j + 6 ] =  EightWeek2 [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  EightWeek3 [ i + 2 ] [ j + 6 ] =  EightWeek2 [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  EightWeek3 [ i - 4 ] [ j + 4 ] =  EightWeek2 [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  EightWeek3 [ i - 6 ] [ j + 6 ] =  EightWeek2 [ i ] [ j ];
					  }
		         }
	        }

			cout << "Weeks" << "\t" << " 1 " << "\t" << " 2 " << "\t" << " 3 " << "\t" << " 4 " << "\t" << " 5 " << "\t" << " 6 " << "\t" << " 7 " << "\t" << " 8 " << endl;
			cout <<"----------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		    for ( int i = 0 ; i < input ; i++ )
    	    {
				cout << "\t";

			    for ( int j = 0 ; j < 8 ; j++ )
		        {
					cout << EightWeek3 [ i ] [ j ] << "\t";
		        }

				cout << endl;
	        }

			delete [] EightWeek;
			delete [] EightWeek2;
			delete [] EightWeek3;

        break;

//------------------------------------------------------------------------------------------------------------

    	case 16:

			string **SixteenWeeks = new string*[input];    
	        for ( int i = 0 ; i < input ; i++ )
	        {
	    	     SixteenWeeks [ i ] = new string [ input ];
        	}

	        for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 4 ; j++ )                                     // Till week 4
		         {
			          SixteenWeeks [ i ] [ j ] =  RNArr [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              SixteenWeeks [ i + 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  SixteenWeeks [ i - 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  SixteenWeeks [ i + 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  SixteenWeeks [ i - 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 10 )
					  {
						  SixteenWeeks [ i + 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 12 )
					  {
						  SixteenWeeks [ i - 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 14 )
					  {
						  SixteenWeeks [ i + 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 16 )
					  {
						  SixteenWeeks [ i - 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
		         }
	        }

			string **SixteenWeeks2 = new string*[input];
			for ( int i = 0 ; i < input ; i++ )
	        {
	    	     SixteenWeeks2 [ i ] = new string [ input ];
        	}

			for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 6 ; j++ )                                          // Till week 6
		         {
			          SixteenWeeks2 [ i ] [ j ] =  SixteenWeeks [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              SixteenWeeks2 [ i + 4 ] [ j + 4 ] =  SixteenWeeks [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  SixteenWeeks2 [ i + 4 ] [ j + 4 ] =  SixteenWeeks [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  SixteenWeeks2 [ i - 4 ] [ j + 4 ] =  SixteenWeeks [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  SixteenWeeks2 [ i - 4 ] [ j + 4 ] =  SixteenWeeks [ i ] [ j ];
					  }
					  else if ( i < 10 )
					  {
						  SixteenWeeks2 [ i + 4 ] [ j + 4 ] =  SixteenWeeks [ i ] [ j ];
					  }
					  else if ( i < 12 )
					  {
						  SixteenWeeks2 [ i - 4 ] [ j + 4 ] =  SixteenWeeks [ i ] [ j ];
					  }
					  else if ( i < 14 )
					  {
						  SixteenWeeks2 [ i + 4 ] [ j + 4 ] =  SixteenWeeks [ i ] [ j ];
					  }
					  else if ( i < 16 )
					  {
						  SixteenWeeks2 [ i - 4 ] [ j + 4 ] =  SixteenWeeks [ i ] [ j ];
					  }
		         }
	        }

			string **SixteenWeeks3 = new string*[input];
			for ( int i = 0 ; i < input ; i++ )
	        {
	    	     SixteenWeeks3 [ i ] = new string [ input ];
        	}

			for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 8 ; j++ )                                            // Till week 8
		         {
			          SixteenWeeks3 [ i ] [ j ] =  SixteenWeeks2 [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              SixteenWeeks3 [ i + 6 ] [ j + 6 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  SixteenWeeks3 [ i + 2 ] [ j + 6 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  SixteenWeeks3 [ i - 4 ] [ j + 4 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  SixteenWeeks3 [ i - 6 ] [ j + 6 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 10 )
					  {
						  SixteenWeeks3 [ i + 6 ] [ j + 6 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 12 )
					  {
						  SixteenWeeks3 [ i - 6 ] [ j + 6 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 14 )
					  {
						  SixteenWeeks3 [ i + 6 ] [ j + 6 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 16 )
					  {
						  SixteenWeeks3 [ i - 6 ] [ j + 6 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
		         }
	        }

			for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 10 ; j++ )                                            // Till week 10
		         {
			          SixteenWeeks3 [ i ] [ j ] =  SixteenWeeks2 [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 10 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 12 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 14 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 16 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
		         }
	        }

			for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 10 ; j++ )                                             // Till week 12
		         {
			          SixteenWeeks3 [ i ] [ j ] =  SixteenWeeks2 [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              SixteenWeeks3 [ i + 10 ] [ j + 10 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  SixteenWeeks3 [ i + 6 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ]; ////ddddddddddd
					  }
					  else if ( i < 10 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 10 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 12 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 14 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 16 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
		         }
	        }

			for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 10 ; j++ )                                            // Till week 14
		         {
			          SixteenWeeks3 [ i ] [ j ] =  SixteenWeeks2 [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 10 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 12 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 14 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 16 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
		         }
	        }

			for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 10 ; j++ )                                            // Till week 16
		         {
			          SixteenWeeks3 [ i ] [ j ] =  SixteenWeeks2 [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  SixteenWeeks3 [ i + 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 10 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 12 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 14 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
					  else if ( i < 16 )
					  {
						  SixteenWeeks3 [ i - 8 ] [ j + 8 ] =  SixteenWeeks2 [ i ] [ j ];
					  }
		         }
	        }

			cout << "Weeks" << "\t" << " 1 " << "\t" << " 2 " << "\t" << " 3 " << "\t" << " 4 " << "\t" << " 5 " << "\t" << " 6 " << "\t" << " 7 " << "\t" << " 8 " << "\t" << " 9 " << "\t" << " 10 " << "\t" << " 11 " << "\t" << " 12 " << "\t" << " 13 " << "\t" << " 14 " << "\t" << " 15 " << "\t" << " 16 " << endl;
			cout <<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		    for ( int i = 0 ; i < input ; i++ )
    	    {
				cout << "\t";

			    for ( int j = 0 ; j < 8 ; j++ )
		        {
					cout << EightWeek3 [ i ] [ j ] << "\t";
		        }

				cout << endl;
	        }

			delete [] SixteenWeeks;
			delete [] SixteenWeeks2;
			delete [] SixteenWeeks3;

        break;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	  /* 
		case 32:

			string **EightWeek = new string*[input];    

	        for ( int i = 0 ; i < input ; i++ )
	        {
	    	     EightWeek [ i ] = new string [ input ];
        	}

	        for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 4 ; j++ )                                // Till week 4
		         {
			          EightWeek [ i ] [ j ] =  RNArr [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              EightWeek [ i + 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  EightWeek [ i - 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  EightWeek [ i + 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  EightWeek [ i - 2 ] [ j + 2 ] =  RNArr [ i ] [ j ];
					  }
		         }
	        }

			string **EightWeek2 = new string*[input];

			for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 6 ; j++ )                                // Till week 6
		         {
			          EightWeek2 [ i ] [ j ] =  EightWeek [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              EightWeek2 [ i + 4 ] [ j + 4 ] =  EightWeek [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  EightWeek2 [ i + 4 ] [ j + 4 ] =  EightWeek [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  EightWeek2 [ i - 4 ] [ j + 4 ] =  EightWeek [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  EightWeek2 [ i - 4 ] [ j + 4 ] =  EightWeek [ i ] [ j ];
					  }
		         }
	        }

			string **EightWeek3 = new string*[input];

			for ( int i = 0 ; i < input ; i++ )
	        {
		         for ( int j = 0 ; j < 8 ; j++ )                                // Till week 8
		         {
			          EightWeek3 [ i ] [ j ] =  EightWeek2 [ i ] [ j ];

					  if      ( i < 2 )
					  {
			              EightWeek3 [ i + 6 ] [ j + 6 ] =  EightWeek2 [ i ] [ j ];
					  }
					  else if ( i < 4 )
					  {
						  EightWeek3 [ i + 2 ] [ j + 6 ] =  EightWeek2 [ i ] [ j ];
					  }
					  else if ( i < 6 )
					  {
						  EightWeek3 [ i - 2 ] [ j + 4 ] =  EightWeek2 [ i ] [ j ];
					  }
					  else if ( i < 8 )
					  {
						  EightWeek3 [ i - 6 ] [ j + 6 ] =  EightWeek2 [ i ] [ j ];
					  }
		         }
	        }

			cout << "Weeks" << "\t" << " 1 " << "\t" << " 2 " << "\t" << " 3 " << "\t" << " 4 " << "\t" << " 5 " << "\t" << " 6 " << "\t" << " 7 " << "\t" << " 8 " << "\t" << " 9 " << "\t" << " 10 " << "\t" << " 11 " << "\t" << " 12 " << "\t" << " 13 " << "\t" << " 14 " << "\t" << " 15 " << "\t" << " 16 " << "\t" << " 17 " << "\t" << " 18 " << "\t" << " 19 " << "\t" << " 20 " << "\t" << " 21 " << "\t" << " 22 " << "\t" << " 23 " << "\t" << " 24 " << "\t" << " 25 " << "\t" << " 26 " << "\t" << " 27 " << "\t" << " 28 " << "\t" << " 29 " << "\t" << " 30 " << "\t" << " 31 " << "\t" << " 32 " << endl;
			cout <<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		    for ( int i = 0 ; i < input ; i++ )
    	    {
				cout << "\t";

			    for ( int j = 0 ; j < 8 ; j++ )
		        {
					cout << EightWeek3 [ i ] [ j ] << "\t";
		        }

				cout << endl;
	        }
        break;
*/
	}

	delete [] TeamArray;
	delete [] NewArr;
	delete [] ReveseOfNewArr;
	delete [] RNArr;

}

