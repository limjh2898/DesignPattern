#include <iostream>
#include "Subject.h"

enum class BehaviorType
{
	Water,
	Fertilizer,
	Nutrients
};

class Fruit : public Observer<BehaviorType>
{
public:
	Fruit(int defaultSize) 
		: fruitCount_(1), fruitSize_(defaultSize) {}

	virtual ~Fruit() {}

	virtual void OnNotify(BehaviorType eventType) override
	{
		switch (eventType)
		{
		case BehaviorType::Water:
			fruitCount_++;
			std::cout << "�� �ֱ�... ";
			break;

		case BehaviorType::Fertilizer:
			fruitSize_++;
			std::cout << "�Ÿ� �ֱ�... ";
			break;

		case BehaviorType::Nutrients:
			fruitCount_++;
			fruitSize_++;
			std::cout << "������ �ֱ�... ";
			break;
		}

		std::cout << "���Ű� " << fruitCount_ << "�� ���Ȱ� ũ��� " << fruitSize_ << "�Դϴ�.\n";
	}

private:
	int fruitCount_;
	int fruitSize_;
};

class TomatoTree : public Fruit
{
public:
	TomatoTree() : Fruit(1) {}

	virtual void OnNotify(BehaviorType eventType) override
	{
		std::cout << "[�丶�� ����] ";
		Fruit::OnNotify(eventType);
	}
};

class MellonTree : public Fruit
{
public:
	MellonTree() : Fruit(2) {}

	virtual void OnNotify(BehaviorType eventType) override
	{
		std::cout << "[�ȷ� ����] ";
		Fruit::OnNotify(eventType);
	}
};

class AppleTree : public Fruit
{
public:
	AppleTree() : Fruit(1) {}

	virtual void OnNotify(BehaviorType eventType) override
	{
		std::cout << "[��� ����] ";
		Fruit::OnNotify(eventType);
	}
};

class Farm : public Subject<BehaviorType>
{
public:
	void FarmerBehavior(BehaviorType type)
	{
		NotifyAll(type);
		std::cout << std::endl;
	}
};

int main()
{
	Farm farm;
	TomatoTree tomato;
	MellonTree mellon;
	AppleTree apple;

	farm.AddObserver(&tomato);
	farm.AddObserver(&mellon);

	farm.FarmerBehavior(BehaviorType::Water);
	farm.FarmerBehavior(BehaviorType::Fertilizer);

	farm.AddObserver(&apple);

	farm.FarmerBehavior(BehaviorType::Nutrients);

	farm.RemoveObserver(&tomato);
	farm.FarmerBehavior(BehaviorType::Water);

	return 0;
}