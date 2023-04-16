#include <algorithm>
#include<iostream>
#include<string>
#include<cmath>
#include<map>
#include<iomanip>
#include<Windows.h>

using namespace std;

const long double C = 299792458;

#pragma region teksty
string wstepPowitanie = "Witaj Kosmito, zaplanujmy razem inwazje.\n";
string wstepCel = "Uwaga! To od twoich decyzji zalezy sukces lub katastrofa inwazji. Twoim celem jest zajecie planety Ziemi!\nDokonasz tego na podstawie swoich wyborow\n";
string wstepPowodzenia = "Wybieraj madrze. POWODZENIA!!!\n\n";

string wprowadzPlanete = "Podaj planete z Ukladu Slonecznego z ktorej pochodzisz: ";
string wprowadzPlaneteBlad = "Przepraszamy, taka planeta nie istnieje!\n\nSPROBUJ PONOWNIE\n";

string wprowadzNazwaStatku = "Teraz nadszedl czas na nazwanie twojego statku kosmicznego: ";
string wprowadzPaliwo = "Wybierz z jakiego surowca zrobione jest paliwo w twoim statku kosmicznym: ";
string wprowadzCzas = "Podaj czas w godzinach, w jakim chcez przeleciec odleglosc ze swojej planety na planete Ziemie.";

string infoPaliwo1 = "Zrobienie paliwa z: ";
string infoPaliwo2 = "jest niemozlwie.\nSPROBUJ PONOWNIE!";
string infoPaliwo3 = "jest mozliwe!\n";
string infopaliwo4 = "Paliwo zrobione z tego surowca umozliwia Ci dotarcie na Ziemie i powrot do domu\n";
string paliwoNieprawidlowe = "Substancja, z ktorej zostalo zrobione paliwo okazuje sie za slaba!!\nKonczy ci sie w polowie drogi!!!.\n\n";
string paliwoBrakSurowca = "Taki surowiec nie istnieje na twojej planecie lub nie da zrobic sie z niego paliwa.\nSPROBUJ PONOWNIE!\n";

string sprawdzaniePredkosci1 = "Twoj statek kosmiczny jest szybszy niz swiatlo!\nJuz dawno wyleciales z galektyki.\nBardzo nam przykro, minales sie z Ziemia";
string sprawdzaniePredkosci2 = "Twoj statek kosmiczny jest tak samo szybki jak swiatlo! Lecisz z predkoscia swiatla i to doslownie!\n";
string sprawdzaniePredkosci3 = "Z przykroscia stwierdzamy, ze twoj lot byl na tyle powolny,\nze Ziemianie zdazyli Cie zlokalizowac.\n\nI unicestwic... ";
string sprawdzaniePredkosci4 = "Doleciales na plenate Ziemie! Na twoje szczescie Ziemianie nie zdazyli Cie zauwazyc!\n";
string predkoscsStatku = "Predkosc twojego statku powinna wynosic: ";

string fazaPierwszaZakonczenie = "FAZA PIERWSZA: Z A K O N C Z O N A\n\nGratulujemy wybrania planety. Jestes krok blizej od podbicia Ziemi.\n\n ";
string fazaDrugaZakonczenie = "FAZA DRUGA: Z A K O N C Z O N A \n";
string fazaDrugaZakonczenieWygrana = "GRATULACJE!! Dobrales odpowiednie paliwo. Umozliwia Ci to, prowadzenie inwazji do konca!\n";

string przegrana = "KOSMITO! P R Z E G R A L E S! INWAZJA ZAKONCZONA K A T A S T R O F A\n";
string wygrana = "\nGRATULUJEMY! INWAZJA ZAKONCZYLA SIE S U K C E S E M!\n\nTWOJA PLANETA PRZEJELA ZIEMIE!\n\nW Y G R A L E S";
#pragma endregion

struct GatunekKosmitow {
    string planeta;
    string nazwaStatku; // wymyslona przez uztytkownika
    string rodzajPaliwa;
};

struct Planeta
{
    string nazwa;
    long double l;
    string atmosfera[3];
    string mineraly[4];
    string info;
    string paliwoMocne[2];
    string paliwoSlabe[2];

    
    string InformacjeOPlanecie()
    {
        string informacje = "Wybrana przez Ciebie planeta to " + nazwa + "! \n\n" + info + "Atmosfera sklada sie z: ";
        for(int i=0;i<3;i++)
            informacje += atmosfera[i] + " ";
        informacje += "\nW sklad powierzchni wchodza m.in.: ";
        for(int i=0;i<4;i++)
            informacje += mineraly[i] + " ";
        informacje +="\n";

        return informacje;
    }

    
};

//zmienne globalne
map<string, Planeta> PlanetyUkladuSlonecznego;
Planeta WybranaPlaneta;
GatunekKosmitow informacje;

//funkcje pomocnicze
void LiterkaPoLiterce(string tekst) {
    for (size_t i = 0; i<tekst.length(); i++) {
        cout << tekst[i];
        Sleep(5);
    }
    cout << endl;
}
long double ObliczeniePredkosc(long double l, long double c, long double t) { //obliczanie predkosc z jaka pojazd moze sie poruszac zeby w x czasu dotarł do planety
    return (l * c) * sqrtl(pow(l, 2) + (powl(c, 2) * powl(t, 2))) / (powl(l, 2) + (powl(c, 2) * powl(t, 2)));
}

//funkcje glowne
void UstawDanePlanet()
{
    Planeta Merkury;
    Merkury = {
        "Merkury",
        62100000000,
        {"dwutlenek wegla", "azot", "argon"},
        {"krzemionka", "zelazo", "tytan", ""},
        "",
        {"", ""},
        {"", ""}
    };
    PlanetyUkladuSlonecznego.insert_or_assign("merkury", Merkury);
    
    Planeta Wenus;
    Wenus = {
        "Wenus",
        62100000000,
        {"dwutlenek wegla", "azot", "argon"},
        {"krzemionka", "zelazo", "tytan", ""},
        "",
        {"", ""},
        {"", ""}
    };
    PlanetyUkladuSlonecznego.insert_or_assign("wenus", Wenus);
    
    Planeta Mars;
    Mars = {
        "Mars",
        62100000000,
        {"dwutlenek wegla", "azot", "argon"},
        {"krzemionka", "zelazo", "tytan", ""},
        "",
        {"tytan", ""},
        {"zelazo", "krzemionka"}
    };
    PlanetyUkladuSlonecznego.insert_or_assign("mars", Mars);
    
    Planeta Jowisz;
    Jowisz = {
        "Jowisz",
        62100000000,
        {"dwutlenek wegla", "azot", "argon"},
        {"krzemionka", "zelazo", "tytan", ""},
        "",
        {"", ""},
        {"", ""}
    };
    PlanetyUkladuSlonecznego.insert_or_assign("jowisz", Jowisz);
    
    Planeta Saturn;
    Saturn = {
        "Saturn",
        62100000000,
        {"dwutlenek wegla", "azot", "argon"},
        {"krzemionka", "zelazo", "tytan", ""},
        "",
        {"", ""},
        {"", ""}
    };
    PlanetyUkladuSlonecznego.insert_or_assign("saturn", Saturn);
    
    Planeta Uran;
    Uran = {
        "Uran",
        62100000000,
        {"dwutlenek wegla", "azot", "argon"},
        {"krzemionka", "zelazo", "tytan", ""},
        "",
        {"", ""},
        {"", ""}
    };
    PlanetyUkladuSlonecznego.insert_or_assign("uran", Uran);
    
    Planeta Neptun;
    Neptun = {
        "Neptun",
        62100000000,
        {"dwutlenek wegla", "azot", "argon"},
        {"krzemionka", "zelazo", "tytan", ""},
        "",
        {"", ""},
        {"", ""}
    };
    PlanetyUkladuSlonecznego.insert_or_assign("neptun", Neptun);
}

//deklaracje funkcji 
void WprowadzDaneOPlanecie();
void WprowadzDaneOStatku();
void WprowadzenieObliczaniePaliwa();
void RozpocznijGre();
void Przegrana();

int main()
{
    RozpocznijGre();
}


//definicje funkcji
void WprowadzDaneOPlanecie()
{
    LiterkaPoLiterce(wstepPowitanie);
    LiterkaPoLiterce(wstepCel);
    LiterkaPoLiterce(wstepPowodzenia);
    LiterkaPoLiterce(wprowadzPlanete);

    while(true)
    {
        cin >> informacje.planeta;
        transform(informacje.planeta.begin(), informacje.planeta.end(), informacje.planeta.begin(), [](unsigned char c){ return tolower(c); }); //zamiana stringa na male litery

        if(PlanetyUkladuSlonecznego.find(informacje.planeta) == PlanetyUkladuSlonecznego.end())
        {
            //nie znaleziono planety
            LiterkaPoLiterce(wprowadzPlaneteBlad);
        }
        else
        {
            //znaleziono planete
            WybranaPlaneta = PlanetyUkladuSlonecznego.at(informacje.planeta);
            LiterkaPoLiterce(WybranaPlaneta.InformacjeOPlanecie());
            break;
        }
    }
    
    LiterkaPoLiterce(fazaPierwszaZakonczenie);
}

void WprowadzDaneOStatku()
{
    LiterkaPoLiterce(wprowadzNazwaStatku);
    cin >> informacje.nazwaStatku;
    cout << "\n";
}

void WprowadzenieObliczaniePaliwa()
{
    long double t = 0; // czas
    long double V = 0; //predkosc
    
    LiterkaPoLiterce(wprowadzPaliwo);
    
    cin >> informacje.rodzajPaliwa;
    transform(informacje.rodzajPaliwa.begin(), informacje.rodzajPaliwa.end(), informacje.rodzajPaliwa.begin(), [](unsigned char c){ return tolower(c); }); //zamiana stringa na male litery

    if(informacje.rodzajPaliwa == WybranaPlaneta.paliwoMocne[0] || informacje.rodzajPaliwa == WybranaPlaneta.paliwoMocne[1])
    {
        //wygrana
        LiterkaPoLiterce(fazaDrugaZakonczenieWygrana);
        LiterkaPoLiterce(infopaliwo4);

        LiterkaPoLiterce(fazaDrugaZakonczenie);

        LiterkaPoLiterce(wprowadzCzas);

        while (t == 0){
            cin >> t;
        }

        t = t * 3600;

        cout << "\n";
        LiterkaPoLiterce(predkoscsStatku);
        
        V = ObliczeniePredkosc(WybranaPlaneta.l, C, t);
        cout << V << "m/s\n\n";
        
        if (V > C) {
            LiterkaPoLiterce(sprawdzaniePredkosci1);
            Przegrana();

        }
        else if (V == C) {
            LiterkaPoLiterce(sprawdzaniePredkosci2);
            LiterkaPoLiterce(wygrana);

        }
        else if (V < 400000) {
            LiterkaPoLiterce(sprawdzaniePredkosci3);
            Przegrana();

        }
        else if (V > 400000 && V < C)
            LiterkaPoLiterce(sprawdzaniePredkosci4);
        LiterkaPoLiterce(wygrana);
    }
    else if(informacje.rodzajPaliwa == WybranaPlaneta.paliwoSlabe[0] || informacje.rodzajPaliwa == WybranaPlaneta.paliwoSlabe[1])
    {
        LiterkaPoLiterce(infoPaliwo1);
        cout << informacje.rodzajPaliwa << endl;
        LiterkaPoLiterce(infoPaliwo3);

        //  przechodzimy do wylczenia predkosci
        LiterkaPoLiterce(wprowadzCzas);
        
        while (t == 0){
            cin >> t;
        }
        
        t = t * 3600;

        cout << "\n";
        LiterkaPoLiterce(predkoscsStatku);
        
        V = ObliczeniePredkosc(WybranaPlaneta.l, C, t);
        
        cout << V << "m/s\n\n";

        LiterkaPoLiterce(paliwoNieprawidlowe);
        Przegrana();

    }
    else
    {
        bool czySubstancjaIstnieje = false;
        for (int i=0;i<3;i++)
        {
            if(WybranaPlaneta.atmosfera[i] == informacje.rodzajPaliwa)
            {
                czySubstancjaIstnieje = true;
                break;
            }
        }
        if(czySubstancjaIstnieje == false)
        {
            for (int i=0;i<4;i++)
            {
                if(WybranaPlaneta.mineraly[i] == informacje.rodzajPaliwa)
                {
                    czySubstancjaIstnieje = true;
                    break;
                }
            }
        }

        if(czySubstancjaIstnieje ==true)
        {
            LiterkaPoLiterce(infoPaliwo1);
            cout << informacje.rodzajPaliwa;
            LiterkaPoLiterce(infoPaliwo2);
        }
        else
        {
            LiterkaPoLiterce(paliwoBrakSurowca);
        }

        WprowadzenieObliczaniePaliwa();
    }
    
}


void RozpocznijGre()
{
    UstawDanePlanet();
    WprowadzDaneOPlanecie();
    WprowadzDaneOStatku();
    WprowadzenieObliczaniePaliwa();
}

void Przegrana()
{
    LiterkaPoLiterce(przegrana);
    Sleep(10000); //10sekund
    system("cls"); //czyszczenie konsoli
    RozpocznijGre();
}