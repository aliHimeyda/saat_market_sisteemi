#include<iostream>
#include<locale.h>
#include<math.h>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<chrono>
#include<fstream>


using namespace std;

class mesaj
{
public:
	mesaj* ilk;
	mesaj* son;
	mesaj* sonraki;
	string yazı;
	mesaj(string);
	void mesajekle(mesaj*);
	void mesajlarıYAZ();
};

mesaj::mesaj(string y)
{
	this->yazı = y;
	this->sonraki = nullptr;
}
void mesaj::mesajekle(mesaj* yeni) {
	mesaj* gec = ilk;
	if (gec == nullptr) { gec = yeni; ilk = yeni; son = yeni; }
	else if (gec->sonraki == nullptr) { gec->sonraki = yeni; son = yeni; }
	else
	{
		while (gec->sonraki != nullptr) { gec = gec->sonraki; }
		gec->sonraki = yeni; son = yeni;
	}

}
void mesaj::mesajlarıYAZ() {

	mesaj* gec = ilk;
	int sayac = 1;
	cout << endl << endl;
	while (gec != nullptr)
	{
		cout << sayac << ". mesaj :" << endl << endl;
		cout << gec->yazı << endl << endl; gec = gec->sonraki;
		sayac++;
	}

}
class urun
{
public:
	int maliyet;
	int fiyat;
	string id;
	string marka;
	string modelISMI;
	urun* sonraki;
	urun* ilk = nullptr;
	urun* ilkistenilen;
	urun* ilktukenmis;
	urun* son;
	urun* sonistenilen;
	urun* sontukenmis;

	string renk;
	int suGecirmezlik;
	string cinsiyet;
	string uretimTARİH;
	int degerlendirmePuanı;
	int satılmaSayısı;
	int agirlik;
	string mekanizma;
	string geceISIGI;
	string kasacapi;
	string pilKapasitesi;
	string kordonMAT;
	string kasaMAT;
	urun(int, int, string, string, string, string, int, string, string, int, int, string, string, string, string, string, string);
	void urunEKLE(urun*);
	void istenilenURUNlistesi(urun*);
	void tukenmisURUNlistesi(urun*);
	void urunSIL(string);
	urun* urunGUNCELLE(string);
	urun* urunARA(string);
	void urunOZELLIGIyazdir(string);
	void tumURUNLERIyazdir();
	void istenilenURUNLERİyazdir();
	void tukenmisURUNLERİyazdir();
	void ucuzdanBUYUGE();
	urun* urunKONUMUgetir(int);
	int urunlerinTOPLAMmaliyeti();
	int urunSAYISI(char);
	void urunuOZELLİKileARA(char);
	void tumURUNLERİNidsiYAZDIR();
	void tumURUNLREzamYAP(float);
	void minimumMALİYETLİURUN();
	void maximumMALİYETLİURUN();
	void urunleriDOSYAYAyazdir();
	urun* urunleriDOSYADANoku(ifstream&);
};
urun::urun(int maliyet, int fiyat, string id, string marka, string modelismi, string renk, int sugecirmezlik, string cinsiyet, string uretimtarihi, int degerlendirme, int agirlik, string mekanizma, string gece, string kasacapi, string pil, string kordon, string kasa) {
	this->maliyet = maliyet;
	this->fiyat = fiyat;
	this->id = id;
	this->marka = marka;
	this->modelISMI = modelismi;
	this->renk = renk;
	this->suGecirmezlik = sugecirmezlik;
	this->cinsiyet = cinsiyet;
	this->uretimTARİH = uretimtarihi;
	this->degerlendirmePuanı = degerlendirme;
	this->agirlik = agirlik;
	this->mekanizma = mekanizma;
	this->geceISIGI = gece;
	this->kasacapi = kasacapi;
	this->pilKapasitesi = pil;
	this->kordonMAT = kordon;
	this->kasaMAT = kasa;
	this->sonraki = nullptr;
}
void urun::urunEKLE(urun* yeni) {
	urun* gec = ilk;
	if (gec == nullptr) { gec = yeni; ilk = yeni; son = yeni; }
	else if (gec == ilk && gec->sonraki == nullptr) { gec->sonraki = yeni; son = yeni; }
	else
	{
		while (gec->sonraki != nullptr) { gec = gec->sonraki; }
		gec->sonraki = yeni; son = yeni;
	}
}
void urun::istenilenURUNlistesi(urun* yeni) {
	urun* gec = ilkistenilen;
	if (gec == nullptr) { gec = yeni; sonistenilen = yeni; ilkistenilen = yeni; }
	else if (gec == ilkistenilen && gec->sonraki == nullptr) { gec->sonraki = yeni; sonistenilen = yeni; }
	else
	{
		while (gec->sonraki != nullptr) { gec = gec->sonraki; }
		gec->sonraki = yeni; sonistenilen = yeni;
	}
}
void urun::tukenmisURUNlistesi(urun* yeni) {
	urun* gec = ilktukenmis;
	if (gec == nullptr) { gec = yeni; sontukenmis = yeni; ilktukenmis = yeni; }
	else if (gec->sonraki == nullptr) { gec->sonraki = yeni; sontukenmis = yeni; }
	else
	{
		while (gec->sonraki != nullptr) { gec = gec->sonraki; }
		gec->sonraki = yeni; sontukenmis = yeni;
	}

}
void urun::urunSIL(string id) {
	urun* gec = ilk;
	while (gec->id != id) { gec = gec->sonraki; }
	if (gec == ilk)
	{
		ilk = gec->sonraki;
		delete gec;
		cout << endl << "başarıyla silindi ..." << endl;
	}
	else if (gec == son)
	{
		urun* temp = ilk;
		while (temp->sonraki != gec)
		{
			temp = temp->sonraki;
		}
		son = temp;
		temp->sonraki = nullptr;
		delete gec;
		cout << endl << "başarıyla silindi ..." << endl;
	}
	else
	{
		urun* temp = ilk;
		while (temp->sonraki != gec)
		{
			temp = temp->sonraki;
		}
		temp->sonraki = gec->sonraki;
		delete gec;
		cout << endl << "başarıyla silindi ..." << endl;
	}
}
urun* urun::urunGUNCELLE(string id) {
	urun* gec = ilk;
	while (gec->id != id) { gec = gec->sonraki; if (gec == nullptr) { return nullptr; } }
	return gec;
}
urun* urun::urunARA(string id) {
	urun* gec = ilk;
	while (gec->id != id) { gec = gec->sonraki; if (gec == nullptr) { return nullptr; } }
	return gec;

}
void urun::urunOZELLIGIyazdir(string id) {
	urun* gec = ilk;
	while (gec->id != id) { gec = gec->sonraki; }

	cout << endl << endl;
	cout << "+----------------------------------+" << endl;
	cout << "| " << "İD : " << gec->id << endl;
	cout << "| " << "MARKA : " << gec->marka << endl;
	cout << "| " << "MODEL : " << gec->modelISMI << endl;
	cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
	cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
	cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
	cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
	cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
	cout << "| " << "RENK : " << gec->renk << endl;
	cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
	cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
	cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
	cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
	cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
	cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
	cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
	cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
	for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
	cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
	cout << "+----------------------------------+" << endl;
}
void urun::tumURUNLERIyazdir() {
	urun* gec = ilk;
	cout << endl << "neredeyse hazır ..." << endl << endl;
	int sayac = 1;
	while (gec->sonraki != nullptr)
	{
		cout << sayac << ". ÜRÜN " << endl;
		cout << "+----------------------------------+" << endl;
		cout << "| " << "İD : " << gec->id << endl;
		cout << "| " << "MARKA : " << gec->marka << endl;
		cout << "| " << "MODEL : " << gec->modelISMI << endl;
		cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
		cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
		cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
		cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
		cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
		cout << "| " << "RENK : " << gec->renk << endl;
		cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
		cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
		cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
		cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
		cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
		cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
		cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
		cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
		for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
		cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
		cout << "+----------------------------------+" << endl;
		gec = gec->sonraki;
		sayac++;
		if (gec == son)
		{
			cout << sayac << ". ÜRÜN " << endl;
			cout << "+----------------------------------+" << endl;
			cout << "| " << "İD : " << gec->id << endl;
			cout << "| " << "MARKA : " << gec->marka << endl;
			cout << "| " << "MODEL : " << gec->modelISMI << endl;
			cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
			cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
			cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
			cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
			cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
			cout << "| " << "RENK : " << gec->renk << endl;
			cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
			cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
			cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
			cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
			cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
			cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
			cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
			cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
			for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
			cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
			cout << "+----------------------------------+" << endl;
			break;
		}

	}




}
void urun::istenilenURUNLERİyazdir() {
	urun* gec = ilkistenilen;
	int sayac = 1;
	cout << endl << "neredeyse hazır ..." << endl << endl;

	while (gec != nullptr)
	{
		cout << sayac << ". ÜRÜN " << endl;
		cout << "+----------------------------------+" << endl;
		cout << "| " << "İD : " << gec->id << endl;
		cout << "| " << "MARKA : " << gec->marka << endl;
		cout << "| " << "MODEL : " << gec->modelISMI << endl;
		cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
		cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
		cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
		cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
		cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
		cout << "| " << "RENK : " << gec->renk << endl;
		cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
		cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
		cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
		cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
		cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
		cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
		cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
		cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
		for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
		cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
		cout << "+----------------------------------+" << endl;
		gec = gec->sonraki;
		sayac++;

	}

}
void urun::tukenmisURUNLERİyazdir() {
	urun* gec = ilktukenmis;
	cout << endl << "neredeyse hazır ..." << endl << endl;
	int sayac = 1;
	while (gec != nullptr)
	{
		cout << sayac << ". ÜRÜN " << endl;
		cout << "+----------------------------------+" << endl;
		cout << "| " << "İD : " << gec->id << endl;
		cout << "| " << "MARKA : " << gec->marka << endl;
		cout << "| " << "MODEL : " << gec->modelISMI << endl;
		cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
		cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
		cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
		cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
		cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
		cout << "| " << "RENK : " << gec->renk << endl;
		cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
		cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
		cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
		cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
		cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
		cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
		cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
		cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
		for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
		cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
		cout << "+----------------------------------+" << endl;
		gec = gec->sonraki;
		sayac++;

	}


}
void urun::ucuzdanBUYUGE() {
	urun* dizi[30];

	for (int i = 0; i < urunSAYISI('a'); i++) { dizi[i] = urunKONUMUgetir(i); }

	for (int i = 0; i < urunSAYISI('a') - 1; ++i) {
		for (int j = 0; j < urunSAYISI('a') - i - 1; ++j) {
			if (dizi[j]->fiyat > dizi[j + 1]->fiyat) {
				urun* gec = dizi[j];
				dizi[j] = dizi[j + 1];
				dizi[j + 1] = gec;
			}
		}
	}
	cout << endl << "neredeyse hazır ..." << endl << endl;
	cout << "İD :               ";
	cout << "MARKA :            ";
	cout << "MODEL :            ";
	cout << "MALİYET :          ";
	cout << "FİYATI :           ";
	cout << "SATILMA SAYISI :   ";
	cout << "DEĞEERLENDİRME :   " << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	for (int i = 0; i < urunSAYISI('a'); i++)
	{
		cout << setw(19) << left << dizi[i]->id << setw(19) << left << dizi[i]->marka << setw(19) << left << dizi[i]->modelISMI << setw(19) << left << dizi[i]->maliyet << setw(19) << left << dizi[i]->fiyat << setw(19) << left << dizi[i]->satılmaSayısı << dizi[i]->degerlendirmePuanı;
		for (int i = 0; i < dizi[i]->degerlendirmePuanı; i++) { cout << '*'; }
		cout << endl;
	}
	cout << endl << endl << "başarıyla yazdırıldı ..." << endl << endl;
}
urun* urun::urunKONUMUgetir(int indis) {
	urun* gec = ilk;

	for (int i = 0; i < indis; i++) { gec = gec->sonraki; }


	return gec;
}
int urun::urunlerinTOPLAMmaliyeti() {
	urun* gec = ilk;
	int toplam = 0;
	while (gec->sonraki != nullptr)
	{
		toplam += gec->maliyet;
		gec = gec->sonraki;
	}
	toplam += gec->maliyet;
	return toplam;
}
void urun::tumURUNLERİNidsiYAZDIR() {
	urun* gec = ilk;
	cout << endl;
	while (gec != nullptr)
	{
		cout << "+-------------------+" << endl;
		cout << "| " << setw(17) << left << gec->id << " |" << endl;
		gec = gec->sonraki;
	}
	cout << "+-------------------+" << endl;
}
int urun::urunSAYISI(char secenek) {
	urun* gec = ilk;
	int sayac = 0;
	string giris;
	int secim;
	switch (secenek)
	{
	case 'a':

		while (gec != nullptr)
		{
			sayac++;
			gec = gec->sonraki;
		}
		break;
	case 'b':
		cout << endl << "marka ismini giriniz --> ";
		cin >> giris;

		while (gec != nullptr)
		{
			if (gec->marka == giris)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;

				sayac++;
				gec = gec->sonraki;
			}
			else
			{
				gec = gec->sonraki;
			}
		}
		break;
	case 'c':
		cout << endl << "fiyatı giriniz --> ";
		cin >> secim;

		while (gec != nullptr)
		{
			if (gec->fiyat == secim)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;

				sayac++;
				gec = gec->sonraki;
			}
			else
			{
				gec = gec->sonraki;
			}
		}
		break;
	case 'd':
		cout << endl << "maliyeti giriniz --> ";
		cin >> secim;

		while (gec != nullptr)
		{
			if (gec->maliyet == secim)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;

				sayac++;
				gec = gec->sonraki;
			}
			else
			{
				gec = gec->sonraki;
			}
		}
		break;
	case 'e':
		cout << endl << "puanı giriniz --> ";
		cin >> secim;

		while (gec != nullptr)
		{
			if (gec->degerlendirmePuanı == secim)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;

				sayac++;
				gec = gec->sonraki;
			}
			else
			{
				gec = gec->sonraki;
			}
		}
		break;
	case 'f':
		cout << endl << "cinsiyeti giriniz --> ";
		cin >> giris;

		while (gec != nullptr)
		{
			if (gec->cinsiyet == giris)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;

				sayac++;
				gec = gec->sonraki;
			}
			else
			{
				gec = gec->sonraki;
			}
		}
		break;

	default:
		return 0;
		break;
	}
	return sayac;
}
void urun::urunuOZELLİKileARA(char secenek) {
	urun* gec;
	string giris;
	int secim;
	switch (secenek)
	{
	case 'a':
		cout << "aramak istediğiniz marka ismini giriniz --> ";
		cin >> giris;
		gec = ilk;
		while (gec != nullptr)
		{
			if (gec->marka == giris)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
			}
			gec = gec->sonraki;
		}
		cout << endl << giris << " markalı ürünler bunlardır ... " << endl << endl;
		break;
	case 'b':
		cout << "aramak istediğiniz model ismini giriniz --> ";
		cin >> giris;
		gec = ilk;
		while (gec != nullptr)
		{
			if (gec->modelISMI == giris)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
			}
			gec = gec->sonraki;
		}
		cout << endl << giris << " model isimli ürünler bunlardır ... " << endl << endl;
		break;
	case 'c':
		cout << "1) 0-1000 " << endl;
		cout << "2) 1000-1500 " << endl;
		cout << "3) 1501_2000 " << endl;
		cout << "4) 2001-2500 " << endl;
		cout << "5) 2501-3000 " << endl;
		cout << "6) 3001-10.000 " << endl;
		cout << endl << "fiyat aralığını seçiniz --> ";
		cin >> secim;
		if (secim == 2)
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (1000 <= gec->fiyat && gec->fiyat <= 1500)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "1000-1500 arası fiyatlı ürünler bunlardır ... " << endl << endl;
		}
		else if (secim == 3)
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (1501 <= gec->fiyat && gec->fiyat <= 2000)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "1501-2000 arası fiyatlı ürünler bunlardır ... " << endl << endl;
		}
		else if (secim == 4)
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (2001 <= gec->fiyat && gec->fiyat <= 2500)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "2001-2500 arası fiyatlı ürünler bunlardır ... " << endl << endl;
		}
		else if (secim == 5)
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (2501 <= gec->fiyat && gec->fiyat <= 3000)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "2501-3000 arası fiyatlı ürünler bunlardır ... " << endl << endl;
		}
		else if (secim == 6)
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (3001 <= gec->fiyat && gec->fiyat <= 10.000)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "3001-10.000 arası fiyatlı ürünler bunlardır ... " << endl << endl;
		}
		else
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (0 <= gec->fiyat && gec->fiyat <= 1000)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "0-1000 arası fiyatlı ürünler bunlardır ... " << endl << endl;
		}
		break;
	case 'd':
		cout << "1) 0-400 " << endl;
		cout << "2) 401-600 " << endl;
		cout << "3) 601_700 " << endl;
		cout << "4) 701-800 " << endl;
		cout << "5) 801-900 " << endl;
		cout << "6) 901-1000 " << endl;
		cout << endl << "maliyet aralığını seçiniz --> ";
		cin >> secim;
		if (secim == 1)
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (0 <= gec->maliyet && gec->maliyet <= 400)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "0-400 arası maliyetlı ürünler bunlardır ... " << endl << endl;
		}
		else if (secim == 2)
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (401 <= gec->maliyet && gec->maliyet <= 600)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "401-600 arası maliyetli ürünler bunlardır ... " << endl << endl;
		}
		else if (secim == 3)
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (601 <= gec->maliyet && gec->maliyet <= 700)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "601-700 arası maliyetli ürünler bunlardır ... " << endl << endl;
		}
		else if (secim == 4)
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (701 <= gec->maliyet && gec->maliyet <= 800)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "701-800 arası maliyetli ürünler bunlardır ... " << endl << endl;
		}
		else if (secim == 5)
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (801 <= gec->maliyet && gec->maliyet <= 900)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "801-900 arası maliyetli ürünler bunlardır ... " << endl << endl;
		}
		else
		{
			gec = ilk;
			while (gec != nullptr)
			{
				if (901 <= gec->maliyet && gec->maliyet <= 1000)
				{
					cout << "+----------------------------------+" << endl;
					cout << "| " << "İD : " << gec->id << endl;
					cout << "| " << "MARKA : " << gec->marka << endl;
					cout << "| " << "MODEL : " << gec->modelISMI << endl;
					cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
					cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
					cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
					cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
					cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
					cout << "| " << "RENK : " << gec->renk << endl;
					cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
					cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
					cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
					cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
					cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
					cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
					cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
					cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
					for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
					cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
					cout << "+----------------------------------+" << endl;
				}
				gec = gec->sonraki;
			}
			cout << "901-1000 arası maliyetli ürünler bunlardır ... " << endl << endl;
		}
		break;
	case 'e':
		cout << endl << "hangi cinsiyet için ürün arıyorsunuz ? --> ";
		cin >> giris;
		gec = ilk;
		while (gec != nullptr)
		{
			if (gec->cinsiyet == giris)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
			}
			gec = gec->sonraki;
		}
		cout << giris << " cinsiyetleri için ürünler bunlardır ... " << endl << endl;
		break;
	case 'f':
		cout << endl << "mekanizma tipini giriniz --> ";
		cin >> giris;
		gec = ilk;
		while (gec != nullptr)
		{
			if (gec->mekanizma == giris)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
			}
			gec = gec->sonraki;
		}
		cout << giris << " mekanizmalı ürünler bunlardır ... " << endl << endl;
		break;
	case 'ğ':
		cout << endl << "aramak istediğiniz rengi giriniz --> ";
		cin >> giris;
		gec = ilk;
		while (gec != nullptr)
		{
			if (gec->renk == giris)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
			}
			gec = gec->sonraki;
		}
		cout << giris << " renklilı ürünler bunlardır ... " << endl << endl;
		break;
	case 'r':
		cout << endl << "değerlendirme puanı giriniz --> ";
		cin >> secim;
		gec = ilk;
		while (gec != nullptr)
		{
			if (gec->degerlendirmePuanı == secim)
			{
				cout << "+----------------------------------+" << endl;
				cout << "| " << "İD : " << gec->id << endl;
				cout << "| " << "MARKA : " << gec->marka << endl;
				cout << "| " << "MODEL : " << gec->modelISMI << endl;
				cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
				cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
				cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
				cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
				cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
				cout << "| " << "RENK : " << gec->renk << endl;
				cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
				cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
				cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
				cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
				cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
				cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
				cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
				cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
			}
			gec = gec->sonraki;
		}
		cout << secim << " puanlı ürünler bunlardır ... " << endl << endl;
		break;
	default:
		break;
	}

}
void urun::tumURUNLREzamYAP(float yuzde) {
	urun* gec = ilk;
	while (gec != nullptr)
	{
		gec->fiyat = gec->fiyat + gec->fiyat * (yuzde / 100);
		gec = gec->sonraki;
	}

}
void urun::minimumMALİYETLİURUN() {
	urun* gec = ilk;
	int MIN = 5000;
	while (gec != nullptr)
	{
		if (gec->maliyet < MIN)
		{
			MIN = gec->maliyet;
			gec = gec->sonraki;
		}
		else
		{
			gec = gec->sonraki;
		}
	}
	gec = ilk;
	while (gec != nullptr)
	{
		if (gec->maliyet == MIN)
		{
			cout << "+----------------------------------+" << endl;
			cout << "| " << "İD : " << gec->id << endl;
			cout << "| " << "MARKA : " << gec->marka << endl;
			cout << "| " << "MODEL : " << gec->modelISMI << endl;
			cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
			cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
			cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
			cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
			cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
			cout << "| " << "RENK : " << gec->renk << endl;
			cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
			cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
			cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
			cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
			cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
			cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
			cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
			cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
			for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
			cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
			cout << "+----------------------------------+" << endl;
			gec = gec->sonraki;
		}
		else
		{
			gec = gec->sonraki;
		}
	}

}
void urun::maximumMALİYETLİURUN() {

	urun* gec = ilk;
	int MAX = 0;
	while (gec != nullptr)
	{
		if (gec->maliyet > MAX)
		{
			MAX = gec->maliyet;
			gec = gec->sonraki;
		}
		else
		{
			gec = gec->sonraki;
		}
	}
	gec = ilk;
	while (gec != nullptr)
	{
		if (gec->maliyet == MAX)
		{
			cout << "+----------------------------------+" << endl;
			cout << "| " << "İD : " << gec->id << endl;
			cout << "| " << "MARKA : " << gec->marka << endl;
			cout << "| " << "MODEL : " << gec->modelISMI << endl;
			cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
			cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
			cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
			cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
			cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
			cout << "| " << "RENK : " << gec->renk << endl;
			cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
			cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
			cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
			cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
			cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
			cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
			cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
			cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
			for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
			cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
			cout << "+----------------------------------+" << endl;
			gec = gec->sonraki;
		}
		else
		{
			gec = gec->sonraki;
		}
	}
}
void urun::urunleriDOSYAYAyazdir() {
	ofstream urunLISTESI("LISTE.txt", ios::out);
	urunLISTESI << setw(33) << setw(17) << "+--------------+" << setw(33) << endl;
	urunLISTESI << setw(33) << setw(17) << "| SAAT KÖŞESİ  |" << setw(33) << endl;
	urunLISTESI << setw(33) << setw(17) << "+--------------+" << endl << endl << endl;
	urunLISTESI << "ÜRÜNLER LİSTESİ :" << endl;
	urun* gec = ilk;
	int sayac = 1;
	while (gec->sonraki != nullptr)
	{
		urunLISTESI << sayac << ". ÜRÜN " << endl;
		urunLISTESI << "+----------------------------------+" << endl;
		urunLISTESI << "| " << "İD : " << gec->id << endl;
		urunLISTESI << "| " << "MARKA : " << gec->marka << endl;
		urunLISTESI << "| " << "MODEL : " << gec->modelISMI << endl;
		urunLISTESI << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
		urunLISTESI << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
		urunLISTESI << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
		urunLISTESI << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
		urunLISTESI << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
		urunLISTESI << "| " << "RENK : " << gec->renk << endl;
		urunLISTESI << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
		urunLISTESI << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
		urunLISTESI << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
		urunLISTESI << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
		urunLISTESI << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
		urunLISTESI << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
		urunLISTESI << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
		urunLISTESI << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
		for (int i = 0; i < gec->degerlendirmePuanı; i++) { urunLISTESI << '*'; }
		urunLISTESI << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
		urunLISTESI << "+----------------------------------+" << endl;
		gec = gec->sonraki;
		sayac++;
		if (gec == son)
		{
			urunLISTESI << sayac << ". ÜRÜN " << endl;
			urunLISTESI << "+----------------------------------+" << endl;
			urunLISTESI << "| " << "İD : " << gec->id << endl;
			urunLISTESI << "| " << "MARKA : " << gec->marka << endl;
			urunLISTESI << "| " << "MODEL : " << gec->modelISMI << endl;
			urunLISTESI << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
			urunLISTESI << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
			urunLISTESI << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
			urunLISTESI << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
			urunLISTESI << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
			urunLISTESI << "| " << "RENK : " << gec->renk << endl;
			urunLISTESI << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
			urunLISTESI << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
			urunLISTESI << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
			urunLISTESI << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
			urunLISTESI << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
			urunLISTESI << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
			urunLISTESI << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
			urunLISTESI << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
			for (int i = 0; i < gec->degerlendirmePuanı; i++) { urunLISTESI << '*'; }
			urunLISTESI << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
			urunLISTESI << "+----------------------------------+" << endl;
			break;
		}

	}

}
urun* urun::urunleriDOSYADANoku(ifstream& file) {
	string id, marka, modelISMI, uretimTARIH, cinsiyet, mekanizma, renk, pilKapasitesi, geceISIGI, kasaCapi, kasaMAT, kordonMAT;
	int maliyet, fiyat, agirlik;
	int suGecirmezlik, degerlendirmePuani, satilmaSayisi;

	string line;
	getline(file, line); id = line.substr(line.find(":") + 2);
	getline(file, line); marka = line.substr(line.find(":") + 2);
	getline(file, line); modelISMI = line.substr(line.find(":") + 2);
	getline(file, line); maliyet = stoi(line.substr(line.find(":") + 2));
	getline(file, line); fiyat = stoi(line.substr(line.find(":") + 2));
	getline(file, line); uretimTARIH = line.substr(line.find(":") + 2);
	getline(file, line); cinsiyet = line.substr(line.find(":") + 2);
	getline(file, line); mekanizma = line.substr(line.find(":") + 2);
	getline(file, line); renk = line.substr(line.find(":") + 2);
	getline(file, line); pilKapasitesi = line.substr(line.find(":") + 2);
	getline(file, line); suGecirmezlik = stoi(line.substr(line.find(":") + 2));
	getline(file, line); geceISIGI = line.substr(line.find(":") + 2);
	getline(file, line); kasaCapi = line.substr(line.find(":") + 2);
	getline(file, line); kasaMAT = line.substr(line.find(":") + 2);
	getline(file, line); kordonMAT = line.substr(line.find(":") + 2);
	getline(file, line); agirlik = stoi(line.substr(line.find(":") + 2));
	getline(file, line); degerlendirmePuani = stoi(line.substr(line.find(":") + 2));
	getline(file, line); satilmaSayisi = stoi(line.substr(line.find(":") + 2));

	// Boş satırı atla
	getline(file, line);

	return new urun(maliyet, fiyat, id, marka, modelISMI, renk, suGecirmezlik, cinsiyet, uretimTARIH, degerlendirmePuani, agirlik, mekanizma, geceISIGI, kasaCapi, pilKapasitesi, kordonMAT, kasaMAT);
}



int main() {
	setlocale(LC_ALL, "turkish");
	urun* komuta = new urun(500, 1500, "123_333_239", "casio", "MO923D", "kırmızı", 5, "kadın", "12.03.2002", 4, 50, "dijital", "var", "39mm", "3400 mAh", "çelik", "silikon");
	urun* yeniURUN;
	mesaj* yeniMESAJ;
	mesaj* mesajKomuta = new mesaj("  ");
	int secim;
	int deger;
	char secenek;
	string giris;
	int maliyet;
	int fiyat;
	string id;
	string marka;
	string modelISMI;
	urun* gec;
	int Syeniozellik;
	string Yyeniozellik;
	ifstream yeniurun("yeniurunlistesi.txt", ios::in);
	urun* u1 = new urun(500, 1500, "123_333_239", "casio", "MO923D", "kırmızı", 5, "kadın", "12.03.2002", 4, 50, "dijital", "var", "39mm", "3400 mAh", "çelik", "silikon");
	komuta->urunEKLE(u1);
	urun* u2 = new urun(600, 1800, "456_789_101", "rolex", "Submariner", "siyah", 10, "erkek", "25.06.2005", 5, 60, "mekanik", "yok", "42mm", "4000 mAh", "deri", "paslanmaz çelik");
	komuta->urunEKLE(u2);
	urun* u3 = new urun(300, 1200, "789_103_654", "seiko", "SKX007", "mavi", 5, "unisex", "30.11.2008", 4, 55, "mekanik", "var", "38mm", "3500 mAh", "kauçuk", "paslanmaz çelik");
	komuta->urunEKLE(u3);
	urun* u4 = new urun(800, 2500, "301_654_987", "omega", "Speedmaster", "gri", 10, "erkek", "15.09.2010", 4, 70, "otomatik", "var", "44mm", "4500 mAh", "metal", "paslanmaz çelik");
	komuta->urunEKLE(u4);
	urun* u5 = new urun(700, 2000, "654_907_321", "omega", "Aquaracer", "beyaz", 5, "kadın", "02.04.2012", 4, 65, "kuarz", "yok", "40mm", "3800 mAh", "silikon", "seramik");
	komuta->urunEKLE(u5);
	urun* u6 = new urun(500, 1500, "987_311_654", "casio", "G-Shock", "sarı", 20, "unisex", "18.07.2014", 4, 75, "dijital", "var", "48mm", "5000 mAh", "kauçuk", "plastik");
	komuta->urunEKLE(u6);
	urun* u7 = new urun(1000, 3000, "147_258_309", "fossil", "Navitimer", "kahverengi", 10, "erkek", "22.10.2016", 5, 80, "otomatik", "var", "46mm", "4800 mAh", "deri", "paslanmaz çelik");
	komuta->urunEKLE(u7);
	urun* u8 = new urun(400, 1000, "208_369_147", "fossil", "Grant", "bordo", 3, "kadın", "14.12.2018", 3, 45, "kuarz", "yok", "36mm", "3200 mAh", "deri", "paslanmaz çelik");
	komuta->urunEKLE(u8);
	urun* u9 = new urun(700, 2000, "399_147_258", "seiko", "Eco-Drive", "yeşil", 5, "unisex", "08.05.2020", 4, 55, "kuarz", "var", "38mm", "3600 mAh", "nylon", "titanyum");
	komuta->urunEKLE(u9);
	urun* u10 = new urun(800, 2800, "951_753_822", "omega", "Big Bang", "mor", 10, "kadın", "01.08.2015", 5, 70, "otomatik", "yok", "44mm", "4200 mAh", "kauçuk", "seramik");
	komuta->urunEKLE(u10);
	urun* u11 = new urun(900, 2700, "753_971_852", "rolex", "Luminor", "turuncu", 5, "erkek", "10.11.2013", 4, 75, "otomatik", "var", "45mm", "4500 mAh", "deri", "paslanmaz çelik");
	komuta->urunEKLE(u11);
	urun* u12 = new urun(600, 1900, "456_123_719", "rolex", "PRC 200", "beyaz", 3, "unisex", "28.03.2017", 4, 60, "kuarz", "yok", "41mm", "3900 mAh", "deri", "paslanmaz çelik");
	komuta->urunEKLE(u12);
	urun* u13 = new urun(900, 3200, "719_456_123", "seiko", "Master Collection", "sarı", 5, "erkek", "05.09.2019", 5, 80, "otomatik", "var", "43mm", "4300 mAh", "metal", "paslanmaz çelik");
	komuta->urunEKLE(u13);
	urun* u14 = new urun(500, 1500, "123_789_446", "casio", "Edifice", "siyah", 3, "kadın", "17.06.2014", 4, 50, "kuarz", "yok", "39mm", "3700 mAh", "silikon", "paslanmaz çelik");
	komuta->urunEKLE(u14);
	urun* u15 = new urun(700, 2200, "156_789_123", "seiko", "Presage", "gri", 5, "unisex", "11.12.2016", 4, 65, "otomatik", "var", "42mm", "4000 mAh", "deri", "paslanmaz çelik");
	komuta->urunEKLE(u15);
	urun* u16 = new urun(800, 2500, "689_123_456", "fossil", "Promaster", "mavi", 10, "erkek", "30.04.2018", 5, 70, "dijital", "var", "44mm", "4200 mAh", "kauçuk", "titanyum");
	komuta->urunEKLE(u16);
	urun* u17 = new urun(600, 1800, "123_456_289", "timex", "Weekender", "kahverengi", 3, "kadın", "02.02.2015", 3, 55, "kuarz", "yok", "38mm", "3500 mAh", "deri", "paslanmaz çelik");
	komuta->urunEKLE(u17);
	urun* u18 = new urun(700, 2000, "780_456_123", "casio", "Pro Trek", "yeşil", 5, "unisex", "19.08.2019", 4, 60, "dijital", "var", "41mm", "3800 mAh", "kauçuk", "plastik");
	komuta->urunEKLE(u18);
	urun* u19 = new urun(800, 2800, "456_123_780", "gucci", "G-Timeless", "siyah", 3, "kadın", "24.01.2017", 5, 65, "kuarz", "yok", "40mm", "3900 mAh", "deri", "paslanmaz çelik");
	komuta->urunEKLE(u19);
	urun* u20 = new urun(1100, 3000, "780_123_666", "patek philippe", "Nautilus", "beyaz", 10, "erkek", "09.07.2021", 5, 75, "otomatik", "yok", "43mm", "4100 mAh", "deri", "paslanmaz çelik");
	komuta->urunEKLE(u20);
	//istenilen ürün bağlı listesinin ilk elemanları....
	urun* Iu1 = new urun(550, 1600, "369_258_147", "Timex", "Expedition", "kahverengi", 3, "erkek", "03.10.2019", 4, 55, "kuarz", "yok", "40mm", "3800 mAh", "deri", "paslanmaz çelik");
	komuta->istenilenURUNlistesi(Iu1);
	urun* Iu2 = new urun(700, 2100, "258_147_369", "Swatch", "Sistem51", "siyah", 5, "unisex", "14.08.2017", 4, 60, "otomatik", "yok", "42mm", "3900 mAh", "kauçuk", "plastik");
	komuta->istenilenURUNlistesi(Iu2);
	urun* Iu3 = new urun(800, 2400, "147_369_258", "Fossil", "Neutra", "gri", 3, "erkek", "27.05.2020", 5, 65, "kuarz", "var", "44mm", "4000 mAh", "deri", "paslanmaz çelik");
	komuta->istenilenURUNlistesi(Iu3);
	urun* Iu4 = new urun(600, 1700, "369_258_147", "Casio", "Baby-G", "pembe", 5, "kadın", "09.03.2018", 4, 50, "dijital", "var", "38mm", "3700 mAh", "silikon", "plastik");
	komuta->istenilenURUNlistesi(Iu4);
	urun* Iu5 = new urun(900, 2600, "258_147_369", "Rolex", "Datejust", "mavi", 10, "kadın", "22.11.2015", 5, 70, "otomatik", "var", "41mm", "4100 mAh", "metal", "paslanmaz çelik");
	komuta->istenilenURUNlistesi(Iu5);
	//tükenmiş ürün bağlı listesinin ilk elemanları...
	urun* Tu1 = new urun(750, 2200, "147_369_258", "Tag Heuer", "Carrera", "siyah", 5, "erkek", "18.09.2019", 4, 65, "otomatik", "var", "43mm", "4200 mAh", "deri", "paslanmaz çelik");
	komuta->tukenmisURUNlistesi(Tu1);
	urun* Tu2 = new urun(850, 2700, "369_258_147", "Seiko", "Prospex", "turuncu", 10, "unisex", "07.07.2016", 5, 70, "otomatik", "yok", "45mm", "4300 mAh", "kauçuk", "paslanmaz çelik");
	komuta->tukenmisURUNlistesi(Tu2);
	urun* Tu3 = new urun(500, 1600, "258_147_369", "Casio", "Sheen", "beyaz", 3, "kadın", "29.04.2018", 4, 55, "kuarz", "yok", "36mm", "3500 mAh", "seramik", "paslanmaz çelik");
	komuta->tukenmisURUNlistesi(Tu3);
	urun* Tu4 = new urun(950, 3000, "147_369_258", "Breitling", "Superocean", "mavi", 10, "erkek", "12.12.2017", 5, 75, "otomatik", "var", "42mm", "4000 mAh", "deri", "paslanmaz çelik");
	komuta->tukenmisURUNlistesi(Tu4);
	urun* Tu5 = new urun(700, 2000, "369_258_147", "Tissot", "Everytime", "gri", 5, "unisex", "03.05.2019", 4, 60, "kuarz", "yok", "40mm", "3800 mAh", "deri", "paslanmaz çelik");
	komuta->tukenmisURUNlistesi(Tu5);

	mesaj* m1 = new mesaj("123_888_089 nolu ürün tükenmiş gözükmektedir");
	mesajKomuta->mesajekle(m1);
	mesaj* m2 = new mesaj("003_888_089 nolu ürün tükenmiş gözükmektedir");
	mesajKomuta->mesajekle(m2);
	mesaj* m3 = new mesaj("120_888_089 nolu ürün çok sık isteniyor");
	mesajKomuta->mesajekle(m3);
	mesaj* m4 = new mesaj("111_888_089 nolu ürünü stokta bulamadık");
	mesajKomuta->mesajekle(m4);
	mesaj* m5 = new mesaj("896_888_089 nolu ürün silinmiş durumda ");
	mesajKomuta->mesajekle(m5);



	cout << setw(33) << setw(17) << "+--------------+" << setw(33) << endl;
	cout << setw(33) << setw(17) << "| SAAT KÖŞESİ  |" << setw(33) << endl;
	cout << setw(33) << setw(17) << "+--------------+" << endl << endl << endl;
	cout << "saat köşesi kontrol sistemine hoş geldiniz  ....." << endl << "--------------------------------------------------------" << endl << endl;
anamenu:
	cout << "+---------------------------------------------------------------------------+\n";
	cout << "|1) Ürün ekle                                                               |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|2) Ürün sil                                                                |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|3) Ürün özelliklerini güncelle                                             |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|4) Listede ürün ara                                                        |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|5) elemanı tüm özellikleri ile yazdır                                      |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|6) mevcut ürünleri yazdır                                                  |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|7) tüm ürünleri fiyat olarak küçükten büyüğe sırala                        |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|8) tüm ürünlerin toplam maliyetini hesapla                                 |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|9) tüm ürünlere zam yap                                                    |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|10) Minimum maliyete sahip ürünü getir                                     |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|11) Maksimum maliyete sahip ürünü getir                                    |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|12) aynı özellikli ürünleri say                                            |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|13) Tüm ürünleri dosyaya yazdır                                            |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|14) Dosyadan ürünleri oku                                                  |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|15) istenilen ürünleri yazdır                                              |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|16) tükenmiş ürünleri yazdır                                               |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|17) müdüre iletilen mesajları yazdır                                       |\n"
		<< "+---------------------------------------------------------------------------+\n"
		<< "|18) Çıkış yap                                                              |\n"
		<< "+---------------------------------------------------------------------------+\n";
	cout << endl << "gerçekleştirmek istediğiniz işlemin numarasını giriniz --> ";
	cin >> secim;

	switch (secim)
	{
	case 1:
		cout << endl;
		cout << "ürünün maliyetini giriniz --> ";
		cin >> maliyet;
		cout << endl;
		cout << "ürünün satış fiyatını giriniz --> ";
		cin >> fiyat;
		cout << endl;
		cout << "ürünün İD numarasını giriniz --> ";
		cin >> id;
		cout << endl;
		cout << "ürünün markasını giriniz --> ";
		cin >> marka;
		cout << endl;
		cout << "ürünün model ismini giriniz --> ";
		cin >> modelISMI;
		cout << endl;
		// sunum yaparken iş uzamasın diye , diğer özellikleri standart olacak şekilde ayarladım...
		yeniURUN = new urun(maliyet, fiyat, id, marka, modelISMI, "siyah", 5, "erkek", "15.05.2024", 5, 80, "dijital", "var", "43mm", "4300 mAh", "metal", "paslanmaz çelik");
		komuta->urunEKLE(yeniURUN);
		cout << "başarıyla eklendi ..." << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}
		break;
	case 2:
		cout << "silinecek ürünün İD numarasını giriniz --> ";
		cin >> giris;
		komuta->urunSIL(giris);

		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}
		break;
	case 3:
	idAL:

		cout << "üzerine güncelleştirme yapmak istediğiniz ürünün İD numarasını giriniz --> ";
		cin >> giris;
		gec = komuta->urunGUNCELLE(giris);
		if (gec == nullptr)
		{
		tekrarSOR:

			cout << "aradığınız ürünü bulamadık ..." << endl << endl;
			cout << "1) farklı bir İD kullanmak " << endl;
			cout << "2) bu ürünün İD numarasını müdüre iletilmek üzere istenilen ürünler listesine eklemek " << endl;
			cout << "3) bu ürünün İD numarasını müdüre iletilmek üzere tükenmiş ürünler listesine eklemek " << endl;
			cout << "4) ürünü farklı bir şekilde aramak " << endl;
			cout << "5) bu İD numarasıyla ilgili müdüre mesaj bırakmak " << endl;
			cout << "6) bu İD numarası ile yeni ürün eklemek " << endl;
			cout << endl << endl << "sıkıntıyı hangi şekilde çözmek istersiniz ? --> ";
			cin >> secim;
			switch (secim)
			{
			case 1:
				cout << "Mevcut ürünlerin İD numaraları :" << endl;
				komuta->tumURUNLERİNidsiYAZDIR();
				cout << endl;
				goto idAL;
				break;
			case 2:
				yeniURUN = new urun(550, 1600, giris, "Timex", "Expedition", "kahverengi", 3, "erkek", "03.10.2019", 4, 55, "kuarz", "yok", "40mm", "3800 mAh", "deri", "paslanmaz çelik");
				komuta->istenilenURUNlistesi(yeniURUN);
				cout << "başarıyla eklendi ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			case 3:
				yeniURUN = new urun(750, 2200, giris, "Tag Heuer", "Carrera", "siyah", 5, "erkek", "18.09.2019", 4, 65, "otomatik", "var", "43mm", "4200 mAh", "deri", "paslanmaz çelik");
				komuta->tukenmisURUNlistesi(yeniURUN);
				cout << "başarıyla eklendi ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}

			case 4:
				cout << endl;
				cout << "a) marka ismi " << endl;
				cout << "b) model ismi " << endl;
				cout << "c) fiyat aralığı " << endl;
				cout << "d) maliyet miktarı " << endl;
				cout << "e) cinsiyet " << endl;
				cout << "f) mekanizma " << endl;
				cout << "ğ) renk " << endl;
				cout << "r) değerlendirme puanı " << endl;
				cout << endl << "hangi özellikle ürünleri aramak istersiniz ? ";
				cin >> secenek;
				komuta->urunuOZELLİKileARA(secenek);
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}

			case 5:
				cout << endl << "iletmek istediğiniz mesajı giriniz : " << endl;
				cin.ignore();
				getline(cin, giris);
				yeniMESAJ = new mesaj(giris);
				mesajKomuta->mesajekle(yeniMESAJ);
				cout << endl << "mesajınız iletilmiştir ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			case 6:
				cout << endl;
				cout << "ürünün maliyetini giriniz --> ";
				cin >> maliyet;
				cout << endl;
				cout << "ürünün satış fiyatını giriniz --> ";
				cin >> fiyat;
				cout << endl;
				cout << "ürünün markasını giriniz --> ";
				cin >> marka;
				cout << endl;
				cout << "ürünün model ismini giriniz --> ";
				cin >> modelISMI;
				cout << endl;
				// sunum yaparken iş uzamasın diye , diğer özellikleri standart olacak şekilde ayarladım...
				yeniURUN = new urun(maliyet, fiyat, giris, marka, modelISMI, "siyah", 5, "erkek", "15.05.2024", 5, 80, "dijital", "var", "43mm", "4300 mAh", "metal", "paslanmaz çelik");
				komuta->urunEKLE(yeniURUN);
				cout << "başarıyla eklendi ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			default:
				cout << "yanlış secim ..." << endl;
				goto tekrarSOR;
				break;
			}
			return 0;

		}
	baskaDEGISTIRME:
		cout << endl << "1) " << gec->id << endl;
		cout << "2) " << gec->marka << endl;
		cout << "3) " << gec->modelISMI << endl;
		cout << "4) " << gec->maliyet << " TL " << endl;
		cout << "5) " << gec->fiyat << " TL " << endl;
		cout << "6) " << gec->uretimTARİH << endl;
		cout << "7) " << gec->cinsiyet << endl;
		cout << "8) " << gec->mekanizma << endl;
		cout << "9) " << gec->renk << endl;
		cout << "10) " << gec->pilKapasitesi << endl;
		cout << "11) " << gec->suGecirmezlik << " ATM " << endl;
		cout << "12) " << gec->geceISIGI << endl;
		cout << "13) " << gec->kasacapi << endl;
		cout << "14) " << gec->kasaMAT << endl;
		cout << "15) " << gec->kordonMAT << endl;
		cout << "16) " << gec->agirlik << " G " << endl;
		cout << "17) " << gec->degerlendirmePuanı;
		for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
		cout << endl;
		cout << "18) " << gec->satılmaSayısı << endl;


		cout << "değiştirmek istediğiniz özelliğinin numarasını giriniz --> ";
		cin >> secim;
		switch (secim)
		{
		case 1:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->id = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}


		case 2:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->marka = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}


		case 3:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->modelISMI = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}


		case 4:

			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Syeniozellik;
			gec->maliyet = Syeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}



		case 5:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Syeniozellik;
			gec->fiyat = Syeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}


		case 6:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->uretimTARİH = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}



		case 7:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->cinsiyet = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}



		case 8:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->mekanizma = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}

		case 9:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->renk = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}

		case 10:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->pilKapasitesi = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}

		case 11:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Syeniozellik;
			gec->suGecirmezlik = Syeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}

		case 12:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->geceISIGI = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}

		case 13:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->kasacapi = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}

		case 14:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->kasaMAT = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}

		case 15:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Yyeniozellik;
			gec->kordonMAT = Yyeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}


		case 16:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Syeniozellik;
			gec->agirlik = Syeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}


		case 17:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Syeniozellik;
			gec->degerlendirmePuanı = Syeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}

		case 18:
			cout << endl << endl << "yeni özelliği giriniz -->";
			cin >> Syeniozellik;
			gec->satılmaSayısı = Syeniozellik;
			cout << endl << "başarıyla değiştirildi ... " << endl;
			cout << "başka bir özellik değiştirmek ister misiniz ? (e/h) ";
			cin >> secenek;
			if (secenek == 'e') { goto baskaDEGISTIRME; }
			else
			{
				cout << "ürünün son hali : " << endl << endl;
				cout << "+----------------------------------+" << endl;
				cout << "| " << gec->id << endl;
				cout << "| " << gec->marka << endl;
				cout << "| " << gec->modelISMI << endl;
				cout << "| " << gec->maliyet << " TL " << endl;
				cout << "| " << gec->fiyat << " TL " << endl;
				cout << "| " << gec->uretimTARİH << endl;
				cout << "| " << gec->cinsiyet << endl;
				cout << "| " << gec->mekanizma << endl;
				cout << "| " << gec->renk << endl;
				cout << "| " << gec->pilKapasitesi << endl;
				cout << "| " << gec->suGecirmezlik << " ATM " << endl;
				cout << "| " << gec->geceISIGI << endl;
				cout << "| " << gec->kasacapi << endl;
				cout << "| " << gec->kasaMAT << endl;
				cout << "| " << gec->kordonMAT << endl;
				cout << "| " << gec->agirlik << " G " << endl;
				cout << "| " << gec->degerlendirmePuanı;
				for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
				cout << endl;
				cout << "| " << gec->satılmaSayısı << endl;
				cout << "+----------------------------------+" << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}
			}

		default:
			cout << "yanlış seçim ..." << endl;
			goto baskaDEGISTIRME; break;
		}
		break;
	case 4:
	case4:

		cout << "aramak istediğiniz ürünün İD numarasını giriniz -->";
		cin >> giris;
		gec = komuta->urunARA(giris);
		if (gec == nullptr)
		{
		tekrarSOR2:

			cout << "aradığınız ürünü bulamadık ..." << endl << endl;
			cout << "1) farklı bir İD kullanmak " << endl;
			cout << "2) bu ürünün İD numarasını müdüre iletilmek üzere istenilen ürünler listesine eklemek " << endl;
			cout << "3) bu ürünün İD numarasını müdüre iletilmek üzere tükenmiş ürünler listesine eklemek " << endl;
			cout << "4) ürünü farklı bir şekilde aramak " << endl;
			cout << "5) bu İD numarasıyla ilgili müdüre mesaj bırakmak " << endl;
			cout << "6) bu İD numarası ile yeni ürün eklemek " << endl;
			cout << endl << endl << "sıkıntıyı hangi şekilde çözmek istersiniz ? --> ";
			cin >> secim;
			switch (secim)
			{
			case 1:
				cout << "Mevcut ürünlerin İD numaraları :" << endl;
				komuta->tumURUNLERİNidsiYAZDIR();
				cout << endl;
				goto case4;
				break;
			case 2:
				yeniURUN = new urun(550, 1600, giris, "Timex", "Expedition", "kahverengi", 3, "erkek", "03.10.2019", 4, 55, "kuarz", "yok", "40mm", "3800 mAh", "deri", "paslanmaz çelik");
				komuta->istenilenURUNlistesi(yeniURUN);
				cout << "başarıyla eklendi ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					return 0;
					break;
				}
			case 3:
				yeniURUN = new urun(750, 2200, giris, "Tag Heuer", "Carrera", "siyah", 5, "erkek", "18.09.2019", 4, 65, "otomatik", "var", "43mm", "4200 mAh", "deri", "paslanmaz çelik");
				komuta->tukenmisURUNlistesi(yeniURUN);
				cout << "başarıyla eklendi ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					return 0;
					break;
				}

			case 4:
				cout << endl;
				cout << "a) marka ismi " << endl;
				cout << "b) model ismi " << endl;
				cout << "c) fiyat aralığı " << endl;
				cout << "d) maliyet miktarı " << endl;
				cout << "e) cinsiyet " << endl;
				cout << "f) mekanizma " << endl;
				cout << "ğ) renk " << endl;
				cout << "r) değerlendirme puanı " << endl;
				cout << endl << "hangi özellikle ürünleri aramak istersiniz ? ";
				cin >> secenek;
				komuta->urunuOZELLİKileARA(secenek);
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}

			case 5:
				cout << endl << "iletmek istediğiniz mesajı giriniz : " << endl;
				cin.ignore();
				getline(cin, giris);
				yeniMESAJ = new mesaj(giris);
				mesajKomuta->mesajekle(yeniMESAJ);
				cout << endl << "mesajınız iletilmiştir ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}

			case 6:
				cout << endl;
				cout << "ürünün maliyetini giriniz --> ";
				cin >> maliyet;
				cout << endl;
				cout << "ürünün satış fiyatını giriniz --> ";
				cin >> fiyat;
				cout << endl;
				cout << "ürünün markasını giriniz --> ";
				cin >> marka;
				cout << endl;
				cout << "ürünün model ismini giriniz --> ";
				cin >> modelISMI;
				cout << endl;
				// sunum yaparken iş uzamasın diye , diğer özellikleri standart olacak şekilde ayarladım...
				yeniURUN = new urun(maliyet, fiyat, giris, marka, modelISMI, "siyah", 5, "erkek", "15.05.2024", 5, 80, "dijital", "var", "43mm", "4300 mAh", "metal", "paslanmaz çelik");
				komuta->urunEKLE(yeniURUN);
				cout << "başarıyla eklendi ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}

			default:
				cout << "yanlış secim ... " << endl;
				goto tekrarSOR2;
				break;
			}
			return 0;

		}
		cout << endl << "ürün bulundu" << endl << endl;
		cout << "+----------------------------------+" << endl;
		cout << "| " << gec->id << endl;
		cout << "| " << gec->marka << endl;
		cout << "| " << gec->modelISMI << endl;
		cout << "| " << gec->maliyet << " TL " << endl;
		cout << "| " << gec->fiyat << " TL " << endl;
		cout << "| " << gec->uretimTARİH << endl;
		cout << "| " << gec->cinsiyet << endl;
		cout << "| " << gec->mekanizma << endl;
		cout << "| " << gec->renk << endl;
		cout << "| " << gec->pilKapasitesi << endl;
		cout << "| " << gec->suGecirmezlik << " ATM " << endl;
		cout << "| " << gec->geceISIGI << endl;
		cout << "| " << gec->kasacapi << endl;
		cout << "| " << gec->kasaMAT << endl;
		cout << "| " << gec->kordonMAT << endl;
		cout << "| " << gec->agirlik << " G " << endl;
		cout << "| " << gec->degerlendirmePuanı;
		for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
		cout << endl;
		cout << "| " << gec->satılmaSayısı << endl;
		cout << "+----------------------------------+" << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}

	case 5:
	case5:

		cout << "özelliklerini yazdırmak istediğiniz ürünün İD numarasını giriniz -->";
		cin >> giris;
		gec = komuta->urunARA(giris);
		if (gec == nullptr)
		{
		tekrarSOR3:

			cout << "aradığınız ürünü bulamadık ..." << endl << endl;
			cout << "1) farklı bir İD kullanmak " << endl;
			cout << "2) bu ürünün İD numarasını müdüre iletilmek üzere istenilen ürünler listesine eklemek " << endl;
			cout << "3) bu ürünün İD numarasını müdüre iletilmek üzere tükenmiş ürünler listesine eklemek " << endl;
			cout << "4) ürünü farklı bir şekilde aramak " << endl;
			cout << "5) bu İD numarasıyla ilgili müdüre mesaj bırakmak " << endl;
			cout << "6) bu İD numarası ile yeni ürün eklemek " << endl;
			cout << endl << endl << "sıkıntıyı hangi şekilde çözmek istersiniz ? --> ";
			cin >> secim;
			switch (secim)
			{
			case 1:
				cout << "Mevcut ürünlerin İD numaraları :" << endl;
				komuta->tumURUNLERİNidsiYAZDIR();
				cout << endl;
				goto case5;
				break;
			case 2:
				yeniURUN = new urun(550, 1600, giris, "Timex", "Expedition", "kahverengi", 3, "erkek", "03.10.2019", 4, 55, "kuarz", "yok", "40mm", "3800 mAh", "deri", "paslanmaz çelik");
				komuta->istenilenURUNlistesi(yeniURUN);
				cout << "başarıyla eklendi ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					return 0;
					break;
				}
			case 3:
				yeniURUN = new urun(750, 2200, giris, "Tag Heuer", "Carrera", "siyah", 5, "erkek", "18.09.2019", 4, 65, "otomatik", "var", "43mm", "4200 mAh", "deri", "paslanmaz çelik");
				komuta->tukenmisURUNlistesi(yeniURUN);
				cout << "başarıyla eklendi ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					return 0;
					break;
				}

			case 4:
				cout << endl;
				cout << "a) marka ismi " << endl;
				cout << "b) model ismi " << endl;
				cout << "c) fiyat aralığı " << endl;
				cout << "d) maliyet miktarı " << endl;
				cout << "e) cinsiyet " << endl;
				cout << "f) mekanizma " << endl;
				cout << "ğ) renk " << endl;
				cout << "r) değerlendirme puanı " << endl;
				cout << endl << "hangi özellikle ürünleri aramak istersiniz ? ";
				cin >> secenek;
				komuta->urunuOZELLİKileARA(secenek);
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}

			case 5:
				cout << endl << "iletmek istediğiniz mesajı giriniz : " << endl;
				cin.ignore();
				getline(cin, giris);
				yeniMESAJ = new mesaj(giris);
				mesajKomuta->mesajekle(yeniMESAJ);
				cout << endl << "mesajınız iletilmiştir ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}

			case 6:
				cout << endl;
				cout << "ürünün maliyetini giriniz --> ";
				cin >> maliyet;
				cout << endl;
				cout << "ürünün satış fiyatını giriniz --> ";
				cin >> fiyat;
				cout << endl;
				cout << "ürünün markasını giriniz --> ";
				cin >> marka;
				cout << endl;
				cout << "ürünün model ismini giriniz --> ";
				cin >> modelISMI;
				cout << endl;
				// sunum yaparken iş uzamasın diye , diğer özellikleri standart olacak şekilde ayarladım...
				yeniURUN = new urun(maliyet, fiyat, giris, marka, modelISMI, "siyah", 5, "erkek", "15.05.2024", 5, 80, "dijital", "var", "43mm", "4300 mAh", "metal", "paslanmaz çelik");
				komuta->urunEKLE(yeniURUN);
				cout << "başarıyla eklendi ..." << endl;
				cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
				cin >> secenek;
				if (secenek == 'e')
				{
					goto anamenu;
				}
				else
				{
					cout << endl << "+-----------------------------+" << endl;
					cout << "| yine bekleriz          ^_^  |" << endl;
					cout << "+-----------------------------+" << endl;
					break;
				}

			default:
				cout << "yanlış secim ... " << endl;
				goto tekrarSOR3;
				break;
			}
			return 0;

		}
		cout << endl << "ürün bulundu" << endl << endl;
		cout << "+----------------------------------+" << endl;
		cout << "| " << gec->id << endl;
		cout << "| " << gec->marka << endl;
		cout << "| " << gec->modelISMI << endl;
		cout << "| " << gec->maliyet << " TL " << endl;
		cout << "| " << gec->fiyat << " TL " << endl;
		cout << "| " << gec->uretimTARİH << endl;
		cout << "| " << gec->cinsiyet << endl;
		cout << "| " << gec->mekanizma << endl;
		cout << "| " << gec->renk << endl;
		cout << "| " << gec->pilKapasitesi << endl;
		cout << "| " << gec->suGecirmezlik << " ATM " << endl;
		cout << "| " << gec->geceISIGI << endl;
		cout << "| " << gec->kasacapi << endl;
		cout << "| " << gec->kasaMAT << endl;
		cout << "| " << gec->kordonMAT << endl;
		cout << "| " << gec->agirlik << " G " << endl;
		cout << "| " << gec->degerlendirmePuanı;
		for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
		cout << endl;
		cout << "| " << gec->satılmaSayısı << endl;
		cout << "+----------------------------------+" << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}
		break;
	case 6:
		komuta->tumURUNLERIyazdir();
		cout << "başarıyla yazdırıldı ..." << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}
		break;
	case 7:
		komuta->ucuzdanBUYUGE();
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}

	case 8:
		deger = komuta->urunlerinTOPLAMmaliyeti();
		cout << "listede bulunan ürünlerin toplam maliyeti " << deger << " TL'dir" << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}
		break;
	case 9:
		cout << endl << "zam yüzdelik miktarını giriniz --> %";
		cin >> secim;
		komuta->tumURUNLREzamYAP(secim);
		cout << endl << "ürünlerin fiyatı %" << secim << "'lik kadar zamlandı ..." << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}

	case 10:
		komuta->minimumMALİYETLİURUN();
		cout << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}

	case 11:
		komuta->maximumMALİYETLİURUN();
		cout << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}

	case 12:
	case12:

		cout << endl << "a) mevcüt ürünler sayısı \n";
		cout << "b) aynı markalı ürün sayısı \n";
		cout << "c) aynı fiyata sahip ürün sayısı \n";
		cout << "d) aynı maliyete sahip ürün sayısı \n";
		cout << "e) aynı değerlendirme puanına sahip ürün sayısı \n";
		cout << "f) aynı cinsiyet için ürün sayısı \n\n";
		cout << endl << "lütfen arama temelini seçiniz --> ";
		cin >> secenek;
		if (secenek == 'a') { deger = komuta->urunSAYISI('a'); cout << endl << deger << " tane ürün bulundu " << endl; }
		else if (secenek == 'b') { deger = komuta->urunSAYISI('b'); cout << endl << deger << " tane ürün bulundu " << endl; }
		else if (secenek == 'c') { deger = komuta->urunSAYISI('c'); cout << endl << deger << " tane ürün bulundu " << endl; }
		else if (secenek == 'd') { deger = komuta->urunSAYISI('d');  cout << endl << deger << " tane ürün bulundu " << endl; }
		else if (secenek == 'e') { deger = komuta->urunSAYISI('e'); cout << endl << deger << " tane ürün bulundu " << endl; }
		else if (secenek == 'f') { komuta->urunSAYISI('f'); cout << endl << deger << " tane ürün bulundu " << endl; }
		else { cout << endl << "yanlış seçim ..." << endl << endl; goto case12; }
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}


	case 13:
		cout << endl << "neredeyse hazır ..." << endl;
		komuta->urunleriDOSYAYAyazdir();
		cout << "başarıyla yazdırıldı ...." << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}
	case 14:

		if (!yeniurun.is_open()) {
			cerr << "Dosya açilamadi!" << endl;
			return 1;
		}
		cout << endl;
		deger = 1;
		while (!yeniurun.eof()) {
			gec = komuta->urunleriDOSYADANoku(yeniurun);
			cout << deger << ". ÜRÜN :" << endl;
			cout << "+----------------------------------+" << endl;
			cout << "| " << "İD : " << gec->id << endl;
			cout << "| " << "MARKA : " << gec->marka << endl;
			cout << "| " << "MODEL : " << gec->modelISMI << endl;
			cout << "| " << "MALİYET : " << gec->maliyet << " TL" << endl;
			cout << "| " << "FİYATI : " << gec->fiyat << " TL" << endl;
			cout << "| " << "ÜRETİM TARİHİ : " << gec->uretimTARİH << endl;
			cout << "| " << "CİNSİYET : " << gec->cinsiyet << endl;
			cout << "| " << "MEKANİZMA : " << gec->mekanizma << endl;
			cout << "| " << "RENK : " << gec->renk << endl;
			cout << "| " << "PİL KAPASİTESİ : " << gec->pilKapasitesi << endl;
			cout << "| " << "SUYA DAYANIKLIK : " << gec->suGecirmezlik << " ATM" << endl;
			cout << "| " << "GECE IŞIĞI : " << gec->geceISIGI << endl;
			cout << "| " << "KASA ÇAPI : " << gec->kasacapi << endl;
			cout << "| " << "KASA MATERYALI : " << gec->kasaMAT << endl;
			cout << "| " << "KORDON MATERYALI : " << gec->kordonMAT << endl;
			cout << "| " << "AĞIRLIK : " << gec->agirlik << " G" << endl;
			cout << "| " << "DEĞEERLENDİRME : " << gec->degerlendirmePuanı;
			for (int i = 0; i < gec->degerlendirmePuanı; i++) { cout << '*'; }
			cout << endl << "| " << "SATILMA SAYISI : " << gec->satılmaSayısı << endl;
			cout << "+----------------------------------+" << endl;
			deger++;
			komuta->urunEKLE(gec);

		}
		cout << endl << "bu ürünler başarıyla ürünler listesine eklenmiştir ..." << endl << endl;

		yeniurun.close();

		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}
		break;
	case 15:
		cout << "neredeyse hazır ..." << endl << endl;
		komuta->istenilenURUNLERİyazdir();
		cout << "başarıyla yazdırıldı ..." << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}
	case 16:
		komuta->tukenmisURUNLERİyazdir();
		cout << "başarıyla yazdırıldı ..." << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}

	case 17:
		mesajKomuta->mesajlarıYAZ();
		cout << endl << "bu mesajlar müdüre iletilmiştir ..." << endl;
		cout << endl << "başka bir işlem yapmak istiyormusunuz ? (e/h) ";
		cin >> secenek;
		if (secenek == 'e')
		{
			goto anamenu;
		}
		else
		{
			cout << endl << "+-----------------------------+" << endl;
			cout << "| yine bekleriz          ^_^  |" << endl;
			cout << "+-----------------------------+" << endl;
			break;
		}
	case 18:
		cout << endl << "+-----------------------------+" << endl;
		cout << "| yine bekleriz          ^_^  |" << endl;
		cout << "+-----------------------------+" << endl;
		break;
	default:
		cout << endl << "yanlış seçim ..." << endl << endl;
		goto anamenu;

	}
	system("pause");
	return 0;
}