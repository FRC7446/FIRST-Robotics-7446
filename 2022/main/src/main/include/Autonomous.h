#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <cameraserver/CameraServer.h>
#include <frc/Timer.h>
#include <units/time.h>
#include <utility>
#include <tuple>
#include <vector>
#include <thread>

#include "VisionControl.h"
#include "SafeData.hpp"
#include "Autonamoter.h"
#include "SafeData.hpp"
/**
 * @brief A class that handles autonomous functionallity
 * 
 */
class Autonomous {
    public:
        /**
         * @brief Construct a new `Autonomous` object
         * 
         * @param drive A `frc::DifferentialDrive` object which will be used to control the robot in Autonomous mode
         * @param yeeter A `YeeterController` object used to control the OMEGA YEETER in autonomous mode
         * @param visionData A `SafeData` object that has the templated values of <double, double, double, double> which are used to store the x, y, distance, and radius values of the detected circle
         * @param camera A `cs::UsbCamera` object that you want to get the video feed from to use for autonomous VisionSense
         */
        Autonomous(frc::DifferentialDrive& drive, frc::PWMVictorSPX& yeeter, frc::PWMVictorSPX& conveyor, SafeData<std::tuple<double, double, double, double>>& visionData, cs::UsbCamera& camera);

        /**
         * @brief Starts the `Autonomous` class
         * 
         * @return int 
         */
        int start();
        /**
         * @brief Stops the `Autonomous` class
         * 
         */
        void stop();
        /**
         * @brief Updates the `Autonomous` class
         * 
         */
        void update();
        /**
         * @brief Returns if the `Autonomous` class is started or not
         * 
         * @return true 
         * @return false 
         */
        bool isStarted();

    private:
        frc::DifferentialDrive& m_drive;
        frc::PWMVictorSPX& m_yeeter;
        frc::PWMVictorSPX& m_conveyor;
        SafeData<std::tuple<double, double, double, double>>& m_visionData;
        bool m_started;
        // Declare your autonomous classes here
        VisionController m_visionControl;
        AutonomousDrive m_autoDrive;
        std::thread m_timerThread;
        bool m_timerContinue;
        std::thread m_move;
        SafeData<units::time::second_t> m_time;
        frc::Timer m_timer;
};