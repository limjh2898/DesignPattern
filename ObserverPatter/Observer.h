/*
	������ Ŭ����
*/

#pragma once

template <typename EventType>
class Observer
{
public:
	Observer() = default;
	virtual ~Observer() {}

	virtual void OnNotify(EventType eventType) = 0;
};