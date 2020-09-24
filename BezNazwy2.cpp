#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
 
struct uczen
{
        
        int liczba;
};
 
class garaz
{
                vector <struct uczen> spis;
       
        public:
            //    void wprowadz();
                void wypisz();
                void zapiszDoPliku(const char *);
                void wczytajZPliku(const char *);  
				 void sortuj();    
				void zapiszDoPlikuNormalnie(const char *);        
};
 int compare(const void * a, const void * b)
{  
struct uczen*samochod1=(struct uczen*)a;
struct uczen*samochod2=(struct uczen*)b;
return (samochod1->liczba-samochod2->liczba);
}
 
 
 
void garaz::wypisz()
{
string a;
ifstream plik2;
    plik2.open("b.txt");  
    if(plik2.good())
     while(!plik2.eof())  
           
                         {
                             
                         plik2>>a;  
                         cout<<a;
                         cout<<endl; //  na ekranie
                         }
    plik2.close();
}
 void garaz::wczytajZPliku(const char *nazwa)
{
	struct uczen wprowadzany;
ifstream plik;
plik.open(nazwa);  //otwarcie pliku
   
   if(plik.good())  //sprawdzenie czy plik istnieje
            while(!plik.eof())  //petla wykonuje sie az program dojedzie do konca pliku
                 // (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
                 {
                plik    >> wprowadzany.liczba;
                         spis.push_back(wprowadzany); //TU WSTAW do tablicy nowy rekord
				 }
                  
                   
                   plik.close();  //zamkniecie pliku tekstowego

cout<<endl;
}
 void garaz::sortuj()
{
        qsort(&spis[0],spis.size(), sizeof(struct uczen), compare); 
        

}
 
 
void garaz::zapiszDoPliku(const char *nazwa)
{
        ofstream plik1;
        plik1.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.end()-1; it != spis.begin()-1; --it)
        {
                  plik1 <<it->liczba<<"\n";
               cout <<it->liczba<<"\n";
        }
        plik1.close();  
}
void garaz::zapiszDoPlikuNormalnie(const char *nazwa)
{
        ofstream plik1;
        plik1.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                  plik1 <<it->liczba<<"\n";
               cout <<it->liczba<<"\n";
        }
        plik1.close();  
}
void menu()
    {
    cout<<"1.Wypisz \n";
    cout<<"2.Zapisz odwrotnie\n";
	 cout<<"3.Qsort \n";
	 cout<<"4.Zapisz normlanie \n";
     cout<<"5.Koniec\n";
}
 
 
int main(int argc, char** argv) {
   
    {
    garaz ti;
    ti.wczytajZPliku("b.txt");
    int wybor;
    do{
    menu();
    cin >> wybor;
    switch (wybor)
    {
         
      
        case 1:
            ti.wypisz();
        break;
        case 2:
            ti.zapiszDoPliku("a.txt");
        break;
		 case 3:
            ti.sortuj();
        break;  
		 case 4:
            ti.zapiszDoPlikuNormalnie("c.txt");
        break;              
    }
      
     
 }while(wybor!=5);
 }
}
