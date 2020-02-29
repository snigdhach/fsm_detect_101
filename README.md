# fsm_detect_101
Simple Fsm code to detect 101

* The current code detects an input of "101". It can be extended to a complicated state system.
* A lookup table is utilized to describe the state of each input and corresponding outputs.
* The new_event function can be modified according to the type of the inputs, i.e. array, dynamic(scanf), etc.
* Example of the output : 0 1 1 1 0 1 DETECTED 0 1 DETECTED 1 1 1 1 1 0 0 1 0 1 DETECTED 0 1 DETECTED
