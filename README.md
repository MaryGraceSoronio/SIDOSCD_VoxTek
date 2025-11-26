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


# RA6M3-HMI-Board-LVGL Reference Design Guide 

[中文](README_ZH.md)|English|[性能评估](docs/evaluation.md)

Get ready to rock with our LVGL music player demo, designed for the HMI-Board development board. Built on the RT-Thread operating system and compatible with RT-Thread Studio/MDK5 software development environment, this design is powered by the RA6M3 central control chip. With features like 2D acceleration, JPEG encoding and decoding, and 2M Flash large-capacity storage control, you’ll have everything you need to create amazing graphic applications.

Our reference design comes pre-loaded with the LVGL music player, boasting a stunning playback interface and easy-to-use controls. Just hit play/pause or skip to the next track right from the main screen.

This guide has got you covered with technical architecture, usage instructions, and resources and documentation. Dive in to evaluate the graphic performance of the RA6M3 chip and start building on this reference design for your own secondary development.

## Technical Architecture

HMI-Board-LVGL technical architecture includes the System Layer, the Components Layer and the Applications layer. 

![](docs/picture/lvgl/lvgl.png)

### System Layer

RT-Thread was born in 2006, it is an open source, neutral, and community-based real-time operating system (RTOS). RT-Thread has not only just a real-time kernel, but also rich components. 

It includes:

- Kernel layer: RT-Thread kernel, the core part of RT-Thread, includes the implementation of objects in the kernel system, such as multi-threading and its scheduling, semaphore, mailbox, message queue, memory management, timer, etc.; libcpu/BSP (Chip Migration Related Files/Board Support Package) is closely related to hardware and consists of peripheral drivers and CPU porting.
- Components and Service Layer: Components are based on upper-level software on top of the RT-Thread kernel, such as virtual file systems, FinSH command-line interfaces, network frameworks, device frameworks, and more. Its modular design allows for high internal cohesion inside the components and low coupling between components.
- [RT-Thread software package](https://packages.rt-thread.org/en/index.html): A general-purpose software component running on the RT-Thread IoT operating system platform for different application areas, consisting of description information, source code or library files. RT-Thread provides an open package platform with officially available or developer-supplied packages that provide developers with a choice of reusable packages that are an important part of the RT-Thread ecosystem. The package ecosystem is critical to the choice of an operating system because these packages are highly reusable and modular, making it easy for application developers to build the system they want in the shortest amount of time. RT-Thread supports 600+ software packages.

### Component Layer

The HMI-Board goes above and beyond with system-level support and integration of several top-notch system components. The LVGL multimedia component has been added to our example project for your convenience. All developers need to do is enable the LVGL software package in RT-Thread Studio/env and pull it from the server to add LVGL to their development project as a component. It’s that easy! No more complicated steps or manual additions - just improved efficiency and a smoother development process.

### Application Layer

The application layer in LVGL allows for the development of secondary user interfaces. Users can integrate their pre-existing or newly developed UI code at this level.

Music Player Demo:

Easily control the music player on the touch panel by playing/pausing or skipping to the next track directly from the main screen. Access the music list by pulling up the panel control. The code can also be modified to switch from manual to automatic playback.

## How to Use

With RT-Thread Studio, you have the option to create an LVGL-Demo using a sample project. Once the project is set up, all you need to do is compile and upload it.

> For more information on installing and using RT-Thread Studio, check out the [[Quick Start]](https://www.rt-thread.io/document/site/rtthread-studio/um/studio-user-manual/) guide.

![](docs/picture/lvgl/lvgl-1.png)

This image illustrates how the LVGL package is integrated within RT-Thread. Users have the ability to configure LVGL using a visual interface.

![](docs/picture/lvgl/lvgl-2.png)

## Resources and Documentation

For LVGL UI development, you can visit the LVGL official website and documentation center for more detailed information:

- [LVGL - Light and Versatile Embedded Graphics Library](https://lvgl.io/)
- [LVGL documentation](https://docs.lvgl.io/8.3/)
