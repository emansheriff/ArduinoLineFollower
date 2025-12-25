# Arduino Line Follower Robot (L298N)

This project implements a 3-IR-sensor line follower robot using:
- Arduino UNO
- L298N Motor Driver
- 2 DC Gear Motors
- 3 IR Obstacle/Line Sensors
- 18650 Battery Pack

## Hardware Connections

### IR Sensors
| Sensor | Arduino Pin |
|------|------------|
| Left | D2 |
| Center | D3 |
| Right | D4 |

### L298N Motor Driver
| L298N Pin | Arduino Pin |
|---------|-------------|
| IN1 | D8 |
| IN2 | D9 |
| IN3 | D10 |
| IN4 | D11 |
| ENA | D5 (PWM) |
| ENB | D6 (PWM) |

## How It Works
- Robot moves forward when center sensor detects line
- Turns left/right when deviation is detected
- Stops if no line is detected

## Power
- Motors powered by 18650 battery via L298N
- Arduino powered via VIN or buck converter

## Uploading Code
1. Open `src/line_follower.ino`
2. Select **Arduino UNO**
3. Upload via USB

## License
MIT License
