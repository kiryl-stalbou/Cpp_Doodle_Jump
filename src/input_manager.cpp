#include "input_manager.hpp"

void InputManager::keyPressed(char key) {
    switch (key) {
    case consts::RIGHT:
        keyInputs_ = InputKeys::right;
        keyPresses_ = InputKeys::right;
        break;

    case consts::LEFT:
        keyInputs_ = InputKeys::left;
        keyPresses_ = InputKeys::left;
        break;

    case consts::PAUSE:
        keyInputs_ = InputKeys::pause;
        keyPresses_ = InputKeys::pause;
        break;

    default: break;
    }
}

void InputManager::keyReleased(char key) {
    switch (key) {
    case consts::RIGHT:
        keyInputs_ = 0;
        break;

    case consts::LEFT:
        keyInputs_ = 0;
        break;

    case consts::PAUSE:
        keyInputs_ = 0;
        break;

    default: break;
    }
}

void InputManager::mouseHandle(InputMouse::type state) {
    switch (state) {
    case InputMouse::Lclick:
        mouseInputs_ = InputMouse::Lclick;
        mousePresses_ = InputMouse::Lclick;
        break;

    case InputMouse::Lrelease:
        mouseInputs_ = 0;
        mouseReleases_ = InputMouse::Lrelease;
        break;

    case InputMouse::Rclick:
        mouseInputs_ = InputMouse::Rclick;
        mousePresses_ = InputMouse::Rclick;
        break;

    case InputMouse::Rrelease:
        mouseInputs_ = 0;
        mouseReleases_ = InputMouse::Rrelease;
        break;

    default: break;
    }
}

void InputManager::reset() {
    mouseReleases_ = 0;
    mousePresses_ = 0;
    keyPresses_ = 0;
    keyReleases_ = 0;
}

void InputManager::setMousePos(Point mousePos) { mousePos_ = mousePos; }

Point InputManager::getMousePos() const { return mousePos_; }

bool InputManager::isKeyPressed(InputKeys::type key) const {
    return key == keyInputs_;
}

bool InputManager::didKeyPress(InputKeys::type key) const {
    return key == keyPresses_;
}

bool InputManager::didKeyRelease(InputKeys::type key) const {
    return key == keyReleases_;
}

bool InputManager::isMousePressed(InputMouse::type state) const {
    return state == mouseInputs_;
}

bool InputManager::didMousePress(InputMouse::type state) const {
    return state == mousePresses_;
}

bool InputManager::didMouseRelease(InputMouse::type state) const {
    return state == mouseReleases_;
}
