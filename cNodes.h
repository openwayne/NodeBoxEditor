#ifndef _cNodes_h_included_
#define _cNodes_h_included_

#include <irrlicht.h>
#include "define.h"
#include <iostream>

using namespace irr;
using namespace gui;
using namespace scene;
using namespace core;
using namespace video;

class cNode
{
public:
	cNode(IrrlichtDevice* mdevice,ed_data* n_ed);
	bool load(wchar_t* input);
	bool save(wchar_t* output);
	bool switchFocus(ISceneNode* hit);
	void addNodeBox();
	void updateTexts();
	void changeID(int n_id);
	void resize(int side, double dir); //0:Up 1:Left 2:Right 3:Down
private:
	ed_data* editor;
	int id;
	int number;
	IMeshSceneNode* boxes[50];

	IVideoDriver* driver;
	IrrlichtDevice* device;
	ISceneManager* smgr;
};

#endif