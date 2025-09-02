 Servo Control with OLED Display (Arduino + PCA9685)

This project demonstrates how to control a servo motor using the PCA9685 servo driver and display system status on an OLED 128x64 screen with the U8g2 library.
 Features
- Control a servo motor through the PCA9685 driver.
- Display servo status messages ("Servo Moving", "Servo Stopped") on the OLED screen.
- Modular code structure with placeholders for future sensors (touch button, vibration sensor, buzzer).
 Hardware Components
- Arduino Uno (or compatible board)  
- PCA9685 Servo Driver (16-channel PWM)  
- Servo Motor  
- OLED Display 128x64 (I2C or SPI)  
- Optional: Touch Button, Vibration Sensor, Buzzer  

 Libraries Used
- `Wire.h`  
- `Adafruit_PWMServoDriver.h`  
- `U8g2lib.h`  
 How It Works
1. The OLED screen initializes and shows setup messages.  
2. The PCA9685 driver generates PWM signals to move the servo motor to a defined angle (90° in this demo).  
3. The OLED displays "Servo Moving…" when active and "Servo Stopped" when the motor is stopped.  
4. Additional sensors (button, vibration, buzzer) can be integrated later for more interactive control.  
 Future Improvements
- Add vibration sensor input to trigger servo movement.  
- Use touch button for manual control.  
- Include buzzer alerts for feedback.  

