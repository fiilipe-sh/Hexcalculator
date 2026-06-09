#include <iostream>
#include <array>
#include <string>

extern "C" int ConvertHexToDec(int number);
extern "C" long ResultRdxResistor;
extern "C" long ResultRdxResistorSession2;
extern "C" long ResultRaxResistor;





std::string LetterConversion(){
    std::string Resultletter;
    switch(ResultRdxResistor){
        case 10:
            Resultletter = "A";
            break;
        case 11:
            Resultletter = "B";
            break;
        case 12:
            Resultletter = "C";
            break;
        case 13:
            Resultletter = "D";
            break;
        case 14:
            Resultletter = "E";
            break;
        case 15:
            Resultletter = "F";
            break;
        default:
            std::cout << " Failure to convert number." << std::endl;
            break;
    }

    return  Resultletter;

}


int main(){
    int numberDecimal;
     std::string Resultletter = LetterConversion();
    std::cout << "Enter a decimal number to be converted to hexadecimal: ";
    std::cin >> numberDecimal;
    ConvertHexToDec(numberDecimal);

    std::cout << "\nResultado " <<  ResultRaxResistor << ResultRdxResistorSession2 << Resultletter << " Hex" << std::endl;





    return 0;
}












