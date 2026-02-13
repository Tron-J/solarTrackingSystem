# Arduino Solar Tracker

**Overview**

This is a simple Arduino-based solar tracking project using two light-dependent resistors (LDRs) and a hobby servo. The Arduino reads two analog LDR sensors on `A0` and `A1` and moves a servo on digital pin `9` to keep a solar panel (or sensor array) pointed toward the brighter side.

**How it works**

- The sketch (`[solar.ino](solar.ino)`) continuously reads two analog inputs and compares their values.
- If the left LDR is significantly brighter, the servo position (`pos`) is decremented to rotate toward the left; if the right is brighter, `pos` is incremented to rotate right.
- The servo position is constrained between `0` and `180` degrees and initialized to `90`.
- Serial output prints both LDR readings and the servo position for debugging at `9600` baud.

**Hardware**

- Arduino Uno (or compatible)
- 2 × LDRs (light-dependent resistors)
- 2 × 10kΩ resistors (for LDR voltage dividers — values may vary)
- 1 × Hobby servo (e.g., SG90)
- Jumper wires and a small protoboard

**Wiring**

- Left LDR voltage divider: one end to `5V`, the other to `GND`; the junction to `A0` (use a resistor to form a divider).
- Right LDR voltage divider: junction to `A1`.
- Servo signal wire to digital pin `9`.
- Servo power: `5V` and `GND` (prefer a separate 5V supply if the servo draws significant current; connect grounds together).

A typical LDR voltage divider: LDR between `5V` and analog pin, and a fixed resistor (e.g., 10kΩ) between analog pin and `GND`.

**Usage**

- Upload `solar.ino` to the Arduino.
- Open the Serial Monitor at `9600` baud to see readings and `pos` value.
- Place the LDRs spaced similarly to the panel so they catch light differences.
- Adjust distance/angle and, if needed, change thresholds in the code (currently uses values ~800 and ~600).

**Calibration & Tuning**

- Thresholds (`800` and `600`) in the sketch are rough and depend on your LDRs and lighting. Lower or raise them to reduce sensitivity.
- Add hysteresis or a deadband to avoid servo jitter when light is nearly equal.
- Increase the delay or implement smoothing (moving average) on sensor readings for more stable motion.

**Notes & Improvements**

- Use a separate power source for the servo if it causes brownouts on the Arduino.
- Add limits or soft stops if the mechanical setup can hit hard stops.
- Replace simple thresholding with a proportional control (map the difference to servo increments) for smoother tracking.
- Add sunrise/sunset behavior or a manual calibration routine to set initial `pos`.

**Files**

- Project sketch: [solar.ino](solar.ino)
- This README: `README.md`

If you want, I can update the code to add hysteresis, smoothing, or a calibration routine next.