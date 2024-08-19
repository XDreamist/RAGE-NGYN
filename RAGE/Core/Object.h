#pragma once



class RObject
{
public:

	RObject();
	~RObject();

	void Begin();
	void Loop();

	bool shouldLoop = false;
};