#include "EventManager.h"

void EventManager::SetupBindingsManualy()
{
	Binding* newBinding = new Binding;
	newBinding->mEvents.push_back(std::make_pair(EventType::Closed, KeyCode()));
	AddBinding("Close", newBinding);
	newBinding = new Binding;
	newBinding->mEvents.push_back(std::make_pair(EventType::KeyDown, KeyCode(sf::Keyboard::F5)));
	AddBinding("ToggleFullscreen", newBinding);
}

EventManager::EventManager()
	: mHasFocus(true)
{
	SetupBindingsManualy();
}

EventManager::~EventManager()
{
	auto itr = mBinding.begin();
	while (itr != mBinding.end())
	{
		delete itr->second;
		++itr;
	}
}

bool EventManager::AddBinding(const std::string & lName, Binding * lBinding)
{
	if (mBinding.find(lName) != mBinding.end())
		return false;

	mBinding[lName] = lBinding;
	return true;
}

bool EventManager::RemoveBinding(const std::string & lName)
{
	if (mBinding.find(lName) == mBinding.end())
		return false;

	delete mBinding.find(lName)->second;
	mBinding.erase(lName);

	return true;
}

bool EventManager::RemoveCallback(const StateType& lType, const std::string & lName)
{
	auto itr = mCallback.find(lType);
	if (itr == mCallback.end())
		return false;
	auto itr2 = itr->second.find(lName);
	if (itr2 == itr->second.end()) { return false; }
	itr->second.erase(lName);
	return true;
}

void EventManager::Update()
{
	if (!mHasFocus)
		return;

	auto itr_b = mBinding.begin();
	while (itr_b != mBinding.end())
	{
		auto events = itr_b->second->mEvents;
		auto itr_e = events.begin();
		while (itr_e != events.end())
		{
			if (itr_e->first == EventType::Keyboard)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(itr_e->second.mCode)))
				{
					++(itr_b->second->count);
				}
			}
			else if (itr_e->first == EventType::Mouse)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button(itr_e->second.mCode)))
				{
					++(itr_b->second->count);
				}
			}
			++itr_e;
		}

		if (itr_b->second->mEvents.size() == itr_b->second->count)
		{
			auto stateCallbacks = mCallback.find(mCurrentState);
			auto otherCallbacks = mCallback.find(StateType(0));

			if (stateCallbacks != mCallback.end())
			{
				auto call = stateCallbacks->second.find(itr_b->first);
				if (call != stateCallbacks->second.end())
					call->second();
			}

			if (otherCallbacks != mCallback.end())
			{
				auto call = otherCallbacks->second.find(itr_b->first);
				if (call != otherCallbacks->second.end())
					call->second();
			}
		}
		itr_b->second->count = 0;
		++itr_b;
	}
}

void EventManager::HandleEvent(const sf::Event & lEvent)
{
	auto itr_b = mBinding.begin();
	while (itr_b != mBinding.end())
	{
		auto events = itr_b->second->mEvents;
		auto itr_e = events.begin();
		while (itr_e != events.end())
		{
			EventType type = (EventType)lEvent.type;
			if (type != itr_e->first)
			{
				++itr_e;
				continue;
			}
			if (type == EventType::KeyDown || type == EventType::KeyUp)
			{
				if (itr_e->second.mCode == lEvent.key.code)
				{
					++(itr_b->second->count);
					break;
				}
					
			}
			else if(type == EventType::MButtonDown || type == EventType::MButtonUp)
			{
				if (itr_e->second.mCode == lEvent.mouseButton.button)
				{
					++(itr_b->second->count);
					break;
				}
			}
			else
			{
				++(itr_b->second->count);
				break;
			}
				
			++itr_e;
		}
		++itr_b;
	}
}

void EventManager::SetFocus(bool lFocus)
{
	mHasFocus = lFocus;
}

void EventManager::SetCurrentState(const StateType & lType)
{
	mCurrentState = lType;
}
