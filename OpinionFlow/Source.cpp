
#include "Agent.h"

#include <iostream>
using namespace std;

int main(void) {

	Agent * agente_1 = new Agent(0);
	Agent * agente_2 = new Agent(1);

	agente_1->SetInfluencer(agente_2, 1);
	agente_2->SetInfluencer(agente_1, -1);
}