
#include "FuncionesExportacion.h"
#include <ctime>
#include <fstream>
#include "Snap.h"
#include <iostream>

typedef PNGraph SnapGraph;

void GraphML(SnapGraph g);
void GEXF(SnapGraph g);
void GDF(SnapGraph g);
void JSON(SnapGraph g);

int main()
{
    SnapGraph dg = TSnap::LoadEdgeList<SnapGraph>("email-Eu-core.txt", 0, 1);

    //GraphML

    auto start = high_resolution_clock::now();
    
    GraphML(dg);
    
    auto stop = high_resolution_clock::now();
    auto durationSegGML = duration_cast<seconds>(stop - start);
    auto durationMilliGML = duration_cast<milliseconds>(stop - start);

    cout << "Tiempo archivo GraphML" << durationMilliGML.count() << " milisegundos\n";

    cout << "\n";

    //GEXF

    auto start1 = high_resolution_clock::now();

    GEXF(dg);

    auto stop1 = high_resolution_clock::now();
    auto durationSegGEXF = duration_cast<seconds>(stop1 - start1);
    auto durationMilliGEXF = duration_cast<milliseconds>(stop1 - start1);

  
    cout << "Tiempo archivo GEXF" << durationMilliGEXF.count() << " milisegundos\n";

    cout << "\n";

    //GDF

    auto start2 = high_resolution_clock::now();

    GDF(dg);

    auto stop2 = high_resolution_clock::now();
    auto durationSegGDF = duration_cast<seconds>(stop2 - start2);
    auto durationMilliGDF = duration_cast<milliseconds>(stop2 - start2);


    cout << "Tiempo archivo GDF" << durationMilliGDF.count() << " milisegundos\n";

    cout << "\n";

    //JSON

    auto start3 = high_resolution_clock::now();

    JSON(dg);

    auto stop3 = high_resolution_clock::now();
    auto durationSegJSON = duration_cast<seconds>(stop3 - start3);
    auto durationMilliJSON = duration_cast<milliseconds>(stop3 - start3);


    cout << "Tiempo archivo JSON" << durationMilliJSON.count() << " milisegundos\n";

    return 0;
}

