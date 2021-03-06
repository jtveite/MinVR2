/*
 * Copyright Regents of the University of Minnesota, 2015.  This software is released under the following license: http://opensource.org/licenses/GPL-2.0
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Ben Knorlein
 */


#ifndef VROPENVRNODE_H
#define VROPENVRNODE_H

#include <display/VRDisplayNode.h>
#include <main/VRFactory.h>
#include <plugin/VRPlugin.h>
#include <math/VRMath.h>

#include <openvr.h>

#include "VROpenVRInputDevice.h"

struct FramebufferDesc
{
	unsigned int m_nDepthBufferId;
	unsigned int m_nRenderTextureId;
	unsigned int m_nRenderFramebufferId;
	unsigned int m_nResolveTextureId;
	unsigned int m_nResolveFramebufferId;
};

namespace MinVR {
  
/** OpenVR Implementation for the MinVR VRDisplayNode abstraction.
 */
class VROpenVRNode : public VRDisplayNode {
public:
	PLUGIN_API VROpenVRNode(VRMainInterface *vrMain, const std::string &name, double near, double far) ;
	
	PLUGIN_API virtual ~VROpenVRNode();

	PLUGIN_API virtual std::string getType() { return "VROpenVRNode"; }

	PLUGIN_API virtual void render(VRDataIndex *renderState, VRRenderHandler *renderHandler);

	//virtual void onVREvent(const std::string &eventName, VRDataIndex *eventData);
	PLUGIN_API static VRDisplayNode* create(VRMainInterface *vrMain, VRDataIndex *config, const std::string &nameSpace);
	
private:
	VROpenVRInputDevice * _inputDev;

	bool isInitialized;
	vr::IVRSystem *m_pHMD;
	vr::IVRRenderModels *m_pRenderModels;
	FramebufferDesc leftEyeDesc;
	FramebufferDesc rightEyeDesc;
	uint32_t m_nRenderWidth;
	uint32_t m_nRenderHeight;
	
	VRMatrix4 m_mat4ProjectionLeft;
	VRMatrix4 m_mat4ProjectionRight;
	VRMatrix4 m_mat4eyePosLeft;
	VRMatrix4 m_mat4eyePosRight;

	double m_fNearClip;
	double m_fFarClip;

	VRMatrix4 GetHMDMatrixProjectionEye( vr::Hmd_Eye nEye );
	VRMatrix4 GetHMDMatrixPoseEye( vr::Hmd_Eye nEye );

	bool SetupStereoRenderTargets();
	bool CreateFrameBuffer( int nWidth, int nHeight, FramebufferDesc &framebufferDesc );
};

} // end namespace

#endif
