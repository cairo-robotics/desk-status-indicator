# desk-status-indicator
Arduino project to indicate whether you are free to chat. Developed by Emily.

# Using the indicator
- Connect your device to your computer with the USB cable
- It should automatically turn on
- Press the button repeatedly to cycle through the LED lights (Green = ok to talk, Yellow = can talk if needed, Red = don't talk to me)
- Turn off the device by unplugging from your computer

# Making changes
You can add more functionality by changing the software loaded onto the device. Instructions adapted from [here](https://www.hackster.io/shilleh/how-to-use-vscode-with-raspberry-pi-pico-w-and-micropython-de88d6)

- Plug board into computer using micro USB cable and holding down the `bootsel` button.
- Download the latest firmware from [MicroPython](https://micropython.org/download/rp2-pico/). Save the `.uf2` file to the Pico device that shows up on your computer.
- Unplug board from computer.
- Replug board into computer *without* holding down the `bootsel` button.
- Install `Pico-W-Go` extension in VSCode
- In the `pico-project` directory, run `Pico-W-Go > Configure Project` using the VSCode command palette (bring this up using `Ctrl+Shift+P`)
- Create a new python script in the directory and add your code. 
- To upload your code to the board, right click the file and select `Run current file`.

# Wiring diagrams
These diagrams are using the Arduino Uno, which is not the final controller to be used in this project.

![Full board wiring](img/full_wiring.jpg)

![Detail of controller wiring](img/arduino_wiring.jpg)

![Detail of breadboard wiring](img/board_wiring.jpg)
