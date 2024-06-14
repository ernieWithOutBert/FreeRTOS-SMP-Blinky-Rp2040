# FreeRTOS SMP Blinky example for RP2040

Uses the queue to send a bool from one core to the other. LED Pin is written from core0. It is set up to be used with VS Code.

## How to Build

Do not initialize your SDK path the build script will fetch the sdk and the FreeRTOS-kernel so that the versions match with the ones I used for this example.
The first CMAKE run will therefor take a moment depending on your internet connection.

### Preconditions

cmake, build-essential, gcc-arm-none-eabi, gdb-multiarch

On debian based system you can use:

```shell
sudo apt install cmake build-essential cmake gcc-arm-none-eabi gdb-multiarch
```

to install the Preconditions.

### Buliding the Project

```shell
usr@Host~/BlinkySMP$ mkdir build
usr@Host~/BlinkySMP$ cd build
usr@Host~/BlinkySMP$ cmake cmake -DCMAKE_BUILD_TYPE=Debug ..
```

**_NOTE:_**  If you are using VS Code you can create the folder and use the Runners from the tasks.json file.
