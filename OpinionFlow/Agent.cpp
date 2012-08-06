#include "Agent.h"

#include <cassert>

Agent::Agent(void) {

}

Agent::~Agent(void) {

}

Agent::Agent(unsigned int id) {
	this->agent_id = id;
}

bool Agent::SetAlignment(unsigned int alignment_id, double alignment, double (*change_function)(double)) {

	assert(alignment >= -1.0);
	assert(alignment <= 1.0);

	alignments[alignment_id].alignment = alignment;
	alignments[alignment_id].opinionChange = change_function;

	return true;
}

bool Agent::SetInfluencer(Agent * influencer, double respect_level) {

	assert(respect_level >= -1.0);
	assert(respect_level <= 1.0);

	influences[influencer->GetId()].influencer = influencer;
	influences[influencer->GetId()].respect = respect_level;

	return true;
}

void Agent::UpdateAlignment(unsigned int alignment_id) {
	double crowd_alignment = 0.0;
	int crowd_size = influences.size();

	for each (pair<unsigned int, AgentInfluence> agent in influences) {
		crowd_alignment += agent.second.influencer->alignments[alignment_id].alignment * agent.second.respect;
	}
	crowd_alignment /= crowd_size;

	TopicOpinion topinion = alignments[alignment_id];

	double force = crowd_alignment - topinion.alignment;

	topinion.alignment += (*topinion.opinionChange)(force);

	if(topinion.alignment <= -1.0)
		topinion.alignment = -1.0;

	if(topinion.alignment >= 1.0)
		topinion.alignment = 1.0;
}

double Agent::GetAlignment(unsigned int alignment_id){
	AlignIter iter = alignments.find(alignment_id);

	if(iter == alignments.end())
		return iter->second.alignment;

	return 0.0;
}