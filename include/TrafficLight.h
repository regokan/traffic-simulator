#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <condition_variable>
#include <deque>
#include <mutex>
#include "TrafficObject.h"

// forward declarations to avoid include cycle
class Vehicle;

template <class T>
class MessageQueue {
 public:
  T receive();
  void send(T &&msg);

 private:
  std::deque<T> _queue;
  std::condition_variable _condition;
  std::mutex _mutex;
};

enum TrafficLightPhase { red, green };

class TrafficLight : public TrafficObject {
 public:
  // constructor / desctructor
  TrafficLight();

  // getters / setters
  TrafficLightPhase getCurrentPhase();
  void toggleCurrentPhase();

  // typical behaviour methods
  void waitForGreen();
  void simulate();

 private:
  // typical behaviour methods
  void cycleThroughPhases();

  // private members
  TrafficLightPhase _currentPhase;

  MessageQueue<TrafficLightPhase> _msgQueue;
  std::condition_variable _condition;
  std::mutex _mutex;
};

#endif