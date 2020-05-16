#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct People
{
	int id;
	string fistName;
	string lastName;
	float results[3] 
		= {std::numeric_limits<float>::min(),
		std::numeric_limits<float>::min(),
		std::numeric_limits<float>::min() };
};

const int PEOPLE_COUNT = 20;
const int TRY_COUNT = 3;
const string PEOPLE_FILE_NAME = "athletes.txt";
const string RESULT_FILE_NAME = "results.txt";

People * findPeopleById(People data[], int id)
{
	People * current = nullptr;
	for (int i = 0; i < PEOPLE_COUNT; ++i)
	{
		if (data[i].id == id)
		{
			current = &data[i];
			return current;
			// return &data[i];
		}
	}
}

void setResultForPeople(People * people, float result)
{
	for (int i = 0; i < TRY_COUNT; ++i)
	{
		if (people->results[i] == std::numeric_limits<float>::min())
		{
			people->results[i] = result;
			return;
		}
	}
}

float maxPeopleResult(People people)
{
	float maxResult = std::numeric_limits<float>::min();

	for (int i = 0; i < TRY_COUNT; ++i)
	{
		if (maxResult < people.results[i])
		{
			maxResult = people.results[i];
		}
	}

	return maxResult;
}

int main()
{
	ifstream peopleFile;
	ifstream resultsFile;

	peopleFile.open(PEOPLE_FILE_NAME);
	if (!peopleFile.is_open())
	{
		cerr << PEOPLE_FILE_NAME << " did not open\n";
		return 1;
	}

	resultsFile.open(RESULT_FILE_NAME);
	if (!resultsFile.is_open())
	{
		cerr << RESULT_FILE_NAME << " did not open\n";
		return 2;
	}

	People * people = new People[PEOPLE_COUNT];
	for (int i = 0; i < PEOPLE_COUNT; ++i)
	{
		peopleFile >> people[i].id;
		peopleFile >> people[i].fistName;
		peopleFile >> people[i].lastName;
		peopleFile.ignore(std::numeric_limits<int>::max(), '\n');
	}
	peopleFile.close();

	for (int i = 0; i < PEOPLE_COUNT * TRY_COUNT; ++i)
	{
		int peopleId;
		resultsFile >> peopleId;
		People * currentPeople = findPeopleById(people, peopleId);

		float currentResult;
		resultsFile >> currentResult;

		setResultForPeople(currentPeople, currentResult);

		resultsFile.ignore(std::numeric_limits<int>::max(), '\n');
	}
	resultsFile.close();

	People * winner = nullptr;
	float maxResult = std::numeric_limits<float>::min();
	for (int i = 0; i < PEOPLE_COUNT; ++i)
	{
		float currentMaxResult = maxPeopleResult(people[i]);
		if (maxResult < currentMaxResult)
		{
			maxResult = currentMaxResult;
			winner = &people[i];
		}
	}

	cout << winner->fistName << ' '
		<< winner->lastName << ' '
		<< maxPeopleResult(*winner) << endl;
}