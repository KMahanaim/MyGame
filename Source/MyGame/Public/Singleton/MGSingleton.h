#pragma once

template <class T>
class MGSingleton
{

protected:
	MGSingleton() {}
	virtual ~MGSingleton() {}

	void Set(T* manager)
	{
		Instance = manager;
	}

	void Clear()
	{
		Instance = nullptr;
	}
public:

	static T* Get()
	{
		return Instance;
	}

private:

	static T* Instance;

};


template <class T> T* MGSingleton<T>::Instance = nullptr;
