/*
  ==============================================================================

    MenuC_Viewport_3D.cpp
    Created: 14 May 2017 12:06:35pm
    Author:  Robin

  ==============================================================================
*/

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "MenuC_Viewport_3D.h"

//==============================================================================
MenuC_Viewport_3D::MenuC_Viewport_3D()
{
	m_camera.m_rotation[0] = 0;
	m_camera.m_rotation[1] = 0;

	bool m_viewportCameraRotation_Enabled = false;
	float m_mouseLocation_lastFrame[2] = {0,0};

}

MenuC_Viewport_3D::~MenuC_Viewport_3D()
{
}

void MenuC_Viewport_3D::paint (Graphics& g)
{

}

void MenuC_Viewport_3D::resized()
{

}

void MenuC_Viewport_3D::initialise()
{
	//Load Shaders:

	m_vertexShader =
		"attribute vec4 position;\n"
		"uniform mat4 viewMatrixX;\n"
		"uniform mat4 viewMatrixY;\n"
		"void main()\n"
		"{\n"
		"gl_Position = (position * viewMatrixX) * viewMatrixY;\n"
		"}\n";

	m_fragmentShader =
		"void main()\n"
		"{\n"
		"vec4 colour = vec4 (0.95 , 0.57, 0.03, 1.0  );\n"
		"gl_FragColor = colour;\n"
		"}\n";

	//add Shaders to Program:
	m_shaderProgram = new OpenGLShaderProgram(openGLContext);
	m_shaderProgram->addVertexShader(OpenGLHelpers::translateVertexShaderToV3(m_vertexShader));
	m_shaderProgram->addFragmentShader(OpenGLHelpers::translateFragmentShaderToV3(m_fragmentShader));

	m_shaderProgram->link();

	// Create GL Attributes:
	m_position = new OpenGLShaderProgram::Attribute(*m_shaderProgram, "position");

	// Create GL Uniforms:
	m_viewMatrix_x = openGLContext.extensions.glGetUniformLocation(m_shaderProgram->getProgramID(), "viewMatrixX");
	m_viewMatrix_y = openGLContext.extensions.glGetUniformLocation(m_shaderProgram->getProgramID(), "viewMatrixY");

	// Setup Buffers:
	openGLContext.extensions.glGenBuffers(1, &m_vertexBuffer);
	openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	openGLContext.extensions.glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex), m_vertices, GL_STATIC_DRAW);
}

void MenuC_Viewport_3D::render()
{
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	m_shaderProgram->use();
	openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);


	openGLContext.extensions.glVertexAttribPointer(m_position->attributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	openGLContext.extensions.glEnableVertexAttribArray(m_position->attributeID);

	updateViewport();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	openGLContext.extensions.glDisableVertexAttribArray(m_position->attributeID);
}

void MenuC_Viewport_3D::shutdown()
{
	openGLContext.extensions.glDeleteBuffers(1, &m_vertexBuffer);
	openGLContext.detach();
}

void MenuC_Viewport_3D::updateViewport()
{
	GLfloat matrixX[] = { 1, 0, 0, 0,
		0, std::cos(m_camera.m_rotation[0]), -std::sin(m_camera.m_rotation[0]), 0,
		0, std::sin(m_camera.m_rotation[0]), std::cos(m_camera.m_rotation[0]), 0,
		0, 0, 0, 1 };

	openGLContext.extensions.glUniformMatrix4fv(m_viewMatrix_x, 1, false, matrixX);

	GLfloat matrixY[] = { std::cos(m_camera.m_rotation[1]), 0, -std::sin(m_camera.m_rotation[1]), 0,
		0, 1, 0, 0,
		std::sin(m_camera.m_rotation[1]), 0, std::cos(m_camera.m_rotation[1]), 0,
		0, 0, 0, 1 };

	openGLContext.extensions.glUniformMatrix4fv(m_viewMatrix_y, 1, false, matrixY);
}

void MenuC_Viewport_3D::mouseDrag(const MouseEvent & event)
{
	if (m_viewportCameraRotation_Enabled)
	{
		// Add Mouse Input:
		m_camera.Add_Rotation_Y((event.x - m_mouseLocation_lastFrame[0])/100);
		m_camera.Add_Rotation_X((event.y - m_mouseLocation_lastFrame[1])/100);

		// Update mouse Location Vars:
		m_mouseLocation_lastFrame[0] = event.x;
		m_mouseLocation_lastFrame[1] = event.y;
	}
}

void MenuC_Viewport_3D::mouseDown(const MouseEvent & event)
{
	if (event.mods.isMiddleButtonDown())
	{
		m_viewportCameraRotation_Enabled = true;
		m_mouseLocation_lastFrame[0] = event.x;
		m_mouseLocation_lastFrame[1] = event.y;
	}
}

void MenuC_Viewport_3D::mouseUp(const MouseEvent & event)
{
	m_viewportCameraRotation_Enabled = false;
}
