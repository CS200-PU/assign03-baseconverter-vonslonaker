#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

const char BINARY = 'B';
const char HEXADECIMAL = 'H';
const char DECIMAL = 'D';

const string BINARY_PREFIX = "0b";
const string HEXADECIMAL_PREFIX = "0x";

int hexCharToInt(char myHex);

char getType(const string& myNumber);

string getNumber();
string reverseString(const string& myNumber);

string binaryToDecimal(const string& myNumber);
string decimalToBinary(const string& myNumber);
string decimalToHex(const string& myNumber);
string hexToDecimal(const string& myNumber);
string hexToBinary(const string& myNumber);
string binaryToHex(const string& myNumber);

void printTitle (const string& myTitle);

//*********************************************************************
int main() {
  const string QUIT = "q";
  const string TITLE = "HEX-DECIMAL-BINARY CONVERTER"; 
  
  printTitle(TITLE); 
  string myNumber = getNumber();

  while (myNumber != QUIT) {
    char myType = getType(myNumber);

    if (BINARY == myType) {
      std::cout << "The decimal conversion is: "
        << binaryToDecimal(myNumber) << endl;
      std::cout << "The hexadecimal conversion is: "
        << HEXADECIMAL_PREFIX
        << binaryToHex(myNumber)
        << endl;
    }

    else if (HEXADECIMAL == myType) {
      std::cout << "The decimal conversion is: "
        << hexToDecimal(myNumber) << endl;
      std::cout << "The binary conversion is: "
        << BINARY_PREFIX
        << hexToBinary(myNumber)
        << endl;
    }

    else if (DECIMAL == myType) {
      std::cout << "The binary conversion is: "
        << BINARY_PREFIX
        << decimalToBinary(myNumber) << endl;
      std::cout << "The hexadecimal conversion is: "
        << HEXADECIMAL_PREFIX
        << decimalToHex(myNumber) << endl;
    }

    cout << endl; 

    myNumber = getNumber();
  }

  return EXIT_SUCCESS;
}
//*********************************************************************

string getNumber() {
  string myString;

  std::cout << "Enter your string to convert (q to quit): ";
  cin >> myString;
  return myString;
}
//*********************************************************************

char getType(const string& myNumber) {
  char myReturnType;
  int length = static_cast<int>(myNumber.length());

  if ( '0' == myNumber.at(0) && length == 1 ) {
    myReturnType = DECIMAL; 
  }
  else if (HEXADECIMAL_PREFIX.at(0) == myNumber.at(0) &&
    HEXADECIMAL_PREFIX.at(1) == myNumber.at(1)) {
    myReturnType = HEXADECIMAL;
  }
  else if (BINARY_PREFIX.at(0) == myNumber.at(0) &&
    BINARY_PREFIX.at(1) == myNumber.at(1)) {
    myReturnType = BINARY;
  }
  else {
    myReturnType = DECIMAL;
  }
  return myReturnType;
}

//*********************************************************************
string binaryToDecimal(const string& myNumber) {

  int length = static_cast<int>(myNumber.length());
  int decimalConversion = 0;
  int coefficient = 0;
  int exponent = 0;

  for (int index = length - 1; index >= 2; index--) {
    coefficient = myNumber.at(index) - '0';
    decimalConversion += coefficient *
      static_cast<int>(pow(2, exponent));
    exponent++;
  }

  return std::to_string(decimalConversion);
}

//*********************************************************************
string hexToDecimal(const string& myNumber) {
  int length = static_cast<int>(myNumber.length());
  int decimalConversion = 0;
  int coefficient = 0;
  int exponent = 0;

  for (int index = length - 1; index >= 2; index--) {

    coefficient = hexCharToInt(myNumber.at(index));

    decimalConversion += coefficient *
      static_cast<int>(pow(16, exponent));
    exponent++;
  }

  return std::to_string(decimalConversion);
}

//*********************************************************************
string decimalToBinary(const string& myNumber) {
  int quotient = stoi(myNumber);
  int remainder = 0;
  string binaryConversion;

    // Have to handle 0 separately
  if (0 == quotient) {
    binaryConversion = "0";
  }

  while (quotient != 0) {
    remainder = quotient % 2;
    quotient = quotient / 2;
    binaryConversion += std::to_string(remainder);
  }

  return reverseString(binaryConversion);
}

//*********************************************************************
string decimalToHex(const string& myNumber) {
  // ans string to store hexadecimal number

  string hexConversion = "";
  int quotient = stoi(myNumber);
  int remainder = 0;
  char ch = ' ';

  // Have to handle 0 separately

  if (0 == quotient) {
    hexConversion = "0";
  };

  while (quotient != 0) {
    remainder = quotient % 16;

    if (remainder < 10) {
      ch = remainder + 48;  //ASCII Shift to number
    }
    else {
      ch = remainder + 55;  //ASCII Shift to letter
    }

    hexConversion += ch;
    quotient = quotient / 16;
  }

  return reverseString(hexConversion);
}

//*********************************************************************
int hexCharToInt(char myHex) {
  int intConversion = 0;

  if (myHex >= '0' && myHex <= '9') {
    intConversion = static_cast<int>(myHex - '0');
  }
  else {
    intConversion = myHex - 55;
  }
  return intConversion;
}

//*********************************************************************
string reverseString(const string& myNumber) {
  string reversedString = myNumber;

  reverse(reversedString.begin(),reversedString.end());
  
  return reversedString;
}

//********************************************************************
string hexToBinary(const string& myNumber) {
  return decimalToBinary(hexToDecimal(myNumber));
}

//*********************************************************************
string binaryToHex(const string& myNumber) {
  return decimalToHex(binaryToDecimal(myNumber));
}

void printTitle (const string& myTitle) {
  cout << "**************************************\n"; 
  cout << "*****" << myTitle << "*****" << endl; 
  cout << "**************************************\n"; 
}