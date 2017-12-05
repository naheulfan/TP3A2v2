#pragma once
#include <vector>
template<typename T>
class PileVector
{

public:
	PileVector()
	{

	}
	~PileVector()
	{

	}
	void Push(const T & value)
	{
		vector.push_back(value);
	}
	T Pop()
	{
		T retval = vector.back();
		vector.pop_back();
		return retval;
	}
	size_t Size()
	{
		return vector.size();
	}
	T Top()
	{
		return vector.back();
	}
	bool IsEmpty()
	{
		return vector.empty();
	}
private:
	std::vector<T> vector;

};

