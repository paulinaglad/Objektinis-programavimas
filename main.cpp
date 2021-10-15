#include "header.h"
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
