/*
  ==============================================================================

    MenuC_Viewport_3D.h
    Created: 14 May 2017 12:06:35pm
    Author:  Robin

  ==============================================================================
*/

#ifndef MENUC_VIEWPORT_3D_H_INCLUDED
#define MENUC_VIEWPORT_3D_H_INCLUDED

#include "../../../JuceLibraryCode/JuceHeader.h"

#include "../../Core/Object/Vertex.h"
#include "../../Core/Object/Camera.h"

//==============================================================================
/*
*/
class MenuC_Viewport_3D    : public OpenGLAppComponent
{
public:
    MenuC_Viewport_3D();
    ~MenuC_Viewport_3D();

	// Component:
	void paint(Graphics&) override;
	void resized() override;

	// GL:
	void initialise() override;
	void render() override;
	void shutdown() override;


	//Custom:
	void updateViewport();
	void mouseDown(const MouseEvent& event) override;
	void mouseUp(const MouseEvent& event) override;
	void mouseDrag(const MouseEvent& event) override;

private:

// GL:
	//Buffer:
	GLuint m_vertexBuffer;

	// Shaders:
	char* m_fragmentShader;
	char* m_vertexShader;
	ScopedPointer<OpenGLShaderProgram> m_shaderProgram;

	// Attributes:
	ScopedPointer<OpenGLShaderProgram::Attribute> m_position;

	// Uniforms:
	GLuint m_viewMatrix_x;
	GLuint m_viewMatrix_y;
	// Mesh:
	Vertex m_vertices[3] = { Vertex(-0.5, -0.5, 0), Vertex(0, 0.5, 0) , Vertex(0.5, -0.5, 0) };

// Viewport:
	Camera m_camera;

	// Camera Vars:

	bool m_viewportCameraRotation_Enabled;
	float m_mouseLocation_lastFrame [2];


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MenuC_Viewport_3D)
};


#endif  // MENUC_VIEWPORT_3D_H_INCLUDED
