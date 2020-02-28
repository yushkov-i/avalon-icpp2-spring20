/* 
 *  Пример создания и инициализации одного студента рандомным значением
 */

#include "Extention.hpp"

using namespace ext;

enum Grade
{  
  F = 1   // неявка
  D = 2,  // неудовлетворительно
  C = 3,  // удовлетворительно
  B = 4,  // хорошо
  A = 5,  // отлично      
};

struct Student
{
  int Id;
  Grade Mark;
  char Name[7];  
};

int main()
{
  Student student;
  
  student.Id = GetRandomValue(1, 1000);
  student.Mark = static_cast<Grade>(GetRandomValue(1,5)); // явное преобразование int в Grade
  
  int tempLength = GetRandomValue(3,6);
  for(int i = 0; i < tempLength; ++i)
  {
    int symbol = GetRandomValue('a', 'z');  // неявное преобразование из char в int в момент вызова функции
    student.Name[i] = symbol; // неявное преобразование из int в char при приравнивании
  }
  
  for(int i = tempLength; i < 7; ++i) // 7-ку лучше конечно заменить на константу
  {
    student.Name[i] = '\0';
  }
}
