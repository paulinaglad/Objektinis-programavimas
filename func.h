#include <bits/stdc++.h>
#include <iostream>
#include <chrono>

using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    float rezultatas;
};

vector<studentas> ivedimas_vector(int kiek);

list<studentas> ivedimas_list(int kiek);

void vector_dalijimas_mano_budas(vector<studentas> studentai);

void list_dalijimas_mano_budas(list<studentas> studentai);

void vector_dalijimas_1_budas(vector<studentas> studentai);

void list_dalijimas_1_budas(list<studentas> studentai);

void vector_dalijimas_2_budas(vector<studentas> studentai);

void list_dalijimas_2_budas(list<studentas> studentai);

void testuoti_vektorius(int kiek);

void testuoti_listus(int kiek);
