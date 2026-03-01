# Real Time Automotive Dashboard Development Using CAN Protocol

## Overview
This project implements a real-time automotive dashboard communication system using CAN protocol.

## Features
- CAN communication between Node A and Node B
- ADC sensor data transmission
- LCD display integration
- Interrupt-based communication
- Embedded C implementation

## Technologies Used
- Embedded C
- CAN Protocol
- Microcontroller Programming
- LCD Interface
- Interrupt Handling

## Folder Structure
- Node_A → Sensor + CAN Transmission
- Node_B → CAN Reception + Display

## System Architecture
- Node A: Reads sensor data using ADC and transmits via CAN
- Node B: Receives CAN messages and displays data on LCD
- Communication via CAN bus protocol

## Hardware Requirements
- Microcontroller (e.g., ATmega / ARM-based MCU)
- CAN Controller
- CAN Transceiver
- LCD Display
- Analog Sensor

## How to Build and Run
1. Compile Node_A firmware
2. Flash to Node A
3. Compile Node_B firmware
4. Flash to Node B
5. Connect both nodes via CAN bus

## Future Improvements
- Add error handling and fault detection
- Add CAN message filtering
- Add RTOS support
- Extend to multi-node architecture
