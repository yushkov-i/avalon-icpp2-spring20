#include "Extention.hpp"

using namespace std;
using namespace ext;

void PrintAgent(int* agents, int agentSum)
{
    for (int i = 0; i < agentSum; i++)
    {
        cout << setw(2) << i + 1 << ")";

        for (int j = 0; j < SumOfMonths; j++)
            cout << setw(7) << *(agents + i * SumOfMonths + j);

        cout << endl;
    }
}

int main()
{
    setlocale(0, "rus");
    int agents[Nsum][SumOfMonths];

    for (int i = 0; i < Nsum; i++)
        AgentWorkGeneration(agents[i]);

    PrintAgent(agents[0], Nsum);
    cout << endl;

    float agentMed[Nsum];
    float MaxMedian = 0;

    for (int i = 0; i < Nsum; i++)
    {
        cout <<setw(3)<< i + 1 << ") ";
        agentMed[i] = FindMedian(agents[i]);
        if (agentMed[i]!=0) printf(" (%8.1f )\n", agentMed[i]);
        else cout << "  не работал\n";

        if (MaxMedian < agentMed[i]) MaxMedian = agentMed[i];
    }

    cout << endl << "наибольшая медиана(" << MaxMedian << ')' << " у agent:";
    for (int i = 0; i < Nsum; i++)
        if (agentMed[i]==MaxMedian) cout << setw(3) << i+1 <<". ";
    cout << endl<<endl;

    system("pause");
}