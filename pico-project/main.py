from machine import Pin
import time

# Define pin numbers
red_pin = 'GP3'
yellow_pin = 'GP2'
green_pin = 'GP1'
button_pin = 'GP0'

# Set up pin inputs and outputs
red = Pin(red_pin, Pin.OUT)
yellow = Pin(yellow_pin, Pin.OUT)
green = Pin(green_pin, Pin.OUT)
button = Pin(button_pin, Pin.IN, Pin.PULL_DOWN)

# flash all lights three times on startup
def startup():
    for i in range(3):
        red.value(1)
        yellow.value(1)
        green.value(1)
        time.sleep(0.5)
        red.value(0)
        yellow.value(0)
        green.value(0)
        time.sleep(0.5)

def waitforinput():
    # Set up variables to track button presses
    button_counter = 0
    last_button_state = False

    # Loop while the board is plugged in
    while True:
        # Get the current state of the button
        button_state = button.value()

        # If the button is pressed and was not pressed last time
        if button_state and not last_button_state:
            # Increment the button counter
            button_counter += 1

            # If the counter is 1, turn on the red light
            if button_counter == 1:
                red.value(1)
                yellow.value(0)
                green.value(0)
            # If the counter is 2, turn on the yellow light
            elif button_counter == 2:
                red.value(0)
                yellow.value(1)
                green.value(0)
            # If the counter is 3, turn on the green light
            elif button_counter == 3:
                red.value(0)
                yellow.value(0)
                green.value(1)
            # If the counter is 4, reset the counter
            elif button_counter == 4:
                button_counter = 0
                red.value(0)
                yellow.value(0)
                green.value(0)

        # Update the last button state
        last_button_state = button_state

        # Wait for 0.1 seconds
        time.sleep(0.1)

# run main method
if __name__ == '__main__':
    startup()
    waitforinput()