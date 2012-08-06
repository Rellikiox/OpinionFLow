#pragma once

#include <map>
using namespace std;

class Agent;

struct AgentInfluence {
	Agent * influencer;
	double respect;
};

class Agent {
public:
	Agent(void);
	~Agent(void);

	Agent(unsigned int id);

	bool AddAlignment(unsigned int alignment_id, double alignment);
	bool AddInfluencer(Agent * influencer, double respect_level);

	bool ModifyInfluencer(Agent * influencer, double respect_level);

	void UpdateAlignment(unsigned int alignment_id);

	double GetAlignment(unsigned int alignment_id);

	unsigned int GetId(){
		return agent_id;
	}

private:
	unsigned int agent_id;
	map<unsigned int, double> alignments;
	typedef map<unsigned int, double>::iterator AlignIter;
	map<unsigned int, AgentInfluence> influences;
	typedef map<unsigned int, AgentInfluence>::iterator AgentIter;
};

