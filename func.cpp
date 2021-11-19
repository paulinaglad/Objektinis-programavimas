#include "func.h"

using namespace std;

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
        return studentai;
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
        return studentai;
}

void vector_dalijimas_mano_budas(vector<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
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

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout<<dydis<<" VECTOR dalijimas MANO budas: "<<time/std::chrono::milliseconds(1)/1000.0<<" sec"<<endl;
}
void list_dalijimas_mano_budas(list<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
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

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout<<dydis<<" LIST dalijimas MANO budas: "<<time/std::chrono::milliseconds(1)/1000.0<<" sec"<<endl;
}

void vector_dalijimas_1_budas(vector<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
    vector<studentas> kvaili;
    vector<studentas> protingi;
    for(int i = 0 ; i < dydis; i++)
    {
        studentas stud = studentai[i];
        if(stud.egz < 5)
        {
            kvaili.push_back(stud);
        }
        else
        {
            protingi.push_back(stud);
        }


    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout<<dydis<<" VECTOR dalijimas 1 budu: "<<time/std::chrono::milliseconds(1)/1000.0<<" sec"<<endl;
}

void list_dalijimas_1_budas(list<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
    vector<studentas> kvaili;
    vector<studentas> protingi;
    for(studentas stud: studentai)
    {
        if(stud.egz < 5)
        {
            kvaili.push_back(stud);
        }
        else
        {
            protingi.push_back(stud);
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout<<dydis<<" LIST dalijimas 1 budu: "<<time/std::chrono::milliseconds(1)/1000.0<<" sec"<<endl;
}

void vector_dalijimas_2_budas(vector<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
    vector<studentas> kvaili;
    for(studentas stud: studentai)
    {
        if(stud.egz < 5)
        {
            kvaili.push_back(stud);
        }

    }
    studentai.erase(std::remove_if(studentai.begin(), studentai.end(), [](studentas stud)
    {
        return stud.egz < 5;
    }), studentai.end());

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout<<dydis<<" VECTOR dalijimas 2 budu: "<<time/std::chrono::milliseconds(1)/1000.0<<" sec"<<endl;
}

void list_dalijimas_2_budas(list<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
    vector<studentas> kvaili;
    for(studentas stud: studentai)
    {
        if(stud.egz < 5)
        {
            kvaili.push_back(stud);
        }

    }
    studentai.erase(std::remove_if(studentai.begin(), studentai.end(), [](studentas stud)
    {
        return stud.egz < 5;
    }), studentai.end());

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout<<dydis<<" LIST dalijimas 2 budu: "<<time/std::chrono::milliseconds(1)/1000.0<<" sec"<<endl;
}

void testuoti_vectorius(int kiek)
{


vector<studentas> studentai = ivedimas_vector(kiek);

vector_dalijimas_mano_budas(studentai);
vector_dalijimas_1_budas(studentai);
vector_dalijimas_2_budas(studentai);


cout<<endl;
}

void testuoti_listus(int kiek)
{


list<studentas> studentai = ivedimas_list(kiek);

list_dalijimas_mano_budas(studentai);
list_dalijimas_1_budas(studentai);
list_dalijimas_2_budas(studentai);


cout<<endl;
}

