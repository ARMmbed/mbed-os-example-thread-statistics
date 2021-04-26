![](./resources/official_armmbed_example_badge.png)
# Thread statistics Mbed OS example

The example project is part of the [Arm Mbed OS Official Examples](https://os.mbed.com/code/). It contains an application that demonstrates how to generate thread statistics in Mbed OS.

You can build the project with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command-line interface tools, [Arm Mbed CLI 1](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli) and [Mbed CLI 2](https://github.com/ARMmbed/mbed-tools#installation).

## Mbed OS build tools

### Mbed CLI 2

Starting with version 6.5, Mbed OS uses Mbed CLI 2. It uses Ninja as a build system, and CMake to generate the build environment and manage the build process in a compiler-independent manner. If you are working with Mbed OS version prior to 6.5 then check the section [Mbed CLI 1](#mbed-cli-1).
1. [Install Mbed CLI 2](https://os.mbed.com/docs/mbed-os/latest/build-tools/install-or-upgrade.html).
1. From the command-line, import the example: `mbed-tools import mbed-os-example-thread-statistics`
1. Change the current directory to where the project was imported.

### Mbed CLI 1
1. [Install Mbed CLI 1](https://os.mbed.com/docs/mbed-os/latest/quick-start/offline-with-mbed-cli.html).
1. From the command-line, import the example: `mbed import mbed-os-example-thread-statistics`
1. Change the current directory to where the project was imported.

## Application functionality

The `main()` function starts two threads: `blinky_thread` and `idle_thread`. It also outputs information such as `id`, `name`, `state`, `priority`, `stack_space` and `stack_size` on the serial interface thread .

## Building and running

1. Connect a USB cable between the USB port on the board and the host computer.
1. Run the following command to build the example project and program the microcontroller flash memory:

    * Mbed CLI 2

    ```bash
    $ mbed-tools compile -m <TARGET> -t <TOOLCHAIN> --flash --sterm
    ```

    * Mbed CLI 1

    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash --sterm
    ```

Your PC may take a few minutes to compile your code.

The binary is located at:
* **Mbed CLI 2** - `./cmake_build/<TARGET>/<PROFILE>/<TOOLCHAIN>/mbed-os-example-thread-statistics.bin`</br>
* **Mbed CLI 1** - `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-thread-statistics.bin`

Alternatively, you can manually copy the binary to the board, which you mount on the host computer over USB.

Depending on the target, you can build the example project with the `GCC_ARM`, `ARM` or `IAR` toolchain. After installing Arm Mbed CLI, run the command below to determine which toolchain supports your target:

```bash
$ mbed compile -S
```

You can also open a serial terminal separately, rather than using the `--sterm` option, with the following command:

* Mbed CLI 2

```bash
$ mbed-tools sterm
```

* Mbed CLI 1

```bash
$ mbed sterm
```

## Expected output

The serial terminal shows an output similar to:

```
--- Terminal on /dev/ttyACM0 - 9600,8,N,1 ---
ID: 0x20000e20 
Name: main 
State: 2 
Priority: 24 
Stack Size: 4096 
Stack Space: 3896 

ID: 0x20000f70 
Name: rtx_idle 
State: 1 
Priority: 1 
Stack Size: 512 
Stack Space: 256 

ID: 0x1fff0580 
Name: blinky_thread 
State: 3 
Priority: 24 
Stack Size: 224 
Stack Space: 128 

ID: 0x20000f2c 
Name: rtx_timer 
State: 3 
Priority: 40 
Stack Size: 768 
Stack Space: 664 

ID: 0x1fff0730 
Name: idle_thread 
State: 3 
Priority: 24 
Stack Size: 384 
Stack Space: 280 
```

The information below shows how to interpret the above fields:

```
ID:            Thread id
Name:          Thread name
State:         Thread states:
               0: Inactive,
               1: Ready,
               2: Running,
               3: Blocked,
               4: Terminated,
              -1: Error             
Priority:      Thread priority (higher number indicates higher priority)
Stack Size:    Current number of bytes reserved for the stack
Stack Space:   Current number of free bytes remaining on the stack
```

## Configuring the application

You can enable thread statistics by setting `platform.thread-stats-enabled` to true in the application configuration file:

```
{
    "target_overrides": {
        "*": {            
            "platform.thread-stats-enabled": true            
        }
    }
}
```

## Troubleshooting 

If you have problems, you can review the [documentation](https://os.mbed.com/docs/latest/tutorials/debugging.html) for suggestions on what could be wrong and how to fix it. 

## Related links

- [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html).
- [Mbed OS configuration](https://os.mbed.com/docs/latest/reference/configuration.html).
- [Mbed OS serial communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html).
- [Mbed boards](https://os.mbed.com/platforms/).

### License and contributions

The software is provided under the Apache-2.0 license. Contributions to this project are accepted under the same license. Please see contributing.md for more information.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.
