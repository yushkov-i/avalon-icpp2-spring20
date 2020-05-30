#include <random>

namespace ext
{
	/** ������� ���������� ��������� �������� ���� int �� ���������� ���������.
  *
  * @param min ������ ������� ��������� (������������)
  * @param max ������� ������� ��������� (������������)
  * @param isDebugMode ���� true �� ������ ��� ����� �������������� ���������� ���������������� ��� �������� ��� �������
  * @return ��������� �������� ���� int �� ���������� ���������
  */
	int GetRandomValue(int min, int max, bool isDebugMode = false)
	{
		static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
		auto distribution = std::uniform_int_distribution<int>(min, max);
		return distribution(randomEngine);
	}
}