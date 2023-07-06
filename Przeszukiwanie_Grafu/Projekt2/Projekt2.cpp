
#include<iostream>
#include<queue>
#include<vector>
#include<iomanip>
#include <cstdlib>
#include<fstream>
#include<string>
using namespace std;

void BFS(vector <vector <int>> Wektor)
{
	queue<int> kolejka;
	vector <int> dodane;
	vector <int> biezacakolejka;
	int n;
	int szukana;
	cout << "jaki wierzcholek chcesz znalezc?";
	cin >> szukana;
	cout << endl;
	cout << "od jakiego wierzcholka chcesz zaczac? ";
	cin >> n;

	bool znalezione = false;
	kolejka.push(n);
	biezacakolejka.push_back(n);
	dodane.push_back(n);
	int licznik = 0;
	cout << "biezaca kolejka: ";
	for (int z = 0; z < biezacakolejka.size(); z++) {

		cout << biezacakolejka[z] << " ";

	}
	cout << endl;
	while (!kolejka.empty()) {

		licznik++;
		n = kolejka.front();
		kolejka.pop();

		for (int i = 0; i < Wektor[n].size(); i++) {

			int k = 0;
			for (int j = 0; j < dodane.size(); j++) {

				if (dodane[j] == Wektor[n][i]) {

					k++;

				}


			}
			if (k == 0) {



				if (Wektor[n][i] == szukana && znalezione == false) {
					cout << "znaleziono twoj element! " << Wektor[n][i] << " po " << licznik << " przeszukaniach " << endl;
					znalezione = true;
					break;
				}
				else
				{
					kolejka.push(Wektor[n][i]);
					dodane.push_back(Wektor[n][i]);
					biezacakolejka.push_back(Wektor[n][i]);
					

				}





			}


		}
		if (znalezione != true) {
			cout << "biezaca kolejka: ";
			for (int z = 0; z < biezacakolejka.size(); z++) {

				cout << biezacakolejka[z] << " ";

			}
			cout << endl;
			biezacakolejka.erase(biezacakolejka.begin());

		}

	}
}

int main() {

	vector <vector <int>> graf;

	ifstream plik;
	string nazwa;

	cout << "Podaj nazwe pliku do wczytania:" << endl;
	cin >> nazwa;

	plik.open(nazwa, ios::in);
	int liczba_linii = 0;
	int x = 0;

	if (plik)
	{
		string linie;

		while (!plik.eof())
		{
			while (getline(plik, linie))
			{
				liczba_linii++;
			}

		}
	}
	else cout << "Nie uzyskano dostepu do pliku!" << endl;

	for (int a = 0; a < liczba_linii; a++)
	{
		graf.push_back(vector<int>());
	}


	plik.close();
	plik.open(nazwa, ios::in);

	string l;
	int g = 0;
	int a = 0;
	ifstream plik2;
	plik2.open(nazwa, ios::in);
	while (getline(plik, l))
	{
		
		for (int i = 0; i < l.length(); i++)
		{
			if (l[i] == ' ')
			{
				x++;
				a = x + 1;
				continue;
			}
		}

		int* tablica = new int[a];


		for (int i = 0; i < x + 1; i++)
		{
		

			plik2 >> tablica[i];



			graf[g].push_back(tablica[i]);

		}
		g++;
		x = 0;
	}


	cout << "lista sasiedztwa wierzcholkow: " << endl;
	for (int i = 0; i < graf.size(); i++) {

		for (int j = 0; j < graf[i].size(); j++) {

			cout << setw(3) << graf[i][j];

		}
		cout << endl;
	}


	system("pause");

	

	BFS(graf);


	return 0;
}


