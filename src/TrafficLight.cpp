#include "TrafficLight.h"
#include <iostream>
#include <random>

/* Implementation of class "MessageQueue" */

template <typename T>
T MessageQueue<T>::receive() {
  std::unique_lock<std::mutex> lock(_mutex);
  _condition.wait(lock, [this] { return !_queue.empty(); });
  T msg = std::move(_queue.back());
  _queue.pop_back();
  return msg;
}

template <typename T>
void MessageQueue<T>::send(T &&msg) {
  std::lock_guard<std::mutex> lock(_mutex);
  _queue.push_front(std::move(msg));
  _condition.notify_one();
}

/* Implementation of class "TrafficLight" */

TrafficLight::TrafficLight() {
  _type = ObjectType::objectTrafficLight;
  _currentPhase = TrafficLightPhase::red;
}

void TrafficLight::waitForGreen() {
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    auto msg = _msgQueue.receive();
    if (msg == TrafficLightPhase::green)
      ;
    return;
  }
}

TrafficLightPhase TrafficLight::getCurrentPhase() { return _currentPhase; }

void TrafficLight::toggleCurrentPhase() {
  _currentPhase = _currentPhase == TrafficLightPhase::red
                      ? TrafficLightPhase::green
                      : TrafficLightPhase::red;
}

void TrafficLight::simulate() {
  threads.emplace_back(&TrafficLight::cycleThroughPhases, this);
}

// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases() {
  double cycleDuration = 4.0 + static_cast<double>(rand()) / RAND_MAX * 2.0;
  auto lastUpdate = std::chrono::steady_clock::now();
  while (true) {
    auto now = std::chrono::steady_clock::now();
    auto timeDifference =
        std::chrono::duration_cast<std::chrono::milliseconds>(now - lastUpdate)
            .count() /
        1000.0;
    if (timeDifference >= cycleDuration) {
      toggleCurrentPhase();
      lastUpdate = now;
      _msgQueue.send(std::move(_currentPhase));
    }
    // sleep at every iteration to reduce CPU usage
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}
