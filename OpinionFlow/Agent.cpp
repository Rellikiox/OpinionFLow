#include "Agent.h"


Agent::Agent(void) {

}

Agent::~Agent(void) {

}

Agent::Agent(unsigned int id) {
	this->agent_id = id;
}

bool Agent::AddAlignment(unsigned int alignment_id, double alignment) {
	AlignIter iter = alignments.find(alignment_id);

	if(iter != alignments.end())
		return false;

	alignments[alignment_id] = alignment;

	return true;
}

bool Agent::AddInfluencer(Agent * influencer, double respect_level) {
	AgentIter iter = influences.find(influencer->GetId());

	if(iter != influences.end())
		return false;

	AgentInfluence ai;
	ai.influencer = influencer;
	ai.respect = respect_level;

	influences[influencer->GetId()] = ai;

	return true;
}

bool Agent::ModifyInfluencer(Agent * influencer, double respect_level){
	AgentIter iter = influences.find(influencer->GetId());

	if(iter == influences.end())
		return false;

	influences[influencer->GetId()].respect = respect_level;

	return true;
}

void Agent::UpdateAlignment(unsigned int alignment_id) {
	double crowd_alignment = 0.0;
	int crowd_size = influences.size();

	for each (pair<unsigned int, AgentInfluence> agent in influences) {
		crowd_alignment += agent.second.influencer->alignments[alignment_id] * agent.second.respect;
	}
	crowd_alignment /= crowd_size;

	double force = crowd_alignment - alignments[alignment_id];
}