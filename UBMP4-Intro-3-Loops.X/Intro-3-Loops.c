/*==============================================================================
 Project: Intro-4-Functions
 Date:    May 16, 2021
 
 This program demonstrates the use of functions, and variable passing between
 the main and function code.
 
 Additional program analysis and programming activities examine function code
 location, function prototypes, and reinforce the concepts of global and local
 variables.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions
#include <stdio.h>
#include <string.h>
#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Button constant definitions
const char noButton = 0;
const char UP = 1;
const char DOWN = 2;
const char MEIKAI = 3;
const char POGGERS = 4;

const unsigned int D4NOTE = 3405;
const unsigned int D5NOTE = 1703;
const unsigned int A4NOTE = 2273;
const unsigned int AF4NOTE = 2408;


// Program variable definitions
unsigned char LED5Brightness = 125;
unsigned char button;

unsigned char button_pressed(void);
void pwm_LED5(unsigned char pwmValue);
unsigned char getButtonPressed(void);
void lightLed(unsigned char);
void clearLeds(void);
void delay_us(unsigned int us);
void playNote(unsigned int period);
unsigned int getTone(void);
int memory[50];
int musicMemory[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};
void playBack(void);
void beepSelect(int);
void morseCode(void);

int pressedCounter = 250;
int arrayCell = 0;
int mode = 0;
int randonumbo = 500;

struct Note {
    unsigned long period;
    unsigned long time;
};

typedef struct Note Note;

const int NOTES_LENGTH = 25;

extern unsigned char timerHit = 0;

extern unsigned int count = 0;

#define bpm 60
#define quarter_note 0.25
#define eigth_note 0.125
#define sixteenth_note .125
#define half_note 0.5

#define note(x, y) {.period = x, .time = (((bpm/60) * y * 4) * 1000000) }

Note notes[] = {
    note(NOTE_C5, eigth_note), note(NOTE_DS5, eigth_note),
    note(NOTE_F5, eigth_note), note(NOTE_FS5, eigth_note),
    note(NOTE_F5, eigth_note), note(NOTE_DS5, eigth_note),
    note(NOTE_C5, eigth_note*1.5), note(NOTE_AS4, sixteenth_note/2),
    note(NOTE_D5, sixteenth_note/2),  note(NOTE_C5, eigth_note),
    note(REST, half_note), note(NOTE_C5, eigth_note),
    note(NOTE_DS5, eigth_note), note(NOTE_F5, eigth_note),
    note(NOTE_GS5, eigth_note), note(NOTE_F5, eigth_note),
    note(NOTE_DS5, eigth_note), note(NOTE_FS5, half_note),
    note(REST, sixteenth_note), note(NOTE_FS5, eigth_note),
    note(NOTE_E5, eigth_note), note(NOTE_CS5, eigth_note),
    note(NOTE_FS5, eigth_note), note(NOTE_E5, eigth_note),
    note(NOTE_CS5, eigth_note)
};

int main(void) {
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    for (int i = 0; i <= 50; i++) {
        
        memory[i] = 3;
        
    }
    
    while(1)
	{
        pressedCounter = 250;
        LATC = 0b10000000;
            
        
            if (SW2 == 0 && mode <= 4) {
                
                mode++;
                beepSelect(0);
                while (SW2 == 0);
                __delay_ms(50);
            } else if (mode == 4) {
                mode = 0;
            }
            
            if (mode == 0) {
                
                LATC = 0b10000000;
                
                
            } else if (mode == 1) {
                
                LATC = 0b10010000;
                
                
            } else if (mode == 2) {
                
                LATC = 0b11010000;
                if (SW5 == 0) {
                    beepSelect(3);
                    
                }
                
            } else if (mode == 3) {
                
                LATC = 0b11110000;
                if (SW5 == 0) {
                    beepSelect(3);
                    morseCode();
                }
                
            }
            
       /* if (SW5 == 0) {
            
            for (long i = 0; i < 50000; i+=250){
                BEEPER = !BEEPER;
                __delay_us(500);
            }
            
            for (long i = 0; i < 50000; i+=200){
                BEEPER = !BEEPER;
                __delay_us(400);
            }
            while(SW5 == 0);
            __delay_ms(50);
            
           // while(SW5 == 0);
           // __delay_ms(50);
        }*/
        
        
        
        
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

// Move the function code to here in Program Analysis, step 5.
/*==============================================================================
 Function: Song Writer
 
 This function will allow the user to create a musical tone up to 50 notes,
 pauses, and breaks. One button will allow user to change the note while another
 button will change the pitch of the note. Jacob Timer Pog. 
==============================================================================*/
void songWriter() {
    __delay_ms(50);
    while(true) {
        
        if (SW4 == 0) {
            
            note[i].period += something;
            
        }
    
        if (SW5 == 0) {
            for (int i = 0; i < NOTES_LENGTH; i++) {
                if (notes[i].period == 0) {
                    delay_us(notes[i].time);
                    continue;
                }
                for (unsigned long repeats = notes[i].time / notes[i].period; repeats != 0; repeats--) {
                    BEEPER = !BEEPER;
                    delay_us(notes[i].period);
                }
                delay_us(notes[i].time / 10);
                if (SW1 == 0) {
                    RESET();
                }
            }

        }
    }
}

void beepSelect(int picker456) {
    
    if (picker456 == 0) {
        for (long i = 0; i < 50000; i+=250){
            BEEPER = !BEEPER;
            __delay_us(500);
            }

        for (long i = 0; i < 50000; i+=200){
            BEEPER = !BEEPER;
            __delay_us(400);
        }
    }
    
    if (picker456 == 1) {
        
        for (long i = 0; i < 50000; i+=200){
            BEEPER = !BEEPER;
            __delay_us(400);
        }
        
        for (long i = 0; i < 50000; i+=250){
            BEEPER = !BEEPER;
            __delay_us(500);
            }
        
    }
    
    if (picker456 == 3) {
        
        for (long i = 0; i < 50000; i+=300){
            BEEPER = !BEEPER;
            __delay_us(600);
            }
        
       /* for (long i = 0; i < 50000; i+=250){
            BEEPER = !BEEPER;
            __delay_us(500);
            }*/
        
        for (long i = 0; i < 50000; i+=150){
            BEEPER = !BEEPER;
            __delay_us(300);
        }
    }
    
}

/*void musicWriter() {
    
    
    
}*/

void delay_us(unsigned int us) {
    unsigned int requiredCount = us/4 - 2;
    
    timerHit = 0;
    
    count = 0;
    
    //OPTION_REG = 0b01010111;    // Enable port pull-ups, TMR0 internal, div-256

    OPTION_REG = 0b01010000; // Modified Prescaler
    TMR0IE = 1;
    GIE = 1;
    TMR0IF=0;       // Clear timer interrupt flag
    PEIE = 1;
    
    TMR0 = 240;
    
    while(count < requiredCount) {
        NOP();
    }
        
    TMR0IE = 0;
    GIE = 0;
    
    timerHit = 0xff;
    H1OUT = 0;
}

void __interrupt() timer_isr() {
    if(TMR0IF==1 && !timerHit) { // Timer flag has been triggered due to timer overflow
        NOP();
        NOP();
        TMR0IF=0;       // Clear timer interrupt flag
        count++;
        TMR0 = 246;     //Load the timer Value
    }
}

void morseCode() {
    __delay_ms(50);
    while(true) {
        pressedCounter = 250;
        
        if (arrayCell <= 50) {

            if (SW2 == 0) {

                memory[arrayCell] = 2;
                arrayCell++;
                while(SW2 == 0);
                __delay_ms(50);
            }

            if (SW3 == 0) {

                memory[arrayCell] = 0;
                arrayCell++;
                while(SW3 == 0);
                __delay_ms(50);
            }

            if (SW4 == 0) {
                while (SW4 == 0) {

                    if (SW3 == 0) {

                        pressedCounter--;
                        __delay_ms(1);

                        if (pressedCounter == 0) {
                            beepSelect(1);
                            return;
                        }
                    } else if (SW4 == 1){
                        memory[arrayCell] = 1;
                        arrayCell++;
                        while(SW4 == 0);
                        __delay_ms(50);
                        break;
                    }
                }
            }
        }

        if (SW5 == 0) {
            while (SW5 == 0) {
                
                if (SW2 == 0) {
                    
                    pressedCounter--;
                    __delay_ms(1);

                    if (pressedCounter == 0) {
                        
                        for (int i = 0; i <= 50; i++) {

                            memory[i] = 3;

                        }
                        arrayCell = 0;
                        while(SW5 == 0);
                        __delay_ms(50);
                        break;
                    }
                } else if (SW5 == 1) {
                    
                    playBack();
                    while(SW5 == 0);
                    __delay_ms(50);
                    break;
                }
            }
        }
    }
}


    
        
void playBack() {
    for (int i = 0; i <= 40; i++) {
        
        if (memory[i] == 0) {
            
            for (long ii = 0; ii < 100000; ii+=3405){
                BEEPER = 1;
                __delay_us(3405);
                BEEPER = 0;
                __delay_us(3405);
            }
            
            __delay_ms(200);
        }
        
        if (memory[i] == 1) {
            
            for (long iii = 0; iii < 200000; iii+=3405){
                BEEPER = 1;
                __delay_us(3405);
                BEEPER = 0;
                __delay_us(3405);
            }
            
            __delay_ms(200);
        }
        
        if (memory[i] == 2) {
            
            __delay_ms(500);
            
        }
        
        if (memory[i] == 3) {
            
            break;
            
        }
    }
}
