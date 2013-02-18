/* 
 * File:   SceneIK.hpp
 * Author: sandy
 *
 * Created on February 18, 2013, 7:33 AM
 */

#ifndef SCENEIK_HPP
#define	SCENEIK_HPP

#include <gtkmm.h>
#include <gtkglmm.h>
#include "SceneBase.hpp"

class IKLine;

class SceneIK : public SceneBase 
              , public Gtk::GL::Widget<SceneIK>
{
public:
    SceneIK();
    SceneIK(const SceneIK& orig);
    virtual ~SceneIK();
private:
    virtual bool create_shaders (const char*);
    virtual void create_vao (void);
    virtual void render (void);
    
    IKLine* lines = NULL;
    
    /* Uniforms */
    GLuint gOrient;
    GLuint gPos;
    
    const char* VERTEX_SHADER =
        "#version 330\n"
        "layout (location = 0) in vec3 gl_Vertex;\n"
        "uniform mat4 gWorld;\n"
        "uniform float o;\n"
        "uniform vec2 t;\n"
        "out vec3 ex_Color;\n"

        "void main( void ) {\n"
        "    mat4 r = mat4( cos(o),  sin(o), 0.0, 0.0,\n"
        "                  -sin(o),  cos(o), 0.0, 0.0,\n"
        "                   0.0,     0.0,    1.0, 0.0,\n"
        "                   0.0,     0.0,    0.0, 1.0);\n"

        "    gl_Position = gWorld * r * vec4(gl_Vertex, 1.0) + vec4(t, 0.0, 0.0);\n"
        "    ex_Color = clamp(gl_Vertex, 0.0, 1.0);\n"
        "}";
};

#endif	/* SCENEIK_HPP */

