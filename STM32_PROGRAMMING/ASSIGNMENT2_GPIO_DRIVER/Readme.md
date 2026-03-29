Video Link => https://drive.google.com/file/d/1R6BVK5NVGkG9p4d46eZxpdQ2xzpOpozX/view?usp=sharing

# STM32 GPIO Driver – Button Toggle & Non-Blocking LED Blink

##  Overview
This project demonstrates the implementation of a custom GPIO driver for the STM32F446 microcontroller. It integrates both onboard and external hardware using driver-level APIs without direct register manipulation in the application layer.

The assignment includes:
- Button-controlled LED toggle
- Alternating external LED blinking using non-blocking delay

---

## Objectives

### Task 1: Button-Controlled LED
- Onboard LED (PA5) is configured as output
- Onboard button (PC13) is configured as input (active LOW)
- When button is pressed:
  - LED toggles state (ON ↔ OFF)
- A small delay (~40 ms) is used for debouncing

---

### Task 2: Alternating External LED Blink
- Two external LEDs connected to:
  - PA6
  - PA7
- LEDs blink alternately:
  - One ON while the other OFF
  - ~250 ms per state (approximate)
- Implemented using **non-blocking delay**

---

##  Hardware Used

- STM32F446RE Nucleo Board
- Onboard LED → PA5
- Onboard Button → PC13
- External LEDs → PA6, PA7

---

##  Circuit Connections

- PA6 → Resistor → LED → GND  
- PA7 → Resistor → LED → GND  

---

## Key Concepts Used

### 1. GPIO Driver Abstraction
- All GPIO operations handled via custom driver APIs
- No direct register access in `main.c`
- Improves modularity and code readability

---

### 2. Button Debouncing
- Simple software delay used (~40 ms)
- Prevents false triggering due to mechanical noise

---

### 3. Non-Blocking Delay
- Instead of using `delay_ms(250)`, a software counter is used:

```c
counter++;

if(counter >= 200000)
{
    gpio_toggle_pin(...);
    counter = 0;
}
