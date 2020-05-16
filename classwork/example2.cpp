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
};

struct Result
{
	int peopleId;
	float value;
};

const int PEOPLE_COUNT = 20;
const int TRY_COUNT = 3;
const int RESULTS_COUNT = PEOPLE_COUNT * TRY_COUNT;
const string PEOPLE_FILE_NAME = "athletes.txt";
const string RESULT_FILE_NAME = "results.txt";

Result findMaxResult(Result results[])
{
	float maxResult = results[0].value;
	int index = 0;

	for (int i = 1; i < RESULTS_COUNT; ++i)
	{
		if (maxResult < results[i].value)
		{
			maxResult = results[i].value;
			index = i;
		}
	}

	return results[index];
}

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

	Result * results = new Result[RESULTS_COUNT];
	for (int i = 0; i < RESULTS_COUNT; ++i)
	{
		resultsFile >> results[i].peopleId;
		resultsFile >> results[i].value;
		resultsFile.ignore(std::numeric_limits<int>::max(), '\n');
	}
	resultsFile.close();

	Result maxResult = findMaxResult(results);

	People * winner = nullptr;
	for (int i = 0; i < PEOPLE_COUNT; ++i)
	{
		if (people[i].id == maxResult.peopleId)
		{
			winner = &people[i];
			break;
		}
	}

	cout << winner->fistName << ' '
		<< winner->lastName << ' '
		<< maxResult.value << endl;
}