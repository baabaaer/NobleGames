// Fill out your copyright notice in the Description page of Project Settings.


#include "AakmalBTComps.h"

AakmalBTComps::AakmalBTComps()
{
}

AakmalBTComps::~AakmalBTComps()
{
}

void BTCompositeNodes::addChild(BTNodes* child)
{
	children.emplace_back(child);
}

BTNodeStatus BTSelector::activity()
{
	for (BTNodes* child : getChildren()) {
		switch (btNodeStatus) 
		{ case FAILS: 
			continue;
		  case RUNS:
			return RUNS;
			continue;
		  case SUCCEEDS:
			return SUCCEEDS;
		  default:
			continue;
		}
	}
	return BTNodeStatus();
}

BTNodeStatus BTSequence::activity()
{
	for (BTNodes* child : getChildren()) {
		switch (btNodeStatus)
		{
		case FAILS:
			break;
		case RUNS:
			return RUNS;
			continue;
		case SUCCEEDS:
			return SUCCEEDS;
		default:
			continue;
		}
	}
	return BTNodeStatus();
}
