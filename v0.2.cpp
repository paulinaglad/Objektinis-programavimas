#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <time.h>
#include <numeric>
#include <iomanip>
#include <iostream>


using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    float rezultatas;
};

double vidurkis(vector<int> nd)
{
    int sum = std::accumulate(nd.begin(), nd.end(), 0.0);
    double mean = sum / nd.size();
    return mean;
}
double mediana(vector<int> nd)
{
    if (nd.size() == 1 ){return nd.back()*1.00;}
    return 0.5 * (nd[nd.size() / 2 - 1] + nd[nd.size() / 2]);
}

bool studentu_skaiciaus_patikra(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false)
        {
            return false;
        }
    }
    if (stoi(str) <= 0)
    {
        return false;
    }
    return true;
}
bool tfstring_patikra(string str)
{
    if(str == "1" || str == "0")
    {
        return true;
    }
    return false;
}
bool egz_patikra(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false)
        {
            return false;
        }
    }
    if (stoi(str) <= 0 || stoi(str) >10)
    {
        return false;
    }
    return true;
}
bool nd_patikra(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false)
        {
            return false;
        }
    }
    if (stoi(str) <= 0 )
    {
        return false;
    }
    return true;
}
int ivesti_studentu_skaiciu(string zinute, string klaidoszinute)
{
    string strskaicius;
    cout<<zinute;
    cin>>strskaicius;
    while(studentu_skaiciaus_patikra(strskaicius) == false)
    {
        cout<<klaidoszinute;
        cin>>strskaicius;
    }
    return stoi(strskaicius);
}
int ivesti_skaiciu_t_f(string zinute, string klaidoszinute)
{
    string strskaicius;
    cout<<zinute;
    cin>>strskaicius;
    while(tfstring_patikra(strskaicius) == false)
    {
        cout<<klaidoszinute;
        cin>>strskaicius;
    }
    return stoi(strskaicius);
}
int ivesti_egz(string zinute, string klaidoszinute)
{
    string strskaicius;
    cout<<zinute;
    cin>>strskaicius;
    while(egz_patikra(strskaicius) == false)
    {
        cout<<klaidoszinute;
        cin>>strskaicius;
    }
    return stoi(strskaicius);
}
int ivesti_nd(string zinute, string klaidoszinute)
{
    string strskaicius;
    cout<<zinute;
    cin>>strskaicius;
    while(nd_patikra(strskaicius) == false)
    {
        cout<<klaidoszinute;
        cin>>strskaicius;
    }
    return stoi(strskaicius);
}

bool palyginimas(studentas st1, studentas st2)
{
    if(st1.vardas < st2.vardas) {return true;}
    return false;
}

vector<studentas> rusiavimas(vector<studentas>  studentai)
{
     sort(studentai.begin(), studentai.end(), palyginimas);
     return studentai;
}

vector<studentas> ivedimas()
{
ifstream failas;
vector<studentas> studentai;
try
    {
        failas.open("kursiokai.txt");
        string dummyLine;
        string temp;
        while(!failas.eof())
            {
            getline(failas,dummyLine);
            studentas st;
            failas>>st.vardas>>st.pavarde;
            for(int i = 0 ; i < 5;i++)
                {
                    failas>>temp;
                    if(!egz_patikra(temp)){throw 1;}
                    st.nd.push_back(stoi(temp));
                }
            failas>>temp;
            if(!egz_patikra(temp)){throw 1;}
            st.egz = stoi(temp);
            studentai.push_back(st);
            }
            failas.close();
    }
    catch(...)
    {
        cout<<"Patikrinkite failo pavadinima, turini ir vieta"<<endl; exit(1);
    }
            return studentai;
    }
int main()
{
    vector<studentas> studentai;
    int txtarne = ivesti_skaiciu_t_f("Ar norite ivesti duomenis is failo?  0 - Ne 1 - Taip :  ","Iveskite 0 arba 1: " );
    if(txtarne == 1)
    {
        studentai = ivedimas();
    }
    else
        {
        srand(time(NULL));
        int n;
        int ndn;
        n = ivesti_studentu_skaiciu("Iveskite studentu kieki: ","Iveskite teigiama sveika skaiciu: ");

        for (int i = 0; i < n; i++)
        {
            studentas st;
            cout << "Iveskite varda: ";
            cin >> st.vardas;
            cout << "Iveskite pavarde: ";
            cin >> st.pavarde;
            int nd = 11;
            int argeneruoti = ivesti_skaiciu_t_f("Ar generuoti duomenis automatiskai? 0/1:  ", "Iveskite 0 arba 1: ");
            if (argeneruoti == 0)
            {
                while(nd>10)
                    {
                    nd = ivesti_nd("Iveskite pirma namu darba:  ","Turite ivesti bent viena namu darbo pazymi:  ");
                    }
                while (nd <=10 )
                {
                    st.nd.push_back(nd);
                    nd = ivesti_nd("Iveskite nd ( Nutraukimui iveskite skaiciu > 10):  ","Iveskite sveika teigiama skaiciu tarp 0 ir 10 :  ");
                }

                }

            if (argeneruoti == 1)
            {
                int gensk;
                gensk = ivesti_studentu_skaiciu("Iveskite kiek nd generuoti:  ","Iveskite sveika teigiama skaicius:  ");
                for (int j = 0; j < gensk; j++)
                {
                    int randsk = 1 + (rand() % 10);
                    cout << "ND " << j + 1 << " : " << randsk << endl;
                    st.nd.push_back(randsk);
                }
            }
            st.egz = ivesti_egz("Iveskite egzamino rezultata: ", "Iveskite sveika skaiciu tarp 0 ir 10:  ");
            studentai.push_back(st);
            cout<<"------------Sekmingai----prideta----------"<<endl;


        }
    }

    cout << "--------------------------------------------------------------------------------------" << endl;
         cout<<left<<setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20)<<"Galutinis (Vid.)"<<setw(20)<< "Galutinis (Med.)"<< endl;
    cout << "--------------------------------------------------------------------------------------" << endl;

    studentai = rusiavimas(studentai);


    for (studentas st : studentai)
    {
        cout<< setw(20) << st.vardas << setw(20) << st.pavarde;
        cout<< setw(20) << fixed << setprecision( 2 )<<vidurkis(st.nd) * 0.4 + 0.6 * st.egz;
        cout<< setw(20) << fixed << setprecision( 2 )<< mediana(st.nd) * 0.4 + 0.6 * st.egz<< endl;
    }

    return 0;
}
