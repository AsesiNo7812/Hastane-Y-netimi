#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Personel {
protected:
    string Ad, Soyad, Bolum;
    int Id;
    double Maas;
    double calismaSaati;
    double fazlamesai;
    static int personelSayisi;

public:
    
    Personel(string ad, string soyad, string bolum, double maas, int id,int fazlamesai)
        : Ad(ad.empty() ? "Bilinmiyor" : ad)
        , Soyad(soyad.empty() ? "Bilinmiyor" : soyad)
        , Bolum(bolum.empty() ? "Bilinmiyor" : bolum)
        , Maas(maas<0 ? 0 : maas)
        , Id(id<0 ? 0 : id)
        , calismaSaati(0)
        , fazlamesai(fazlamesai<0 ? 0 : fazlamesai) {
        personelSayisi++;
        
    }

    virtual ~Personel() {}

    virtual void bilgiGoster()=0;
    virtual void zamYap(double oran)=0;

    string getAdSoyad() const {
        return Ad + " " + Soyad;
    }

    double getMaas() const {
        return Maas;
    }
    static int getPersonelsayisi(){
        return personelSayisi;
    }
};
int Personel::personelSayisi = 0;
class Hasta {
private:
    string Ad, Soyad, Sikayet;
    int Tckno, Yas;
    static int hastaSayisi;
public:
    Hasta(string ad, string soyad, int tc, int yas, string sikayet)
        : Ad(ad.empty() ? "Bilinmiyor" : ad)
        , Soyad(soyad.empty() ? "Bilinmiyor" : soyad)
        , Tckno(tc<0 ? 0 : tc)
        , Yas(yas<0 ? 0 : yas)
        , Sikayet(sikayet.empty() ? "Bilinmiyor" : sikayet) {
        hastaSayisi++;
    }
    static int getHastaSayisi(){
        return hastaSayisi;
    }
    void bilgiGoster() const {
        cout << "Hasta: " << Ad << " " << Soyad << endl;
        cout << "TC: " << Tckno << endl;
        cout << "Yas: " << Yas << endl;
        cout << "Sikayet: " << Sikayet << endl;
    }

    string getAdSoyad() const { return Ad + " " + Soyad; }
    int getTC() const { return Tckno; }
    string getSikayet() const { return Sikayet; }
};
int Hasta::hastaSayisi = 0;


class Doktor : public Personel {
public:
    Doktor(string ad, string soyad, string bolum, double maas, int id,int fazlamesai)
        : Personel(ad.empty() ? "Bilinmiyor" : ad,
        soyad.empty() ? "Bilinmiyor" : soyad,
        bolum.empty() ? "Bilinmiyor" : bolum,
        maas<0 ? 0 : maas,
        id<0 ? 0 : id,
        fazlamesai<0 ? 0 : fazlamesai) {
        calismaSaati = 40;
    }

    void bilgiGoster()override {
        cout << "[DOKTOR]\n";
        cout<<"------------------\n";
        cout << "Ad: " << Ad << endl;
        cout << "Soyad: " << Soyad << endl;
        cout << "Bolum: " << Bolum << endl;
        cout << "Maas: " << Maas << endl;
        cout << "ID: " << Id << endl;
        cout << "Calisma Saati: " << calismaSaati << endl;
        cout << "Fazla Mesai: " << fazlamesai << endl;
    }
    void zamYap(double oran) override {
        cout << "Doktorun zam yapilmadan once maasi: " << Maas << endl;
        Maas += Maas * oran+fazlamesai*200; // Doktora %10 zam
        cout << "zam yapildiktan sonraki ! " << "maas=" << Maas << endl;
    }

    void receteYaz(const Hasta& hasta, string teshis, string ilacAdi, string doz) const {
        cout << "\n--- RECETE ---\n";
        cout << "Doktor: " << getAdSoyad() << endl;
        cout << "Hasta: " << hasta.getAdSoyad() << endl;
        cout << "TC: " << hasta.getTC() << endl;
        cout << "Sikayet: " << hasta.getSikayet() << endl;
        cout << "Teshis: " << teshis << endl;
        cout << "Ilac: " << ilacAdi << endl;
        cout << "Doz: " << doz << endl;
    }

    void dosyayaYaz(const Hasta& hasta, string teshis, string ilacAdi, string doz) const {
        ofstream file("receteler.txt", ios::app);
            file << "\n--- RECETE ---\n";
        file << "Doktor: " << getAdSoyad() << endl;
        file << "Hasta: " << hasta.getAdSoyad() << endl;
        file << "TC: " << hasta.getTC() << endl;
        file << "Sikayet: " << hasta.getSikayet() << endl;
        file << "Teshis: " << teshis << endl;
        file << "Ilac: " << ilacAdi << endl;
        file << "Doz: " << doz << endl;
        file.close();
    }
};
class Hemsire : public Personel {
public:
    Hemsire(string ad, string soyad, string bolum, double maas,int id, int fazlamesai)
        : Personel(ad.empty() ? "Bilinmiyor" : ad
        , soyad.empty() ? "Bilinmiyor" : soyad
        , bolum.empty() ? "Bilinmiyor" : bolum
        , maas<0 ? 0 : maas
        , id<0 ? 0 : id
        , fazlamesai<0 ? 0 : fazlamesai){
        calismaSaati = 38;
    }
    void bilgiGoster() override {
        cout << "[HEMSIRE]\n";
         cout<<"------------------\n";
        cout << "Ad: " << Ad << endl;
        cout << "Soyad: " << Soyad << endl;         
        cout << "Bolum: " << Bolum << endl;
        cout << "Maas: " << Maas << endl;
        cout << "ID: " << Id << endl;
        cout << "Calisma Saati: " << calismaSaati << endl;
        cout << "Fazla Mesai: " << fazlamesai << endl;
    }
        void zamYap(double oran) override {
            cout << "Hemsirenin zam yapilmadan once maasi: " << Maas << endl;
            Maas += Maas * oran+fazlamesai*120; // Hemsireye %10 zam
            cout << "zam yapildiktan sonraki ! " << "maas=" << Maas << endl;
    }
    
    // Hastanin var olup olmadigini sorgula
    bool hastaVarMi(const vector<Hasta*>& hastalar, const string& hastaAdi) const {
        for (const auto& hasta : hastalar) {
            if (hasta->getAdSoyad() == hastaAdi) {
                return true;
            }
        }
        return false;
    }
    
    void serumBagla(const vector<Hasta*>& hastalar, string hastaAdi) const {
        if (!hastaVarMi(hastalar, hastaAdi)) {
            cout << "HATA: " << hastaAdi << " adinda hasta sistemde bulunamadi!" << endl;
            return;
        }
        cout << "Hemsire " << getAdSoyad() << ", " << hastaAdi << " kisisine serum bagladi." << endl;
    }
    
    void ilacVer(const vector<Hasta*>& hastalar, string hastaAdi, string ilacAdi) const {
        if (!hastaVarMi(hastalar, hastaAdi)) {
            cout << "HATA: " << hastaAdi << " adinda hasta sistemde bulunamadi!" << endl;
            return;
        }
        cout << "Hemsire " << getAdSoyad() << ", " << hastaAdi << " kisisine " << ilacAdi << " ilacini verdi." << endl;
    }
    
    void bakimYap(const vector<Hasta*>& hastalar, string hastaAdi) const {
        if (!hastaVarMi(hastalar, hastaAdi)) {
            cout << "HATA: " << hastaAdi << " adinda hasta sistemde bulunamadi!" << endl;
            cout << "Hemsirenin bakım yapması için hastanın sistemde kayıtlı olması gerekmektedir!" << endl;
            return;
        }
        cout << "Hemsire " << getAdSoyad() << ", " << hastaAdi << " kisisine bakim yapti." << endl;
    }
};
class IdariPersonel : public Personel {
public:
    IdariPersonel(string ad, string soyad, string bolum, double maas, int id,int fazlamesai)
        : Personel(ad.empty() ? "Bilinmiyor" : ad
        , soyad.empty() ? "Bilinmiyor" : soyad
        , bolum.empty() ? "Bilinmiyor" : bolum
        , maas<0 ? 0 : maas
        , id<0 ? 0 : id
        , fazlamesai<0 ? 0 : fazlamesai) {
        calismaSaati = 30;
    }

    void bilgiGoster() override {
        cout << "[IDARI PERSONEL]\n";
        cout<<"------------------\n";
        cout << "Ad: " << Ad << endl;
        cout << "Soyad: " << Soyad << endl;     
        cout << "Bolum: " << Bolum << endl;
        cout << "Maas: " << Maas << endl;
        cout << "ID: " << Id << endl;
        cout << "Calisma Saati: " << calismaSaati << endl;
        cout << "Fazla Mesai: " << fazlamesai << endl;
    }
    void zamYap(double oran) override {
        cout << "Idari personelin zam yapilmadan once maasi: " << Maas << endl;
        Maas += Maas * oran+fazlamesai*100; // Idari personele %10 zam
        cout << "zam yapildiktan sonraki ! " << "maas=" << Maas << endl;
    }
};

int main() {
    vector<Personel*> personeller;
    vector<Hasta*>hastalar;

    // Nesneler
    
    Doktor* d1 = new Doktor("Adem", "Karaca", "Kardiyoloji", 5000, 1, 15);
    Doktor* d2 = new Doktor("kerem", "calis", "Dahiliye", 7000, 2, 20);
    IdariPersonel* i1 = new IdariPersonel("Lale", "Kara", "Yonetim", 4000, 3, 5);
    Hemsire* hemsire1 = new Hemsire("Ayse", "Demir", "Genel", 3000,4, 10);
    // Hasta ve reçete
    Hasta* h1 = new Hasta("Mehmet", "Tan", 123456789, 40, "Bas agrisi");
    Hasta* h2 = new Hasta("Arda", "Kent", 987654321, 35, "Diyabet");
    Hasta* h3 = new Hasta("Fatma", "Yilmaz",978563412, 30, "grip");
    
    //Vectore ekleme
    personeller.push_back(d1);
    personeller.push_back(d2);
    personeller.push_back(i1);
    personeller.push_back(hemsire1);
    hastalar.push_back(h1);
    hastalar.push_back(h2);
    hastalar.push_back(h3);
    // Personelleri yazdır 
    cout << "\n--- PERSONEL LISTESI ---\n";
    for (int i = 0; i < personeller.size(); i++) {
        personeller[i]->bilgiGoster();
        cout << "--------------\n";
    }
    
    
    //Hastalari yazdir
    cout << "\n---HASTA LISTESI---\n";
    for (int i = 0; i < hastalar.size(); i++) {
        hastalar[i]->bilgiGoster();
        cout << "---------------\n";
    }

    // Zam yap
    cout << "\n--- ZAM UYGULANIYOR (%10) ---\n";

    for (int i = 0; i < personeller.size(); i++) {
        personeller[i]->zamYap(0.10);
        cout<<personeller[i]->getAdSoyad();
        cout << " maasi ";
        cout<<personeller[i]->getMaas();
        cout << " oldu." << endl;
        cout << "--------------\n";
    }
    // Hasta ve Personel sayisi
    cout << "\n---Personel ve Hasta Sayisi---\n" << endl;
    cout<<"Personel Sayisi: "<<d1->getPersonelsayisi() << endl;
    cout <<"Hasta Sayisi: "<< h1->getHastaSayisi() << endl;

  cout << "\n---Hemsirenin muayene ettigi hastalar---\n";
    hemsire1->serumBagla(hastalar, "Fatma Yilmaz");
    hemsire1->ilacVer(hastalar, "Fatma Yilmaz", "Parol");
    hemsire1->bakimYap(hastalar, "Fatma Yilmaz");
    
    // Var olmayan hasta icin deneme
    cout << "\n---Var olmayan hasta icin deneme---\n";
    hemsire1->bakimYap(hastalar, "Ali Veli");
    d1->receteYaz(*h1, "Migren", "Parol", "500mg");
    d2->receteYaz(*h2, "Diyabet", "Matofin", "500mg");
    // Dosyaya yazma
    d1->dosyayaYaz(*h1, "Migren", "Parol", "500mg");
    d2->dosyayaYaz(*h2, "Diyabet", "Matofin", "500mg");
    // Belleği temizle
    for (int i = 0; i < personeller.size(); i++) {
        delete personeller[i];
    }
    for (int i = 0; i < hastalar.size(); i++) {
        delete hastalar[i];
    }

    return 0;
}