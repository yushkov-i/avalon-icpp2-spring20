#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;
enum Grade
{  
  F = 1,   // неявка
  D = 2,  // неудовлетворительно
  C = 3,  // удовлетворительно
  B = 4,  // хорошо
  A = 5  // отлично      
};

struct Student
{
  int Id;
  Grade Mark;
  char Name[7];  
};
void sort_name(Student List[100])
{
    	for (int i = 0; i<100; i++ )
	{
		bool hasSwap = false;
		for (int j=0; j< 100; j++)
		{
			if (int(List[j].Name[0]) > int(List[j+1].Name[0])) { Student temp = List[j]; List[j]= List[j + 1]; List[j + 1] = temp; hasSwap = true; }
	else if (int(List[j].Name[0]) == int(List[j+1].Name[0]) && int(List[j].Name[1]) > int(List[j+1].Name[1])){ Student temp = List[j]; List[j] = List[j + 1]; List[j + 1] = temp; hasSwap = true; }
		    
		}
}
}
void sort_mark(Student List[100])
{
    	for (int i = 0; i<100; i++ )
	{
		bool hasSwap = false;
		for (int j=0; j< 100; j++)
		{
			if (int(List[j].Mark) > int(List[j+1].Mark)) { Grade temp = List[j].Mark; List[j].Mark = List[j + 1].Mark; List[j + 1].Mark = temp; hasSwap = true; }
		}
}
}
void sort_id(Student List[100])
{
    	for (int i = 0; i<100; i++ )
	{
		bool hasSwap = false;
		for (int j=0; j< 100; j++)
		{
			if (List[j].Id > List[j+1].Id) { int temp = List[j].Id; List[j].Id = List[j + 1].Id; List[j + 1].Id = temp; hasSwap = true; }
		}
}
}

int main()
    {
    Student List[100];
    int in;
        cout << "Для сортировки по имени введите 1. Для сортировки по номеру - 2. Для сортировки по оценке - 3. : ";
    cin >> in;
    for(int i=0; i<=100; i++)
    {
  List[i].Id=GetRandomValue(1, 1000);
  List[i].Mark=static_cast<Grade>(GetRandomValue(1, 5));
    int temp=GetRandomValue(3,6);
    for (int k=0; k<7; k++){ List[i].Name[k]='\0';}
  for(int k=0; k<temp; k++) 
  {
      List[i].Name[k]=GetRandomValue('a', 'z');
  }
    }
    if(in==1){sort_name(List);}
    else if(in==2){sort_id(List);}
    else if(in==3){sort_mark(List);}
     for(int i=0; i<100; i++) 
     {
         cout << List[i].Id << ' ' << List[i].Name << ' ' << int(List[i].Mark)  << endl;
     }
	     int count[5]={0};
     for(int i=0; i<100; i++)
     {
         count[int(List[i].Mark)-1]++;
     }
	     for(int i=0; i<=4; i++){cout << "Оценок " << i+1 << " : " << count[i] << endl;}
     if(count[0] > count[1] && count[0] > count[2] && count[0] > count[3] && count[0] > count[4] ){cout << "Мода оценок: 1";}
     if(count[1] > count[0] && count[1] > count[2] && count[1] > count[3] && count[1] > count[4] ){cout << "Мода оценок: 2";}
     if(count[2] > count[1] && count[2] > count[2] && count[0] > count[3] && count[2] > count[4] ){cout << "Мода оценок: 3";}
     if(count[3] > count[1] && count[3] > count[2] && count[3] > count[0] && count[3] > count[4] ){cout << "Мода оценок: 4";}
     if(count[4] > count[1] && count[4] > count[2] && count[4] > count[3] && count[4] > count[0] ){cout << "Мода оценок: 5";}
    cout << endl;
    }
