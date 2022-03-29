/*
  my solution of:
  https://www.codewars.com/kata/54b724efac3d5402db00065e/
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STR_MAX_LEN 1000
#define MORSE_LETTER_MAX_LEN 10

const char *morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};
const char ascii[54]  = {'A',  'B',    'C',    'D',   'E', 'F',    'G',   'H',    'I',  'J',    'K',   'L',    'M',  'N',  'O',   'P',    'Q',    'R',   'S',   'T', 'U',   'V',    'W',   'X',    'Y',    'Z',    '0',     '1',     '2',     '3',     '4',     '5',     '6',     '7',     '8',     '9',     '.',      ',',      '\?',      '\'',      '!',      '/',     '(',     ')',      '&',     ':',      ';',      '=',     '+',     '-',      '_',      '\"',     '$',       '@'};

void addLetterToStr(char *, int, char *);
char *decode_morse(const char *);

int main(int argc, char *argv[]) {
  char *str = decode_morse("      ...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- -.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... .   .-.. .- --.. -.--   -.. --- --. .-.-.-     ");
  if(!strcmp(str, "SOS! THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG."))
    printf("works!");
  return 0;
}

char *decode_morse(const char* morse_code) {
  char *str = (char *) malloc(sizeof(char)*STR_MAX_LEN);
  str[0] = '\0';
  char *letter = (char *) malloc(sizeof(char)*MORSE_LETTER_MAX_LEN);
  letter[0] = '\0';
  bool spaceLetter = false;
  bool spaceWord = false;
  int i = 0;  // for input string
  int j = 0;  // for output string
  int k = 0;  // for letter string
  while(morse_code[i] != '\0') {
    if(morse_code[i] != ' ') {
      if(spaceWord) {
        str[j++] = ' ';
        spaceWord = false;
      } else if(spaceLetter)
        spaceLetter = false;
      letter[k++] = morse_code[i];
    } else {
      if(spaceLetter) {
        spaceWord = true;
        spaceLetter = false;
      } else if(!spaceWord && k) {   // both spaceLetter and spaceWord == false
        letter[k] = '\0';
        addLetterToStr(str, j, letter);
        if(!strcmp(morse[54], letter))  // "SOS"
          j += 2;
        ++j;
        str[j] = '\0';
        k = 0;
        letter[0] = '\0';
        spaceLetter = true;
      }
    }
    ++i;
  }
  if(k) { // last letter
    letter[k] = '\0';
    addLetterToStr(str, j, letter);
    if(!strcmp(morse[54], letter))  // "SOS"
          j += 2;
    str[++j] = '\0';
  }
  return str;
}

void addLetterToStr(char *str, int j, char *letter) {
  int i = 0;
  while(i<55 && strcmp(morse[i], letter))
    ++i;
  if(i<54) {
    str[j] = ascii[i];
  } else if(i == 54) {
    str[j] = ascii[18];   // 'S'
    str[j+1] = ascii[14]; // 'O'
    str[j+2] = ascii[18]; // 'S'
  }
  return;
}