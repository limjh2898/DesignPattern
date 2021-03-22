/*
	���� ��� ��ü ���̽� Ŭ����
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

	// ������ ���
	void AddObserver(ObserverType_* observer)
	{
		observerCollection_.push_back(observer);
	}

	// ������ ����
	void RemoveObserver(ObserverType_* observer)
	{
		observerCollection_.remove(observer);
	}

	void ClearObserver()
	{
		observerCollection_.clear();
	}

protected:
	// ����
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