#pragma once

#include <map>
using namespace std;

class Agent;

struct TopicOpinion {
	double alignment;
	double (*opinionChange)(double);
	double (*randomOffset)(double);
};

struct AgentInfluence {
	Agent * influencer;
	double respect;
};

class Agent {
public:
	Agent(void);
	~Agent(void);

	Agent(unsigned int id);

	bool SetAlignment(unsigned int alignment_id, double alignment, double (*change_function)(double), double (*randoffset_function)(double));
	bool SetInfluencer(Agent * influencer, double respect_level);

	void UpdateAlignment(unsigned int alignment_id);

	double GetAlignment(unsigned int alignment_id);

	unsigned int GetId(){
		return agent_id;
	}

private:
	unsigned int agent_id;
	map<unsigned int, TopicOpinion> alignments;
	typedef map<unsigned int, TopicOpinion>::iterator AlignIter;
	map<unsigned int, AgentInfluence> influences;
	typedef map<unsigned int, AgentInfluence>::iterator AgentIter;
};

