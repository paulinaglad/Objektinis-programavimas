#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <time.h>


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
    auto n = nd.size();
    float average = 0.0f;
    if ( n != 0)
    {
        average = accumulate( nd.begin(), nd.end(), 0.0) / n;
    }
}
double mediana(vector<int> nd)
{
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
    if (stoi(str) < 0 || stoi(str) >10)
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

int main()
{
    srand(time(NULL));

    int n;
    int ndn;
    n = ivesti_studentu_skaiciu("Iveskite studentu kieki: ","Iveskite teigiama sveika skaiciu: ");
    studentas studentai[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Iveskite varda: ";
        cin >> studentai[i].vardas;
        cout << "Iveskite pavarde: ";
        cin >> studentai[i].pavarde;
        int nd = 0;
        int argeneruoti = ivesti_skaiciu_t_f("Ar generuoti duomenis automatiskai? 0/1:  ", "Iveskite 0 arba 1: ");
        if (argeneruoti == 0)
        {
            while (nd <=10)
            {
                nd = ivesti_nd("Iveskite nd ( Nutraukimui iveskite skaiciu > 10):  ","Iveskite sveika teigiama skaiciu tarp 0 ir 10 :  ");
                studentai[i].nd.push_back(nd);
            }
            studentai[i].nd.pop_back();

        }
        if (argeneruoti == 1)
        {
            int gensk;
            gensk = ivesti_studentu_skaiciu("Iveskite kiek nd generuoti:  ","Iveskite sveika teigiama skaicius:  ");
            for (int j = 0; j < gensk; j++)
            {
                int randsk = 1 + (rand() % 10);
                cout << "ND " << j + 1 << " : " << randsk << endl;
                studentai[i].nd.push_back(randsk);
            }
        }
        studentai[i].egz = ivesti_egz("Iveskite egzamino rezultata: ", "Iveskite sveika skaiciu tarp 0 ir 10:  ");
        int medianaARvidurkis;

        medianaARvidurkis = ivesti_skaiciu_t_f("Kaip skaiciuoti? 0 - Vidurkis, 1 - Mediana :   ", "Iveskite 0 arba 1  :  ");
        if (medianaARvidurkis == 0)
        {
            studentai[i].rezultatas = vidurkis(studentai[i].nd) * 0.4 + 0.6 * studentai[i].egz;
        }
        if (medianaARvidurkis == 1)
        {
            studentai[i].rezultatas = mediana(studentai[i].nd) * 0.4 + 0.6 * studentai[i].egz;
        }
        cout<<"**********************************"<<endl;
    }
    cout << "------------------------------------" << endl;
    cout << "Vardas       Pavarde       Galutinis" << endl;
    cout << "------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << studentai[i].vardas << "       " << studentai[i].pavarde << "       " << printf("%.1f", studentai[i].rezultatas) << endl;
    }

    return 0;
}
