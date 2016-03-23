/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRGRAPHICSWINDOWNODE_H_
#define VRGRAPHICSWINDOWNODE_H_

#include "display/VRDisplayNode.h"
#include "math/VRRect.h"
#include "display/nodes/graphics/structure/VRTile.h"

namespace MinVR {

class VRGraphicsWindowNode : public VRDisplayNode {
public:
	virtual ~VRGraphicsWindowNode();

	virtual void render(VRRenderHandler& renderer);
	virtual void waitForRenderToComplete();
	virtual void displayTheFinishedRendering();

	const VRRect& getRect() const;
	void setRect(const VRRect& rect);

protected:
	VRGraphicsWindowNode(const VRRect& rect);
	virtual void updateState(VRRenderState& state);

	virtual std::string getContextType() = 0;
	virtual void setCurrentContext() = 0;
	virtual void clearCurrentContext() = 0;
	virtual void swapBuffers() = 0;
	virtual void flush() = 0;
	virtual void finish() = 0;

private:
	VRRect m_rect;
};

} /* namespace MinVR */

#endif /* VRGRAPHICSWINDOWNODE_H_ */
