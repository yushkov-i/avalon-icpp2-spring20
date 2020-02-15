  
Для всех задач данные следует генерировать с помощью библиотеки "Extention.hpp"

Задание #1
Напишите программу которая сортирует массив из структур Student. (N = 100)
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
Критерий сортировки необходимо спрашивать у пользователя. (по Id, по Mark, или по Name)
Id в диапазоне от 1 до 1000, Name состоит от 3 до 6 английских символов;

Задание #2
Напишите программу, которая анализирует массив студентов определяет моду оценок и какие оценки необходимо получить,
чтобы стать лучше 25% студентов, 50% студентов, 75% студентов.
int main()
{
  Grade mark = Grade::B;
  Grade userMark;
  cout << static_cast<int>(mark) << endl;
  int i;
  cin << i;
  userMark=  static_cast<int>(i) << endl;
  Student student;
  student.Id=GetRandomValue(1, 1000);
  student.Mark=static_cast<Grade>(GetRandomValue(1, 5))
    int tempetRandomValue(3,6);
  for(int i=0; i<temp; i++)
  {
    student.Name[i]=GetRandomValur('a', 'z');
  }
  
}
