/*
BStone: A Source port of
Blake Stone: Aliens of Gold and Blake Stone: Planet Strike

Copyright (c) 1992-2013 Apogee Entertainment, LLC
Copyright (c) 2013-2019 Boris I. Bendovsky (bibendovsky@hotmail.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the
Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/


//
// OpenGL.
//


#include "bstone_ogl.h"


#ifdef GL_VERSION_1_0

PFNGLCULLFACEPROC glCullFace = nullptr;
PFNGLFRONTFACEPROC glFrontFace = nullptr;
PFNGLHINTPROC glHint = nullptr;
PFNGLLINEWIDTHPROC glLineWidth = nullptr;
PFNGLPOINTSIZEPROC glPointSize = nullptr;
PFNGLPOLYGONMODEPROC glPolygonMode = nullptr;
PFNGLSCISSORPROC glScissor = nullptr;
PFNGLTEXPARAMETERFPROC glTexParameterf = nullptr;
PFNGLTEXPARAMETERFVPROC glTexParameterfv = nullptr;
PFNGLTEXPARAMETERIPROC glTexParameteri = nullptr;
PFNGLTEXPARAMETERIVPROC glTexParameteriv = nullptr;
PFNGLTEXIMAGE1DPROC glTexImage1D = nullptr;
PFNGLTEXIMAGE2DPROC glTexImage2D = nullptr;
PFNGLDRAWBUFFERPROC glDrawBuffer = nullptr;
PFNGLCLEARPROC glClear = nullptr;
PFNGLCLEARCOLORPROC glClearColor = nullptr;
PFNGLCLEARSTENCILPROC glClearStencil = nullptr;
PFNGLCLEARDEPTHPROC glClearDepth = nullptr;
PFNGLSTENCILMASKPROC glStencilMask = nullptr;
PFNGLCOLORMASKPROC glColorMask = nullptr;
PFNGLDEPTHMASKPROC glDepthMask = nullptr;
PFNGLDISABLEPROC glDisable = nullptr;
PFNGLENABLEPROC glEnable = nullptr;
PFNGLFINISHPROC glFinish = nullptr;
PFNGLFLUSHPROC glFlush = nullptr;
PFNGLBLENDFUNCPROC glBlendFunc = nullptr;
PFNGLLOGICOPPROC glLogicOp = nullptr;
PFNGLSTENCILFUNCPROC glStencilFunc = nullptr;
PFNGLSTENCILOPPROC glStencilOp = nullptr;
PFNGLDEPTHFUNCPROC glDepthFunc = nullptr;
PFNGLPIXELSTOREFPROC glPixelStoref = nullptr;
PFNGLPIXELSTOREIPROC glPixelStorei = nullptr;
PFNGLREADBUFFERPROC glReadBuffer = nullptr;
PFNGLREADPIXELSPROC glReadPixels = nullptr;
PFNGLGETBOOLEANVPROC glGetBooleanv = nullptr;
PFNGLGETDOUBLEVPROC glGetDoublev = nullptr;
PFNGLGETERRORPROC glGetError = nullptr;
PFNGLGETFLOATVPROC glGetFloatv = nullptr;
PFNGLGETINTEGERVPROC glGetIntegerv = nullptr;
PFNGLGETSTRINGPROC glGetString = nullptr;
PFNGLGETTEXIMAGEPROC glGetTexImage = nullptr;
PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv = nullptr;
PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv = nullptr;
PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv = nullptr;
PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv = nullptr;
PFNGLISENABLEDPROC glIsEnabled = nullptr;
PFNGLDEPTHRANGEPROC glDepthRange = nullptr;
PFNGLVIEWPORTPROC glViewport = nullptr;
PFNGLNEWLISTPROC glNewList = nullptr;
PFNGLENDLISTPROC glEndList = nullptr;
PFNGLCALLLISTPROC glCallList = nullptr;
PFNGLCALLLISTSPROC glCallLists = nullptr;
PFNGLDELETELISTSPROC glDeleteLists = nullptr;
PFNGLGENLISTSPROC glGenLists = nullptr;
PFNGLLISTBASEPROC glListBase = nullptr;
PFNGLBEGINPROC glBegin = nullptr;
PFNGLBITMAPPROC glBitmap = nullptr;
PFNGLCOLOR3BPROC glColor3b = nullptr;
PFNGLCOLOR3BVPROC glColor3bv = nullptr;
PFNGLCOLOR3DPROC glColor3d = nullptr;
PFNGLCOLOR3DVPROC glColor3dv = nullptr;
PFNGLCOLOR3FPROC glColor3f = nullptr;
PFNGLCOLOR3FVPROC glColor3fv = nullptr;
PFNGLCOLOR3IPROC glColor3i = nullptr;
PFNGLCOLOR3IVPROC glColor3iv = nullptr;
PFNGLCOLOR3SPROC glColor3s = nullptr;
PFNGLCOLOR3SVPROC glColor3sv = nullptr;
PFNGLCOLOR3UBPROC glColor3ub = nullptr;
PFNGLCOLOR3UBVPROC glColor3ubv = nullptr;
PFNGLCOLOR3UIPROC glColor3ui = nullptr;
PFNGLCOLOR3UIVPROC glColor3uiv = nullptr;
PFNGLCOLOR3USPROC glColor3us = nullptr;
PFNGLCOLOR3USVPROC glColor3usv = nullptr;
PFNGLCOLOR4BPROC glColor4b = nullptr;
PFNGLCOLOR4BVPROC glColor4bv = nullptr;
PFNGLCOLOR4DPROC glColor4d = nullptr;
PFNGLCOLOR4DVPROC glColor4dv = nullptr;
PFNGLCOLOR4FPROC glColor4f = nullptr;
PFNGLCOLOR4FVPROC glColor4fv = nullptr;
PFNGLCOLOR4IPROC glColor4i = nullptr;
PFNGLCOLOR4IVPROC glColor4iv = nullptr;
PFNGLCOLOR4SPROC glColor4s = nullptr;
PFNGLCOLOR4SVPROC glColor4sv = nullptr;
PFNGLCOLOR4UBPROC glColor4ub = nullptr;
PFNGLCOLOR4UBVPROC glColor4ubv = nullptr;
PFNGLCOLOR4UIPROC glColor4ui = nullptr;
PFNGLCOLOR4UIVPROC glColor4uiv = nullptr;
PFNGLCOLOR4USPROC glColor4us = nullptr;
PFNGLCOLOR4USVPROC glColor4usv = nullptr;
PFNGLEDGEFLAGPROC glEdgeFlag = nullptr;
PFNGLEDGEFLAGVPROC glEdgeFlagv = nullptr;
PFNGLENDPROC glEnd = nullptr;
PFNGLINDEXDPROC glIndexd = nullptr;
PFNGLINDEXDVPROC glIndexdv = nullptr;
PFNGLINDEXFPROC glIndexf = nullptr;
PFNGLINDEXFVPROC glIndexfv = nullptr;
PFNGLINDEXIPROC glIndexi = nullptr;
PFNGLINDEXIVPROC glIndexiv = nullptr;
PFNGLINDEXSPROC glIndexs = nullptr;
PFNGLINDEXSVPROC glIndexsv = nullptr;
PFNGLNORMAL3BPROC glNormal3b = nullptr;
PFNGLNORMAL3BVPROC glNormal3bv = nullptr;
PFNGLNORMAL3DPROC glNormal3d = nullptr;
PFNGLNORMAL3DVPROC glNormal3dv = nullptr;
PFNGLNORMAL3FPROC glNormal3f = nullptr;
PFNGLNORMAL3FVPROC glNormal3fv = nullptr;
PFNGLNORMAL3IPROC glNormal3i = nullptr;
PFNGLNORMAL3IVPROC glNormal3iv = nullptr;
PFNGLNORMAL3SPROC glNormal3s = nullptr;
PFNGLNORMAL3SVPROC glNormal3sv = nullptr;
PFNGLRASTERPOS2DPROC glRasterPos2d = nullptr;
PFNGLRASTERPOS2DVPROC glRasterPos2dv = nullptr;
PFNGLRASTERPOS2FPROC glRasterPos2f = nullptr;
PFNGLRASTERPOS2FVPROC glRasterPos2fv = nullptr;
PFNGLRASTERPOS2IPROC glRasterPos2i = nullptr;
PFNGLRASTERPOS2IVPROC glRasterPos2iv = nullptr;
PFNGLRASTERPOS2SPROC glRasterPos2s = nullptr;
PFNGLRASTERPOS2SVPROC glRasterPos2sv = nullptr;
PFNGLRASTERPOS3DPROC glRasterPos3d = nullptr;
PFNGLRASTERPOS3DVPROC glRasterPos3dv = nullptr;
PFNGLRASTERPOS3FPROC glRasterPos3f = nullptr;
PFNGLRASTERPOS3FVPROC glRasterPos3fv = nullptr;
PFNGLRASTERPOS3IPROC glRasterPos3i = nullptr;
PFNGLRASTERPOS3IVPROC glRasterPos3iv = nullptr;
PFNGLRASTERPOS3SPROC glRasterPos3s = nullptr;
PFNGLRASTERPOS3SVPROC glRasterPos3sv = nullptr;
PFNGLRASTERPOS4DPROC glRasterPos4d = nullptr;
PFNGLRASTERPOS4DVPROC glRasterPos4dv = nullptr;
PFNGLRASTERPOS4FPROC glRasterPos4f = nullptr;
PFNGLRASTERPOS4FVPROC glRasterPos4fv = nullptr;
PFNGLRASTERPOS4IPROC glRasterPos4i = nullptr;
PFNGLRASTERPOS4IVPROC glRasterPos4iv = nullptr;
PFNGLRASTERPOS4SPROC glRasterPos4s = nullptr;
PFNGLRASTERPOS4SVPROC glRasterPos4sv = nullptr;
PFNGLRECTDPROC glRectd = nullptr;
PFNGLRECTDVPROC glRectdv = nullptr;
PFNGLRECTFPROC glRectf = nullptr;
PFNGLRECTFVPROC glRectfv = nullptr;
PFNGLRECTIPROC glRecti = nullptr;
PFNGLRECTIVPROC glRectiv = nullptr;
PFNGLRECTSPROC glRects = nullptr;
PFNGLRECTSVPROC glRectsv = nullptr;
PFNGLTEXCOORD1DPROC glTexCoord1d = nullptr;
PFNGLTEXCOORD1DVPROC glTexCoord1dv = nullptr;
PFNGLTEXCOORD1FPROC glTexCoord1f = nullptr;
PFNGLTEXCOORD1FVPROC glTexCoord1fv = nullptr;
PFNGLTEXCOORD1IPROC glTexCoord1i = nullptr;
PFNGLTEXCOORD1IVPROC glTexCoord1iv = nullptr;
PFNGLTEXCOORD1SPROC glTexCoord1s = nullptr;
PFNGLTEXCOORD1SVPROC glTexCoord1sv = nullptr;
PFNGLTEXCOORD2DPROC glTexCoord2d = nullptr;
PFNGLTEXCOORD2DVPROC glTexCoord2dv = nullptr;
PFNGLTEXCOORD2FPROC glTexCoord2f = nullptr;
PFNGLTEXCOORD2FVPROC glTexCoord2fv = nullptr;
PFNGLTEXCOORD2IPROC glTexCoord2i = nullptr;
PFNGLTEXCOORD2IVPROC glTexCoord2iv = nullptr;
PFNGLTEXCOORD2SPROC glTexCoord2s = nullptr;
PFNGLTEXCOORD2SVPROC glTexCoord2sv = nullptr;
PFNGLTEXCOORD3DPROC glTexCoord3d = nullptr;
PFNGLTEXCOORD3DVPROC glTexCoord3dv = nullptr;
PFNGLTEXCOORD3FPROC glTexCoord3f = nullptr;
PFNGLTEXCOORD3FVPROC glTexCoord3fv = nullptr;
PFNGLTEXCOORD3IPROC glTexCoord3i = nullptr;
PFNGLTEXCOORD3IVPROC glTexCoord3iv = nullptr;
PFNGLTEXCOORD3SPROC glTexCoord3s = nullptr;
PFNGLTEXCOORD3SVPROC glTexCoord3sv = nullptr;
PFNGLTEXCOORD4DPROC glTexCoord4d = nullptr;
PFNGLTEXCOORD4DVPROC glTexCoord4dv = nullptr;
PFNGLTEXCOORD4FPROC glTexCoord4f = nullptr;
PFNGLTEXCOORD4FVPROC glTexCoord4fv = nullptr;
PFNGLTEXCOORD4IPROC glTexCoord4i = nullptr;
PFNGLTEXCOORD4IVPROC glTexCoord4iv = nullptr;
PFNGLTEXCOORD4SPROC glTexCoord4s = nullptr;
PFNGLTEXCOORD4SVPROC glTexCoord4sv = nullptr;
PFNGLVERTEX2DPROC glVertex2d = nullptr;
PFNGLVERTEX2DVPROC glVertex2dv = nullptr;
PFNGLVERTEX2FPROC glVertex2f = nullptr;
PFNGLVERTEX2FVPROC glVertex2fv = nullptr;
PFNGLVERTEX2IPROC glVertex2i = nullptr;
PFNGLVERTEX2IVPROC glVertex2iv = nullptr;
PFNGLVERTEX2SPROC glVertex2s = nullptr;
PFNGLVERTEX2SVPROC glVertex2sv = nullptr;
PFNGLVERTEX3DPROC glVertex3d = nullptr;
PFNGLVERTEX3DVPROC glVertex3dv = nullptr;
PFNGLVERTEX3FPROC glVertex3f = nullptr;
PFNGLVERTEX3FVPROC glVertex3fv = nullptr;
PFNGLVERTEX3IPROC glVertex3i = nullptr;
PFNGLVERTEX3IVPROC glVertex3iv = nullptr;
PFNGLVERTEX3SPROC glVertex3s = nullptr;
PFNGLVERTEX3SVPROC glVertex3sv = nullptr;
PFNGLVERTEX4DPROC glVertex4d = nullptr;
PFNGLVERTEX4DVPROC glVertex4dv = nullptr;
PFNGLVERTEX4FPROC glVertex4f = nullptr;
PFNGLVERTEX4FVPROC glVertex4fv = nullptr;
PFNGLVERTEX4IPROC glVertex4i = nullptr;
PFNGLVERTEX4IVPROC glVertex4iv = nullptr;
PFNGLVERTEX4SPROC glVertex4s = nullptr;
PFNGLVERTEX4SVPROC glVertex4sv = nullptr;
PFNGLCLIPPLANEPROC glClipPlane = nullptr;
PFNGLCOLORMATERIALPROC glColorMaterial = nullptr;
PFNGLFOGFPROC glFogf = nullptr;
PFNGLFOGFVPROC glFogfv = nullptr;
PFNGLFOGIPROC glFogi = nullptr;
PFNGLFOGIVPROC glFogiv = nullptr;
PFNGLLIGHTFPROC glLightf = nullptr;
PFNGLLIGHTFVPROC glLightfv = nullptr;
PFNGLLIGHTIPROC glLighti = nullptr;
PFNGLLIGHTIVPROC glLightiv = nullptr;
PFNGLLIGHTMODELFPROC glLightModelf = nullptr;
PFNGLLIGHTMODELFVPROC glLightModelfv = nullptr;
PFNGLLIGHTMODELIPROC glLightModeli = nullptr;
PFNGLLIGHTMODELIVPROC glLightModeliv = nullptr;
PFNGLLINESTIPPLEPROC glLineStipple = nullptr;
PFNGLMATERIALFPROC glMaterialf = nullptr;
PFNGLMATERIALFVPROC glMaterialfv = nullptr;
PFNGLMATERIALIPROC glMateriali = nullptr;
PFNGLMATERIALIVPROC glMaterialiv = nullptr;
PFNGLPOLYGONSTIPPLEPROC glPolygonStipple = nullptr;
PFNGLSHADEMODELPROC glShadeModel = nullptr;
PFNGLTEXENVFPROC glTexEnvf = nullptr;
PFNGLTEXENVFVPROC glTexEnvfv = nullptr;
PFNGLTEXENVIPROC glTexEnvi = nullptr;
PFNGLTEXENVIVPROC glTexEnviv = nullptr;
PFNGLTEXGENDPROC glTexGend = nullptr;
PFNGLTEXGENDVPROC glTexGendv = nullptr;
PFNGLTEXGENFPROC glTexGenf = nullptr;
PFNGLTEXGENFVPROC glTexGenfv = nullptr;
PFNGLTEXGENIPROC glTexGeni = nullptr;
PFNGLTEXGENIVPROC glTexGeniv = nullptr;
PFNGLFEEDBACKBUFFERPROC glFeedbackBuffer = nullptr;
PFNGLSELECTBUFFERPROC glSelectBuffer = nullptr;
PFNGLRENDERMODEPROC glRenderMode = nullptr;
PFNGLINITNAMESPROC glInitNames = nullptr;
PFNGLLOADNAMEPROC glLoadName = nullptr;
PFNGLPASSTHROUGHPROC glPassThrough = nullptr;
PFNGLPOPNAMEPROC glPopName = nullptr;
PFNGLPUSHNAMEPROC glPushName = nullptr;
PFNGLCLEARACCUMPROC glClearAccum = nullptr;
PFNGLCLEARINDEXPROC glClearIndex = nullptr;
PFNGLINDEXMASKPROC glIndexMask = nullptr;
PFNGLACCUMPROC glAccum = nullptr;
PFNGLPOPATTRIBPROC glPopAttrib = nullptr;
PFNGLPUSHATTRIBPROC glPushAttrib = nullptr;
PFNGLMAP1DPROC glMap1d = nullptr;
PFNGLMAP1FPROC glMap1f = nullptr;
PFNGLMAP2DPROC glMap2d = nullptr;
PFNGLMAP2FPROC glMap2f = nullptr;
PFNGLMAPGRID1DPROC glMapGrid1d = nullptr;
PFNGLMAPGRID1FPROC glMapGrid1f = nullptr;
PFNGLMAPGRID2DPROC glMapGrid2d = nullptr;
PFNGLMAPGRID2FPROC glMapGrid2f = nullptr;
PFNGLEVALCOORD1DPROC glEvalCoord1d = nullptr;
PFNGLEVALCOORD1DVPROC glEvalCoord1dv = nullptr;
PFNGLEVALCOORD1FPROC glEvalCoord1f = nullptr;
PFNGLEVALCOORD1FVPROC glEvalCoord1fv = nullptr;
PFNGLEVALCOORD2DPROC glEvalCoord2d = nullptr;
PFNGLEVALCOORD2DVPROC glEvalCoord2dv = nullptr;
PFNGLEVALCOORD2FPROC glEvalCoord2f = nullptr;
PFNGLEVALCOORD2FVPROC glEvalCoord2fv = nullptr;
PFNGLEVALMESH1PROC glEvalMesh1 = nullptr;
PFNGLEVALPOINT1PROC glEvalPoint1 = nullptr;
PFNGLEVALMESH2PROC glEvalMesh2 = nullptr;
PFNGLEVALPOINT2PROC glEvalPoint2 = nullptr;
PFNGLALPHAFUNCPROC glAlphaFunc = nullptr;
PFNGLPIXELZOOMPROC glPixelZoom = nullptr;
PFNGLPIXELTRANSFERFPROC glPixelTransferf = nullptr;
PFNGLPIXELTRANSFERIPROC glPixelTransferi = nullptr;
PFNGLPIXELMAPFVPROC glPixelMapfv = nullptr;
PFNGLPIXELMAPUIVPROC glPixelMapuiv = nullptr;
PFNGLPIXELMAPUSVPROC glPixelMapusv = nullptr;
PFNGLCOPYPIXELSPROC glCopyPixels = nullptr;
PFNGLDRAWPIXELSPROC glDrawPixels = nullptr;
PFNGLGETCLIPPLANEPROC glGetClipPlane = nullptr;
PFNGLGETLIGHTFVPROC glGetLightfv = nullptr;
PFNGLGETLIGHTIVPROC glGetLightiv = nullptr;
PFNGLGETMAPDVPROC glGetMapdv = nullptr;
PFNGLGETMAPFVPROC glGetMapfv = nullptr;
PFNGLGETMAPIVPROC glGetMapiv = nullptr;
PFNGLGETMATERIALFVPROC glGetMaterialfv = nullptr;
PFNGLGETMATERIALIVPROC glGetMaterialiv = nullptr;
PFNGLGETPIXELMAPFVPROC glGetPixelMapfv = nullptr;
PFNGLGETPIXELMAPUIVPROC glGetPixelMapuiv = nullptr;
PFNGLGETPIXELMAPUSVPROC glGetPixelMapusv = nullptr;
PFNGLGETPOLYGONSTIPPLEPROC glGetPolygonStipple = nullptr;
PFNGLGETTEXENVFVPROC glGetTexEnvfv = nullptr;
PFNGLGETTEXENVIVPROC glGetTexEnviv = nullptr;
PFNGLGETTEXGENDVPROC glGetTexGendv = nullptr;
PFNGLGETTEXGENFVPROC glGetTexGenfv = nullptr;
PFNGLGETTEXGENIVPROC glGetTexGeniv = nullptr;
PFNGLISLISTPROC glIsList = nullptr;
PFNGLFRUSTUMPROC glFrustum = nullptr;
PFNGLLOADIDENTITYPROC glLoadIdentity = nullptr;
PFNGLLOADMATRIXFPROC glLoadMatrixf = nullptr;
PFNGLLOADMATRIXDPROC glLoadMatrixd = nullptr;
PFNGLMATRIXMODEPROC glMatrixMode = nullptr;
PFNGLMULTMATRIXFPROC glMultMatrixf = nullptr;
PFNGLMULTMATRIXDPROC glMultMatrixd = nullptr;
PFNGLORTHOPROC glOrtho = nullptr;
PFNGLPOPMATRIXPROC glPopMatrix = nullptr;
PFNGLPUSHMATRIXPROC glPushMatrix = nullptr;
PFNGLROTATEDPROC glRotated = nullptr;
PFNGLROTATEFPROC glRotatef = nullptr;
PFNGLSCALEDPROC glScaled = nullptr;
PFNGLSCALEFPROC glScalef = nullptr;
PFNGLTRANSLATEDPROC glTranslated = nullptr;
PFNGLTRANSLATEFPROC glTranslatef = nullptr;

#endif // !GL_VERSION_1_0


#ifdef GL_VERSION_1_1

PFNGLDRAWARRAYSPROC glDrawArrays = nullptr;
PFNGLDRAWELEMENTSPROC glDrawElements = nullptr;
PFNGLGETPOINTERVPROC glGetPointerv = nullptr;
PFNGLPOLYGONOFFSETPROC glPolygonOffset = nullptr;
PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D = nullptr;
PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D = nullptr;
PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D = nullptr;
PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D = nullptr;
PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D = nullptr;
PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D = nullptr;
PFNGLBINDTEXTUREPROC glBindTexture = nullptr;
PFNGLDELETETEXTURESPROC glDeleteTextures = nullptr;
PFNGLGENTEXTURESPROC glGenTextures = nullptr;
PFNGLISTEXTUREPROC glIsTexture = nullptr;
PFNGLARRAYELEMENTPROC glArrayElement = nullptr;
PFNGLCOLORPOINTERPROC glColorPointer = nullptr;
PFNGLDISABLECLIENTSTATEPROC glDisableClientState = nullptr;
PFNGLEDGEFLAGPOINTERPROC glEdgeFlagPointer = nullptr;
PFNGLENABLECLIENTSTATEPROC glEnableClientState = nullptr;
PFNGLINDEXPOINTERPROC glIndexPointer = nullptr;
PFNGLINTERLEAVEDARRAYSPROC glInterleavedArrays = nullptr;
PFNGLNORMALPOINTERPROC glNormalPointer = nullptr;
PFNGLTEXCOORDPOINTERPROC glTexCoordPointer = nullptr;
PFNGLVERTEXPOINTERPROC glVertexPointer = nullptr;
PFNGLARETEXTURESRESIDENTPROC glAreTexturesResident = nullptr;
PFNGLPRIORITIZETEXTURESPROC glPrioritizeTextures = nullptr;
PFNGLINDEXUBPROC glIndexub = nullptr;
PFNGLINDEXUBVPROC glIndexubv = nullptr;
PFNGLPOPCLIENTATTRIBPROC glPopClientAttrib = nullptr;
PFNGLPUSHCLIENTATTRIBPROC glPushClientAttrib = nullptr;

#endif // !GL_VERSION_1_1