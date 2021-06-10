//
// Created by Mevlüt Özdemir on 25-02-18.
//

#ifndef SHOOTER_SPACESHIPBRAKESTATE_H
#define SHOOTER_SPACESHIPBRAKESTATE_H


class SpaceShipBrakeState : public State<SpaceShip> {

public:
    void enterState(SpaceShip &owner) override;

    void exitState(SpaceShip &owner) override;

    void updateState(SpaceShip &owner, float elapsedTime) override;

    std::string getName() const override;
};

#endif //SHOOTER_SPACESHIPBRAKESTATE_H
