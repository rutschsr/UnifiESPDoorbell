# UnifiESPDorbell
This project integrates Unifi Doorbells with a mechanical chime.
This allows for two doorbells to both ring a chime using a relay breakout board and a ESP8266 MCU
Several other Integrations are needed to make this work correctly:

First the ESP needs set up with the Arduino editor
    I used these instructions: https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/
    These Instructions may also prove useful: https://circuits4you.com/2016/12/16/getting-strted-iot-esp8266/

This allows the Doorbell access program to be accessible from the ip address assigned to the device, I recommend
setting this static as soon as the device is connected.

Home Assistant Setup:
    Several Tools, Integrations and add-ons may prove useful for this project. This uses supervised processes and I am
    unsure how well they would work on a docker install of Home Assistant. I am using HASSOS.

    Install Terminal and Visual Studio Code add-ons from the Supervisor Window

    Use terminal to install the Home Assitant Community Store Integration following these instructions:
        https://hacs.xyz/docs/installation/prerequisites/
    Use HACS integration to install the pyscript integation:
        https://hacs-pyscript.readthedocs.io/en/latest/installation.html
    Use HACS integration to install the Unifi Protect Integration:
        https://github.com/briis/unifiprotect


With those integrations and add ons installed and configured according to their instructions the "Doorbell.py" file can be placed in the "pyscript" folder
(I recommend creating a new file in VSCode and copying the code)

Restart Home assistant (or reload pyscript scrips)
The services that define the doorbells should now be accessible from Home Assistant Automations
Create Automations that call the respective doorbell function when the doorbell rings.

Hardware instructions will be added in pdf.
    
