#include <iostream>
#include <fstream>

using namespace std;

class zad
{
	ifstream pIn;
	
	
	public:
		zad();
		~zad();
		void wczytaj();
};

zad::zad() 
{
	pIn.open("dane_ulamki.txt");	
}

void zad::wczytaj() 
{
 	double licz, mian, min, min_licz, min_mian;
	if(pIn.good()) 
	{
		pIn>>licz;
		pIn>>mian;	
		min = licz/mian;
		min_licz = licz;
		min_mian = mian;
			while(!pIn.eof()) 
			{
				pIn>>licz;
				pIn>>mian;	
				if(licz/mian<min) 
				{
					min = licz/mian;
					min_licz = licz;
					min_mian = mian;
				}
				if(licz/mian==min) 
				{
					if(mian<=min_mian) 
					{
						min_licz = licz;
						min_mian = mian;
					}
				}
			}
		cout<<min_licz<<" "<<min_mian;
	}
}
	
zad::~zad() 
{
	pIn.close();
}

int main(int argc, char** argv) {
	zad z1;
	z1.wczytaj();
	
	return 0;
}
