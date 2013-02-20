/* 
 * File:   SceneBase.cpp
 * Author: sandy
 * 
 * Created on February 17, 2013, 11:48 PM
 */

#include <iostream>
#include <GL/glew.h>
#include <GL/glu.h>

#include <gtkmm.h>
#include <gtkglmm.h>

#include "../GLConfigUtil.hpp"
#include "../math3d.hpp"
#include "SceneBase.hpp"


SceneBase::SceneBase (void)
    : World(new Matrix4f(1.0f, 0.0f, 0.0f, 0.0f,
                         0.0f, 1.0f, 0.0f, 0.0f,
                         0.0f, 0.0f, 1.0f, 0.0f,
                         0.0f, 0.0f, 0.0f, 1.0f))
{
    /* Connect timeout */
    //Glib::signal_timeout().connect( sigc::mem_fun(*this, &SceneBase::on_timeout), 17 );

    /* Configure OpenGL-capable visual. */
    Glib::RefPtr<Gdk::GL::Config> glconfig;

    /* Try double-buffered visual */
    glconfig = Gdk::GL::Config::create(Gdk::GL::MODE_RGB    |
                                       Gdk::GL::MODE_DEPTH  |
                                       Gdk::GL::MODE_DOUBLE);
    if (!glconfig)
    {
      std::cerr << "*** Cannot find the double-buffered visual.\n"
                << "*** Trying single-buffered visual.\n";

      /* Try single-buffered visual */
      glconfig = Gdk::GL::Config::create(Gdk::GL::MODE_RGB   |
                                         Gdk::GL::MODE_DEPTH);
      if (!glconfig)
        {
          std::cerr << "*** Cannot find any OpenGL-capable visual.\n";
          std::exit(1);
        }
    }

    /* print frame buffer attributes. */
    GLConfigUtil::examine_gl_attrib(glconfig);

    /* Set OpenGL-capability to the widget. */
    set_gl_capability(glconfig);
}

SceneBase::~SceneBase (void)
{ 
    release();
    delete(World); World = NULL;
    delete(vertices); vertices = NULL;
}

/* Signal to take any necessary actions when the widget is instantiated on a
 * particular display. */
void SceneBase::on_realize (void)
{
    /* We need to call the base on_realize() */
    Gtk::DrawingArea::on_realize();

    /* Get GL::Drawable. */
    Glib::RefPtr<Gdk::GL::Drawable> gldrawable = get_gl_drawable();

    /*** OpenGL BEGIN ***/
    if (!gldrawable->gl_begin(get_gl_context()))
        return;

    if (!init_opengl())
        return;

    gldrawable->gl_end();
    /*** OpenGL END ***/
    
    /* Start timer. */
    m_Timer.start();
}

/* Signal to take any necessary actions when the widget changes size. */
bool SceneBase::on_configure_event (GdkEventConfigure* event)
{
    /* Get GL::Drawable. */
    Glib::RefPtr<Gdk::GL::Drawable> gldrawable = get_gl_drawable();

    /*** OpenGL BEGIN ***/
    if (!gldrawable->gl_begin(get_gl_context()))
        return false;
    
    glViewport(0, 0, get_width(), get_height());
    
    set_perspective();

    gldrawable->gl_end();
    /*** OpenGL END ***/

    return true;
}

void SceneBase::set_perspective()
{
    // TODO: set persepctive based on get_height() and get_width()
}

/* Signal to handle redrawing the contents of the widget. */
bool SceneBase::on_expose_event (GdkEventExpose* event)
{
    /* Get GL::Window. */
    Glib::RefPtr<Gdk::GL::Drawable> gldrawable = get_gl_drawable();

    /*** OpenGL BEGIN ***/
    if (!gldrawable->gl_begin(get_gl_context()))
        return false;

    /* Draw here */
    render();

    /* Swap buffers. */
    if (gldrawable->is_double_buffered())
        gldrawable->swap_buffers();
    else
        glFlush();

    gldrawable->gl_end();

    return true;
}

bool SceneBase::on_map_event(GdkEventAny* event)
{
    if (!m_ConnectionIdle.connected())
        m_ConnectionIdle = Glib::signal_idle().connect(
        sigc::mem_fun(*this, &SceneBase::on_idle), GDK_PRIORITY_REDRAW);

    return true;
}

bool SceneBase::on_unmap_event(GdkEventAny* event)
{
    if (m_ConnectionIdle.connected())
        m_ConnectionIdle.disconnect();

    return true;
}

bool SceneBase::on_visibility_notify_event(GdkEventVisibility* event)
{
    if (event->state == GDK_VISIBILITY_FULLY_OBSCURED) {
        if (m_ConnectionIdle.connected())
            m_ConnectionIdle.disconnect();
    } else {
        if (!m_ConnectionIdle.connected())
            m_ConnectionIdle = Glib::signal_idle().connect(
            sigc::mem_fun(*this, &SceneBase::on_idle), GDK_PRIORITY_REDRAW);
    }

    return true;
}

/* OpenGL specific functions */

/* Initialize OpenGL */
bool SceneBase::init_opengl (void)
{
    std::cout << "GL_RENDERER   = " << glGetString(GL_RENDERER)   << std::endl;
    std::cout << "GL_VERSION    = " << glGetString(GL_VERSION)    << std::endl;
    std::cout << "GL_VENDOR     = " << glGetString(GL_VENDOR)     << std::endl;
    std::cout << "GL_EXTENSIONS = " << glGetString(GL_EXTENSIONS) << std::endl;
    std::cout << std::endl;

    /* Initialize GLEW */
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
      std::cerr << "*** Error Initializing GLEW: "
                << glewGetErrorString(err) << std::endl;
      std::exit(1);
    }

    /* Check that the machine supports the 2.1 API. */
    if (!GLEW_VERSION_3_0)
    {
      std::cerr << "*** Machine does not support GLEW 3.0 API.\n";
      std::exit(1);
    }

    /* Check that the machine supports the 2.1 API. */
    if (!GLEW_VERSION_4_3)
      std::cout << "*** WARN: Machine does not support GLEW 4.3 API.\n";

    /* Create Shader and vertex buffer */
    if(!create_shaders(VERTEX_SHADER))
    {
        std::cerr << "*** Error Creating shaders.\n";
        return false;
    }
    
    create_light();
    create_geom();

    /* Clear Frame Buffers */
    glClearColor(CLEAR_R, CLEAR_G, CLEAR_B, CLEAR_A);
    glClearDepth(1.0f);

    /* Configure Viewport to take up the whole window */
    glViewport(0, 0, get_width(), get_height());

    glPointSize(5.0f);
            
    return true;
}

/* Shaders */
bool SceneBase::create_shaders (const char* vsh)
{
    char shader_error[1024];
    int error_length = 0;
    GLint res;

    /* Generate some IDs for our shader programs */
    SHVERT = glCreateShader(GL_VERTEX_SHADER);
    SHFRAG = glCreateShader(GL_FRAGMENT_SHADER);
    SHPROG = glCreateProgram();

    /* Assign shader source code to these IDs */
    glShaderSource(SHVERT, 1, &vsh, NULL);
    glShaderSource(SHFRAG, 1, &FRAGMENT_SHADER, NULL);

    /* Compile the code */
    glCompileShader(SHVERT);
    glCompileShader(SHFRAG);

    /* Check if compilation was successful */
    glGetShaderiv(SHVERT, GL_COMPILE_STATUS, &res);
    if (res == GL_FALSE)
    {
        std::cerr << "Compilation of vertex shader failed" << std::endl;
        glGetShaderInfoLog(SHVERT, 1024, &error_length, shader_error);
        std::cerr << shader_error << std::endl;
        return false;
    }
    glGetShaderiv(SHFRAG, GL_COMPILE_STATUS, &res);
    if (res == GL_FALSE)
    {
        std::cerr << "Compilation of fragment shader failed" << std::endl;
        glGetShaderInfoLog(SHFRAG, 1024, &error_length, shader_error);
        std::cerr << shader_error << std::endl;
        return false;
    }

    /* Attach these shaders to the shader program */
    glAttachShader(SHPROG, SHVERT);
    glAttachShader(SHPROG, SHFRAG);

    /* Flag the shaders to be deleted when the shader program is deleted */
    glDeleteShader(SHVERT);
    glDeleteShader(SHFRAG);

    /* Link the shaders */
    glLinkProgram(SHPROG);
    glGetProgramiv(SHPROG, GL_LINK_STATUS, &res);
    if (res == GL_FALSE)
        std::cerr << "Failed to link shader program" << std::endl;

    /* Get Uniforms */
    gWorldLocation = glGetUniformLocation(SHPROG, "gWorld");
    if (gWorldLocation == 0xFFFFFFFF)
        return false;

    return true;
}

/* Vertex array objects */
void SceneBase::create_geom (void)
{
}
/* Create lights in the scene */
void SceneBase::create_light(void)
{
}

/* Draw Scene */
void SceneBase::render ()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Set current rendering shader */
    glUseProgram(SHPROG);
    
    /* Uniform update */
    glUniformMatrix4fv(gWorldLocation, 1, GL_TRUE, World->m);

}



bool SceneBase::on_idle()
{
    // Invalidate the whole window.
    invalidate();

    // Update window synchronously (fast).
    update();

    return true;
}

/* Releases the context */
void SceneBase::release (void)
{
}