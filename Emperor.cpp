//Se da urmatoarea ierarhie de baze. Clasa de baza punct cu coordonatele x, y, z de tip int, din care se deriveaza cerc si patrat.
 //Mostenesc x y z care reprezinta centrele acestor figuri geometrice. Din clasa cerc este derivata clasa cilindru. Cilindru mosteneste atributele din punct si cerc si mai are in plus inaltime
 //Din dreptunghi este derivata paralelipiped dreptunghic care mosteneste toate atributele din clasa de baza si mai are in plus l3 care reprezinta inaltimea acestei figuri geometrice. 
 //Creati un vector care sa contina obiecte de toate aceste tipuri si afisatile aria, volumul, perimetrul, precum si toate atributele lor.
 
 #include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Punct
{
	protected: 
	int x, y, z;
	public:
		
		Punct(int xx, int yy, int zz)
		{
			x=xx;
			y=yy;
			z=zz;
		};
		
		virtual double getArie()
		{
			return 0;
		}
		
		virtual double getPer()
		{
			return 0;
		}
		
		virtual double getVolum()
		{
			return 0;
		}
		
		virtual ~Punct()
		{
		}
		
		virtual void afis()
		{
			cout<<x<<" "<<y<<" "<<z<<endl;
		}
		
};

class Cerc:public Punct
{
	protected:
		int R;
		static const double Pi=3.14;
		//x, y, z resprezinta centrul cercului. 
		public:
			Cerc(int xx, int yy, int zz, int RR):Punct(xx, yy, zz)
			{
				R=RR;
			}
			
			 double getArie()
			{
				return Pi*R*R;
			}
			
			 double getPer()
			{
				return 2*Pi*R;
			}
			
			 double getVolum()
			{
				return 0;
			}
			
			void afis()
			{
				Punct::afis();
				cout<<R<<endl;
			}
};

class Drept:public Punct
{
	protected:
		int l1, l2;
		//x, y, z-centru dreptunghi
	public:
		Drept(int xx, int yy, int zz, int ll1, int ll2):Punct(xx, yy, zz)
		{
			l1=ll1;
			l2=ll2;
		}
		
		double getArie()
		{
			return l1*l2;
		}
		
		double getPer()
		{
			return 2*l1 + 2*l2;
		}
		
		double getVolum()
		{
			return 0;
		}
		
		void afis()
		{
			Punct::afis();
			cout<<l1<<" "<<l2<<endl;
		}
			
};

class Cilindru:public Cerc
{	
	protected:
	int h;
	public:
		
		Cilindru(int xx, int yy, int zz, int RR, int hh):Cerc(xx, yy, zz, RR)
		{
			h=hh;
		}
		
		double getArie()
		{
			return 2*3.14*R*h;
		}
		
		double getPer()
		{
			return 0;
		}
		
		double getVolum()
		{
			return 3.14*R*R*h;
		}
		
		void afis()
		{
			Cerc::afis();
			cout<<h<<endl;
		}
	
};

class Paralelipiped:public Drept
{
	int l3; //inaltimea
	public:
	Paralelipiped(int xx, int yy, int zz, int ll1, int ll2, int ll3):Drept(xx, yy, zz, ll1, ll2)
	{
		l3=ll3;
	}
	
	double getArie()
	{
		return (2*l1*l2 + 2*l1*l3 + 2*l2*l3);
	}
	
	double getPer()
	{
		return 0;
	}
	
	double getVolum()
	{
		return l1*l2*l3;
	}
	
	void afis()
	{
		Drept::afis();
		cout<<l3<<endl;
	}
	
};

//1. constuctori cu parametri pentru tot.
//2. functie virtuala pentru afisare
//3. functie virtuala pentru arie, perimetru  double getArie(),  getPer(),   getVolum()
//4. virtual ~Punct;
//De desenat cum sunt apelate in memorie elementele din vector.



int main()
{
	Punct **v;
	int i;
	v=new Punct*[5];
	v[0] = new Cerc(0,0,0,8);
	v[1] = new Cilindru(0,0,0,8,10);
	v[2] = new Drept(0,0,0,8,10);
	v[3] = new Paralelipiped(0,0,0,8,10,18);
	
	for(i=0; i<=3; i++)
	{
		v[i]->afis();
		cout<<v[i]->getArie()<<endl;
		cout<<v[i]->getPer()<<endl;
		cout<<v[i]->getVolum()<<endl;
	}
	
	
}
