// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#include <list>
#include "CoreMinimal.h"

/**
 * 
 */
class NOBLEGAMES_API AakmalBTComps
{
public:
	AakmalBTComps();
	~AakmalBTComps();
};

enum BTNodeStatus { FAILS, RUNS, SUCCEEDS };

class BTNodes {
	protected:
		virtual BTNodeStatus activity() = 0;
	public:
		BTNodeStatus btNodeStatus;
};

class BTCompositeNodes : public BTNodes {
	public:
		std::list<BTNodes*> children;
		const std::list<BTNodes*>& getChildren() const
		{
			return children;
		}
	private:
		void addChild(BTNodes* child);
};

class BTSelector :public BTCompositeNodes {
public:
	virtual BTNodeStatus activity() override;
};

class BTSequence :public BTCompositeNodes {
public:
	virtual BTNodeStatus activity() override;
};