#pragma once

class IFormatList
{
public:
	IFormatList();
	virtual ~IFormatList();

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
};