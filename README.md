### All primary project files and the stable codebase are maintained in the `master` branch. Make sure to switch to that branch when cloning or pulling.

# Smart Industrial Drying Oven Simulated Control Dashboard Using RT-Thread HMI-Board
Simulates and controls industrial drying oven via modern RT-Thread HMI dashboard with auto/manual modes, adjustable temperature and drying time, real-time safety/door status, notifications, input simulation, touch interface, codebase expandable for physical sensors, network integration, data visualization, remote access.

### by: VoxTek_SIDOSCD

## Overview

This repository provides a complete simulation of an industrial drying oven interface using the RT-Thread HMI board. The project features automatic and manual modes, real-time status, safety notifications, and a modern dashboard UI for experimenting with temperature, time, and lock logic. Originally designed for simulation, the platform is extensible for real hardware integration.

## 1. Preparation

- Clone this repository locally:
  ```bash
  git clone https://github.com/yourusername/drying-oven-simulator.git
  ```
- Download and install [RT-Thread Studio](https://www.rt-thread.io/studio.html).
- Download and install [SquareLine Studio](https://squareline.io/downloads) for GUI screen asset creation.
- Prepare the RT-Thread HMI board and a USB Type-C cable.

## 2. Creating and Importing the Project

### 2.1 Create a New Project in RT-Thread Studio
1. Open RT-Thread Studio.
2. Click **File > New > RT-Thread Project**.
3. Select your HMI board model and project template.
4. Name your project and click **Finish**.

### 2.2 Add Board Support Packages (BSP) and Configure Drivers
1. In the Project Explorer, right-click the project, choose **Board Support Package > Import** as needed.
2. Open **RT-Thread Settings** from the sidebar.
3. Enable touch, display, or other drivers as required for your board.  
   *Example: Turn on LCD, touch panel drivers.*

### 2.3 Import GUI Assets from SquareLine Studio
1. Open SquareLine Studio and design your dashboard UI (screens, buttons, indicators, icons).
2. Export the project as **LVGL C code**.
3. Copy exported files (usually `.c` and `.h`) to your RT-Thread project’s `/UI/` folder.

## 3. Configuring, Building, and Flashing

### 3.1 Adjust Project Configuration
1. Review and adjust memory settings, display parameters, or touch configuration as needed under **RT-Thread Settings**.
2. Save changes (`Ctrl+S`).

### 3.2 Build and Download Firmware
1. Click the **Build** (hammer) icon to compile your project.
2. Plug your HMI board into your PC via USB Type-C.
3. Click **Download** (green arrow), set your debug method (J-Link, DAPLink, etc.).
4. Wait for the flashing process to finish.

## 4. Using the Simulator

- The oven dashboard UI will appear on your HMI display.
- Tap between **Automatic Mode** (preset profiles) and **Manual Mode** (rotary selectors for temperature and time).
- Observe the real-time status, notifications, and safety indicator updates.
- For simulation, no extra hardware is needed; all functions are done using the board display and touch.

## 5. Optional: Adding Real Hardware

- To connect sensors (temperature, potentiometers, etc.):
  - Follow board datasheet for pinout.
  - Enable relevant drivers under **RT-Thread Settings**.
  - Update your code logic to read real input and update the dashboard accordingly.

## 6. Troubleshooting

- If the UI doesn’t display, confirm that LCD and touch are enabled and wired correctly.
- If code fails to build, check for missing drivers or incorrect settings in project config.
- Review `README.md` or seek help in RT-Thread and SquareLine Studio documentation/forums.

## About

- Designed for prototyping, UI testing, and educational demonstration of smart oven logic.
- Contributions welcome; see LICENSE for terms of use (recommended: MIT License).

## Resources

- `readme.md`: Basic configuration and guide.
- `/UI/`: SquareLine Studio-generated assets.
- `/src/`: Main code base, including dashboard logic and safety algorithms.

## Releases

No releases published.

## Languages

- C/C++
- UI asset files
- Makefile and script files
