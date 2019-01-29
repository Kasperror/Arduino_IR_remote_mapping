1. NEEDED COMPONENTS FOR PROGRAM TO RUN CORRECTLY
2. HOW TO USE THE PROGRAM

*************************************************

1.
NEEDED COMPONENTS ARE:
- any Arduino/Genuino board
- standard led
- 220 ohm resiston
- infra-red reciever
- infra-red transmitter
- Arduino IDE
- 5 breadboard wires

2.
IMPORTANT:
A)Program can give unsatisfying results if IR transmitter is poor 
quality - they tend to randomly send various signals from one button 

B)Program doesn't support toggle code buttons - it will read and use only one
code - feel free to update remote_map.h to adjust it to toggle buttons

INSTRUCTIONS:

1. Open Arduino IDE and connect Arduino board 
2. Copy/paste code from "Arduino_code.txt" into code window
3. Upload it into your Arduino
4. Connect the circuit as shown on "IR_reciever_scheme.jpg"
5. Look at Serial output and led to check if code works propely
if not check your wiring
6. Clear Serial output window [close and open it]
	!!! If you downloaded whole Remote_mapping folder skip to step 9 !!!
7. Now compile mapping program and put EXE file into new folder[this might need -std=c++11 flag]
8. In the same folder create "codes.txt" text file
9. Start the EXE program
10. Continue with command line instructions
11. It is important that every button press results in only
one new code line in Serial output
11. !!! You will be asked to copy Arduino Serial output into "codes.txt" file
12. After executing program use the created "remote_map.h" as follows:
	a) add and include it in your Arduino codes
	b) before setup function always put line "constexpr Remote myRemote;"
	c) now to call button's code you use myRemote.b_myButtonName()
	where myButtonName is the name u gave to button during program runtime
13. Enjoy faster and easier method of IR remote mapping :) 
