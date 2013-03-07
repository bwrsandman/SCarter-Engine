// -*- C++ -*-
/*
 * 3-D gear wheels.  This program is in the public domain.
 *
 * Brian Paul
 */

/* Conversion to gtkglextmm by Naofumi Yasufuku */

#include <iostream>
#include <GL/glew.h>
#include <GL/glu.h>

#include <gtkmm.h>
#include <gtkglmm.h>

#include "SceneBase.hpp"
#include "SceneGears.hpp"

///////////////////////////////////////////////////////////////////////////////
//
// Gears scene.
//
///////////////////////////////////////////////////////////////////////////////

SceneGears::SceneGears(bool is_sync)
  : m_Gear1(0), m_Gear2(0), m_Gear3(0),
    m_ViewRotX(20.0), m_ViewRotY(30.0), m_ViewRotZ(0.0),
    m_Angle(0.0), m_IsSync(is_sync),
    m_Frames(0)
{
}

SceneGears::~SceneGears()
{
}

/*
 * Draw a gear wheel.  You'll probably want to call this function when
 * building a display list since we do a lot of trig here.
 *
 * Input:  inner_radius - radius of hole at center
 * outer_radius - radius at center of teeth
 * width - width of gear
 * teeth - number of teeth
 * tooth_depth - depth of tooth
 */

void SceneGears::gear(GLfloat inner_radius,
                      GLfloat outer_radius,
                      GLfloat width,
                      GLint   teeth,
                      GLfloat tooth_depth)
{
  GLint i;
  GLfloat r0, r1, r2;
  GLfloat angle, da;
  GLfloat u, v, len;

  r0 = inner_radius;
  r1 = outer_radius - tooth_depth / 2.0;
  r2 = outer_radius + tooth_depth / 2.0;

  da = 2.0 * G_PI / teeth / 4.0;

  glShadeModel(GL_FLAT);

  glNormal3f(0.0, 0.0, 1.0);

  /* draw front face */
  glBegin(GL_QUAD_STRIP);
  for (i = 0; i <= teeth; i++) {
    angle = i * 2.0 * G_PI / teeth;
    glVertex3f(r0 * cos(angle), r0 * sin(angle), width * 0.5);
    glVertex3f(r1 * cos(angle), r1 * sin(angle), width * 0.5);
    if (i < teeth) {
      glVertex3f(r0 * cos(angle), r0 * sin(angle), width * 0.5);
      glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), width * 0.5);
    }
  }
  glEnd();

  /* draw front sides of teeth */
  glBegin(GL_QUADS);
  da = 2.0 * G_PI / teeth / 4.0;
  for (i = 0; i < teeth; i++) {
    angle = i * 2.0 * G_PI / teeth;

    glVertex3f(r1 * cos(angle), r1 * sin(angle), width * 0.5);
    glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), width * 0.5);
    glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), width * 0.5);
    glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), width * 0.5);
  }
  glEnd();

  glNormal3f(0.0, 0.0, -1.0);

  /* draw back face */
  glBegin(GL_QUAD_STRIP);
  for (i = 0; i <= teeth; i++) {
    angle = i * 2.0 * G_PI / teeth;
    glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
    glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
    if (i < teeth) {
      glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
      glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
    }
  }
  glEnd();

  /* draw back sides of teeth */
  glBegin(GL_QUADS);
  da = 2.0 * G_PI / teeth / 4.0;
  for (i = 0; i < teeth; i++) {
    angle = i * 2.0 * G_PI / teeth;

    glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
    glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), -width * 0.5);
    glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), -width * 0.5);
    glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
  }
  glEnd();

  /* draw outward faces of teeth */
  glBegin(GL_QUAD_STRIP);
  for (i = 0; i < teeth; i++) {
    angle = i * 2.0 * G_PI / teeth;

    glVertex3f(r1 * cos(angle), r1 * sin(angle), width * 0.5);
    glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
    u = r2 * cos(angle + da) - r1 * cos(angle);
    v = r2 * sin(angle + da) - r1 * sin(angle);
    len = sqrt(u * u + v * v);
    u /= len;
    v /= len;
    glNormal3f(v, -u, 0.0);
    glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), width * 0.5);
    glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), -width * 0.5);
    glNormal3f(cos(angle), sin(angle), 0.0);
    glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), width * 0.5);
    glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), -width * 0.5);
    u = r1 * cos(angle + 3 * da) - r2 * cos(angle + 2 * da);
    v = r1 * sin(angle + 3 * da) - r2 * sin(angle + 2 * da);
    glNormal3f(v, -u, 0.0);
    glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), width * 0.5);
    glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
    glNormal3f(cos(angle), sin(angle), 0.0);
  }

  glVertex3f(r1 * cos(0), r1 * sin(0), width * 0.5);
  glVertex3f(r1 * cos(0), r1 * sin(0), -width * 0.5);

  glEnd();

  glShadeModel(GL_SMOOTH);

  /* draw inside radius cylinder */
  glBegin(GL_QUAD_STRIP);
  for (i = 0; i <= teeth; i++) {
    angle = i * 2.0 * G_PI / teeth;
    glNormal3f(-cos(angle), -sin(angle), 0.0);
    glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
    glVertex3f(r0 * cos(angle), r0 * sin(angle), width * 0.5);
  }
  glEnd();

}

void SceneGears::create_light()
{
    /* Create lighting */
    static GLfloat pos[4] = {5.0, 5.0, 10.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void SceneGears::create_geom()
{
    static GLfloat red[4] = {0.8, 0.1, 0.0, 1.0};
    static GLfloat green[4] = {0.0, 0.8, 0.2, 1.0};
    static GLfloat blue[4] = {0.2, 0.2, 1.0, 1.0};
    
    // Make the gears.
    m_Gear1 = glGenLists(1);
    glNewList(m_Gear1, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
    gear(1.0, 4.0, 1.0, 20, 0.7);
    glEndList();

    m_Gear2 = glGenLists(1);
    glNewList(m_Gear2, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, green);
    gear(0.5, 2.0, 2.0, 10, 0.7);
    glEndList();

    m_Gear3 = glGenLists(1);
    glNewList(m_Gear3, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    gear(1.3, 2.0, 0.5, 10, 0.7);
    glEndList();
}

void SceneGears::set_perspective()
{
    GLfloat h = (GLfloat)(get_height()) / (GLfloat)(get_width());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -h, h, 5.0, 60.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -40.0);
}

void SceneGears::print_framerate(const float dt)
{
    //
    // Print frame rate.
    //

    ++m_Frames;

    if (dt >= 5.0f)
      {
        // std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout.setf(std::ios::fixed, std::ios::floatfield);
        std::cout.precision(3);
        std::cout << m_Frames << " frames in "
                  << dt << " seconds = "
                  << (m_Frames / dt) << " FPS\n";
        m_Frames = 0;
      }
}

void SceneGears::render(const float dt)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(m_ViewRotX, 1.0, 0.0, 0.0);
        glRotatef(m_ViewRotY, 0.0, 1.0, 0.0);
        glRotatef(m_ViewRotZ, 0.0, 0.0, 1.0);

        glPushMatrix();
            glTranslatef(-3.0, -2.0, 0.0);
            glRotatef(m_Angle, 0.0, 0.0, 1.0);
            glCallList(m_Gear1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(3.1, -2.0, 0.0);
            glRotatef(-2.0 * m_Angle - 9.0, 0.0, 0.0, 1.0);
            glCallList(m_Gear2);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.1, 4.2, 0.0);
            glRotatef(-2.0 * m_Angle - 25.0, 0.0, 0.0, 1.0);
            glCallList(m_Gear3);
        glPopMatrix();

    glPopMatrix();
    
    print_framerate(dt);
}

void SceneGears::update(const float dt)
{
    SceneBase::update(dt);
    m_Angle += 2.0;
}