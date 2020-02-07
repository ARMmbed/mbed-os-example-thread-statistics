![](./resources/official_armmbed_example_badge.png)
# Thread statistics Mbed OS example

This guide reviews the steps required to get thread statistics on an Mbed OS enabled platform.

You can build this project with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command-line interface tool [Arm Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

1. [Install Mbed CLI](https://os.mbed.com/docs/mbed-os/latest/quick-start/offline-with-mbed-cli.html).

1. Clone this repository on your system, and change the current directory to where the project was cloned:

    ```bash
    $ git clone git@github.com:armmbed/mbed-os-example-thread-statistics && cd mbed-os-example-thread-statistics
    ```

    Alternatively, you can download the example project with Arm Mbed CLI using the `import` subcommand:

    ```bash
    $ mbed import mbed-os-example-thread-statistics && cd mbed-os-example-thread-statistics

## Application functionality

The `main()` function starts two threads: `blinky_thread` and `idle_thread`. It also outputs information such as `id`, `name`, `state`, `priority`, `stack_space` and `stack_size` on the serial interface thread .

## Building and running

1. Connect a USB cable between the USB port on the target and the host computer.
1. Run this command to build the example project and program the microcontroller flash memory:

    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash --sterm
    ```

(Note: You can use the Mbed CLI command-line option "--sterm" to open a serial terminal after flashing.)

Your PC may take a few minutes to compile your code.

The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-thread-statistics.bin`.

Alternatively, you can manually copy the binary to the target, which gets mounted on the host computer through USB.

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
