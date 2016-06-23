#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
/*
int con_romchar_int(char c)
{
	switch (c)
	{
	case 'i':
	case 'I': return 1;
	case 'v':
	case 'V': return 5;
	case 'x':
	case 'X': return 10;
	case 'l':
	case 'L': return 50;
	case 'c':
	case 'C': return 100;
	case 'd':
	case 'D': return 500;
	case 'm':
	case 'M': return 1000;
	case '\0':return 0;
	}
}
int conv_number2Roman(char *n2r)
{
	int strln = strlen(n2r);
	printf("%d %s\n", strln,n2r);
	return 0;
}

void main()
{
	char rom1[30]= "Lxi";
	char rom2[30] = "MDi";
	int rom_in1;
	int rom_int2;
	
	
	printf("%d", con_romchar_int('m'));
	
	//conv_number2Roman(rom1);
	//conv_number2Roman(rom2);

}*/

//Roman to Decimal 

int digitValue(char c){

	int value = 0;

	switch (c){
	case 'I':
	case 'i':
		value = 1; break;
	case 'V':
	case 'v':
		value = 5; break;
	case 'X':
	case 'x':
		value = 10; break;
	case 'L':
	case 'l':
		value = 50; break;
	case 'C':
	case 'c':
		value = 100; break;
	case 'D':
	case 'd':
		value = 500; break;
	case 'M':
	case 'm':
		value = 1000; break;
	case '\0': value = 0; break;
	default: value = -1;
	}

	return value;
}

long int conv_Roman2Int(char *r2n)
{
	long int number = 0;
	int i = 0;
	while (r2n[i]){

		if (digitValue(r2n[i]) < 0){
			printf("Invalid roman digit : %c", r2n[i]);
			return 0;
		}

		if ((strlen(r2n) - i) > 2){
			if (digitValue(r2n[i]) < digitValue(r2n[i + 2])){
				printf("Invalid roman number");
				return 0;
			}
		}

		if (digitValue(r2n[i]) >= digitValue(r2n[i + 1]))
			number = number + digitValue(r2n[i]);
		else{
			number = number + (digitValue(r2n[i + 1]) - digitValue(r2n[i]));
			i++;
		}
		i++;
	}

	return number;
}



void convertToRoman(unsigned int val, char *res) {
	char *huns[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	char *tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	char *ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	int   size[] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2 };


	//  Add 'M' until we drop below 1000.

	while (val >= 1000) {
		*res++ = 'M';
		val -= 1000;
	}

	// Add each of the correct elements, adjusting as we go.

	strcpy(res, huns[val / 100]); res += size[val / 100]; val = val % 100;
	strcpy(res, tens[val / 10]);  res += size[val / 10];  val = val % 10;
	strcpy(res, ones[val]);     res += size[val];

	// Finish string off.

	*res = '\0';
}

int main(){
	long int Num1,Num2;
	unsigned int Addition, Subtraction;
	char roman_Number1[30];
	char roman_Number2[30];
	char roman_sub[30];
	char roman_add[30];
	
	

	printf("Enter Two roman numbers (Valid digits are I, V, X, L, C, D, M):  \n");
	scanf("%s %s", roman_Number1, roman_Number2);

	Num1 = conv_Roman2Int(roman_Number1);
	if(Num1>0)
		printf("Its decimal value is : %ld\n", Num1);
	Num2 = conv_Roman2Int(roman_Number2);
	if (Num1>0)
		printf("Its decimal value is : %ld\n", Num2);
	Addition = Num1 + Num2;
	if (Num1 > Num2)
		Subtraction = Num1 - Num2;
	else
		Subtraction = Num2 - Num1;
	printf("Add : %d, Sub :%d", Addition, Subtraction); getchar();
	convertToRoman(Addition, roman_add); 
	convertToRoman(Subtraction, roman_sub);

	printf("Addition of Roman numbers %s and %s is :: %s\n", roman_Number1, roman_Number2, roman_add);
	printf("Subraction of Roman numbers %s and %s is :: %s\n", roman_Number1, roman_Number2, roman_sub);


	return 0;

}

/*


int main()
{
	int decimalNumber;
	char rom[30];


	printf("Decimal Number to Roman Numeral Converter in C \n");
	printf("Enter Decimal Number: ");
	scanf("%d", &decimalNumber);
	convertToRoman(decimalNumber, rom);
	printf("Roman : %s", rom);

}*/