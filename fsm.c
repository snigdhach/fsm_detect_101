#include "stdio.h"
#include "stdlib.h"
#include "string.h"

enum states { STATE_0,STATE_1, STATE_2, STATE_3, MAX_STATES } current_state;
enum events { EVENT_1, EVENT_2, MAX_EVENTS } new_event;

/* Provide the fuction prototypes for each action procedure. In a real
program, you might have a separate source file for the action procedures of 
each state. Then you could create a .h file for each of the source files, 
and put the function prototypes for the source file in the .h file. Instead 
of listing the prototypes here, you would just #include the .h files. */

void action_s1_e0 (void);
void action_s1_e1 (void);
void action_s2_e0 (void);
void action_s2_e1 (void);
void action_s3_e0 (void);
void action_s3_e1 (void);
void action_s4_e0 (void);
void action_s4_e1 (void);
enum events get_new_event (void);

int i=0;
enum states current_state = 0;
/* Define the state/event lookup table. The state/event order must be the
same as the enum definitions. Also, the arrays must be completely filled - 
don't leave out any events/states. If a particular event should be ignored in 
a particular state, just call a "do-nothing" function. */

void (*const state_table [MAX_STATES][MAX_EVENTS]) (void) = {

    { action_s1_e0, action_s1_e1 }, /* procedures for state 1 */
    { action_s2_e0, action_s2_e1 }, /* procedures for state 2 */
    { action_s3_e0, action_s3_e1 }, /* procedures for state 3 */
    { action_s4_e0, action_s4_e1 }  /* procedures for state 4 */
};

/* This is the heart of the state machine - where you execute the proper 
action procedure based on the new event you have to process and your current 
state. It's important to make sure the new event and current state are 
valid, because unlike "switch" statements, the lookup table method has no 
"default" case to catch out-of-range values. With a lookup table, 
out-of-range values cause the program to crash! */

int main (void)
{
    while(i<20){
        new_event = get_new_event (); /* get the next event to process */

        if (((new_event >= 0) && (new_event < MAX_EVENTS))
        && ((current_state >= 0) && (current_state < MAX_STATES))) {

            state_table [current_state][new_event] (); /* call the action procedure */

        } else {

            printf("Wrong inputs");
            break;
        }
    }
}

/* In an action procedure, you do whatever processing is required for the
particular event in the particular state. Among other things, you might have
to set a new state. */

void action_s1_e0 (void)
{
 current_state = 0;   
}

void action_s1_e1 (void) {
    current_state = 1; 
}  /* other action procedures */
void action_s2_e0 (void) {
    current_state = 2; 
}
void action_s2_e1 (void) {
    current_state = 1; 
}
void action_s3_e0 (void) {
    current_state = 0; 
}
void action_s3_e1 (void) {
    current_state = 3; 
    printf("DETECTED");

}
void action_s4_e0 (void) {
    current_state = 2; 
}
void action_s4_e1 (void) {
    current_state = 1; 
}

/* Return the next event to process - how this works depends on your
application. */

enum events get_new_event (void)
{
    i++;
    int k[20]={0,1,1,1,0,1,0,1,1,1,1,1,1,0,0,1,0,1,0,1};

    //int k=(rand()%2);
    //printf("%d ",k);
    //scanf("%d",&k);
    printf("%d ",k[i-1]);
    return k[i-1];

}