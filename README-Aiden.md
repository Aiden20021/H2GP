# Dashboard Application

## Description
(TODO: Add a brief description of what this application does.)

## Getting Started: Step-by-Step Guide for Windows

This guide will walk you through setting up the necessary tools and building the Dashboard application from scratch on a Windows machine.

### Step 1: Install MSYS2 (for g++ Compiler and Make)

1.  **Download MSYS2**: Go to the official MSYS2 website at [https://www.msys2.org/](https://www.msys2.org/) and download the installer.
2.  **Run the Installer**: Follow the on-screen instructions to install MSYS2. It's recommended to install it in the default location (e.g., `C:\msys64`).
3.  **Open MSYS2 MinGW 64-bit Terminal**: After installation, search for "MSYS2 MinGW 64-bit" in your Start Menu and open it.
4.  **Update Package Database**: In the MSYS2 terminal, type the following command and press Enter. This updates the list of available packages.
    ```bash
    pacman -Syu
    ```
    *   If prompted, close the terminal (often by pressing `Y` and then Enter), then reopen it and run `pacman -Syu` again to complete all updates.
5.  **Install g++ and make**: Once the updates are complete, install the MinGW-w64 toolchain (which includes the `g++` C++ compiler and `make` utility) by running:
    ```bash
    pacman -S mingw-w64-x86_64-toolchain
    ```
    *   Press Enter to select the default (all packages in the group) and then `Y` to proceed with the installation.
6.  **Add MinGW to PATH Environment Variable**:
    *   To use `g++` and `make` from the regular Command Prompt or PowerShell, you need to add the MinGW-w64 `bin` directory to your system's PATH.
    *   This directory is typically `C:\msys64\mingw64\bin` (if you installed MSYS2 to the default location).
    *   Search for "Edit the system environment variables" in the Start Menu, open it, click the "Environment Variables..." button. In the "System variables" section, find the `Path` variable, select it, and click "Edit...". Click "New" and add the path to your MinGW-w64 `bin` directory.
    *   Close and reopen any open terminals for this change to take effect.

### Step 2: Download and Set Up Raylib

The current project `Makefile` is configured to look for Raylib library files in the project's root directory.

1.  **Go to Raylib GitHub Releases**: Navigate to the Raylib releases page: [https://github.com/raysan5/raylib/releases](https://github.com/raysan5/raylib/releases)
2.  **Download Raylib for MinGW**: Find the latest release and download the `raylib-X.Y.Z_mingw_w64.zip` file (or similar, where X.Y.Z is the version number, e.g., `raylib-5.0_mingw_w64.zip`).
3.  **Extract Raylib Files**: Extract the downloaded ZIP file.
4.  **Copy Necessary Files to Your Project**:
    *   Navigate into the extracted folder. You will find a `lib` and an `include` directory (or similar, structure might vary slightly between versions, look for `raylib.h` and `libraylib.a`).
    *   **Copy `raylib.h`**: From the `include` folder (or its subfolder like `src` in older versions), copy the `raylib.h` file into the root directory of **your** Dashboard application project (e.g., `test 99 car/`).
    *   **Copy `libraylib.a`**: From the `lib` folder, copy the `libraylib.a` file into the root directory of **your** Dashboard application project (e.g., `test 99 car/`). Your `Makefile` is looking for this with `-L. -lraylib` (the `-L.` tells the linker to look in the current directory, and `-lraylib` links `libraylib.a`).

    *(Alternatively, instead of copying to the root, you could create `include` and `lib` subdirectories in your project and adjust the `CXXFLAGS` and `LDFLAGS` in your `Makefile` accordingly, but the current `Makefile` expects them in the root or standard system paths.)*

### Step 3: Get the Application Code

1.  Ensure you have the application's source code, including `dashboard.cpp` and the `Makefile`, in your project directory (e.g., `test 99 car/`).

### Step 4: Build the Application

1.  **Open a Terminal**: Open a new Command Prompt, PowerShell, or MSYS2 MinGW 64-bit terminal.
2.  **Navigate to Project Directory**: Use the `cd` command to navigate to the root directory of your Dashboard application (e.g., `cd "C:/Users/Aiden/OneDrive - ROC Gilde Opleidingen/Documenten/test 99 car"`).
3.  **Run Make**: Type the following command and press Enter:
    ```bash
    make
    ```
    *   If you are using the MSYS2 MinGW terminal, the command is `make`. If you are using Command Prompt or PowerShell and have added MinGW to your PATH correctly, you might need to type `mingw32-make` if `make` isn't found or conflicts with another program.
    *   This command will use `g++` to compile `dashboard.cpp` and link it with Raylib, creating an executable file named `dashboard.exe`.

### Step 5: Run the Application

1.  After the build is successful, you can run the application from the same terminal by typing:
    ```bash
    ./dashboard.exe
    ```
    Or simply:
    ```bash
    dashboard.exe
    ```

## Cleaning Up

To remove the compiled executable (`dashboard.exe`), open a terminal in the project directory and run:
```bash
make clean
```

## Troubleshooting

*   **`make` or `g++` not found**: Ensure you have correctly added the MinGW `bin` directory to your system PATH (Step 1.6) and reopened your terminal. If using MSYS2 terminal, these commands should be available by default after installation.
*   **Raylib linking errors (e.g., `cannot find -lraylib` or `undefined reference to ...`)**: 
    *   Double-check that `libraylib.a` is in the same directory as your `Makefile` (or that `-L.` is appropriate for its location).
    *   Ensure `raylib.h` is also in a place the compiler can find it (the current `Makefile` doesn't add a special include path, so it expects `raylib.h` to be in the same directory or a standard include path).
    *   Make sure you downloaded the MinGW version of Raylib.
*   **Other compilation errors**: Check your `dashboard.cpp` for C++ syntax errors. 