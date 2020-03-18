#pragma once
#include <random>

namespace ext
{
	/** Ôóíêöèÿ âîçâðàùàåò ñëó÷àéíîå çíà÷åíèå òèïà int èç óêàçàííîãî èíòåðâàëà.
  *
  * @param min íèæíÿÿ ãðàíèöà èíòåðâàëà (âêëþ÷èòåëüíî)
  * @param max âåðõíÿÿ ãðàíèöà èíòåðâàëà (âêëþ÷èòåëüíî)
  * @param isDebugMode åñëè true òî êàæäûé ðàç áóäåò ãåíåðèðîâàòüñÿ îäèíàêîâàÿ ïîñëåäîâàëüíîñòü äëÿ óäîáñòâà ïðè îòëàäêè
  * @return ñëó÷àéíîå çíà÷åíèå òèïà int èç óêàçàííîãî èíòåðâàëà
  */
	int GetRandomValue(int min, int max, bool isDebugMode = false)
	{
		static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
		auto distribution = std::uniform_int_distribution<int>(min, max);
		return distribution(randomEngine);
	}
}
