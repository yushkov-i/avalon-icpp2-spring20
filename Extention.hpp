#pragma once
#include <iostream>
#include<iomanip>
#include <random>

namespace ext
{
    int GetRandomValue(int min, int max, bool isDebugMode=false)
    {
        if (min > max) return max;
        static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
        auto distribution = std::uniform_int_distribution<int>(min, max);
        return distribution(randomEngine);
    }

    const int Nsum = 10;
    const int SumOfMonths = 12;
    const int minValue = 2;

    void AgentWorkGeneration(int* agents)
    {
        int month = 1;
        bool iswork;
        int workend= 0;

        while (month <= SumOfMonths)
        {
            iswork = GetRandomValue(false, true);

            workend = GetRandomValue(workend+ minValue, SumOfMonths);
           
            for (; month <= workend; month++)
            {
                if (iswork) agents[month-1] = GetRandomValue(1000, 100000);
                else agents[month-1] = -1;
            }
        }
    }

    void Sorting(int* work, int* index, int Sum)
    {
        for (int i = 0; i < SumOfMonths; i++)
            index[i] = i;

        for (int i = 0; i < Sum; i++)
        {
            for (int j = SumOfMonths-1; j > i; j--)
            {
                if (work[index[j]] > work[index[j - 1]])
                    std::swap(index[j], index[j - 1]);
            }
        }
    }

    float FindMedian(int *work)
    {
        int sumnWork = 0;
        for (int i = 0; i < SumOfMonths; i++)
            if (work[i] == -1) sumnWork++;

        if (sumnWork == SumOfMonths) return 0;

        int index[SumOfMonths];
        Sorting(work, index, SumOfMonths - sumnWork);

        int medianPos = (SumOfMonths - sumnWork) / 2;

        if (sumnWork % 2 == 1) return work[index[medianPos]];
        else return (static_cast<float>(work[index[medianPos-1]]) + work[index[medianPos]]) / 2;
    }

}