#include <iostream>
#include <cstdlib>
#include <ctime>
#include "red_polje.h"
//#include "red_pokazivac.h"
using namespace std;

void unos(char *znakovni_niz){
     cin.getline(znakovni_niz, 40);
     if (cin.gcount()==1)
        cin.getline (znakovni_niz,40);
}

void stanje(red a, int n){
     cout<<"Prioritet\tPrezime i ime\tDatum Rodjenja\tTekuci racun\tDevizni racun"<<endl<<endl;
     for(int i=0;i<n;i++) {
                          elem x = FrontQ(a);
                          switch(x.ci) {
                          case 1: cout<<"Umirovljenik \t";break;
                          case 2: cout<<"Invalid \t";break;
                          case 3: cout<<"Trudnica \t";break;
                          case 4: cout<<"VIP klijent \t";break;
                          case 5: cout<<"Ostali klijent \t";break;
                          case 6: cout<<"Nije klijent \t";break;
                          }
             cout<<x.pre_ime<<"     \t"<<x.dan<<"."<<x.mjesec<<"."<<x.godina<<".\t"<<x.tekuci<<" HRK    \t"<<x.devizni<<" EUR"<<endl;
             DeQueueQ(a);
             EnQueueQ(x,a);
             }
     }

void generiraj(){
     n=0;
     while(n<20){
     cout<<"Unesite broj klijenata (20+): ";
     cin>>n;
     }
     for(int i=0;i<n;i++){
             x.ai=rand()%400 + 101;
             x.bi=rand()%400 + 101;
             if(i==0 || i==2 || i==15 || i==6 || i==20) x.di=1;
             else if(i==4 || i==7 || i==11 || i==1 || i==3) x.di=2;
             else if(i==5 || i==8 || i==17  || i== 10 || i==13) x.di=3;
             else if(i==9 || i==12 || i==19 ||i==14 || i==16) x.di=4;
             else x.di=rand()%4+1;
             
             if(x.di==1 || x.di==2) x.ci=rand()%5+1;
             else if(x.di==4) x.ci==rand()%5+2;
             else x.ci=rand()%6+1;
             
             if(x.di==3) placa++;
             EnQueueQ(x,q);
             }
}

void zapisi(){
     int p[7]={0,0,0,0,0,0,0};
     for (int i=0;i<n;i++){
         x=FrontQ(q);
         p[x.ci]++;
         cout<<"Prioritet: ";
         switch(x.ci){
                      case 1: cout<<"Umirovljenik"<<endl;break;
                      case 2: cout<<"Invalid"<<endl;break;
                      case 3: cout<<"Trudnica"<<endl;break;
                      case 4: cout<<"VIP"<<endl;break;
                      case 5: cout<<"Ostali"<<endl;break;
                      case 6: cout<<"Nije klijent"<<endl;break;
                      }
         cout<<"Prezime i ime: ";
         unos(x.pre_ime);
         x.dan=rand()%30+1;
         x.mjesec=rand()%12+1;
         x.godina=rand()%75 + 1920;
         x.godine= 2013 - x.godina;
         
         cout<<"Datum rodjenja: "<<x.dan<<"."<<x.mjesec<<"."<<x.godina<<"."<<endl;
         if(x.ci==4) x.tekuci=rand()%230;
         else if(x.ci==1) x.tekuci=rand()%4000 + 3000;
         else x.tekuci=rand();
         cout<<"Stanje na tekucem racunu: "<<x.tekuci<<".00 HRK"<<endl;
         x.devizni=rand()%3000;
         cout<<"Stanje na deviznom racunu: "<<x.devizni<<".00 EUR"<<endl<<endl;
         
         DeQueueQ(q);
         EnQueueQ(x,q);
         EnQueueQ(x,salter);
         }
     cout<<"--------------------------\n\n";
     int k=n,br=0;
     for(int i=1;i<7;i++){
             for(int j=0;j<k;j++){
                     x=FrontQ(salter);
                     DeQueueQ(salter);
                     if(x.ci==i){
                     cout<<"---SALTER---"<<endl;
                     switch(x.ci){
                                  case 1: cout<<"Umirovljenik "<<x.pre_ime<<endl;break;
                                  case 2: cout<<"Invalid "<<x.pre_ime<<endl;break;
                                  case 3: cout<<"Trudnica "<<x.pre_ime<<endl;break;
                                  case 4: cout<<"VIP "<<x.pre_ime<<endl;break;
                                  case 5: cout<<"Ostali "<<x.pre_ime<<endl;break;
                                  case 6: cout<<"Nije klijent "<<x.pre_ime<<endl;break;
                      }
                      cout<<"Transakcija: ";
                      switch(x.di){
                                   case 1: cout<<"Uplata"<<endl;break;
                                   case 2: cout<<"Isplata"<<endl;break;
                                   case 3: cout<<"Placanje racuna"<<endl;break;
                                   case 4: cout<<"Kredit"<<endl;break;
                                   }
                      cout<<"Trajanje: "<<x.bi<<" s"<<endl;
                      
                      if(x.devizni * 7.5 > 10000)
                                   cout<<"Stanje deviznog racuna: "<<x.devizni<<".00 EUR"<<endl;
                                   br++;
                     }
             else EnQueueQ(x,salter);
             }
     k-=br;
     br=0;
     }
}

void sort_pom(elem p[],int n){
     for(int i=n-1;i>0;i--)
             for(int j=0;j<i;j++) 
                     if(p[j].ci>p[i].ci) {
                                       elem pom=p[j];
                                       p[j]=p[i];
                                       p[i]=pom;
                     }
     }

void brzo_placanje(){
     elem pom[placa];
     int k=0,j=n;
     for(int i=0;i<j;i++){
             x=FrontQ(q);
             DeQueueQ(q);
             if(x.di==3){
                         pom[k++]=x;
                         n--;
                         }
             else EnQueueQ(x,q);
             }
     sort_pom(pom,k);
     
     for(int i=0;i<k;i++)
             EnQueueQ(pom[i],brzi);
     cout<<"---GLAVNI RED---"<<endl;
     stanje(q,n);
     cout<<endl<<endl<<"---BRZI RED---"<<endl;
     stanje(brzi,placa);
     
     }

void brisanje(){
     int k=n;
     for(int i=0;i<k;i++){
             x=FrontQ(q);
             if((x.ci==4 && x.godine<30 && x.di==1&&x.tekuci<100)
                 ||(x.ci==1&&x.di==2&&x.tekuci>5000)){
                                                      DeQueueQ(q);
                                                      n--;
                                                      }
             else {
                  DeQueueQ(q);
                  EnQueueQ(x,q);
                  }
             }
     cout<<"---STANJE REDA---"<<endl;
     stanje(q,n);
     }

int main(){
    srand(time(0));
    rand();
    InitQ(q);
    InitQ(salter);
    InitQ(brzi);
    InitQ(novi);
    
    generiraj();
    zapisi();
    
    int izbor;
    do{
        cout<<endl<<"---IZBORNIK---"<<endl;
        cout<<"1) Otvaranje brzog reda za placanje racuna"<<endl;
        cout<<"2) Brisanji VIP klijenata mladjih od 30 godina koji zele izvrsiti uplatu i \nimanju manje od 100 HRK na tekucem racunu i umirovljenika koji zele obaviti \nisplatu i imaju preko 5.000 HRK na racunu"<<endl;
        cout<<"3) Otvaranje novog saltera"<<endl;
        cin>>izbor;
        if(izbor==1) brzo_placanje();
        else if(izbor==2) brisanje();
        }while(izbor!=9);
}
