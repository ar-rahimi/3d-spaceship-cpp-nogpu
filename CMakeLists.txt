cmake_minimum_required(VERSION 3.8)
project(Shooter)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Shooter_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wno-c++11-narrowing)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wno-narrowing")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

message(${SDL2_mixer_FOUND})


include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} source/headers include content lib)
message(${SDL2_TTF_INCLUDE_DIR})
message(${SDL2_TTF_LIBRARIES})
set(SOURCE_FILES
        Engine/StateMachine/NullState.h
        Engine/StateMachine/State.h
        Engine/StateMachine/StateMachine.h
        Game/SpaceShipInputHandlers/headers/ActionTurnUp.h
        Game/SpaceShipInputHandlers/headers/ActionTurnDown.h
        Game/SpaceShipInputHandlers/handlers/ActionTurnDown.cpp
        Game/SpaceShipInputHandlers/handlers/MatrixActionInterface.h
        Game/SpaceShipInputHandlers/ActionHandlerFactory.h
        Game/SpaceShipInputHandlers/headers/ActionNull.h
        Game/SpaceShipInputHandlers/ActionHandlerFactory.cpp
        Game/SpaceShipInputHandlers/handlers/ActionTurnUp.cpp
        Game/SpaceShipInputHandlers/handlers/ActionNull.cpp
        main.cpp
        Game/Game.h
        Game/Game.cpp
        Game/SpaceShip.cpp
        Game/SpaceShip.h
        Engine/headers/Drawable.h
        Engine/Timer.cpp
        Engine/headers/Timer.h
        Engine/RenderManager.cpp
        Engine/headers/RenderManager.h
        Engine/headers/Controls.h
        Engine/InputManager.cpp
        Engine/headers/InputManager.h
        Engine/headers/Helper.h
        Engine/MatrixFactory.cpp
        Engine/headers/MatrixFactory.h
        Game/mvector.cpp
        Game/mvector.h
        Game/point.cpp
        Game/point.h
        Game/matrix.cpp
        Game/matrix.h
        Game/Matrix2d.cpp
        Game/Matrix2d.h
        Game/point3d.cpp
        Game/point3d.h
        Game/Matrix3d.cpp
        Game/Matrix3d.h
        Game/vector3d.cpp
        Game/vector3d.h
        Game/Camera.cpp
        Game/Camera.h
        Game/Bullet.cpp
        Game/Bullet.h
        Game/SpaceShipInputHandlers/headers/ActionMoveLeft.h
        Game/SpaceShipInputHandlers/headers/ActionMoveRight.h
        Game/SpaceShipInputHandlers/handlers/ActionScaleUp.cpp
        Game/SpaceShipInputHandlers/headers/ActionScaleUp.h
        Game/SpaceShipInputHandlers/handlers/ActionScaleDown.cpp
        Game/SpaceShipInputHandlers/headers/ActionScaleDown.h
        Game/SpaceShipInputHandlers/handlers/ActionPitch.cpp
        Game/SpaceShipInputHandlers/headers/ActionPitch.h
        Game/SpaceShipInputHandlers/handlers/ActionShoot.cpp
        Game/SpaceShipInputHandlers/headers/ActionShoot.h
        Game/TargetObject.cpp
        Game/TargetObject.h
        Game/SpaceShipInputHandlers/handlers/ActionRoll.cpp
        Game/SpaceShipInputHandlers/headers/ActionRoll.h
        Game/SpaceShipInputHandlers/handlers/ActionYaw.cpp
        Game/SpaceShipInputHandlers/headers/ActionYaw.h Tests/ActionHandlerTest.cpp Game/SpaceShipInputHandlers/handlers/ActionRollLeft.cpp Game/SpaceShipInputHandlers/handlers/ActionRollLeft.h Game/SpaceShipInputHandlers/handlers/ActionRollRight.cpp Game/SpaceShipInputHandlers/handlers/ActionRollRight.h Game/SpaceShipInputHandlers/handlers/ActionTurnLeft.cpp Game/SpaceShipInputHandlers/handlers/ActionTurnLeft.h Game/SpaceShipInputHandlers/handlers/ActionTurnRight.cpp Game/SpaceShipInputHandlers/handlers/ActionTurnRight.h Game/SpaceShipInputHandlers/handlers/ActionGas.cpp Game/SpaceShipInputHandlers/handlers/ActionGas.h Game/SpaceShipStates/SpaceShipMoveState.cpp Game/SpaceShipStates/headers/SpaceShipMoveState.h Game/SpaceShipStates/SpaceShipIdleState.cpp Game/SpaceShipStates/headers/SpaceShipIdleState.h Game/SpaceShipStates/SpaceShipBrakeState.cpp Game/SpaceShipStates/headers/SpaceShipBrakeState.h Game/SpaceShipInputHandlers/handlers/ActionBrake.cpp Game/SpaceShipInputHandlers/handlers/ActionBrake.h Game/SpaceShipInputHandlers/handlers/ActionSwitchHelpLine.cpp Game/SpaceShipInputHandlers/handlers/ActionSwitchHelpLine.h Game/SpaceShipInputHandlers/handlers/ActionSwitchDebug.cpp Game/SpaceShipInputHandlers/handlers/ActionSwitchDebug.h)
add_executable(GroepH ${SOURCE_FILES} Tests/MatrixTest.cpp Tests/Matrix3dTest.cpp Tests/TemplateTest.cpp)

target_link_libraries(GroepH gtest gtest_main)

target_link_libraries(GroepH ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_TTF_LIBRARIES})