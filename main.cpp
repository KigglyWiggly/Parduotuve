#include <iostream>
using namespace std;

class Preke{
private:
    string Pavadinimas;
    double Kaina;
    int Kiekis;
public:
    void setPavadinimas(string pavadinimas){
        Pavadinimas = pavadinimas;
    }
    string getPavadinimas(){
        return Pavadinimas;
    }
    void setKaina(double kaina){
        Kaina = kaina;
    }
    double getKaina(){
        return Kaina;
    }
    void setKiekis(int kiekis){
        Kiekis = kiekis;
    }
    int getKiekis(){
        return Kiekis;
    }
};

class Parduotuve{
private:
    Preke Preke[16];
    double suma;
public:
    void Nieko()
    {
        for(int i=0;i<16;i++)
        {
            suma=0;
            Preke[i].setPavadinimas("");
            Preke[i].setKaina(0);
            Preke[i].setKiekis(0);
        }
    }
    void Atvezti(string pavadinimas, double kaina)
    {
        for(int i=0;i<16;i++)
        {
            if(Preke[i].getPavadinimas() == pavadinimas)
            {
                if(Preke[i].getKiekis() == 0)
                    cout<<Preke[i].getPavadinimas()<<" pripildytas sandelyje"<<endl;
                int kiekis=Preke[i].getKiekis();
                kiekis++;
                Preke[i].setKiekis(kiekis);
                break;
            }

            else if(Preke[i].getPavadinimas() == "")
            {
                Preke[i].setPavadinimas(pavadinimas);
                Preke[i].setKaina(kaina);
                Preke[i].setKiekis(1);
                break;

            }
        }
    }
    void Parduoti(string pavadinimas)
    {
        for(int i=0;i<16;i++)
        {
            if(Preke[i].getPavadinimas() == pavadinimas)
            {
                if(Preke[i].getKiekis() == 0)
                {
                    cout<<Preke[i].getPavadinimas()<<" nebera sandelyje"<<endl;
                    break;
                }
                int kiekis=Preke[i].getKiekis();
                kiekis--;
                Preke[i].setKiekis(kiekis);
                //--//
                suma+=Preke[i].getKaina();
                //--//
            }
        }
    }
    void Pelnas()
    {
        cout<<"Parduotuves pelnas yra "<<suma<<endl;
    }
};

int main()
{
    Parduotuve p;
    p.Nieko();
    p.Atvezti("Pienas",0.99);
    p.Atvezti("Duona",1.99);
    p.Parduoti("Duona");
    p.Parduoti("Pienas");
    p.Parduoti("Pienas");
    p.Atvezti("Pienas",0.99);
    p.Parduoti("Pienas");
    p.Pelnas();
    return 0;
}
