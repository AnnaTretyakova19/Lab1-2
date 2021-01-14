#include "longHex.h"
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
		c("269D7722EA018F2AC35C5A3517AA06EAA1949059AE8240428BBFD0A8BE6E2EBF91223991F80D7413D6B2EB213E7122710EDEC617460FA0191F3901604619972018EBEF22D81AED9C56424014CADCC2CCDEE67D36A54BFC500230CA6693ABA057B374746622341ED6D52FE5A79E6860F54F197791B3FEF49FD534CB2C675B6BDB"),
		ab_sum("10F51035ED319BC50C0C4503B4D44872FC7DE7FC00F5DE863D6520E3906FC3E7E8761505118C918DB31AADBEA5A054B13A25F259CD47C1FAA7DB9B76F2DB450861BA26C4794E8E3BFBC2924DE45E47E5408536E3548A03591DA0556D595AB78C55149F45170F2CB7736A46976D1C09BFCE4DF6EAB040599AF235968F8070E25C2"),
		ab_div("9A531EB436073A5B899CEAEF7CFEEE386318967D8CAA2000BCF598BA51261E38AE874C932360023620DA0CAF90CEC25EB7F21C1A55A3A9F327AE7CA879634C73FC1F9E7256D38E258EE860B509506BAE185E180C06CC8DFBC23316BA1B357240BE81B14C9EC0A25A73AE85C0049185BD4A8D7E29F9F82A7C2FBFEF68174229F4"),
		ab_mul("30A120B609DCBE28B09CA92E12DD29D77AE6400DC22B026AFB5FB945AAF62B57F4E48BD299261F02BBB35DD2495B5CD2713BF0E30192DAE1B334659160C8552423F0AD7FB82870920DF4E9B57980EAD2ADA9F3EF4B5D0718AB7F1053700395278998CB9AD48498D65150E3E837B0BB169D432B441424557061F838A17C65F90A31105F599BF69B87485BF9C70F51D37A417E476E372558C26782AC8C8F35C3D1227E851D8A72CD708700FD90C5E17F22C4EA15730345E56BD76F04B54580813CBE306B4404C6F34BCD9840D2911E6B3CF6DE3EE428C274EDF0A97335D8256DA26FCD67BA5450593A15F6B527ECE76FBBE20F7A882347614AF4B7FAF55086659D"),
		ab_sub("3"),
		ab_mod("25553a0998f4b866527585a3acb95540fe52ad3b09f6579da399233b9b4ffdf2d5ad48d52df6eb9110093d74c79839a9cd851297d6cb343bd1a341e1c5124861dc9cd09d18be388b61a79c8bccbc59082868c1e2c4f8e665aa60d69ea0bf6bbc2bb96e47cc8e793db0b8a20937626f7db03b8da8efeabb493c2675d827762e26"),
		a_n_modc("11e97d13ac2368a6ddcc2a87b5c71cd0b33951d68ef905f95a7efa2bf49ebeec63bfdd69c6022e93d0963407b8a0942a72c6cafbccfc66c3ed2bbe86751b41e7d69e23a430794e9edd055b5741ad83bda475af10fed1b331cb4287280d51a518a3940c24c336f789cd8035d4156a29e15a88ede96e0ef32cd1be12ea034fece1"),
		gcd("1"),
		lcm("30a120b609dcbe28b09ca92e12dd29d77ae6400dc22b026afb5fb945aaf62b57f4e48bd299261f02bbb35dd2495b5cd2713bf0e30192dae1b334659160c8552423f0ad7fb82870920df4e9b57980ead2ada9f3ef4b5d0718ab7f1053700395278998cb9ad48498d65150e3e837b0bb169d432b441424557061f838a17c65f90a31105f599bf69b87485bf9c70f51d37a417e476e372558c26782ac8c8f35c3d1227e851d8a72cd708700fd90c5e17f22c4ea15730345e56bd76f04b54580813cbe306b4404c6f34bcd9840d2911e6b3cf6de3ee428c274edf0a97335d8256da26fcd67ba5450593a15f6b527ece76fbbe20f7a882347614af4b7faf55086659d"),
		abc_sum("102c16a6d0ed225693dd8c7a79e56c55cce8d4c49ce26920413599bd1f8f7418f71bd53506aec5052c66e01a4ed59fc3a47baf9ea0ebefaa32aadcd43012ea56d2ee253ac2c64796059644cb9db2ab9f00601b6c38c4f61caafce078bfa165f691ac5868185f397625521e17ce5f547bb2d29af180ce9504ee7dac1338e32c5"),
		abc_div("267ab94b78028cdb3f87dc503600d9787e5ae57081235f3919b626c015db91f9fb209fdd3b37a5fa9cc14b4bd57b5b0b8b55c9d48374c9a7ca037887a7168713b15bd109ce82c5508c21a076a8ba23477baaa06816e8990bbba0b78660329139a424541a382445d5f41ed4c9295862dd5d411774ddfb4c9cb0218de2e12fe663"),
		abc_mul("b274d0d82e9b2997834fe06626976c55d7bad04a38623214d2c29f08d4bb6d4c3eb31d0bf3b5bb7965f820af3ceb31fd0498d6e94feab692c36df783c400d19a0f1a25e9232945024c249770c34f610d9dd31672b1cfbde78856afe52cb54ca3750fb6d4529c0b4e491c12aebb0f2db2f8449107611cc66cac56b4275c31ee7"),
		abc_pow("11e97d13ac2368a6ddcc2a87b5c71cd0b33951d68ef905f95a7efa2bf49ebeec63bfdd69c6022e93d0963407b8a0942a72c6cafbccfc66c3ed2bbe86751b41e7d69e23a430794e9edd055b5741ad83bda475af10fed1b331cb4287280d51a518a3940c24c336f789cd8035d4156a29e15a88ede96e0ef32cd1be12ea034fece1"),
		n("269D7722EA018F2AC35C5A3517AA06EAA1949059AE82404"),
		n1("1BE");

//longHex n2("3AC4"),
		//n3("12ABD");
		

	cout << "a = " << "\n";
	a.print();
	cout << "b = ";
	b.print(); 
	cout << "n = ";
	n.print();
	cout << "c = ";
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
	cout << "        ";
	ab_sum.print();
	cout << "\n" << "Time: " << time << "\n\n";


	cout << "a - b = ";
	benchmark<1>();
	temp = a - b;
	time = benchmark<1>();
	assert(temp == ab_div);
	temp.print();
	cout << "        ";
	ab_div.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "a * b = ";
	benchmark<1>();
	temp = a * b;
	time = benchmark<1>();
	assert(temp == ab_mul);
	temp.print();
	cout << "        ";
	ab_mul.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "a / b = ";
	benchmark<1>();
	temp = a / b;
	time = benchmark<1>();
	assert(temp == ab_sub);
	temp.print();
	cout << "        ";
	ab_sub.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "a % b = ";
	benchmark<1>();
	temp = a % b;
	time = benchmark<1>();
	assert(temp == ab_mod);
	temp.print();
	cout << "        ";
	ab_mod.print();
	cout << "\n" << "  Time: " << time << "\n\n";

	//cout << "n2 ^ n3 : ";
	//benchmark<1>();
	//temp = longHex::pow(n2, n3);
	//time = benchmark<1>();
	////assert(temp == an_pow);
	//os << string(temp) << "\n";

	
	cout << "n ^ n1 : ";
	benchmark<1>();
	temp = longHex::pow(n, n1);
	time = benchmark<1>();
	//assert(temp == an_pow);
	os << string(temp) << "\n";

	cout << "length: " << string(temp).size() << " Time: " << time << "\n";

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
	cout << "\n\n\n=============================================================================================\n\n\n";











	cout << "gcd(a, b) = ";
	benchmark<1>();
	temp = longHex::gcd(a, b);
	time = benchmark<1>();
	temp.print();	
	cout << "        ";
	gcd.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "lcm(a, b) = ";
	benchmark<1>();
	temp = longHex::lcm(a, b);
	time = benchmark<1>();
	temp.print();
	cout << "        ";
	lcm.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "(a + b) % c= ";
	benchmark<1>();
	temp = (a + b)%c;
	time = benchmark<1>();
	temp.print();
	cout << "        ";
	abc_sum.print();
	cout << "\n" << "Time: " << time << "\n\n";


	cout << "(a - b)%c = ";
	benchmark<1>();
	temp = (a - b)%c;
	time = benchmark<1>();
	temp.print();
	cout << "        ";
	abc_div.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "(a * b)%c = ";
	benchmark<1>();
	temp = (a * b)%c;
	time = benchmark<1>();
	temp.print();
	cout << "        ";
	abc_mul.print();
	cout << "\n" << "Time: " << time << "\n\n";

	cout << "(a ^ b)%c = ";
	benchmark<1>();
	temp = longHex::powm(a, b, c);
	time = benchmark<1>();
	temp.print();
	cout << "        ";
	abc_pow.print();
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
	longHex::powm(x, y, z).print();


	cout << "\n\n";
	time = benchmark<0>();
	cout << "Total time: " << time << "\n";

	
}