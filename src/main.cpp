/*
MIT License

Copyright (c) 2022 Lou Amadio

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// This ROS Project is responsible for converting user intent into BB-8 body movements. 
// The BB-8 body is implemented using 2 differential drive controllers: a Servo and Robo claw motor controller.
// The Servo Controller handles the following body movements:
// 1. Head rotation
// 2. Head nod
// 3. Head tilt
// 4. Body tilt

// The Robo Claw Controller handles the following body movements:
// 1. Body revolution about the center axis
// 2. Body spin in place

// To support bringup, this project will directly map joystick inputs to the body movements in the following way:
// 1. Left joystick X axis: Body tilt
// 2. Left joystick Y axis: Body revolution
// 3. Right joystick X axis: Head tilt
// 4. Right joystick Y axis: Head nod
// 5. Left and shoulder buttons: Head Spin

// The Servo controller subscribes to /servo/channel_x, where x is between 0 and 15. It accepts a float32 message with a value between -1.0 and 1.0.

// RoboClaw controller drivers that are avaiable are designed for differential drive robots, which this robot is not. 





#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class BBBody : public rclcpp::Node
{
  public:
    BBBody()
    : Node("bb_body")
    {
    }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<BBBody>());
  rclcpp::shutdown();
  return 0;
}