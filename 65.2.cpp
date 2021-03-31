#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class zad
{
	ifstream pIn;
	vector <string> obraz;
	
	public:
		zad();
		~zad();
		void wczytaj();
		vector <int> rozklad(int);
		bool nieskracalne(vector <int>, vector<int>);
};

zad::zad() 
{
	pIn.open("dane_ulamki.txt");
}

void zad::wczytaj() 
{
	vector <int> czyn1;
	vector <int> czyn2;
 	int num1, num2;
 	int ile_nieskracalne=0;
	if(pIn.good()) 
	{
		while(!pIn.eof()) 
		{
			pIn>>num1;
			czyn1 = rozklad(num1);
			pIn>>num2;
			czyn2 = rozklad(num2);	
			if(nieskracalne(czyn1, czyn2)) 
			{
				ile_nieskracalne++;
			}
		}
		cout<<ile_nieskracalne;
	}
}
	
vector <int> zad::rozklad(int liczba) 
{
	vector <int> czynniki;
		for (int i=2; i<=liczba; i++) 
		{
	   		while (liczba%i == 0) 
				{
	        		liczba/=i;
	        		czynniki.push_back(i);
	    		}
	 	}
	return czynniki;
}

bool zad::nieskracalne(vector <int> czyn1, vector <int> czyn2) 
{
	for (int i=0; i<czyn1.size(); i++) 
	{
		for (int j=0; j<czyn2.size(); j++) 
		{
			if(czyn1[i]==czyn2[j]) 
			{
				return false;
			}
		}
	}
	return true;
}

zad::~zad()
 {
	pIn.close();
}

int main(int argc, char** argv) 
{
	zad z;
	z.wczytaj();
	
	return 0;
}
