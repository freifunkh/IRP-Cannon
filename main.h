/*
Last Updated: 11 Aug. 2019
By aiyion (freifunk@aiyionpri.me)
*/

#ifndef IRP_MAIN_H
#define IRP_MAIN_H


int get_code_count(void);
String get_freifunk_ipv6(void);
String get_public_ipv6(void);
int get_region(void);
String get_region_code(void);
int get_status(void);
unsigned long get_statuschange(void);
unsigned long get_uptime(void);
void load_EU(void);
void sendAllCodes(void);
void update_status(int new_status);

// The TV-B-Gone for Arduino can use either the EU (European Union) or the NA (North America) database of POWER CODES
// EU is for Europe, Middle East, Australia, New Zealand, and some countries in Africa and South America
// NA is for North America, Asia, and the rest of the world not covered by EU

// Two regions!
#define NA 1
#define EU 0

// What pins do what
#define IRLED 0        //the IR sender LED
#define TRIGGER 2       //the button pin

// Lets us calculate the size of the NA/EU databases
#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)));

// set define to 0 to turn off debug output
#define DEBUG 0
#define DEBUGP(x) if (DEBUG == 1) { x ; }

// Shortcut to insert single, non-optimized-out nop
#define NOP __asm__ __volatile__ ("nop")

// Not used any more on esp8266, so don't bother
// Tweak this if neccessary to change timing
// -for 8MHz Arduinos, a good starting value is 11
// -for 16MHz Arduinos, a good starting value is 25
#define DELAY_CNT 25

// Makes the codes more readable. the OCRA is actually
// programmed in terms of 'periods' not 'freqs' - that
// is, the inverse!
// #define freq_to_timerval(x) (F_CPU / 8 / x - 1)
#define freq_to_timerval(x) (x / 1000)

// The structure of compressed code entries
struct IrCode {
  uint8_t timer_val;
  uint8_t numpairs;
  uint8_t bitcompression;
  uint16_t const *times;
  uint8_t const *codes;
};

#endif //IRP_MAIN_H
