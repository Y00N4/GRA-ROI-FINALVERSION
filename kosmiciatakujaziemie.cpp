// kosmiciatakujaziemie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie progr


#include <iostream>

 int main {
     
  cout << "Witajcie ziemianie jestesmy z planety kosmitow przybylismy podbic ziemie"
 cout << "zginiecie"
   
   
 }

// gra o kosmitach, przeprowadzajacych inwazje na planete ziemie (ziemianin). 
//3 CZESCI , do kazdej gracz sam podaje informacje.
//1. faza:  wylosowanie liczby kosmitów, którzy przeprowadzaja inwazje. 
//2. faza: (struktura) gatunek, zmieszkanie, typ pojazdu....//  
//3. faza wybranie da


////paliwa: mocno schłodzonej, ciekłej kerozyny oraz również schłodzonego i ciekłego tlenu.
 ///napędu ciekłego tlenu jako utleniacza i nafty lub ciekłego wodoru


 //switch (informacje.planeta){
   // case "Wenus" : numerpojazdu= 0176;

    //}
    //default:
#include <bits/stdc++.h>
using namespace std;

struct GatunekKosmitow{
    string planeta;
    string nazwapojazdu; // wymyslona przez uztytkownika
    string rodzajpaliwa;
    int liczbakosmitownastatku;
    double predkoscswietlna;
};


int main()
{
    float numerpojazdu;
    GatunekKosmitow informacje;

    cout << "Witajcie w tej interaktywnej inwazji na planete ziemie!" << endl;
    cout << "Kosmito, zaplanuj swoja inwazje. Pamietaj, wybieraj ostroznie."<< endl;
    cout << "Od twoich wyborów zalezy sukces, jak i katastrofa wyprawy" << endl;
    cout << "Powodzenia!" << endl << endl << endl;

    cout << "Podaj planete z ukladu slonecznego";
    cin >> informacje.planeta;

    while (true) {
    if (informacje.planeta=="Merkury"){
        numerpojazdu=5680;
        break;
    }
    else if (informacje.planeta=="Wenus"){
        numerpojazdu=6176;
        break;
    }
    else if (informacje.planeta=="Mars"){
        numerpojazdu=2235;
        break;
    }
    else if (informacje.planeta=="Jowisz"){
        numerpojazdu=9801;
        break;
    }
    else if (informacje.planeta=="Saturn"){
        numerpojazdu=5478;
        break;
    }
    else if (informacje.planeta=="Uran"){
        numerpojazdu=3640;
        break;
    }
    else if (informacje.planeta=="Neptun"){
        numerpojazdu=9781;
        break;
    }
    else{
        cout<< "Kosmito, nie znasz nazwy swojej planety, prosze sprawdz pisownie.";
        cin >> informacje.planeta;

    }

    }

    cout << "Numer pojazdu z " << informacje.planeta << " to " << numerpojazdu << endl;

    cout << "Podaj nazwe pojazdu";
    cin >> informacje.nazwapojazdu;

    cout << "Podaj rodzaj paliwa uzywanego do napedzenia statku kosmicznego." << endl;
    cout << "UWAGA! Rakiety kosmiczne wykorzystuja tylko paliw z: nafta, ciekly wodor, kerozyna, ciekly i schlodzony tlen";

    cout << "Rodzaj paliwa: ";
    cin >> informacje.rodzajpaliwa;

    //while (true){
    //switch (informacje.rodzajpaliwa){
    //case "nafta" :
    //    break;
   // case "ciekly wodor":
   //     break;
   // case "kerozyna";
    //    break;
   // case "ciekly i schlodzony tlen"
   //     break;
   //default: }

    }



    }
///// ROI PLANETA MARS
