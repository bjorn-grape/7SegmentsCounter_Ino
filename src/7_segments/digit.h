#pragma once
#include "digitLink.h"

#define segA 2
#define segB 3
#define segC 4
#define segD 5
#define segE 6
#define segF 7
#define segG 8
#define segDec 9

#define dig1 10
#define dig2 11
#define dig3 12
#define dig4 13

#define HIGH 0x1
#define LOW  0x0


class Digit
{

 static  digitLink *Dico;
  
 static   constexpr int none[8] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
 static   constexpr int zero[8] = {HIGH, HIGH, HIGH, HIGH,HIGH, HIGH, LOW, LOW};
 static   constexpr int one[8] = {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW};    
 static   constexpr int two[8] = {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW};    
 static   constexpr int three[8] = {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW};    
 static   constexpr int four[8] = {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW};    
 static   constexpr int five[8] = {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW};    
 static   constexpr int six[8] = {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW};
 static   constexpr int seven[8] = {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW};
 static   constexpr int eight[8] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW};
 static   constexpr int nine[8] = {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW};
 static   constexpr int e[8] = {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH, LOW};
 static   constexpr int r[8] = {LOW, LOW, LOW, LOW,  HIGH, LOW,  HIGH, LOW};



public:
  static void init()
  {
    Dico = (digitLink*) malloc(13 * sizeof(digitLink));
    
    Dico[0] = digitLink(' ', none);
    Dico[1] =  digitLink('0', zero);
    Dico[2] =  digitLink('1', one);
    Dico[3] = digitLink('2', two);
    Dico[4] = digitLink('3', three);
    Dico[5] = digitLink('4', four);
    Dico[6] = digitLink('5', five);
    Dico[7] = digitLink('6', six);
    Dico[8] = digitLink('7', seven);
    Dico[9] = digitLink('8', eight);
    Dico[10] =  digitLink('9', nine);
    Dico[11] = digitLink('e', e);
    Dico[12] = digitLink('r', r);
  }

  
  static void setNumber(char c)
  {
     for (int i = 0; i <  ::digitLink::membersNb; i++)
     {
      if (Dico[i].elm == c)
      {
          ApplyNumber(Dico[i].arr);
          break;
      }
     }
  }

  static void ApplyNumber(const int* arr)
  {
     digitalWrite(segA, arr[0]);
     digitalWrite(segB, arr[1]);
     digitalWrite(segC, arr[2]);
     digitalWrite(segD, arr[3]);
     digitalWrite(segE, arr[4]);
     digitalWrite(segF, arr[5]);
     digitalWrite(segG, arr[6]);
     digitalWrite(segDec, arr[7]);
  }

  public :
    static void resetPosition()
    {
        digitalWrite(dig1, LOW);
        digitalWrite(dig2, LOW);
        digitalWrite(dig3, LOW);
        digitalWrite(dig4, LOW);
    }
  
    static void setPosition(int pos)
    {
      for (int i = 1; i < 5; i++)
      {
       int realPos = 0;
        switch(i)
       {
          case 1:
            realPos = dig1;
           break;
         case 2:
           realPos = dig2;
           break;
          case 3:
           realPos = dig3;
           break;
         case 4:
           realPos = dig4;
           break;
         default:
            
            return;
        }
        int setVal = (pos == i) ? HIGH : LOW;
        digitalWrite(realPos, setVal);
      }
    }
};

digitLink *Digit::Dico;
constexpr int Digit::none[8];
constexpr int Digit::zero[8];
constexpr int Digit::one[8];    
constexpr int Digit::two[8];    
constexpr int Digit::three[8];    
constexpr int Digit::four[8];    
constexpr int Digit::five[8];    
constexpr int Digit::six[8];
constexpr int Digit::seven[8];
constexpr int Digit::eight[8];
constexpr int Digit::nine[8];
constexpr int Digit::e[8];
constexpr int Digit::r[8];
