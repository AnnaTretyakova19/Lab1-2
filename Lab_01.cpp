#include <iostream>
#include <chrono>
#include "longHexHeader.h"

using namespace std::chrono;

int main()
{       
    
        longHex a1("4D3C91C579C2C6216567A5241614B561ADDF76C4BB659E6FE7F65FF76A918C843F0458B3EF457BCD9022D78798A29462EC99C74E6674690267D3E9844251B39D");
        longHex b1("DAF1ABDA4AD4D9FE3E36A529210C2AE99B905922FC0519798A26E351FE23AF375AD6BA288EE030B70DF0CE1CDF1E8B75BA56494DC6ED36B181814CD5783E6C81");
        longHex n1("2AB3786D3A85E62EC763A05A73A7F08D21EEE3CBCAE207E40854121BFF8258F7B2B293B0D30277CDB987A6FCB5BF28B68D8E68ABA88DED37BD80A879A1BB53E3");
        longHex c1, d1, e1, f1, g1,gcd1,lcm1,powm1;
        longHex m1("333");
        longHex k1("12A");

        //longHex a2("A664199B424E606126A31B875E3D5E9E9C2E13D6995CC801E60C30247808A6EE01E78895E16EAD95354FE50A9396DA3D5BDB6327FBF7DE11871BF3D0143055EC"); 
        //longHex b2("D4DA433DBC99DE3D9F192F4B84000A628F00F01D10532B8299BE4987E001E2F23137039D7106217C58800406778F64750E949A6D229AC61FCD424632593C4735");
        //longHex n2("94542B4FFCBB952A7355D808E397347DADD94894030779FA764DA32E6916347158BA0375D3626643D8033A8DFC0F2E0E15002029B553DDC072A6D636D192D976");
        //longHex c2, d2, e2, f2;

        //longHex a3("7723A9B9AFFCFCACFEF4537D2C587BA1E07EC2A27B9C907261F6461044DE2FEC26DA9BACDAC77063244D575EE788BB1145D7D09A94EC4B59859669CF8D86F454");
        //longHex b3("CE22515AE64F0FB5E6E33EF5D0D74AFE107BE2A91150D38A3AFCBC7608774631B56F41CDDD8A7D6A6C4170A4D17185E5C7578A27C2BD5816A62CD6D3E1E9266E");
        //longHex n3("38CDD88155E5E68A2B66FC28861FB57657E27A1D41D3E61730FAB712FB0E55728443D1A18C27DE41A5C3CAAFE43DE9484F48D282F29F8505F4BDF734D492B484");
        //longHex c3, d3, e3, f3;

        //longHex a4("94EDE1A444B9738ADF06CDB40DCAFA87B25A8BECA2D2262A53D8431A119405F0CBEFB83D2AD547CCE3AE74A8EC74A313C8BED20D4349D9EFBA356FE6E8AD89E2");
        //longHex b4("5BCC0B222EE17877C9EB60FA91632BC7A6E29D80F02CD3FE16B5C2A2231B43DB2B2D12F21B293AAF49FE1165CB7A21D12D6ACEC225285544B36BABD3F8B4DD8D");
        //longHex n4("8E06E4DFFB37B57A66ECC52CF2D7D888C49C2794E6FB944C4183A128203932FEBEA4B6E62B2EBDAD4FF0B80DBEDC8439D31280D13E7E523596D92861F6A89E81");
        //longHex c4, d4, e4, f4;

        c1 = a1 + b1;
        d1 = b1 - a1;
        e1 = a1 * b1;
        f1 = (a1 * b1) / b1;
        g1 = longHex::pow(m1, k1);

        cout << "\n";
        gcd1 = longHex::gcd(a1, b1);
        lcm1 = longHex::lcm(a1, b1);
        cout << "\n";
        /*cout << "\n";
        longHex test1("123");
        longHex test2 = test1 * longHex("64");
        test2.print();
        longHex test3;
        for (int i = 0; i < 100; i++) {
            test3 = test3 + test1;
        }
        test3.print();

        longHex f1 = (a1 + b1) * c1;
        longHex f2 = c1 * (a1 + b1);
        longHex f3 = a1 * c1 + b1 * c1;
        f1.print();
        f2.print();
        f3.print();*/
        

        //a1.print();
        //b1.print();
        c1.print();
        d1.print();
        e1.print();  
        f1.print();
        g1.print();
        gcd1.print();
        lcm1.print();

        cout << "\n";
        auto start = high_resolution_clock::now().time_since_epoch().count();
        cout << string(longHex::pow(a1, b1, n1)) << "\n";
        auto time = high_resolution_clock::now().time_since_epoch().count() - start;
        cout << "\n" << time;

        /*c2 = a2 + b2;
        d2 = a2 - b2;
        e2 = a2 * b2;
        f2 = (a2 * b2) / b2;

        a2.print();
        b2.print();
        c2.print();
        d2.print();
        e2.print();
        f2.print();*/
 }