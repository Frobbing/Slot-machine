#pragma once

#include <stdint.h>

static const long stepsPerRev = 1600;

static const int spinStartInterval = 500;

static const int screenResultTimeout = 5000;

static const int buttonPin = 11;

// Motor initialization

static const uint8_t leftMotorPins[2] = {2, 5};    // Step, Dir
static const uint8_t middleMotorPins[2] = {3, 6};  // Step, Dir
static const uint8_t rightMotorPins[2] = {4, 7};   // Step, Dir
static const uint8_t enablePin = 8;

// Score calculation

static const int bonusSymbol = 0;

static const int baseScore = 100;
static const int bonusPoint = 50;
static const int defaultDoubleX = 2;
static const int bonusDoubleX = 5;
static const int defaultTripleX = 15;
static const int bonusTripleX = 80;

// Display initialization

static const uint8_t screenAddress = 0x26;
static const uint8_t screenWidth = 16;
static const uint8_t screenHeight = 2;



