#pragma once

#include <memory>		//unique_ptr
#include <stack>		//states will be stored on a stack with top as the active one
#include "State.hpp"

namespace gui {
	typedef std::unique_ptr<State> stateRef;

	class StateMachine {
		public:
			StateMachine() {}
			~StateMachine() {}

			void addState(stateRef newState, bool isReplacing = true);
			void removeState();
			void processStateChanges();

			stateRef& getActiveState();

		private:
			std::stack<stateRef> states;
			stateRef newState;

			bool isRemoving;
			bool isAdding;
			bool isReplacing;
	};
}
