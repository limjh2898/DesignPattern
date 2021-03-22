/*
	관찰 대상 객체 베이스 클래스
*/

#pragma once
#include<list>
#include<algorithm>
#include "Observer.h"

template <typename EventType>
class Subject
{
	typedef Observer<EventType> ObserverType_;
public:
	Subject() = default;
	virtual ~Subject() { ClearObserver(); }

public:

	// 관찰자 등록
	void AddObserver(ObserverType_* observer)
	{
		observerCollection_.push_back(observer);
	}

	// 관찰자 삭제
	void RemoveObserver(ObserverType_* observer)
	{
		observerCollection_.remove(observer);
	}

	void ClearObserver()
	{
		observerCollection_.clear();
	}

protected:
	// 통지
	void NotifyAll(EventType eventType)
	{
		for (auto& o : observerCollection_)
		{
			o->OnNotify(eventType);
		}
	}

private:
	std::list<ObserverType_*> observerCollection_;
};