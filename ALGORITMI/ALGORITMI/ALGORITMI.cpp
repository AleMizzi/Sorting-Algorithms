#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <time.h>
#include <random>
using namespace std;

void BubbleSort(vector <int> vect, int n);
void SelectionSort(vector <int> vect, int n);
void InsertionSort(vector <int> vect, int n);
void domandaSort(vector <int> vect, int n);


int main()
{
	random_device rd;
	mt19937 gen(rd()); // inizializzo il generatore pseudo
	

	vector<int> vect;
	int n, i, j, temp, x = 0;
	string risposta;
	
	
	 cout << "Quanti elementi vuoi mettere nel vettore?" << endl;
	 cin >> n;

	cout << "Vuoi che i numeri siano generati casualmente? Digita 1 \nVuoi che immettere i numeri manualmente? Digita 2" << endl;
	cin >> risposta;

	

	if (risposta == "1") {
		
		int r1, r2;

		cout << "Range dei numeri casuali (inserisci valori interi) : \nRange1: ";
		cin >> r1;
		cout << "Range2: ";
		cin >> r2;

		uniform_int_distribution<> dis(r1, r2); //creo i numeri

		cout << "\nI numeri generati sono: ";

		for (int z = 0; z < n; z++)
		{
			int random = dis(gen);
			cout << " " << random;
			vect.push_back(random);
		}

		int sort = 0;
		cout << "\n\nQuale metodo vuoi usare?\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort(per numeri piccoli)\n\nDigita il numero del metodo: ";
		cin >> sort;

		switch (sort)
		{
		case 1:
			BubbleSort(vect, n);
		case 2:
			SelectionSort(vect, n);
		case 3:
			InsertionSort(vect, n);
		default:
			break;
		}
		
	}
	else if (risposta == "2") {
		cout << "Inserisci gli elementi:\n";
		for (i = 0; i < n; i++) {
			cin >> x;
			vect.push_back(x);
		}

		int sort = 0;
		cout << "\n\nQuale metodo vuoi usare?\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort (per numeri piccoli)\n\nDigita il numero del metodo: ";
		cin >> sort;

		switch (sort)
		{
		case 1:
			BubbleSort(vect, n);
		case 2:
			SelectionSort(vect, n);
		case 3:
			InsertionSort(vect, n);
		default:
			break;
		}
		
	}
	else {
		cout << "Risposta non valida.";
	}

	return 0;
}


void domandaSort(vector <int> vect, int n) {

	
}

void BubbleSort(vector<int> vect, int n){

	int temp, j, i;
	int contatore = 0;
		//ordino gli elementi		
	for (j = 0; j < n - 1; j++)
		for (i = 0; i < n - 1; i++)
			if (vect[i] > vect[i + 1])
			{
				//swap
				temp = vect[i];
				vect[i] = vect[i + 1];
				vect[i + 1] = temp;
				contatore++;
			}

	cout << "\n\nArray ordinato con bubble sort:";
	for (i = 0; i < n; i++)
		cout << " " << vect[i];
	cout << "\n\nNumero di operazioni: " << contatore;
}

void SelectionSort(vector <int> vect, int n) {
	int temp, j, i;
	int contatore = 0;
	//ordino gli elementi		
	for (i = 0; i < n - 1 ; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (vect[j] < vect[i]) {
				temp = vect[j];
				vect[j] = vect[i];
				vect[i] = temp;
				contatore++;
			}
		}
	cout << "\n\nArray ordinato con selection sort:";
	for (i = 0; i < n; i++)
		cout << " " << vect[i];
	cout << "\n\nNumero di operazioni: "<< contatore;
}

void InsertionSort(vector <int> vect, int n) {
	int temp, j, i;
	int contatore = 0;

	//ordino gli elementi	
	
	for (i = 1; i < n; i++) {

		temp = vect[i]; // i numero dopo, j numero prima
		j = i - 1;

		while (j >= 0 || vect[j] > temp ) {
			vect[j + 1] = vect[j];
			j--;
			contatore++;
		}
		vect[j + 1] = temp;
		
	}
		
	cout << "\n\nArray ordinato con insertion sort:";
	for (i = 0; i < n; i++)
		cout << " " << vect[i];
	cout << "\n\nNumero di operazioni: " << contatore;
}
