# MIT 6.S081 Operating Systems Labs Solutions

This repository contains my solutions to the labs from the MIT 6.S081 (Operating Systems) course. The course covers fundamental concepts in operating systems, including processes, memory management, file systems, and more. The labs are designed to help students understand these concepts by implementing features in the xv6 operating system.

## Course Link

The course materials, including the schedule and lab assignments, can be found on the official MIT 6.S081 website:  
[MIT 6.S081 Schedule](https://pdos.csail.mit.edu/6.S081/2024/schedule.html)

## Purpose

This repository is intended for **educational purposes only**. The solutions provided here are my own work and are meant to help others understand the concepts covered in the course. 

---

## Installation

To run the labs, you will need to set up the xv6 environment on your machine. Follow these steps to get started:

### Prerequisites

- **Linux or macOS**: The labs are designed to run on Unix-like systems. Windows users can use WSL (Windows Subsystem for Linux).
- **QEMU**: A virtual machine emulator used to run xv6.
- **RISC-V Toolchain**: Required to compile xv6.

### Step 1: Install Dependencies

#### On Ubuntu/Debian:
```bash
sudo apt-get update
sudo apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu
```

### Step 2: Clone the xv6 Repository
```bash
git clone git://g.csail.mit.edu/xv6-labs-2024
cd xv6-labs-2024
```

### Step 3: Build and Run xv6
Compile and run xv6 using QEMU:
```bash
make qemu
```
This will start the xv6 operating system in a QEMU virtual machine. You should see the xv6 shell prompt ($).
