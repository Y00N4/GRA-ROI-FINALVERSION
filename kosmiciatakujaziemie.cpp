#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<Windows.h>
using namespace std;

struct GatunekKosmitow {
    string planeta;
    string nazwastatku; // wymyslona przez uztytkownika
    string rodzajpaliwa;
};


void literkapoliterce(string tekst) {
    for (size_t i = 0; i<tekst.length(); i++) {
        std::cout << tekst[i];
        Sleep(30);
    }
    std::cout << endl;
}
long double obliczeniepredkosc(long double l, long double c, long double t) { //obliczanie predkosc z jaka pojazd moze sie poruszac zeby w x czasu dotarł do planety
    long double V = (l * c) * sqrtl(pow(l, 2) + (powl(c, 2) * powl(t, 2))) / (powl(l, 2) + (powl(c, 2) * powl(t, 2)));
   // cout.precision(6);
    return V;
}



int main()
{
    long double l = 0; // długosc od ziemi do marsa w prostej linii
    long double c = 299792458; // m/s
    long double C;
    long double t; // czas
    long double V; //predkosc
    float idpojazdu;
    GatunekKosmitow informacje;
    int proba = 0;

    string tekst = "Witaj Kosmito, zaplanujmy razem inwazje.\n";
    string tekst2 = "Uwaga! To od twoich decyzji zalezy sukces lub katastrofa inwazji. Twoim celem jest zajecie planety Ziemi!\n Dokonasz tego na podstawie swoich wyborów\n";
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
    string npwdpaliwo = "Substancja, z ktorej zostalo zrobione paliwo okazuje sie za slaba!!\n W polowie drogi konczy Ci sie!!. \n\n";
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

start:
    literkapoliterce(tekst);
    literkapoliterce(tekst2);
    literkapoliterce(tekst3);
    literkapoliterce(tekst4);

    std::cin >> informacje.planeta;

    while (true) {
        if (informacje.planeta == "Mars" || informacje.planeta == "mars" || informacje.planeta == "MARS") {
            idpojazdu = 2235;
            l = 62100000000;// metry!!!
            literkapoliterce(tekst6);
            break; // continue; 
        }
        if (informacje.planeta == "Merkury" || informacje.planeta== "merkury"|| informacje.planeta== "MERKURY") {
            idpojazdu = 5680;
            l = 68600000000;
            literkapoliterce(tekst8);
            break;
        }
        else if (informacje.planeta == "Wenus" || informacje.planeta == "wenus" || informacje.planeta == "WENUS") {
            idpojazdu = 6176;
            l = 38000000000;
            literkapoliterce(tekst9);
            break;
        }
        else if (informacje.planeta == "Jowisz" || informacje.planeta == "jowisz"|| informacje.planeta == "JOWISZ") {
            idpojazdu = 9801;
            l = 629000000000;
            literkapoliterce(tekst10);
            break;
        }
        else if (informacje.planeta == "Saturn" || informacje.planeta == "saturn" || informacje.planeta=="SATURN") {
            idpojazdu = 5478;
            break;
        }
        else if (informacje.planeta == "Uran" || informacje.planeta == "uran" || informacje.planeta == "URAN") {
            idpojazdu = 3640;
            break;
        }
        else if (informacje.planeta == "Neptun" || informacje.planeta == "NEPTUN" || informacje.planeta == "neptun") {
            idpojazdu = 9781;
            break;
        }
        else {
            literkapoliterce(infobrak);
            std::cin >> informacje.planeta;
        }
    }
    literkapoliterce(infozakonczenie);
    literkapoliterce(nazwastatku);
    std::cin >> informacje.nazwastatku;
    std::cout << "\n";
    literkapoliterce(tekst7);

    std::cin >> informacje.rodzajpaliwa;

    if (informacje.planeta == "Mars" || informacje.planeta == "mars" || informacje.planeta == "MARS") {
        while (true) {
            if (informacje.rodzajpaliwa == "wegiel" || informacje.rodzajpaliwa == "azot" || informacje.rodzajpaliwa == "argon") {
                literkapoliterce(infopaliwo1);
                 std::cout << informacje.rodzajpaliwa;
                literkapoliterce(infopaliwo2);

                std::cin >> informacje.rodzajpaliwa;
            }
            else if (informacje.rodzajpaliwa == "zelazo" || informacje.rodzajpaliwa == "krzemionka") {

                literkapoliterce(infopaliwo1);
                std::cout << informacje.rodzajpaliwa;
                literkapoliterce(infopaliwo3);

                //  przechodzimy do wylczenia predkosci

                literkapoliterce(pytanieczas);
                std::cin >> t;
                t = t * 3600;

                obliczeniepredkosc(l, c, t);
                std::cout << "\n";
                literkapoliterce(predkoscstatku);

                std::cout << obliczeniepredkosc(l, c, t) << "m/s\n\n";

                literkapoliterce(npwdpaliwo);


                literkapoliterce(przegrana);
                goto start;

                break;
            }
            else if (informacje.rodzajpaliwa == "tytan") {
                literkapoliterce(wygranafazy2);
                literkapoliterce(infopaliwo4);

                literkapoliterce(faza2);



                literkapoliterce(pytanieczas);
                std::cin >> t;
                t = t * 3600;

                obliczeniepredkosc(l, c, t);
                std::cout << "\n";
                literkapoliterce(predkoscstatku);

                std::cout << obliczeniepredkosc(l, c, t) << "m/s\n\n";
                V = obliczeniepredkosc(l, c, t);
                C = 299792458;
                //cout << "wyswietlam V: " << V;

                if (V > C) {
                    literkapoliterce(sprawdzaniepredkosci1);
                    literkapoliterce(przegrana);

                }
                else if (V == C) {
                    literkapoliterce(sprawdzaniepredkosci2);
                    literkapoliterce(wygrana);

                }
                else if (V < 400000) {
                    literkapoliterce(sprawdzaniepredkosci3);
                    literkapoliterce(przegrana);

                }
                else if (V > 400000 && V < C)
                    literkapoliterce(sprawdzaniepredkosci4);
                    literkapoliterce(wygrana);
               
                break;

            }
            else {
                literkapoliterce(info);
                std::cin >> informacje.rodzajpaliwa;
            }
        }
    }
