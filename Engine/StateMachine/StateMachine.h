//
// Created by Mevlüt Özdemir on 18-12-17.
//

#ifndef TOETS_STATEMACHINE_H
#define TOETS_STATEMACHINE_H

#include "State.h"
#include "NullState.h"

template<typename T>

class StateMachine {

private:
    T &owner;
    State<T> *currentState;
    State<T> *globalState;

public:
    explicit StateMachine(T &owner) :
            owner{owner},
            currentState{new NullState<T>()},
            globalState{new NullState<T>()} {

        // set states to NullState so we don't need to have
        // null checks, eg: if(currentState != nullptr)
    }

    void changeGlobalState(State<T> *newState) {
        changeState(globalState, newState);
    }

    void changeCurrentState(State<T> *newState) {
        changeState(currentState, newState);
    }

    void changeState(State<T> *&state, State<T> *&newState) {
        state->exitState(owner);
        delete state;

        state = newState;
        state->enterState(owner);
    }

    void update(float elapsedTime) {
        globalState->updateState(owner, elapsedTime);
        currentState->updateState(owner, elapsedTime);
    }

    State<T> *getCurrentState() const {
        return currentState;
    }

    ~StateMachine() {
        delete currentState;
        delete globalState;
    }

};


#endif //TOETS_STATEMACHINE_H
