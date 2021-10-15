#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <time.h>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <random>


using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    float rezultatas;
};
void isvedimas(vector<studentas> studentai, string failo_pavadinimas, string zinute, int dydis);

double vidurkis(vector<int> nd)
{
    int suma = 0;
    for(int i: nd)
        {
        suma+=i;
        }
    return suma/nd.size();
}




void generavimas(int kiek)
{

    clock_t begin = clock();

    vector<studentas> studentai;
    for(int i = 0 ; i < kiek; i++)
        {
        studentas temp;
        temp.vardas = "Vardas" + to_string(i+1);
        temp.pavarde = "Pavarde" + to_string(i+1);
        int ND1 = rand()%10 + 1;
        int ND2 = rand()%10 + 1;
        int ND3 = rand()%10 + 1;
        int ND4 = rand()%10 + 1;
        int ND5 = rand()%10 + 1;

        temp.nd.push_back(ND1);
        temp.nd.push_back(ND2);
        temp.nd.push_back(ND3);
        temp.nd.push_back(ND4);
        temp.nd.push_back(ND5);

        temp.egz = rand()%10 + 1;


        temp.rezultatas = 0.4*vidurkis(temp.nd) + 0.6*temp.egz;
        studentai.push_back(temp);
        }
        string pavadinimas = "studentai" + to_string(kiek) + ".txt";
        ofstream failas;
        failas.open(pavadinimas);
        for(studentas st: studentai)
            {
            failas<<st.vardas<<" "<<st.pavarde<<" "<<st.nd[0]<<" "<<st.nd[1]<<" "<<st.nd[2]<<" "<<st.nd[3]<<" "<<st.nd[4]<<" "<<st.egz<<" "<<st.rezultatas<<endl;
            }
        failas.close();
        clock_t end = clock();
        double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;
        cout<<kiek<<" failo sukurimo trukme: "<<laikas_sekundemis<<" sec."<<endl;
}

vector<studentas> ivedimas(int kiek)
{
clock_t begin = clock();
ifstream failas;
vector<studentas> studentai;
        string pavadinimas = "studentai" + to_string(kiek) + ".txt";
        failas.open(pavadinimas);
        string temp;
        for(int i = 0 ; i < kiek; i++)
            {
            studentas st;
            failas>>st.vardas>>st.pavarde;
            for(int i = 0 ; i < 5;i++){failas>>temp;st.nd.push_back(stoi(temp));}
            failas>>temp;
            st.egz = stoi(temp);
            failas>>temp;
            st.rezultatas = stof(temp);
            studentai.push_back(st);
            }
            failas.close();

        clock_t end = clock();
        double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;
        cout<<kiek<<" failo nuskaitymo trukme: "<<laikas_sekundemis<<" sec."<<endl;
        return studentai;
}


bool palyginimas(studentas st1, studentas st2)
{
    if(st1.rezultatas< st2.rezultatas) {return true;}
    return false;
}


    vector<studentas> rusiavimas(vector<studentas>  studentai)
{
     clock_t begin = clock();

     sort(studentai.begin(), studentai.end(), palyginimas);
     clock_t end = clock();

     double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;
     cout<<studentai.size()<<" failo rusiavimo trukme: "<<laikas_sekundemis<<" sec."<<endl;
     return studentai;
}
void dalijimas(vector<studentas> studentai)
{
    int dydis = studentai.size();
    // Dalijimas
    clock_t begin = clock();
    vector<studentas> kvaili;
    vector<studentas> protingi;
    for(int i = 0 ; i < dydis; i++)
        {
        studentas stud = studentai.back();
        studentai.pop_back();
        if(stud.egz < 5)
            {
                kvaili.push_back(stud);
            }
        else
            {
                protingi.push_back(stud);
            }


        }
    clock_t end = clock();
    double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;
    cout<<dydis<<" failo dalijimo trukme: "<<laikas_sekundemis<<" sec."<<endl;
    // Kvailu isvedimas
    isvedimas(kvaili,"kvaili"," kvailu isvedimo trukme",dydis);
    // Protingu isvedimas
    isvedimas(protingi,"protingi"," protingu isvedimo trukme",dydis);


}
void isvedimas(vector<studentas> studentai, string failo_pavadinimas, string zinute, int dydis)
{
    clock_t begin = clock();

    string pavadinimas = "studentai" + to_string(dydis) + failo_pavadinimas +  ".txt";
    ofstream failas;
        failas.open(pavadinimas);
        for(studentas st: studentai)
            {
                failas<<st.vardas<<" "<<st.pavarde<<" "<<st.nd.front()<<" "<<st.nd.front()<<" "<<st.nd.front()<<" "<<st.nd.front()<<" "<<st.nd.front()<<" "<<st.rezultatas<<endl;
            }
        failas.close();

    clock_t end = clock();
    double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;
    cout<<dydis<<zinute<<": "<<laikas_sekundemis<<" sec."<<endl;

}
void testuoti(int kiek)
{
clock_t begin = clock();

generavimas(kiek);
vector<studentas> studentai = ivedimas(kiek);
studentai = rusiavimas(studentai);

dalijimas(studentai);

clock_t end = clock();
double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;
cout<<endl;
cout<<to_string(kiek)<<" irasu testo trukme: "<<laikas_sekundemis<<" sec."<<endl;
cout<<"---------------------------------------------------"<<endl;
}

int main()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);

    testuoti(1000);
    testuoti(10000);
    testuoti(100000);
    testuoti(1000000);
    testuoti(10000000 );


    return 0;
}
