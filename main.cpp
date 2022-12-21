/*
 * Wade Bradford
 * CS 124
 * Project 4
 */


#include <vector>
#include <string>
#include <iostream>
#include "Streamer.h"
#include "SeparateChaining.h"
#include "OpenAddressing.h"
using namespace std;

// 1st getKey method
string getStreamer(Streamer object) {
    return object.getStreamerName();
}

// 2nd getKey method
string getStreamerOther(Streamer object) {
    int temp = object.getAverageViewers();
    string aV = std::to_string(temp);
    return aV;
 }


int main() {

    vector<Streamer> streamers;
    string fn = "../twitchdata-update.csv";
    cout << endl;

    // reads file and stores into vector
    if (readDataFromFile(fn, streamers)) {
        cout << streamers.size() << " steamers read from file" << std::endl;
        string firstName = streamers.front().getStreamerName();
        cout << "The first streamer read was " << firstName << endl;
        string lastName = streamers.back().getStreamerName();
        cout << "The last streamer read was " << lastName << endl;
    }
    else {
        cout << "Something went wrong." << endl;
    }

    cout << endl;

    // 10 separate-chaining hash table objects
    SeparateChaining<Streamer> sepChainTable1(1020, getStreamer);
    SeparateChaining<Streamer> sepChainTable2(1500, getStreamer);
    SeparateChaining<Streamer> sepChainTable3(1900, getStreamer);
    SeparateChaining<Streamer> sepChainTable4(2500, getStreamer);
    SeparateChaining<Streamer> sepChainTable5(3000, getStreamer);

    SeparateChaining<Streamer> sepChainTable6(1020, getStreamerOther);
    SeparateChaining<Streamer> sepChainTable7(1500, getStreamerOther);
    SeparateChaining<Streamer> sepChainTable8(1900, getStreamerOther);
    SeparateChaining<Streamer> sepChainTable9(2500, getStreamerOther);
    SeparateChaining<Streamer> sepChainTable10(3000, getStreamerOther);

    // 10 open addressing (quadratic probing) hash table objects
    QuadraticProbing<Streamer> quadProbTable1(1020, getStreamer);
    QuadraticProbing<Streamer> quadProbTable2(1500, getStreamer);
    QuadraticProbing<Streamer> quadProbTable3(1900, getStreamer);
    QuadraticProbing<Streamer> quadProbTable4(2500, getStreamer);
    QuadraticProbing<Streamer> quadProbTable5(3000, getStreamer);

    QuadraticProbing<Streamer> quadProbTable6(1020, getStreamerOther);
    QuadraticProbing<Streamer> quadProbTable7(1500, getStreamerOther);
    QuadraticProbing<Streamer> quadProbTable8(1900, getStreamerOther);
    QuadraticProbing<Streamer> quadProbTable9(2500, getStreamerOther);
    QuadraticProbing<Streamer> quadProbTable10(3000, getStreamerOther);

    /* Example of writing out to a file
    ofstream outFile;
    outFile.open("../data/example-output.txt");
    for (int i = 999; i >= 0; --i) {
        outFile << i << endl;
    }
    outFile.close();
    */

    // files for number of hashed objects read
    ofstream hashFileSep1("hashFileSep1.txt");
    ofstream hashFileSep2("hashFileSep2.txt");
    ofstream hashFileSep3("hashFileSep3.txt");
    ofstream hashFileSep4("hashFileSep4.txt");
    ofstream hashFileSep5("hashFileSep5.txt");
    ofstream hashFileSep6("hashFileSep6.txt");
    ofstream hashFileSep7("hashFileSep7.txt");
    ofstream hashFileSep8("hashFileSep8.txt");
    ofstream hashFileSep9("hashFileSep9.txt");
    ofstream hashFileSep10("hashFileSep10.txt");
    ofstream hashFileQuad1("hashFileQuad1.txt");
    ofstream hashFileQuad2("hashFileQuad2.txt");
    ofstream hashFileQuad3("hashFileQuad3.txt");
    ofstream hashFileQuad4("hashFileQuad4.txt");
    ofstream hashFileQuad5("hashFileQuad5.txt");
    ofstream hashFileQuad6("hashFileQuad6.txt");
    ofstream hashFileQuad7("hashFileQuad7.txt");
    ofstream hashFileQuad8("hashFileQuad8.txt");
    ofstream hashFileQuad9("hashFileQuad9.txt");
    ofstream hashFileQuad10("hashFileQuad10.txt");

    // doubles for average reads
    double averageReadsSep1 = 0;
    double averageReadsSep2 = 0;
    double averageReadsSep3 = 0;
    double averageReadsSep4 = 0;
    double averageReadsSep5 = 0;
    double averageReadsSep6 = 0;
    double averageReadsSep7 = 0;
    double averageReadsSep8 = 0;
    double averageReadsSep9 = 0;
    double averageReadsSep10 = 0;

    double averageReadsQuad1 = 0;
    double averageReadsQuad2 = 0;
    double averageReadsQuad3 = 0;
    double averageReadsQuad4 = 0;
    double averageReadsQuad5 = 0;
    double averageReadsQuad6 = 0;
    double averageReadsQuad7 = 0;
    double averageReadsQuad8 = 0;
    double averageReadsQuad9 = 0;
    double averageReadsQuad10 = 0;


    // loop to insert all 1000 streamers into the 20 tables
    for (int i = 0; i < streamers.size(); i++) {
        // separate chaining
        int sep1Temp = sepChainTable1.insert(streamers.at(i));
        hashFileSep1 <<  sep1Temp << endl;
        averageReadsSep1 += sep1Temp;

        int sep2Temp = sepChainTable2.insert(streamers.at(i));
        hashFileSep2 <<  sep2Temp << endl;
        averageReadsSep2 += sep2Temp;

        int sep3Temp = sepChainTable3.insert(streamers.at(i));
        hashFileSep3<<  sep3Temp << endl;
        averageReadsSep3 += sep3Temp;

        int sep4Temp = sepChainTable4.insert(streamers.at(i));
        hashFileSep4 <<  sep4Temp << endl;
        averageReadsSep4 += sep4Temp;

        int sep5Temp = sepChainTable5.insert(streamers.at(i));
        hashFileSep5 <<  sep5Temp << endl;
        averageReadsSep5 += sep5Temp;

        int sep6Temp = sepChainTable6.insert(streamers.at(i));
        hashFileSep6 <<  sep6Temp << endl;
        averageReadsSep6 += sep6Temp;

        int sep7Temp = sepChainTable7.insert(streamers.at(i));
        hashFileSep7 <<  sep7Temp << endl;
        averageReadsSep7 += sep7Temp;

        int sep8Temp = sepChainTable8.insert(streamers.at(i));
        hashFileSep8 <<  sep8Temp << endl;
        averageReadsSep8 += sep8Temp;

        int sep9Temp = sepChainTable9.insert(streamers.at(i));
        hashFileSep9 <<  sep9Temp << endl;
        averageReadsSep9 += sep9Temp;

        int sep10Temp = sepChainTable10.insert(streamers.at(i));
        hashFileSep10 <<  sep10Temp << endl;
        averageReadsSep10 += sep10Temp;

        // open addressing (quadratic probing)
        int quad1Temp = quadProbTable1.insert(streamers.at(i));
        hashFileQuad1 <<  quad1Temp << endl;
        averageReadsQuad1 += quad1Temp;

        int quad2Temp = quadProbTable2.insert(streamers.at(i));
        hashFileQuad2 <<  quad2Temp << endl;
        averageReadsQuad2 += quad2Temp;

        int quad3Temp = quadProbTable3.insert(streamers.at(i));
        hashFileQuad3 <<  quad3Temp << endl;
        averageReadsQuad3 += quad3Temp;

        int quad4Temp = quadProbTable4.insert(streamers.at(i));
        hashFileQuad4 <<  quad4Temp << endl;
        averageReadsQuad4 += quad4Temp;

        int quad5Temp = quadProbTable5.insert(streamers.at(i));
        hashFileQuad5 <<  quad5Temp << endl;
        averageReadsQuad5 += quad5Temp;

        int quad6Temp = quadProbTable6.insert(streamers.at(i));
        hashFileQuad6 <<  quad6Temp << endl;
        averageReadsQuad6 += quad6Temp;

        int quad7Temp = quadProbTable7.insert(streamers.at(i));
        hashFileQuad7 <<  quad7Temp << endl;
        averageReadsQuad7 += quad7Temp;

        int quad8Temp = quadProbTable8.insert(streamers.at(i));
        hashFileQuad8 <<  quad8Temp << endl;
        averageReadsQuad8 += quad8Temp;

        int quad9Temp = quadProbTable9.insert(streamers.at(i));
        hashFileQuad9 <<  quad9Temp << endl;
        averageReadsQuad9 += quad9Temp;

        int quad10Temp = quadProbTable10.insert(streamers.at(i));
        hashFileQuad10 <<  quad10Temp << endl;
        averageReadsQuad10 += quad10Temp;

    }

    hashFileSep1.close();
    hashFileSep2.close();
    hashFileSep3.close();
    hashFileSep4.close();
    hashFileSep5.close();
    hashFileSep6.close();
    hashFileSep7.close();
    hashFileSep8.close();
    hashFileSep9.close();
    hashFileSep10.close();


    // calculate and print averages
    cout << "AVERAGE READS FOR EACH TABLE" << endl;
    cout << "Separate Chaining (1-10):" << endl;
    cout << (averageReadsSep1 / streamers.size()) << endl;
    cout << (averageReadsSep2 / streamers.size()) << endl;
    cout << (averageReadsSep3 / streamers.size()) << endl;
    cout << (averageReadsSep4 / streamers.size()) << endl;
    cout << (averageReadsSep5 / streamers.size()) << endl;
    cout << (averageReadsSep6 / streamers.size()) << endl;
    cout << (averageReadsSep7 / streamers.size()) << endl;
    cout << (averageReadsSep8 / streamers.size()) << endl;
    cout << (averageReadsSep9 / streamers.size()) << endl;
    cout << (averageReadsSep10 / streamers.size()) << endl;

    cout << endl;

    cout << "Open Addressing (1-10):" << endl;
    cout << (averageReadsQuad1 / streamers.size()) << endl;
    cout << (averageReadsQuad2 / streamers.size()) << endl;
    cout << (averageReadsQuad3 / streamers.size()) << endl;
    cout << (averageReadsQuad4 / streamers.size()) << endl;
    cout << (averageReadsQuad5 / streamers.size()) << endl;
    cout << (averageReadsQuad6 / streamers.size()) << endl;
    cout << (averageReadsQuad7 / streamers.size()) << endl;
    cout << (averageReadsQuad8 / streamers.size()) << endl;
    cout << (averageReadsQuad9 / streamers.size()) << endl;
    cout << (averageReadsQuad10 / streamers.size()) << endl;

    cout << endl;

    // printing out the size of the open addressing tables after insertion
    cout << "Open Addressing Table Sizes (After Insertion):" << endl;
    cout << quadProbTable1.getTableSize() << endl;
    cout << quadProbTable2.getTableSize() << endl;
    cout << quadProbTable3.getTableSize() << endl;
    cout << quadProbTable4.getTableSize() << endl;
    cout << quadProbTable5.getTableSize() << endl;
    cout << quadProbTable6.getTableSize() << endl;
    cout << quadProbTable7.getTableSize() << endl;
    cout << quadProbTable8.getTableSize() << endl;
    cout << quadProbTable9.getTableSize() << endl;
    cout << quadProbTable10.getTableSize() << endl;



}
