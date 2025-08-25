#pragma once

#include <vector>
#include <functional>

// Generic parameter
template<typename T>
class Signal
{
public:
	using Callback = std::function<void(T)>;

	void connect(Callback callback)
	{
		listeners.push_back(std::move(callback));
	}

	void emit(const T& value)
	{
		for (auto& callback : listeners)
		{
			callback(value);
		}
	}

	explicit operator bool() const
	{
		return !listeners.empty();
	}

private:
	std::vector<Callback> listeners;
};

// Void parameter
template<>
class Signal<void>
{
public:
	using Callback = std::function<void()>;

	void connect(Callback callback)
	{
		listeners.push_back(std::move(callback));
	}

	void emit()
	{
		for (auto& callback : listeners)
		{
			callback();
		}
	}

	explicit operator bool() const
	{
		return !listeners.empty();
	}

private:
	std::vector<Callback> listeners;
};
