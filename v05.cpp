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

vector<studentas> ivedimas_vector(int kiek)
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

void dalijimas_vector(vector<studentas> studentai)
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


}

void testuoti_vector(int kiek)
{
clock_t begin = clock();

vector<studentas> studentai = ivedimas_vector(kiek);

dalijimas_vector(studentai);

clock_t end = clock();
double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;

cout<<endl;
}

list<studentas> ivedimas_list(int kiek)
{
clock_t begin = clock();
ifstream failas;
list<studentas> studentai;
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


void dalijimas_list(list<studentas> studentai)
{
    int dydis = studentai.size();
    // Dalijimas
    clock_t begin = clock();
    list<studentas> kvaili;
    list<studentas> protingi;
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


}

void testuoti_list(int kiek)
{
clock_t begin = clock();

list<studentas> studentai = ivedimas_list(kiek);

dalijimas_list(studentai);

clock_t end = clock();
double laikas_sekundemis = double(end - begin) / CLOCKS_PER_SEC;

cout<<endl;
}


int main()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);
    cout<<"VECTOR TESTAVIMAS"<<endl;
    testuoti_vector(1000);
    testuoti_vector(10000);
    testuoti_vector(100000);
    testuoti_vector(1000000);
    testuoti_vector(10000000);

   cout<<"LIST TESTAVIMAS"<<endl;
   testuoti_list(1000);
   testuoti_list(10000);
   testuoti_list(100000);
   testuoti_list(1000000);
   testuoti_list(10000000);

    return 0;
}
