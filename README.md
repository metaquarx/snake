# Snake

Simple snake game, written in C++

# Usage

You can either download a prebuilt binary from the releases tab, or [build it yourself](#building).

# Building

Use CMake to automatically configure and build. Make sure you have the correct [dependencies](#dependencies) installed.
```
cmake -S . -B build
cmake --build build
```

You will then find the executable in
```
./build/Snake
```

# Dependencies

This program depends on [SFML](https://www.sfml-dev.org/), which is assumed to already be installed.

## Linux

You can get SFML via your package manager.

Arch:
```
pacman -Syu sfml
```

Debian:
```
apt-get install libsfml-dev
```
