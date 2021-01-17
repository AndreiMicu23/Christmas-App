#include <iostream>
using namespace std;
class Inventar_Jucarii
{
private:
    string nume;
    int pret=0;
public:
    void set_nume(string nume)
    {
        this->nume = nume;
    }
    void set_pret(int pret)
    {
        this->pret = pret;
    }
    string get_nume()
    {
        return this->nume;
    }
    int get_pret()
    {
        return this->pret;
    }
};
class Scrisoare
{
public:
    string nume;
    string prenume;
    int varsta;
    string oras;
    string wishlist[3];
    string culoare;
    Scrisoare(string n, string p, int age, string city, string lista[3],string c)
    {
        int i;
        nume = n;
        prenume = p;
        varsta = age;
        oras = city;
        for (i = 0;i < 3;i++)
            wishlist[i] = lista[i];
        culoare = c;
    }
    Scrisoare();
    ~Scrisoare();
   
};
Scrisoare::~Scrisoare(void)
{
   
}
/* clasa copil mosteneste atributele clasei scrisoare
        clasa copil are un atribut in plus, status,
        pentru ca niciun copil nu stie daca este cuminte/rau
 */
class Copil:public Scrisoare
{
public:
    string status;
    Copil();
    Copil(string n, string p, int age, string city, string lista[3], string c, string s) :Scrisoare{ n,p,age,city,lista,c }
    {
        int i;
        nume = n;
        prenume = p;
        varsta = age;
        oras = city;
        for (i = 0;i < 3;i++)
            wishlist[i] = lista[i];
        culoare = c;
        status = s;
    }
    void afisare(Copil c)
    {
        cout << "Nume: " << c.nume << "\n";
        cout << "Prenume: " << c.prenume << "\n";
        cout << "Varsta: " << c.varsta << "\n";
        cout << "Oras: " << c.oras << "\n";
        cout << "Lista dorinte: " << c.wishlist[0] << ", " << c.wishlist[1] << ", " << c.wishlist[2] << "\n";
        cout << "Culoare plic: " << c.culoare << "\n";
    }
    void afisare(Copil c, string status)
    {
        cout << "Status copil: " << status<<"\n";
    }  
    ~Copil();
};
Copil::~Copil(void)
{

}
class Elfi
{
public:
    float cadouri_primite(Copil copil, Inventar_Jucarii jucarie[])
    {
        int buget;
        int  i, j;
        if (copil.status == "cuminte")
        {
            buget = 100;
            int ok = 0;
            for (i = 0;i < 3;i++)
                for (j = 0;j < 15;j++)
                    if (copil.wishlist[i] == jucarie[j].get_nume() && buget - jucarie[j].get_pret() >= 0)
                    {
                        ok++;
                        if (buget - jucarie[j].get_pret() == 0)
                            cout << copil.wishlist[i];
                        else cout << copil.wishlist[i] << ", ";
                        buget = buget - jucarie[j].get_pret();
                    }
            if (ok == 0)
            {
                cout << "cadou default de 100$ ";
                buget = 0;
            }
            else
            {
                if (buget == 1)
                    cout << buget << " acadea";
                if (buget <= 19 && buget > 1)
                    cout << buget << " acadele";
                if (buget > 19)
                    cout << buget << " de acadele";
            }
            return buget;
        }
        if (copil.status == "rau")
        {
            buget = 10;
            int ok = 0;
            for (i = 0;i < 3;i++)
                for (j = 0;j < 15;j++)
                    if (copil.wishlist[i] == jucarie[j].get_nume() && buget - jucarie[j].get_pret() > 0)
                    {
                        ok++;
                        cout << copil.wishlist[i] << ", ";
                        buget = buget - jucarie[j].get_pret();
                    }
            if (ok == 0)
            {
                cout << "cadou default de 10$ ";
                buget = 0;
            }
            else
            {
                if (buget == 1)
                    cout << buget << " acadea";
                if (buget <= 19 && buget > 1)
                    cout << buget << " acadele";
                if (buget > 19)
                    cout << buget << " de acadele";
            }
            return buget;
        }
    }

};
class Troli
{
public:
    template<class X>
    int ambalaj_cadou(X culoare1)
    {
        if (culoare1 == "albastru")
            return 1;
        if (culoare1 == "roz")
            return 0;
        else
            throw "culoare gresita\n";
    }
    int nr_carbuni(Copil copil)
    {
        if (copil.status == "cuminte")
            return 0;
        return 1;
    }
};
class MosCraciun
{
private:
    int m[5][5];
public:
    friend class Doamna_Craciun;
    void set_drum(int distanta,int i,int j)
    {
        this->m[i][j] = distanta;
    }
    int get_drum(int i,int j)
    {
        return this->m[i][j];
    }
    void drum(MosCraciun m)
    {
        int minimul1 = 5000, minimul2 = 5000, minimul3 = 5000, minimul4 = 5000;
        int minp1, minp2, minp3, minp4;
        /* minp1,minp2,minp3,minp4 sunt variabile pe care le
        folosesc pentru a nu merge de 2 ori in acelasi oras.
            de la al 2-lea for j nu are voie sa mai ia o
            valoare pe care a luat-o inainte */
        int next, j;
        for (j = 0;j < 5;j++)
            if (m.get_drum(0, j) < minimul1 && m.get_drum(0, j) > 0)
                minimul1 = m.get_drum(0, j);
        for (j = 0;j < 5;j++)
            if (m.get_drum(0, j) == minimul1)
            {
                minp1 = j;
                next = j;
                break;
            }
        if (next == 0)
            cout << "Romaniemi(0), ";
        else if (next == 1)
            cout << "Istanbul(1), ";
        else if (next == 2)
            cout << "Ankara(2), ";
        else if (next == 3)
            cout << "Bursa(3), ";
        else cout << "Antalya(4), ";

        for (j = 0;j < 5;j++)
            if (m.get_drum(next, j) < minimul2 && m.get_drum(next, j) > 0 && j!=minp1)//daca nu am fost deja in oras
                minimul2 = m.get_drum(next,j);
        for (j = 0;j < 5;j++)
            if (m.get_drum(next, j) == minimul2)
            {
                minp2 = j;
                next = j;
                break;
            }
        if (next == 0)
            cout << "Romaniemi(0), ";
        else if (next == 1)
            cout << "Istanbul(1), ";
        else if (next == 2)
            cout << "Ankara(2), ";
        else if (next == 3)
            cout << "Bursa(3), ";
        else cout << "Antalya(4), ";

        for (j = 0;j < 5;j++)
            if (m.get_drum(next,j) < minimul3 && m.get_drum(next,j)>0  && j != minp1 && j != minp2)//daca nu am fost deja in oras
                minimul3 = m.get_drum(next,j);
        for (j = 0;j < 5;j++)
            if (m.get_drum(next, j) == minimul3)
            {
                minp3 = j;
                next = j;
                break;
            }
        if (next == 0)
            cout << "Romaniemi(0), ";
        else if (next == 1)
            cout << "Istanbul(1), ";
        else if (next == 2)
            cout << "Ankara(2), ";
        else if (next == 3)
            cout << "Bursa(3), ";
        else cout << "Antalya(4), ";

        for (j = 0;j < 5;j++)
            if (m.get_drum(next,j) < minimul4 && m.get_drum(next,j)>0
                && j != minp1 && j != minp2 && j!=minp3)//daca nu am fost deja in oras
                minimul4 = m.get_drum(next,j);
        for (j = 0;j < 5;j++)
            if (m.get_drum(next, j) == minimul4)
            {
                minp4 = j;
                next = j;
                break;
            }
        if (next == 0)
            cout << "Romaniemi(0)";
        else if (next == 1)
            cout << "Istanbul(1)";
        else if (next == 2)
            cout << "Ankara(2)";
        else if (next == 3)
            cout << "Bursa(3)";
        else cout << "Antalya(4)";
        cout << "\n" << minimul1 << " + " << minimul2 << " + " << minimul3 << " + " << minimul4 <<" = "<< minimul1 + minimul2 + minimul3 + minimul4<<" KM";
    }
};
class Abstracta
{
public: virtual void drumul_mosului(MosCraciun drum_optim) = 0;//abstractizarea
};
class Doamna_Craciun:public Abstracta
{
public:
    int buget_acadele(int acadele)
    {
        return acadele;
    }
   float buget_carbuni(int carbuni)
    {
       return carbuni * 0.5;
    }
   void drumul_mosului(MosCraciun drumul_optim)
   {
       drumul_optim.drum(drumul_optim);
   }
};
int main()
{
    // am creat inventarul jucariilor pe care elfii le au in atelier
    Inventar_Jucarii j[15];
    j[0].set_nume("masina");
    j[0].set_pret(40);
    j[1].set_nume("urs de plus");
    j[1].set_pret(25);
    j[2].set_nume("papusa");
    j[2].set_pret(30);
    j[3].set_nume("tren");
    j[3].set_pret(40);
    j[4].set_nume("adidasi");
    j[4].set_pret(80);
    j[5].set_nume("elicopter");
    j[5].set_pret(55);
    j[6].set_nume("minge de fotbal");
    j[6].set_pret(40);
    j[7].set_nume("casa");
    j[7].set_pret(70);
    j[8].set_nume("prajituri");
    j[8].set_pret(5);
    j[9].set_nume("avion");
    j[9].set_pret(45);
    j[10].set_nume("bomboane");
    j[10].set_pret(7);
    j[11].set_nume("ochelari de soare");
    j[11].set_pret(35);
    j[12].set_nume("pisica");
    j[12].set_pret(20);
    j[13].set_nume("racheta de tenis");
    j[13].set_pret(45);
    j[14].set_nume("tricou");
    j[14].set_pret(25);
    cout << "Inventar(Nume/pret):\n";
    int i;
    for (i = 0;i < 15;i++)
    {
        cout << i + 1 << ")";
        cout << j[i].get_nume() << "->" << j[i].get_pret() << "$\n";
    }
    cout << "\n";

    // am initializat listele de dorinte ale celor 5 copii
    // fiecare copil are o lista cu 3 dorinte
    string lista1[3] = { "masina","casa","avion" };
    string lista2[3] = { "papusa","urs de plus","casa" };
    string lista3[3] = { "elicopter","minge de fotbal","prajituri" };
    string lista4[3] = { "minge de fotbal","tren","avion" };
    string lista5[3] = { "urs de plus","papusa","bomboane" };

    // scrisorile copiilor
    Scrisoare s1("Micu", "Andrei", 10, "Istanbul", lista1, "albastru");
    Scrisoare s2("Popescu", "Diana", 9, "Ankara", lista2, "roz");
    Scrisoare s3("Akbar", "Mohamed", 12, "Antalya", lista3, "albastru");
    Scrisoare s4("Stanciu", "Abdul", 11, "Bursa", lista4, "albastru");
    Scrisoare s5("Ionescu", "Amalia", 10, "Istanbul", lista5, "roz");

    // copiii
    Copil copil1(s1.nume, s1.prenume, s1.varsta, s1.oras, lista1, s1.culoare, "cuminte");
    Copil copil2(s2.nume, s2.prenume, s2.varsta, s2.oras, lista2, s2.culoare, "rau");
    Copil copil3(s3.nume, s3.prenume, s3.varsta, s3.oras, lista3, s3.culoare, "rau");
    Copil copil4(s4.nume, s4.prenume, s4.varsta, s4.oras, lista4, s4.culoare, "cuminte");
    Copil copil5(s5.nume, s5.prenume, s5.varsta, s5.oras, lista5, s5.culoare, "cuminte");

    // afisarea scrisorilor
    cout << "Scrisoare 1" << "\n";
    copil1.afisare(copil1);
    copil1.afisare(copil1, copil1.status);
    cout << "\n";

    cout << "Scrisoare 2" << "\n";
    copil2.afisare(copil2);
    copil2.afisare(copil2, copil2.status);
    cout << "\n";

    cout << "Scrisoare 3" << "\n";
    copil3.afisare(copil3);
    copil3.afisare(copil3, copil3.status);
    cout << "\n";

    cout << "Scrisoare 4" << "\n";
    copil4.afisare(copil4);
    copil4.afisare(copil4, copil4.status);
    cout << "\n";

    cout << "Scrisoare 5" << "\n";
    copil5.afisare(copil5);
    copil5.afisare(copil5, copil5.status);
    cout << "\n";

    cout << "\n                                          REZULTATE:"<<"\n\n";
    // afisarea listelor cu cadourile pe care le vor primi copiii 
    float buget_carbuni = 0, buget_acadele = 0;
    int carbuni = 0, acadele = 0;
    int buget_extra = 0;
    Elfi elf1;
    cout << "Copilul " << copil1.nume << " " << copil1.prenume << " " << "va primi: ";
    acadele = acadele + elf1.cadouri_primite(copil1, j);
    cout << "\n";
    cout << "Copilul " << copil2.nume << " " << copil2.prenume << " " << "va primi: ";
    acadele = acadele + elf1.cadouri_primite(copil2, j);
    cout << "\n";
    cout << "Copilul " << copil3.nume << " " << copil3.prenume << " " << "va primi: ";
    acadele = acadele + elf1.cadouri_primite(copil3, j);
    cout << "\n";
    cout << "Copilul " << copil4.nume << " " << copil4.prenume << " " << "va primi: ";
    acadele = acadele + elf1.cadouri_primite(copil4, j);
    cout << "\n";
    cout << "Copilul " << copil5.nume << " " << copil5.prenume << " " << "va primi: ";
    acadele = acadele + elf1.cadouri_primite(copil5, j);
    cout << endl;
 
    // ambalajele folosite de troli
    Troli trol1;
    cout << endl;
    int nrf = 0, nrb = 0;//numarul de fete si de baieti
    try
    {
        if (trol1.ambalaj_cadou<string>(copil1.culoare) == 1)
            nrb++;
        if (trol1.ambalaj_cadou<string>(copil1.culoare) == 0)
            nrf++;
    }
    catch(const char* msg)
    {
        cout << msg;
    }
    try 
    {
        if (trol1.ambalaj_cadou<string>(copil2.culoare) == 1)
            nrb++;
        if (trol1.ambalaj_cadou<string>(copil2.culoare) == 0)
            nrf++;
    }
    catch (const char* msg)
    {
        cout << msg;
    }
    try 
    {
        if (trol1.ambalaj_cadou<string>(copil3.culoare) == 1)
            nrb++;
        if (trol1.ambalaj_cadou<string>(copil3.culoare) == 0)
            nrf++;
    }
    catch (const char* msg)
    {
        cout << msg;
    }
    try
    {
        if (trol1.ambalaj_cadou<string>(copil4.culoare) == 1)
            nrb++;
        if (trol1.ambalaj_cadou<string>(copil4.culoare) == 0)
            nrf++;
    }
    catch (const char* msg)
    {
        cout << msg;
    }
    try
     {
        if (trol1.ambalaj_cadou<string>(copil5.culoare) == 1)
            nrb++;
        if (trol1.ambalaj_cadou<string>(copil5.culoare) == 0)
            nrf++;
    }
    catch (const char* msg)
    {
        cout << msg;
    }
    cout << "Trolii au folosit:\n" << nrb << " ambalaje pentru baieti\n" << nrf << " ambalaje pentru fete\n";
    cout << endl;
    if (trol1.nr_carbuni(copil1))
        carbuni++;
    if (trol1.nr_carbuni(copil2))
        carbuni++;
    if (trol1.nr_carbuni(copil3))
        carbuni++;
    if (trol1.nr_carbuni(copil4))
        carbuni++;
    if (trol1.nr_carbuni(copil5))
        carbuni++;
    Doamna_Craciun doamna_craciun;
    buget_carbuni = doamna_craciun.buget_carbuni(carbuni);
    buget_acadele = doamna_craciun.buget_acadele(acadele);
    buget_extra = buget_acadele + buget_carbuni;

    // bugetul extra
    if (buget_extra <= 19)
        cout << "Bugetul extra calculat de Doamna Craciun este: " << buget_extra << "$\n";
    else cout << "Bugetul extra calculat de Doamna Craciun este: " << buget_extra << " de $\n";


    /* matricea in care punem distantele dintre orase
       matricea este de tip Mos Craciun pentru a putea 
       fi utilizata si de Doamna Craciun, care este 
       o clasa prieten cu clasa Mos Craciun*/
    MosCraciun drum_minim;
    drum_minim.set_drum(0, 0, 0);
    drum_minim.set_drum(2841, 0, 1);
    drum_minim.set_drum(2991, 0, 2);
    drum_minim.set_drum(2933, 0, 3);
    drum_minim.set_drum(3308, 0, 4);
    drum_minim.set_drum(2841, 1, 0);
    drum_minim.set_drum(0, 1, 1);
    drum_minim.set_drum(351, 1, 2);
    drum_minim.set_drum(92, 1, 3);
    drum_minim.set_drum(482, 1, 4);
    drum_minim.set_drum(2991, 2, 0);
    drum_minim.set_drum(351, 2, 1);
    drum_minim.set_drum(0, 2, 2);
    drum_minim.set_drum(326, 2, 3);
    drum_minim.set_drum(384, 2, 4);
    drum_minim.set_drum(2933, 3, 0);
    drum_minim.set_drum(92, 3, 1);
    drum_minim.set_drum(326, 3, 2);
    drum_minim.set_drum(0, 3, 3);
    drum_minim.set_drum(394, 3, 4);
    drum_minim.set_drum(3308, 4, 0);
    drum_minim.set_drum(482, 4, 1);
    drum_minim.set_drum(384, 4, 2);
    drum_minim.set_drum(394, 4, 3);
    drum_minim.set_drum(0, 4, 4);

    int k;
    int a;
    cout << "\n";
    for (i = 0;i < 5;i++)
    {
        for (k = 0;k < 5;k++)
        {
            a = drum_minim.get_drum(i, k);
            cout << a << " ";
        }
        cout << "\n";
    }

    //drumul optim pe care Mos Craciun va merge
    cout << "\n";
    cout << "Drumul: Rovaniemi(0), ";
    drum_minim.drum(drum_minim);
    cout << "\n";

    //Doamna Craciun stie drumul Mosului
    cout << "\nDoamna Craciun stie drumul pe care va merge Mos Craciun\n";
    cout << "Drumul: Romaniemi(0), ";
    doamna_craciun.drumul_mosului(drum_minim);
    cout << "\n";
}