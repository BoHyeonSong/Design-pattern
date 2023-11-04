#include <iostream>

using namespace std;

class Singleton
{
	Singleton() {};
	//�����ڸ� private���� �����Ͽ� �ܺο��� ���� ��ü�� ������ �� ����

	static Singleton* instance;
	//Singleton �� ��ü�� ����Ű�� instance
	//static ���� �Ͽ� instance�� �ϳ��� ���� �ϵ��� ��

public:
	static Singleton* getInstance()
	{
		if (instance != nullptr)
		{
			return instance; 
			//instance�� �����Ǿ� ������ ��ȯ
		}
		else
		{
			instance = new Singleton();
			return instance; 
			//instance�� ������ ����� ��ȯ
		}
	}
};

Singleton* Singleton::instance = nullptr;

int main()
{
	// Singleton a;(x) �������� ���������ڰ� private��

	Singleton* a = Singleton::getInstance();
	Singleton* b = Singleton::getInstance();
	Singleton* c = Singleton::getInstance();

	cout << "a addr : " << a << endl;
	cout << "b addr : " << b << endl;
	cout << "b addr : " << c << endl;

	return 0;
}