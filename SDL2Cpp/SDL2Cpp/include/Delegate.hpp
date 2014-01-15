// Delegate.hpp

#ifndef __DELEGATE_H__
#define __DELEGATE_H__

#include <functional>
#include <vector>

template<typename R, typename... Args> class Delegate
{
	public:
		template<typename U> Delegate& Register(const U& pFunction)
		{
			mFunctions.push_back(std::function<R(Args...)>(pFunction));
			return *this;
		}

		std::vector<R> Execute(Args... pParams)
		{
			std::vector<R> ret;
			for (auto f : mFunctions)
				ret.push_back(f(pParams...));

			return ret;
		}

	private:
		std::vector<std::function<R(Args...)>> mFunctions;
};

template<typename... Args> class Delegate<void, Args...>
{
	public:
		template<typename U> Delegate& Register(const U& pFunction)
		{
			mFunctions.push_back(std::function<void(Args...)>(pFunction));
			return *this;
		}

		void Execute(Args... pParams)
		{
			for (auto f : mFunctions)
				f(pParams...);
		}

	private:
		std::vector<std::function<void(Args...)>> mFunctions;
};

#endif
