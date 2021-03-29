#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <sstream>
#include<time.h>
#include <cwchar>
#include <windows.h>
#include <MMsystem.h>


using namespace std;

string DoOdgadniecia ;
string haslo;
int wygrane=0;
int przegrane=0;

void losowanie (string dane);
void Odgadywanie ();
void rysunek(int warunek);
void menu ();
void noweHaslo(void);
void subMenu(void);
void polskieZnaki(char & dane);
void welcome(void);
void WinLose(string nazwaPliku);
bool state = true;
int main(int argc, char** argv) {
	
	welcome();
	_sleep(400);
	system("cls");
	menu();
	
	return 0;
} 

void rysunek(int warunek)
{
	
	switch (warunek)
	{
		case 6:
		cout<< endl<<"/ \\";
			break;
		case 5:
			  for(int i =1 ; i<=7;i++)
				  {
				  	cout<<endl<<" |";
				  }
				  cout<< endl<<"/ \\";
			break;
		case 4:
				cout<<"  ";
			   for(int i =1 ; i<=14;i++)
				  {
				
				  	cout<<"_";

				  }
				  			  for(int i =1 ; i<=7;i++)
				  {
				  	cout<<endl<<" |";
				  }
				  cout<< endl<<"/ \\";
			break;
		case 3:
				cout<<"  ";
			   for(int i =1 ; i<=14;i++)
				  {
				
				  	cout<<"_";
				  					  	if(i==14) 
					  {
					  	  		
					  	cout<<endl<<" |              |";
					  	cout<<endl<<" |              |";
					  	cout<<endl<<" |              ";
					  	cout<<endl<<" |             ";
					  	cout<<endl<<" |              ";
					  	cout<<endl<<" |             ";
					  	cout<<endl<<" |";
					  }

				  }
				  cout<< endl<<"/ \\";
			break;
		case 2:
							cout<<"  ";
			   for(int i =1 ; i<=14;i++)
				  {
				
				  	cout<<"_";
				  					  	if(i==14) 
					  {
					  	  		
					  	cout<<endl<<" |              |";
					  	cout<<endl<<" |              |";
					  	cout<<endl<<" |              O";
					  	cout<<endl<<" |             ";
					  	cout<<endl<<" |              ";
					  	cout<<endl<<" |             ";
					  	cout<<endl<<" |";
					  }

				  }
				  cout<< endl<<"/ \\";
			break;
		case 1:
										cout<<"  ";
			   for(int i =1 ; i<=14;i++)
				  {
				
				  	cout<<"_";
				  					  	if(i==14) 
					  {
					  	  		
					  	cout<<endl<<" |              |";
					  	cout<<endl<<" |              |";
					  	cout<<endl<<" |              O";
					  	cout<<endl<<" |             /|\\";
					  	cout<<endl<<" |               ";
					  	cout<<endl<<" |             ";
					  	cout<<endl<<" |";
					  }

				  }
				  cout<< endl<<"/ \\";
			break;
		case 0:
													cout<<"  ";
			   for(int i =1 ; i<=14;i++)
				  {
				
				  	cout<<"_";
				  					  	if(i==14) 
					  {
					  	  		
					  	cout<<endl<<" |              |";
					  	cout<<endl<<" |              |";
					  	cout<<endl<<" |              O";
					  	cout<<endl<<" |             / \\";
					  	cout<<endl<<" |              |";
					  	cout<<endl<<" |             / \\";
					  	cout<<endl<<" |";
					  }

				  }
				  cout<< endl<<"/ \\";
			break;		
	}
	

} 



void  Odgadywanie ()
{
	string poprawne;
	char wprowadzana;
	int proby = 7;
	string uzyteLitery;
	char bell = 7;
	int poprawna = 0;
	
	
		while(proby>0)
	{
		poprawna=0;
		wprowadzana=getchar();
		cout<<endl<<"Podaj litere : ";
		wprowadzana=getchar();
		state = true;
		wprowadzana = toupper(wprowadzana);
		polskieZnaki(wprowadzana);
		stringstream ss;
		ss << wprowadzana;
		uzyteLitery	+= ss.str();
		uzyteLitery+=", ";


		
			for(int i =0; i<DoOdgadniecia.length(); i++)
			{
				if(	DoOdgadniecia[i] == wprowadzana)
				{	
					if (state == true) PlaySound(TEXT("music/poprawna.wav"),NULL,SND_SYNC);
					state = false;
					system("cls");
					
					if (i ==0) {
					haslo[i] = wprowadzana;}
				
					else {
					haslo[2*i] = wprowadzana;}
						
					poprawne += wprowadzana;
					
				cout<<"haslo:  "<<haslo<<endl<<endl;
				rysunek(proby);
				cout<<endl<<"Uzyte litery: "<<uzyteLitery<<endl;
				}
			
			}

			if (poprawne[poprawne.length() - 1] != wprowadzana ) {
			
			system("cls");
			proby--;
			cout<<"haslo:  "<<haslo<<endl<<endl;
			rysunek(proby);
			cout<<endl<<"Uzyte litery: "<<uzyteLitery<<endl;
			
			PlaySound(TEXT("music/zla.wav"),NULL,SND_SYNC);
			
			}
					
			

			
			for(int h =0; h < haslo.length(); h++)
			{
				if (haslo[h] == '_') poprawna ++;
				
				if (h==haslo.length()-1 && poprawna ==0)
					{
						system("cls");
						WinLose("database/winner.txt");	
						wygrane++;
						proby = 0;
						haslo="";
						menu();
					}
				
			}
				
	}
	
	
	if ( poprawna!= 0)
	{
			system("cls");
			WinLose("database/looser.txt");
			cout<<endl<<"Poprzednie  haslo to: "<<DoOdgadniecia<<endl<<endl;
			haslo="";
			przegrane++;
			menu();
	}

}
void losowanie (string dane){
	int iloscLiniiPliku=0;
	fstream plik;
    plik.open( dane, ios::in );
    if( plik.good() )
    {
        string napis;
        while( !plik.eof() )
        {
            getline( plik, napis );
            iloscLiniiPliku++;
            
        }
        plik.close();
    } else cout << "Error! Nie udalo otworzyc sie pliku!" << endl;
    
    
  
  
     // Tworzymy strumiñ wejœcia
 	 ifstream file(dane);
 
 	srand( time( NULL ) );
 	int losowana = rand()%iloscLiniiPliku;
 
  // Zmienna line do przechowywania linii
 	string linie;
 
  // Pêtla wykonuj¹ca siê (n - 1) razy
  for(int i = 0; i < losowana- 1; ++i) {
    // Wyjmujemy te linie, nic z nimi nie robimy
    getline(file,linie);
  }
 
  // Nastêpna pobrana linia jest t¹, której poszukujemy
  getline(file, linie);
 

    
  
  	DoOdgadniecia = linie;
//	cout<<DoOdgadniecia<<endl;
	for(int i =0; i<DoOdgadniecia.length(); i++)
	{	DoOdgadniecia[i] = toupper(DoOdgadniecia[i]);
		polskieZnaki(DoOdgadniecia[i]);
		if(DoOdgadniecia[i] == ' ') haslo += " ";
		else haslo += "_ ";
	}
	cout<<"haslo:  ";
	cout<<haslo<<endl<<endl;
}
void menu ()
{
	int MainMenu;
	if(wygrane !=0 || przegrane !=0) cout<< "WYGRANE: "<<wygrane<<"      PRZEGRANE: "<<przegrane<<endl<<endl;
	cout<<"MENU"<<endl;
	cout<<"1. GRAJ"<<endl;
	cout<<"2. DODAJ NOWE HASLO"<<endl;
	cout<<"3. KONIEC"<<endl;
	cin>>MainMenu;
	system("cls");
	switch (MainMenu)
	{
		case 1:
			subMenu();
		break;
		
		case 2:
			noweHaslo();
			menu ();
		break;
			
		case 3:
			system("EXIT");
		break;
	}
	
	
}
void noweHaslo(void)
{
	string napis;
	cout<<"Podaj nowe haslo: ";
	cin>>napis;
		
	fstream plik;
    plik.open( "database/test.txt", ios::out|ios::app);


            plik <<endl<<napis;
            plik.flush();
        
        plik.close();
        void menu ();
}
void subMenu(void)
{
	int SubMenu;
	

	cout<<"Wybierz kategorie "<<endl;
	cout<<"1. Panstwa"<<endl;
	cout<<"2. Ogolne"<<endl;
	cout<<"3. Wlasne"<<endl;
	cout<<"4. Cofnij"<<endl;
			
	cin>> SubMenu;
	
	switch(SubMenu)
	{
		case 1:
			system("cls");
			cout<<"Kategoria:  Panstwa"<<endl<<endl<<endl;
			losowanie ("database/kraje.txt");
			Odgadywanie ();
		break;
		
		case 2:
			system("cls");
			cout<<"Kategoria:  Ogolne"<<endl<<endl<<endl;
			losowanie ("database/dane.txt");
			Odgadywanie ();
		break;
		
		case 3:
			system("cls");
			cout<<"Kategoria:  Wlasne"<<endl<<endl<<endl;
			losowanie ("database/test.txt");
			Odgadywanie ();
		break;
		
		case 4:
			system("cls");
			menu ();
		break;
		
	}
		
}
void polskieZnaki(char  & dane)
{
	if( (int)dane == -91 ) dane= -92;  // ¥ 
	if( (int)dane == -87 ) dane= -88;  // Ê
	if( (int)dane == -122) dane=-113;  // Æ
	if( (int)dane == -104) dane=-105;  // Œ
	if( (int)dane == -28 ) dane= -29;  // Ñ
	if( (int)dane == -66 ) dane= -67;  // ¯
	if( (int)dane == -85 ) dane=-115;  // 
	if( (int)dane == -94 ) dane= -32;  // Ó
	if( (int)dane == -120) dane= -99;  // £
	
}
void welcome(void)
{

	fstream plik;
	
	plik.open( "database/welcome.txt", ios::in );
    if( plik.good() )
    {
        string napis;
        while( !plik.eof() )
        {
            getline( plik, napis );
            cout<<napis<<endl;     
            _sleep(60);
        }
        plik.close();
    } else cout << "Error! Nie udalo otworzyc sie pliku!" << endl;
    
}
void WinLose(string nazwaPliku)
{
	
	do{
	fstream plik;
	plik.open( nazwaPliku, ios::in );
    if( plik.good() )
    {
        string napis;
        while( !plik.eof() )
        {
            getline( plik, napis );
            cout<<napis<<endl;     
        }
        plik.close();
    } else cout << "Error! Nie udalo otworzyc sie pliku!" << endl;
	cout<<endl<<"Press any key to continue..."<<endl;
  	_sleep(400);
  	system("cls");
  	_sleep(400);
	}while(!kbhit() );
}
