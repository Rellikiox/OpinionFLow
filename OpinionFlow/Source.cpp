
#include "Agent.h"

#include <iostream>
using namespace std;

double opchange(double);
double randoffset(double);

int main(void) {

	Agent * agente_1 = new Agent(0);
	Agent * agente_2 = new Agent(1);

	agente_1->SetInfluencer(agente_2, 1);
	agente_2->SetInfluencer(agente_1, 0);

	agente_1->SetAlignment(0, 0, opchange, randoffset);
	agente_2->SetAlignment(0, 1, opchange, randoffset);

	while(true){
		agente_1->UpdateAlignment(0);
		cout << "1: " << agente_1->GetAlignment(0) << endl;
		cout << "2: " << agente_2->GetAlignment(0) << endl;

		system("pause");
		
		agente_2->UpdateAlignment(0);
		cout << "1: " << agente_1->GetAlignment(0) << endl;
		cout << "2: " << agente_2->GetAlignment(0) << endl;

		system("pause");
	}

	return 0;
}

double opchange(double x) {
	return x;
}

double randoffset(double x) {
	return 0; //(rand()%200) / 10000.0 - 0.01;
}
