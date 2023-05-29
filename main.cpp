#include <bits/stdc++.h>

#include "ds/Graph.h"


void startingScreen();
void menu();
void changeGraph();
void changeGraphNumber();
void backtrakingAlgorithm();
void triangularAlgorithm();
void otherHeuristics();

void clearScreen();
void wait();



void readToyGraph(Graph &g, const string &filename)
{
	ifstream input(filename);
	int V;
	input >> V;
	input.ignore(numeric_limits<streamsize>::max(), '\n');
	g = Graph(V);
	string line;
	getline(input, line); // skip first line

	while (getline(input, line)) {
		stringstream ss(line);
		int src, dest;
		double weight;
		ss >> src;
		ss.ignore();
		ss >> dest;
		ss.ignore();
		ss >> weight;
		g.addEdge(src, dest, weight);
	}
}



bool firstTime, graphToy;
int graphNumber;



int main()
{
    system("Color 0B");

	/*Graph g1, g2, g3;
	readToyGraph(g1, "../csv/Toy-Graphs/shipping.csv");
	readToyGraph(g2, "../csv/Toy-Graphs/stadiums.csv");
	readToyGraph(g3, "../csv/Toy-Graphs/tourism.csv");
	cout << "Shipping: " << g1.tsp_exact() << endl;
	cout << "Stadiums: " << g2.tsp_exact() << endl;
	cout << "Tourism: " << g3.tsp_exact() << endl;*/

    firstTime = true;

    startingScreen();
    changeGraph();


	return 0;
}

void startingScreen(){

    clearScreen();
    std::cout << "  ===========================================================================  " << std::endl;
    std::cout << R"(//                                                                           \\)" << std::endl;
    std::cout << "||    ##        ##  ######  ##      #####    #####  ####     ####  ######    ||" << std::endl;
    std::cout << "||    ##   ##   ##  ##      ##     ##   ##  ##  ##  ## ##   ## ##  ##        ||" << std::endl;
    std::cout << "||    ##   ##   ##  ####    ##     ##       ##  ##  ##  ## ##  ##  ####      ||" << std::endl;
    std::cout << "||     ## #### ##   ##      ##     ##   ##  ##  ##  ##   ###   ##  ##        ||" << std::endl;
    std::cout << "||      ###  ###    ######  #####   #####   #####   ##         ##  ######    ||" << std::endl;
    std::cout << "||                                                                           ||" << std::endl;
    std::cout << "||                                       .                                   ||" << std::endl;
    std::cout << "||              . .                     -:-             .  .  .              ||" << std::endl;
    std::cout << R"(||            .'.:,'.        .  .  .     ' .           . \ | / .             ||)" << std::endl;
    std::cout << R"(||            .'.;.`.       ._. ! ._.       \          .__\:/__.             ||)" << std::endl;
    std::cout << R"(||             `,:.'         ._\!/_.                      .';`.      . ' .   ||)" << std::endl;
    std::cout << "||             ,'             . ! .        ,.,      ..======..       .:.     ||" << std::endl;
    std::cout << "||            ,                 .         ._!_.     ||::: : | .        ',    ||" << std::endl;
    std::cout << "||     .====.,                  .           ;  .~.===: : : :|   ..===.       ||" << std::endl;
    std::cout << R"(||     |.::'||      .=====.,    ..=======.~,   |"|: :|::::::|   ||:::|=====| ||)" << std::endl;
    std::cout << R"(||  ___| :::|!__.,  |:::::|!_,   |: :: ::|"|l_l|"|:: |:;;:::|___!| ::|: : :| ||)" << std::endl;
    std::cout << R"(|| |: :|::: |:: |!__|; :: |: |===::: :: :|"||_||"| : |: :: :|: : |:: |:::::| ||)" << std::endl;
    std::cout << R"(|| |:::| _::|: :|:::|:===:|::|:::|:===F=:|"!/|\!"|::R|:====:|::_:|: :|:7__:| ||)" << std::endl;
    std::cout << R"(|| !_[]![_]_!_[]![]_!_[__]![]![_]![_][I_]!//_:_\\![]I![_][_]!_[_]![]_!_[__]! ||)" << std::endl;
    std::cout << R"(|| -----------------------------------"---''''```---"----------------------- ||)" << std::endl;
    std::cout << "|| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |= _ _:_ _ =| _ _ _ _ _ _ _ _ _ _ _ _ ||" << std::endl;
    std::cout << R"(||    D - M - P         \ō͡≡o˞̶        |=    :    =|                G05_6    ||)" << std::endl;
    std::cout << "|| ____________________________________L___________J________________________ ||" << std::endl;
    std::cout << "|| ------------------------------------------------------------------------- ||" << std::endl;
    std::cout << "||                                                                           ||" << std::endl;
    std::cout << "||                      --- Press Enter to Continue ---                      ||" << std::endl;
    std::cout << R"(\\                                                                           //)" << std::endl;
    std::cout << "  ===========================================================================  " << std::endl;
    wait();
}


void changeGraph(){

    string option;


    if(firstTime){
        do {
            clearScreen();
            std::cout << "  ===========================================================================  " << std::endl;
            std::cout << R"(//                                                                           \\)" << std::endl;
            std::cout << "||             #####  #####   ######   #####   ##  ######  ##  ##            ||" << std::endl;
            std::cout << "||            ##      ##  ##  ##      ##   ##  ##  ##      ##  ##            ||" << std::endl;
            std::cout << "||             ####   #####   ####    ##       ##  ####     ####             ||" << std::endl;
            std::cout << "||                ##  ##      ##      ##   ##  ##  ##        ##              ||" << std::endl;
            std::cout << "||            #####   ##      ######   #####   ##  ##        ##              ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||   ######  ##  ##  ######        #####    #####    ####   #####   ##  ##   ||" << std::endl;
            std::cout << "||     ##    ##  ##  ##           ###       ##  ##  ##  ##  ##  ##  ##  ##   ||" << std::endl;
            std::cout << "||     ##    ######  ####         ##  ####  #####   ######  #####   ######   ||" << std::endl;
            std::cout << "||     ##    ##  ##  ##           ##   ##   ##  ##  ##  ##  ##      ##  ##   ||" << std::endl;
            std::cout << "||     ##    ##  ##  ######        #####    ##  ##  ##  ##  ##      ##  ##   ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||    [1] Toy Graphs                                                         ||" << std::endl;
            std::cout << "||    [2] Real Life Graphs                                                   ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << R"(\\                                                                           //)" << std::endl;
            std::cout << "  ===========================================================================  " << std::endl;
            wait();

            std::cout << "  > ";
            std::getline(std::cin >> std::ws, option);

            if (option == "1") {
                graphToy = true;
                changeGraphNumber();
            } else if (option == "2") {
                graphToy = false;
                changeGraphNumber();
            } else {
                clearScreen();
                std::cout << "  > Invalid Option!" << std::endl;
                std::cout << "  > Press Enter to Continue..." << std::endl;
                wait();
            }
        }while(option != "1" && option != "2");
    }
    else {
        do {
            clearScreen();
            std::cout << "  ===========================================================================  " << std::endl;
            std::cout << R"(//                                                                           \\)"
                      << std::endl;
            std::cout << "||             #####  #####   ######   #####   ##  ######  ##  ##            ||" << std::endl;
            std::cout << "||            ##      ##  ##  ##      ##   ##  ##  ##      ##  ##            ||" << std::endl;
            std::cout << "||             ####   #####   ####    ##       ##  ####     ####             ||" << std::endl;
            std::cout << "||                ##  ##      ##      ##   ##  ##  ##        ##              ||" << std::endl;
            std::cout << "||            #####   ##      ######   #####   ##  ##        ##              ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||   ######  ##  ##  ######        #####    #####    ####   #####   ##  ##   ||" << std::endl;
            std::cout << "||     ##    ##  ##  ##           ###       ##  ##  ##  ##  ##  ##  ##  ##   ||" << std::endl;
            std::cout << "||     ##    ######  ####         ##  ####  #####   ######  #####   ######   ||" << std::endl;
            std::cout << "||     ##    ##  ##  ##           ##   ##   ##  ##  ##  ##  ##      ##  ##   ||" << std::endl;
            std::cout << "||     ##    ##  ##  ######        #####    ##  ##  ##  ##  ##      ##  ##   ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||    [1] Toy Graphs                                                         ||" << std::endl;
            std::cout << "||    [2] Real Life Graphs                                                   ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                                                                [0] Back   ||" << std::endl;
            std::cout << R"(\\                                                                           //)"
                      << std::endl;
            std::cout << "  ===========================================================================  " << std::endl;
            wait();

            std::cout << "  > ";
            std::getline(std::cin >> std::ws, option);

            if (option == "1") {
                graphToy = true;
                changeGraphNumber();
            } else if (option == "2") {
                graphToy = false;
                changeGraphNumber();
            } else if (option == "0") {
                menu();
            } else {
                clearScreen();
                std::cout << "  > Invalid Option!" << std::endl;
                std::cout << "  > Press Enter to Continue..." << std::endl;
                wait();
            }
        } while (option != "1" && option != "2" && option != "0");
    }
}


void menu(){

    string option;

    do {
        clearScreen();
        std::cout << "  ===========================================================================  " << std::endl;
        std::cout << R"(//                                                                           \\)" << std::endl;
        std::cout << "||                           ######   #####  #####                           ||" << std::endl;
        std::cout << "||                             ##    ##      ##  ##                          ||" << std::endl;
        std::cout << "||                  #####      ##     ####   #####     #####                 ||" << std::endl;
        std::cout << "||                             ##        ##  ##                              ||" << std::endl;
        std::cout << "||                             ##    #####   ##                              ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||    #####   #####    #####  #####   ##      ######  ####   ####   #####    ||" << std::endl;
        std::cout << "||    ##  ##  ##  ##  ##  ##  ##  ##  ##      ##      ## ## ## ##  ##        ||" << std::endl;
        std::cout << "||    #####   #####   ##  ##  #####   ##      ####    ##  ###  ##   ####     ||" << std::endl;
        std::cout << "||    ##      ##  ##  ##  ##  ##  ##  ##      ##      ##       ##      ##    ||" << std::endl;
        std::cout << "||    ##      ##  ##  #####   #####   ######  ######  ##       ##  #####     ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        if(graphToy){
            std::cout << "||                            --- Toy Graph ---                              ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                            --- Graph nº "<< graphNumber <<" ---                             ||" << std::endl;
        }
        else{
            std::cout << "||                         --- Real Life Graph ---                           ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||                            --- Graph nº "<< graphNumber <<" ---                             ||" << std::endl;
        }
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||    [1] Backtracking Algorithm                                             ||" << std::endl;
        std::cout << "||    [2] Triangular Approximation Heuristic                                 ||" << std::endl;
        std::cout << "||    [3] Other Heuristic                                                    ||" << std::endl;
        std::cout << "||    [4] Change Graph                                                       ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                [0] Exit   ||" << std::endl;
        std::cout << R"(\\                                                                           //)" << std::endl;
        std::cout << "  ===========================================================================  " << std::endl;
        wait();

        std::cout << "  > ";
        std::getline(std::cin >> std::ws, option);

        if (option == "1") {
            backtrakingAlgorithm();
        } else if (option == "2") {
            triangularAlgorithm();
        } else if (option == "3") {
            otherHeuristics();
        } else if (option == "4"){
            changeGraph();
        } else if (option == "0"){
            break;
        } else {
            clearScreen();
            std::cout << "  > Invalid Option!" << std::endl;
            std::cout << "  > Press Enter to Continue..." << std::endl;
            wait();
        }
    }while(option != "1" && option != "2" && option != "3" && option != "4" && option != "0");

}

void changeGraphNumber(){
    string option;
    do {
        clearScreen();
        std::cout << "  ===========================================================================  " << std::endl;
        std::cout << R"(//                                                                           \\)"
                  << std::endl;


        if(graphToy){
            std::cout << "||                           ######   #####  ##  ##                          ||" << std::endl;
            std::cout << "||                             ##    ##  ##  ##  ##                          ||" << std::endl;
            std::cout << "||                             ##    ##  ##   ####                           ||" << std::endl;
            std::cout << "||                             ##    ##  ##    ##                            ||" << std::endl;
            std::cout << "||                             ##    #####     ##                            ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||               #####    #####    ####   #####   ##  ##   #####             ||" << std::endl;
            std::cout << "||              ###       ##  ##  ##  ##  ##  ##  ##  ##  ##                 ||" << std::endl;
            std::cout << "||              ##  ####  #####   ######  #####   ######   ####              ||" << std::endl;
            std::cout << "||              ##   ##   ##  ##  ##  ##  ##      ##  ##      ##             ||" << std::endl;
            std::cout << "||               #####    ##  ##  ##  ##  ##      ##  ##  #####              ||" << std::endl;
        }
        else{
            std::cout << "||      #####   ######   ####   ##           ##      ##  ######  ######      ||" << std::endl;
            std::cout << "||      ##  ##  ##      ##  ##  ##           ##      ##  ##      ##          ||" << std::endl;
            std::cout << "||      #####   ####    ######  ##           ##      ##  ####    ####        ||" << std::endl;
            std::cout << "||      ##  ##  ##      ##  ##  ##           ##      ##  ##      ##          ||" << std::endl;
            std::cout << "||      ##  ##  ######  ##  ##  ######       ######  ##  ##      ######      ||" << std::endl;
            std::cout << "||                                                                           ||" << std::endl;
            std::cout << "||               #####    #####    ####   #####   ##  ##   #####             ||" << std::endl;
            std::cout << "||              ###       ##  ##  ##  ##  ##  ##  ##  ##  ##                 ||" << std::endl;
            std::cout << "||              ##  ####  #####   ######  #####   ######   ####              ||" << std::endl;
            std::cout << "||              ##   ##   ##  ##  ##  ##  ##      ##  ##      ##             ||" << std::endl;
            std::cout << "||               #####    ##  ##  ##  ##  ##      ##  ##  #####              ||" << std::endl;
        }

        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||    [1] Graph - 1                                                          ||" << std::endl;
        std::cout << "||    [2] Graph - 2                                                          ||" << std::endl;
        std::cout << "||    [3] Graph - 3                                                          ||" << std::endl;
        std::cout << "||                                                                           ||" << std::endl;
        std::cout << "||                                                                [0] Back   ||" << std::endl;
        std::cout << R"(\\                                                                           //)"
                  << std::endl;
        std::cout << "  ===========================================================================  " << std::endl;
        wait();

        std::cout << "  > ";
        std::getline(std::cin >> std::ws, option);

        if (option == "1") {
            graphNumber = 1;
            firstTime = false;
            menu();
        } else if (option == "2") {
            graphNumber = 2;
            firstTime = false;
            menu();
        } else if (option == "3"){
            graphNumber = 3;
            firstTime = false;
            menu();
        } else if (option == "0") {
            changeGraph();
        } else {
            clearScreen();
            std::cout << "  > Invalid Option!" << std::endl;
            std::cout << "  > Press Enter to Continue..." << std::endl;
            wait();
        }
    } while (option != "1" && option != "2" && option != "3" && option != "0");
}



void clearScreen(){
    for (int i = 0; i < 50; i++) {
        std::cout << std::endl;
    }
}

void wait(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cin.get();
}
