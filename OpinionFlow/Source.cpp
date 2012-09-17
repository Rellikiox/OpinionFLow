
#include "Agent.h"

#include <iostream>
using namespace std;

double opchange(double);
double randoffset(double);

int main(void) {

	Agent * agente_1 = new Agent(0);
	Agent * agente_2 = new Agent(1);

	agente_1->SetInfluencer(agente_2, 1);
	agente_2->SetInfluencer(agente_1, -1);

	agente_1->SetAlignment(0, 0, opchange, randoffset);
	agente_2->SetAlignment(0, 1, opchange, randoffset);

	while(true){
		
		cout << "A1: " << agente_1->GetAlignment(0) << endl;
		cout << "A2: " << agente_2->GetAlignment(0) << endl;
		agente_1->UpdateAlignment(0);
		system("pause");
		
		
		cout << "A1: " << agente_1->GetAlignment(0) << endl;
		cout << "A2: " << agente_2->GetAlignment(0) << endl;
		agente_2->UpdateAlignment(0);
		system("pause");
	}

	return 0;
}

double opchange(double x) {
	return x/5;
}

double randoffset(double x) {
	return (rand()%200) / 10000.0 - 0.01;
}
