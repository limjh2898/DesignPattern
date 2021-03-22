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
			std::cout << "물 주기... ";
			break;

		case BehaviorType::Fertilizer:
			fruitSize_++;
			std::cout << "거름 주기... ";
			break;

		case BehaviorType::Nutrients:
			fruitCount_++;
			fruitSize_++;
			std::cout << "영양제 주기... ";
			break;
		}

		std::cout << "열매가 " << fruitCount_ << "개 열렸고 크기는 " << fruitSize_ << "입니다.\n";
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
		std::cout << "[토마토 나무] ";
		Fruit::OnNotify(eventType);
	}
};

class MellonTree : public Fruit
{
public:
	MellonTree() : Fruit(2) {}

	virtual void OnNotify(BehaviorType eventType) override
	{
		std::cout << "[맬론 나무] ";
		Fruit::OnNotify(eventType);
	}
};

class AppleTree : public Fruit
{
public:
	AppleTree() : Fruit(1) {}

	virtual void OnNotify(BehaviorType eventType) override
	{
		std::cout << "[사과 나무] ";
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