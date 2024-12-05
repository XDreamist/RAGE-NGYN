// Copyright © 2024 XDreamist. All rights reserved.
#pragma once


class Test
{
public:
	virtual bool initialize() = 0;
	virtual void run() = 0;
	virtual void shutDown() = 0;
};