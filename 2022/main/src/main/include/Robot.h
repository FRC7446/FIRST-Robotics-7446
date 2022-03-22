#pragma once
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Timer.h>
#include <frc/Joystick.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <cameraserver/CameraServer.h>
#include <utility>
#include <thread>
#include <memory>
#include <vector>

#include "ButtonState.h"
#include "DriverControl.h"
#include "GradTurn.h"
#include "YeeterControl.h"
#include "PickupMechControl.h"
#include "ConveyorControl.h"
#include "SafeData.hpp"
#include "Autonomous.h"


/**
 * @brief Main robot class
 * @brief For more information on how to use WPILibC++ goto https://first.wpi.edu/wpilib/allwpilib/docs/release/cpp/index.html
 */
template<typename JoystickType>
class Robot : public frc::TimedRobot {
 public:
/**
 * @brief Construct a new Robot object
 * 
 */
  Robot();

/**
 * @brief This function that gets called when the robot first turns on
 * 
 */
  void RobotInit() override;
/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
  void RobotPeriodic() override;
/**
 * @brief This function gets called whenever the mode gets switched to Autonomous and it only gets called once per mode switch
 * 
 */
  void AutonomousInit() override;
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Autonomous
 * 
 */
  void AutonomousPeriodic() override;
/**
 * @brief This function gets called whenever the mode gets switched to Teleoperated and only gets called once per mode switch
 * 
 */
  void TeleopInit() override;
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Teleoperated
 * 
 */
  void TeleopPeriodic() override;
/**
 * @brief This function gets called whenever the mode gets switched to Disabled, or when you first start your robot and only gets called once per mode switch
 * 
 */
  void DisabledInit() override;
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Disabled
 * 
 */
  void DisabledPeriodic() override;
/**
 * @brief This function gets called whenever the mode gets switched to Test and only gets called once per mode switch
 * 
 */
  void TestInit() override;
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Test
 * 
 */
  void TestPeriodic() override;

 private:
  // Motors for the drive wheels
  /**
   * @brief Left motor
   * 
   */
  frc::PWMVictorSPX m_leftMotor;
  /**
   * @brief Right motor
   * 
   */
  frc::PWMVictorSPX m_rightMotor;
  // Motor for the launcher
  /**
   * @brief Motor for the YEETER (launcher)
   * 
   */
  frc::PWMVictorSPX m_yeeter;
  // Motor for the conveyor belt
  /**
   * @brief Motor for the conveyor belt
   * 
   */
  frc::PWMVictorSPX m_conveyor;
  // Motor for the pickup mechanism
  /**
   * @brief Motor for the pickup mechanism
   * 
   */
  frc::PWMVictorSPX m_pickupMech;
  /**
   * @brief The `DifferentialDrive` object
   * 
   */
  frc::DifferentialDrive m_drive;
  /**
   * @brief The joystick object
   * 
   */
  JoystickType m_joystick;

  /**
   * @brief The `ButtonState` object
   * 
   */
  ButtonState m_joystickButtons;
  /**
   * @brief The `DriveController` object
   * 
   */
  DriverController m_driveControl;
  /**
   * @brief The `GradualTurn` object
   * 
   */
  GradualTurn m_gradualTurn;
  /**
   * @brief The YeeterController object
   * 
   */
  YeeterController m_yeeterControl;
  /**
   * @brief The PickupController object
   * 
   */
  PickupController m_pickupControl;
  /**
   * @brief The ConveyorController object
   * 
   */
  ConveyorController m_conveyorControl;
  /**
   * @brief The all purpose camera thread for normal camera use
   * 
   */
  std::thread m_cameraThread;
  /**
   * @brief The `Autonomous` controller object
   * 
   */
  Autonomous m_autonomous;
  /**
   * @brief The `SafeData` object
   * 
   */
  SafeData<std::tuple<double, double, double, double>> m_safeData;
  /**
   * @brief The main camera object
   * 
   */
  cs::UsbCamera m_camera;
  /**
   * @brief The server broadcasting the data from `m_camera` to the SmartDashboard
   * 
   */
  cs::MjpegServer m_cameraServer;
};

#include "Robot.hpp"