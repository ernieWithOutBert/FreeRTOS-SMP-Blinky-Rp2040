# FreeRTOS SMP Blinky example for RP2040

Uses the queue to send a bool from one core to the other.LED Pin is written from core0. It is set up to be used with VS Code.

# How to Build

Do not initialize your SDK path the build script will fetch the sdk and the FreeRTOS-kernel so that the versions match with the ones I used for this example.

## Preconditions:



```shell
usr@Host~/BlinkySMP$ mkdir build
usr@Host~/BlinkySMP$ cd build
usr@Host~/BlinkySMP$ cmake cmake -DCMAKE_BUILD_TYPE=Debug ..
```

# 