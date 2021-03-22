/*
	관찰자 클래스
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