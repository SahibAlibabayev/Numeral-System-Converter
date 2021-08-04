#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;
int convertBinaryToDecimal(long long);

void decToOctal(int n)
{
 
    // array to store octal number
    int octalNum[100];
 
    // counter for octal number array
    int i = 0;
    while (n != 0) {
 
        // storing remainder in octal array
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
 
    // printing octal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << octalNum[j];
}
static int hexadecimalToDec(string hexVal)
{
    int len = hexVal.length();

    // Initializing base1 value
    // to 1, i.e 16^0
    int base1 = 1;
 
    int dec_val = 0;
 
    // Extracting characters as
    // digits from last character
    for (int i = len - 1; i >= 0; i--) {
        // if character lies in '0'-'9',
        // converting it to integral 0-9
        // by subtracting 48 from ASCII value
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (hexVal[i] - 48) * base1;
 
            // incrementing base1 by power
            base1 = base1 * 16;
        }
 
        // if character lies in 'A'-'F' ,
        // converting it to integral
        // 10 - 15 by subtracting 55
        // from ASCII value
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (hexVal[i] - 55) * base1;
 
            // incrementing base1 by power
            base1 = base1 * 16;
        }
    }
    return dec_val;
}
void decToHexDecimal(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];
 
    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // temporary variable to store remainder
        int temp = 0;
 
        // storing remainder in temp variable.
        temp = n % 16;
 
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
 
        n = n / 16;
    }
    int content;
    // printing hexadecimal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << hexaDeciNum[j];
}
int binToDec(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
int octalToDec(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 8^0
    int base = 1;
 
    int temp = num;
    while (temp) {
 
        // Extracting last digit
        int last_digit = temp % 10;
        temp = temp / 10;
 
        // Multiplying last digit with appropriate
        // base value and adding it to dec_value
        dec_value += last_digit * base;
 
        base = base * 8;
    }
 
    return dec_value;
}

int main(){
    string secim;
    string language;
    
    cout << "**************************************" << endl;
    cout << "*******Numeral System Converter*******" << endl;
    cout << "**************************************" << endl;
    cout << "1)English\n2)Turkish\nChoose the language:";
    cin >> language;
    cout << "\n\n";
    if (language == "1"){
        while (true)
        {    
            cout << "1) Decimal to Binary\n2) Binary to Decimal\n3) Decimal to Hexdecimal\n4) Hexdecimal to Decimal\n5) Decimal to Octal\n6) Octal to Decimal\n7) Exit\n ";
            cout << "Enter Your Choice:";
            cin >> secim;
            cout << "\n";
            if (secim == "1"){
                cout << "Enter the decimal number:";
                int a[10], n, i;    
                cin >> n;
                for (i = 0; n > 0; i++)
                {
                    a[i]=n%2;    
                    n = n/2;  
                }
                cout<<"Binary form of the given number = ";    
                for(i=i-1 ;i>=0 ;i--)    
                {    
                    cout<< a[i];    
                }  
                cout << "\n\n";
            }
            else if (secim == "2"){
                long long n;
                cout << "Enter the binary number: ";
                cin >> n;
                cout << "Decimal form of the given number  = " << binToDec(n);
                cout << "\n\n";
            }
            else if (secim == "3"){
                int n;
                cout << "Enter the Decimal number:";
                cin >> n;
                cout << "Hexadecimal form of the given number = ";
                decToHexDecimal(n); 
                cout << "\n\n";
            }
            else if(secim == "4"){
                string hexNum;
                cout << "Enter the HexaDecimal number:";
                cin >> hexNum;
                cout << "Decimal form of the given number = " << hexadecimalToDec(hexNum);
                cout << "\n\n";
            }
            else if(secim == "5"){
                cout << "Enter the decimal number:";
                int n; 
                cin >> n;
                cout << "Octal form of the given number = ";
                decToOctal(n);
                cout << "\n\n";
            }
            else if(secim == "6"){
                cout << "Enter the octal number:";
                int n; 
                cin >> n;
                cout << "Decimal form of the given number = " << octalToDec(n);
                cout << "\n\n";
            }
            else if(secim == "7") {
                break;
            }
        }
    }
    if (language == "2"){
        while (true)
        {    
            cout << "1) Ondalikdan Ikiliye\n2) Ikiliden Ondaliga\n3) Ondalikdan Onaltiliga\n4) Onaltilikdan Onluga\n5) Onlukdan Sekizlige\n6) Sekizlikden Onluga\n7) Cikis\n ";
            cout << "Seciminizi Giriniz:";
            cin >> secim;
            cout << "\n";
            if (secim == "1"){
                cout << "Cevirmek istediginiz onluk sayiyi girin:";
                int a[10], n, i;    
                cin >> n;
                for (i = 0; n > 0; i++)
                {
                    a[i]=n%2;    
                    n = n/2;  
                }
                cout<<"Verilen sayinin ikilik hali = ";    
                for(i=i-1 ;i>=0 ;i--)    
                {    
                    cout<< a[i];    
                }  
                cout << "\n\n";
            }
            else if (secim == "2"){
                long long n;
                cout << "Cevirmek istediginiz ikilik sayiyi girin: ";
                cin >> n;
                cout << n << " ikilisinin ondalik hali = " << binToDec(n);
                cout << "\n\n";
            }
            else if (secim == "3"){
                int n;
                cout << "Cevirmek istediginiz onluk sayiyi girin:";
                cin >> n;
                cout << n << " sayisinin onaltilik hali = ";
                decToHexDecimal(n); 
                cout << "\n\n";
            }
            else if (secim == "4"){
                string hexNum;
                cout << "Cevirmek istediginiz Onaltilik sayiyi girin:";
                cin >> hexNum;
                cout << hexNum <<" sayisinin ondalik hali = " << hexadecimalToDec(hexNum);
                cout << "\n\n";
            }
            else if(secim == "5"){
                cout << "Cevirmek istediginiz Onaltilik sayiyi girin:";
                int n; 
                cin >> n;
                cout << n <<" sayisinin sekizlik hali = ";
                decToOctal(n);
                cout << "\n\n";
            }
            else if(secim == "6") {
                cout << "Cevirmek istediginiz sekizlik sayiyi girin:";
                int n; 
                cin >> n;
                cout << "Decimal form of the given number = " << octalToDec(n);
                cout << "\n\n";
            }
            else if(secim == "7") {
                break;
            }
        }
    }
    return 0;
}






