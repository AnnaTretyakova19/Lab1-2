﻿#include "longHex.h"
#include <iostream>
#include <chrono>
#include <bitset>
#include <assert.h>
#include <fstream>


using namespace std::chrono;
ofstream os("output.txt");
template < int >

string benchmark() {
	static auto start = chrono::high_resolution_clock::now();
	long long result = (chrono::high_resolution_clock::now() - start).count();
	start = chrono::high_resolution_clock::now();
	char buffer[1024];
	sprintf_s(buffer, "%.6fms", result / 1000000.0);
	return buffer;
}

int main()
{

	benchmark<0>();

	longHex
		a("D4D2110984907B5625309D956521BAB4157B8B1ECE04043249A3D379AC112E5B9AF44E721E148D88A942744CF56A06B92D28A0DB950FE4CED2B41A0BD38BCE7D0BE1055CF5DE38F2A588C2C9A79A75011058C320A7B661C6CE1C36C7D870758307E5D2CF07D9B6E8D529779B6B2910DD17B6766A7EFEE215A98CAC300F2827DB"),
		b("3A7EF2554E8940FA9B93B2A5E822CC7BB262F4A14159E4318CAE3ABF5AEB1022EC6D01DEFAB48B528868679D649B445A753684C13F6C3ADBAB059D635A2882090FC166EA9F0AAACD16A062149E4A0952F7FAAB14A0E9D3CB0BE9200DBD3B0342496421826919148E617AF1DB66978B1FCD28F8408506B79979CCBCC7F7E5FDE7"),
		n("269D7722EA018F2AC35C5A3517AA06EAA1949059AE82404"),
		c("269D7722EA018F2AC35C5A3517AA06EAA1949059AE8240428BBFD0A8BE6E2EBF91223991F80D7413D6B2EB213E7122710EDEC617460FA0191F3901604619972018EBEF22D81AED9C56424014CADCC2CCDEE67D36A54BFC500230CA6693ABA057B374746622341ED6D52FE5A79E6860F54F197791B3FEF49FD534CB2C675B6BDB"),
		ab_sum("10F51035ED319BC50C0C4503B4D44872FC7DE7FC00F5DE863D6520E3906FC3E7E8761505118C918DB31AADBEA5A054B13A25F259CD47C1FAA7DB9B76F2DB450861BA26C4794E8E3BFBC2924DE45E47E5408536E3548A03591DA0556D595AB78C55149F45170F2CB7736A46976D1C09BFCE4DF6EAB040599AF235968F8070E25C2"),
		ab_div("9A531EB436073A5B899CEAEF7CFEEE386318967D8CAA2000BCF598BA51261E38AE874C932360023620DA0CAF90CEC25EB7F21C1A55A3A9F327AE7CA879634C73FC1F9E7256D38E258EE860B509506BAE185E180C06CC8DFBC23316BA1B357240BE81B14C9EC0A25A73AE85C0049185BD4A8D7E29F9F82A7C2FBFEF68174229F4"),
		ab_mul("30A120B609DCBE28B09CA92E12DD29D77AE6400DC22B026AFB5FB945AAF62B57F4E48BD299261F02BBB35DD2495B5CD2713BF0E30192DAE1B334659160C8552423F0AD7FB82870920DF4E9B57980EAD2ADA9F3EF4B5D0718AB7F1053700395278998CB9AD48498D65150E3E837B0BB169D432B441424557061F838A17C65F90A31105F599BF69B87485BF9C70F51D37A417E476E372558C26782AC8C8F35C3D1227E851D8A72CD708700FD90C5E17F22C4EA15730345E56BD76F04B54580813CBE306B4404C6F34BCD9840D2911E6B3CF6DE3EE428C274EDF0A97335D8256DA26FCD67BA5450593A15F6B527ECE76FBBE20F7A882347614AF4B7FAF55086659D"),
		n1("1BE");

	cout << "a = " << "\n";
	a.print();
	cout << "b = ";
	b.print(); 
	cout << "n = ";
	n.print();
	cout << "n = ";
	c.print();
	cout << "\n\n";

	longHex temp;
	string time;

	cout << "a + b = ";
	benchmark<1>();
	temp = a + b;
	time = benchmark<1>();
	assert(temp == ab_sum);
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";


	cout << "a - b = ";
	benchmark<1>();
	temp = a - b;
	time = benchmark<1>();
	assert(temp == ab_div);
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "a * b = ";
	benchmark<1>();
	temp = a * b;
	time = benchmark<1>();
	//assert(temp == n1);
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "a / b = ";
	benchmark<1>();
	temp = a / b;
	time = benchmark<1>();
	//assert(temp == n1);
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "a % b = ";
	benchmark<1>();
	temp = a % b;
	time = benchmark<1>();
	//assert(temp == n1);
	temp.print();
	cout << "\n" << "  Time: " << time << "\n\n";

	cout << "n ^ n1 : ";
	benchmark<1>();
	temp = longHex::pow(n, n1);
	time = benchmark<1>();
	//assert(temp == an_pow);
	os << string(temp) << "\n";

	cout << "length: " << string(temp).size()  << "Time: " << time << "\n";
		
	longHex
		x = (a + b) * n,
		y = b * n + n * a;

	//assert(x == y);
	cout << "(a + b) * n = " << "\n";
	x.print(); 
	cout << "b * n + n * a = " << "\n";
	y.print();
	cout << "\n";


	x = a * longHex("100");
	longHex z;
	for (int i = 0; i < 256; ++i) {
		z += a;
	}
	cout << "a * 100 = " << "\n";
	x.print();	
	cout << "(a + a +...+ a)   = " << "\n";
	z.print();
	cout << "\n";

	cout << "gcd(a, b) = ";
	benchmark<1>();
	temp = longHex::gcd(a, b);
	time = benchmark<1>();
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "gcd(a, c) = ";
	benchmark<1>();
	temp = longHex::gcd(a, c);
	time = benchmark<1>();
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "lcm(a, b) = ";
	benchmark<1>();
	temp = longHex::lcm(a, b);
	time = benchmark<1>();
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "lcm(a, b) = ";
	benchmark<1>();
	temp = longHex::lcm(a, c);
	time = benchmark<1>();
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "(a + b) % c= ";
	benchmark<1>();
	temp = (a + b)%c;
	time = benchmark<1>();
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";


	cout << "(a - b)%c = ";
	benchmark<1>();
	temp = (a - b)%c;
	time = benchmark<1>();
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "(a * b)%c = ";
	benchmark<1>();
	temp = (a * b)%c;
	time = benchmark<1>();
	//assert(temp == n1);
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "(a ^ b)%c = ";
	benchmark<1>();
	temp = longHex::pow(a, b, c);
	time = benchmark<1>();
	//assert(temp == an_pow);
	temp.print();
	cout << "\n" << "Time: " << time << "\n\n";

	

	x = ((a + b) * n)%c,
	y = (b * n + n * a)%c;
	//assert(x == y);
	cout << "((a + b) * n)%c" << "\n";
	x.print();
	cout << "(b * n + n * a)%c = " << "\n";
	y.print();
	cout << "\n";

	x = (a * longHex("100"))%c;
	z = z % c;
	cout << "(a * 100)%c " << "\n";
	x.print();
	cout << "(a + a +...+ a)%c" << "\n";
	z.print();
	cout << "\n";

	x = longHex("8f");
	y = longHex("99C6");
	z = longHex("1CD52");
	cout << "a^(2*3^(k-1))%(3^k) = " << "\n";
	longHex::pow(x, y, z).print();


	cout << "\n\n";
	time = benchmark<0>();
	cout << "Total time: " << time << "\n";
}