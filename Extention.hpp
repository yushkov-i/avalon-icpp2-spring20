#pragma once
#include <iostream>
#include <random>
#include <iomanip>
#include <string>

namespace ext
{
    int StudentSum  = 100;
    
    int GetRandomValue(int min, int max, bool isDebugMode = true)
    {
        static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
        auto distribution = std::uniform_int_distribution<int>(min, max);
        return distribution(randomEngine);
    }

    enum Grade { F=1 , D, C, B, A };
    enum Pole { id, mark, name };

    struct Student
    {
        static const int NameSize = 6;
        int Id;
        Grade Mark;
        char Name[NameSize+1];
    };

    bool* AvailableId = new bool[StudentSum * 10]{};

    void StudentsGeneration(Student & student)
    {
        int id;
        do{
            id = GetRandomValue(1, 1000);
        } while (AvailableId[id]);
        student.Id = id;
        AvailableId[id] = true;
        
        student.Mark = static_cast<Grade>(GetRandomValue(F, A));

        int tempLength = GetRandomValue(3, Student::NameSize);
        for (int i = 0; i < tempLength; i++)
            student.Name[i] = GetRandomValue('a', 'z');
        student.Name[tempLength] = '\0';
    }
   
    void Sort(int* index, Student * student, Pole pole)
    {
        for (int i = 0; i < StudentSum; i++)
            index[i] = i;

        for (int i = 0; i < StudentSum; i++)
        {
            for (int j = 0; j < StudentSum - i - 1; j++)
            {
                switch (pole)
                {
                case id:
                    if (student[index[j]].Id>student[index[j + 1]].Id)
                        std::swap(index[j], index[j + 1]);
                    break;
                case mark:
                    if (student[index[j]].Mark < student[index[j + 1]].Mark)
                        std::swap(index[j], index[j + 1]);
                    break;
                case name:
                    if (strcmp(student[index[j]].Name , student[index[j + 1]].Name)>0)
                        std::swap(index[j], index[j + 1]);
                    break;
                }
            }
        }
    }

    void Fashion(Student* student, char * fashion)
    {
        int qmark[A]{};
        for (int i = 0; i < StudentSum; i++)
            qmark[student[i].Mark - 1]++;

        int moda=0;
        for (int i = 1; i <= 4; i++)
            if (qmark[moda] < qmark[i]) moda = i;
        int posit=0;
        for (int i = 0; i <= 4; i++)
        {
            if (qmark[moda] == qmark[i])
            {
                if (static_cast<Grade>(i + 1) != F) fashion[posit++]= static_cast<char>(70 - i - 1);
                else  fashion[i]= 'F';
                fashion[posit++] = ' ';
            }
        }
    }   
}