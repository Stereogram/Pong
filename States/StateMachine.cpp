#include "StateMachine.h"

void StateMachine::nextState()
{
	if (_resume)
	{
		// Cleanup the current state
		if (!_states.empty())
		{
			_states.pop();
		}

		// Resume previous state
		if (!_states.empty())
		{
			_states.top()->resume();
		}

		_resume = false;
	}

	// There needs to be a state
	if (!_states.empty())
	{
		std::unique_ptr<State> temp = _states.top()->next();

		// Only change states if there's a next one existing
		if (temp != nullptr)
		{
			// Replace the running state
			if (temp->isReplacing())
				_states.pop();
			// Pause the running state
			else
				_states.top()->pause();

			_states.push(std::move(temp));
		}
	}
}
