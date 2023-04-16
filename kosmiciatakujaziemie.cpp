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
string tekst = "Witaj Kosmito, zaplanujmy razem inwazje.\n";
string tekst2 = "Uwaga! To od twoich decyzji zalezy sukces lub katastrofa inwazji. Twoim celem jest zajecie planety Ziemi!\n Dokonasz tego na podstawie swoich wyborow\n";
string tekst3 = "Wybieraj madrze. POWODZENIA!!!\n\n";
string tekst4 = "Podaj planete z Ukladu Slonecznego z ktorej pochodzisz: ";
string tekst5 = "Kosmito, nie znasz nazwy swojej planety, prosze sprawdz pisownie";
string tekst6 = "Wybrana przez Ciebie planeta to MARS!\n\n Jego atmosfera sklada sie glownie z dwutlenku wegla i malych ilosci azotu i argonu\n Na powierzchni wystepuja takie mineraly jak: zelazo, krzemionka i tytan\n\n";
string tekst8 = "Wybrana przez Ciebie planeta to MERKURY!\n\n Jest to niewielka i goraca planeta, polozona najblizej Slonca\n charakteryzuje sie brakiem atmosfery.\n Powierzchnia sklada sie glownie z metali i krzemianow (np. oliwinu, zelaza, rteci, krzemu, niklu)\n\n";
string tekst9 = "Wybrana przez Ciebie planeta to WENUS!\n\n To skalista planeta z bardzo gesta atmosfera, ktora sklada sie az z 96,5% dwutlenku wegla oraz sladowych ilosci helu, neonu oraz kwasu siarkowego\n W sklad powierzchni wchodza m.in.: pirop, granat, oliwin i plagioklazy\n";
string tekst10= "Wybrana przez Ciebie planeta to JOWISZ!\n To najwieksza planeta w Ukladzie Slonecznym.\n Jego atmosfera sklada sie z roznorodnych gazow, w tym wodoru, helu, amoniaku i metanu.";
string tekst11;
string infobrak = "Przepraszamy, taka planeta nie istnieje!\n\n SPROBUJ PONOWNIE\n";
string infozakonczenie = "FAZA PIERWSZA: Z A K O N C Z O N A\n\n Gratulujemy wybrania planety. Jestes krok blizej od podbicia Ziemi.\n\n ";
string nazwastatku = "Teraz nadszedl czas na nazwanie twojego statku kosmicznego: ";
string tekst7 = "Wybierz z jakiego surowca zrobione jest paliwo w twoim statku kosmicznym: \n";
string infopaliwo1 = "Zrobienie paliwa z: ";
string infopaliwo2 = " jest niemozlwie.\n SPROBUJ PONOWNIE!";
string infopaliwo3 = " jest mozliwe!\n";
string pytanieczas = "Podaj czas w godzinach, w jakim chcez przeleciec odleglosc ze swojej planety na planete Ziemie.";
string predkoscstatku = "Predkosc twojego statku powinna wynosic: ";
string npwdpaliwo = "Substancja, z ktorej zostalo zrobione paliwo okazuje sie za slaba!!\n Konczy ci sie w polowie drogi!!!. \n\n";
string faza2 = "FAZA DRUGA: Z A K O N C Z O N A \n";
string przegrana = " KOSMITO! P R Z E G R A L E S! INWAZJA ZAKONCZONA K A T A S T R O F A\n ";
string wygranafazy2 = "GRATULACJE!! Dobrales odpowiednie paliwo. Umozliwia Ci to, prowadzenie inwazji do konca!\n";
string infopaliwo4 = "Paliwo zrobione z tego surowca umozliwia Ci dotarcie na Ziemie i powrot do domu\n";
string info = "Taki surowiec nie istnieje na twojej planecie lub nie da zrobic sie z niego paliwa.\n SPROBUJ PONOWNIE!\n";
string sprawdzaniepredkosci1 = "Twoj statek kosmiczny jest szybszy niz swiatlo!\n Juz dawno wyleciales z galektyki.\n Bardzo nam przykro, minales sie z Ziemia";
string sprawdzaniepredkosci2 = "Twoj statek kosmiczny jest tak samo szybki jak swiatlo! Lecisz z predkoscia swiatla i to doslownie!\n";
string sprawdzaniepredkosci3 = "Z przykroscia stwierdzamy, ze twoj lot byl na tyle powolny,\n ze Ziemianie zdazyli Cie zlokalizowac.\n\n I unicestwic... ";
string sprawdzaniepredkosci4 = "Doleciales na plenate Ziemie! Na twoje szczescie Ziemianie nie zdazyli Cie zauwazyc! \n";
string wygrana = "\nGRATULUJEMY! INWAZJA ZAKONCZYLA SIE S U K C E S E M!\n\n TWOJA PLANETA PRZEJELA ZIEMIE!\n\n W Y G R A L E S";
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
        std::cout << tekst[i];
        Sleep(5);
    }
    std::cout << endl;
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
    LiterkaPoLiterce(tekst);
    LiterkaPoLiterce(tekst2);
    LiterkaPoLiterce(tekst3);
    LiterkaPoLiterce(tekst4);

    while(true)
    {
        std::cin >> informacje.planeta;
        std::transform(informacje.planeta.begin(), informacje.planeta.end(), informacje.planeta.begin(), [](unsigned char c){ return std::tolower(c); }); //zamiana stringa na male litery

        if(PlanetyUkladuSlonecznego.find(informacje.planeta) == PlanetyUkladuSlonecznego.end())
        {
            //nie znaleziono planety
            LiterkaPoLiterce(infobrak);
        }
        else
        {
            //znaleziono planete
            WybranaPlaneta = PlanetyUkladuSlonecznego.at(informacje.planeta);
            LiterkaPoLiterce(WybranaPlaneta.InformacjeOPlanecie());
            break;
        }
    }
    
    LiterkaPoLiterce(infozakonczenie);
}

void WprowadzDaneOStatku()
{
    LiterkaPoLiterce(nazwastatku);
    std::cin >> informacje.nazwaStatku;
    std::cout << "\n";
}

void WprowadzenieObliczaniePaliwa()
{
    long double t; // czas
    long double V; //predkosc
    
    LiterkaPoLiterce(tekst7);
    
    std::cin >> informacje.rodzajPaliwa;
    std::transform(informacje.rodzajPaliwa.begin(), informacje.rodzajPaliwa.end(), informacje.rodzajPaliwa.begin(), [](unsigned char c){ return std::tolower(c); }); //zamiana stringa na male litery

    if(informacje.rodzajPaliwa == WybranaPlaneta.paliwoMocne[0] || informacje.rodzajPaliwa == WybranaPlaneta.paliwoMocne[1])
    {
        //wygrana
        LiterkaPoLiterce(wygranafazy2);
        LiterkaPoLiterce(infopaliwo4);

        LiterkaPoLiterce(faza2);

        LiterkaPoLiterce(pytanieczas);
        std::cin >> t;
        t = t * 3600;

        std::cout << "\n";
        LiterkaPoLiterce(predkoscstatku);
        
        V = ObliczeniePredkosc(WybranaPlaneta.l, C, t);
        std::cout << V << "m/s\n\n";
        
        if (V > C) {
            LiterkaPoLiterce(sprawdzaniepredkosci1);
            Przegrana();

        }
        else if (V == C) {
            LiterkaPoLiterce(sprawdzaniepredkosci2);
            LiterkaPoLiterce(wygrana);

        }
        else if (V < 400000) {
            LiterkaPoLiterce(sprawdzaniepredkosci3);
            Przegrana();

        }
        else if (V > 400000 && V < C)
            LiterkaPoLiterce(sprawdzaniepredkosci4);
        LiterkaPoLiterce(wygrana);
    }
    else if(informacje.rodzajPaliwa == WybranaPlaneta.paliwoSlabe[0] || informacje.rodzajPaliwa == WybranaPlaneta.paliwoSlabe[1])
    {
        LiterkaPoLiterce(infopaliwo1);
        std::cout << informacje.rodzajPaliwa;
        LiterkaPoLiterce(infopaliwo3);

        //  przechodzimy do wylczenia predkosci
        LiterkaPoLiterce(pytanieczas);
        std::cin >> t;
        t = t * 3600;

        std::cout << "\n";
        LiterkaPoLiterce(predkoscstatku);
        
        V = ObliczeniePredkosc(WybranaPlaneta.l, C, t);
        
        std::cout << V << "m/s\n\n";

        LiterkaPoLiterce(npwdpaliwo);
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
            LiterkaPoLiterce(infopaliwo1);
            std::cout << informacje.rodzajPaliwa;
            LiterkaPoLiterce(infopaliwo2);
        }
        else
        {
            LiterkaPoLiterce(info);
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